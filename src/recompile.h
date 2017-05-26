#include "quanteda.h"
using namespace quanteda;

#if QUANTEDA_USE_TBB
typedef tbb::concurrent_vector<unsigned int> VecIds;
#else
typedef std::vector<unsigned int> VecIds;
#endif

inline CharacterVector encode(Types types){
    CharacterVector types_(types.size());
    for (std::size_t i = 0; i < types.size(); i++) {
        String type_ = types[i];
        type_.set_encoding(CE_UTF8);
        types_[i] = type_;
    }
    return(types_);
}

struct recompile_mt : public Worker{
    
    Texts &texts;
    VecIds &ids_new;
    
    recompile_mt(Texts &texts_, VecIds &ids_new_):
        texts(texts_), ids_new(ids_new_) {}
    
    void operator()(std::size_t begin, std::size_t end){
        for (std::size_t h = begin; h < end; h++) {
            for (std::size_t i = 0; i < texts[h].size(); i++) {
                texts[h][i] = ids_new[texts[h][i]];
            }
        }
    }
};

inline Tokens recompile(Texts texts, Types types){
    

    VecIds ids_new(types.size() + 1);
    ids_new[0] = 0; // reserved for padding
    unsigned int id_new = 1;
    //Rcout << setw(10) << "" << ": " << 0 << " -> " << ids_new[0] << "\n";
    
    // Check if IDs are all used
    unsigned int id_limit = ids_new.size();
    std::vector<bool> flags_used(ids_new.size(), false);
    for (std::size_t h = 0; h < texts.size(); h++) {
        for (std::size_t i = 0; i < texts[h].size(); i++) {
            unsigned int id = texts[h][i];
            if (id > id_limit) {
                throw std::range_error("Invalid tokens object");    
            }
            flags_used[id] = true;
        }
    }
    bool all_used = std::all_of(flags_used.begin(), flags_used.end(), [](bool v) { return v; });
    
    // Check if types are duplicated
    std::vector<bool> flags_unique(ids_new.size(), false);
    std::unordered_map<std::string, unsigned int> types_unique;
    flags_unique[0] = true; // padding is always unique
    for (std::size_t g = 1; g < ids_new.size(); g++) {
        if (types[g - 1] == "") continue; // ignore null types
        auto it = types_unique.insert(std::pair<std::string, unsigned int>(types[g - 1], id_new));
        ids_new[g] = it.first->second;
        if (it.second) {
            flags_unique[g] = true;
            if (flags_used[g]) {
                id_new++; // increment iff there is no gap
            }
        }
        // if (flags_used[g]) {
        //     Rcout << setw(10) << types[g - 1] << ": " << g << " -> " << ids_new[g] << "\n";
        // } else {
        //     Rcout << setw(10) << types[g - 1] << ": " << g << " ->\n";
        // }
    }
    bool all_unique = std::all_of(flags_unique.begin(), flags_unique.end(), [](bool v) { return v; });
     
    // Do nothing if all used and unique
    //Rcout << all_used << " " << all_unique << "\n";
    if (all_used && all_unique) {
        ListOf<IntegerVector> texts_list = Rcpp::wrap(texts);
        texts_list.attr("padding") = (bool)flags_used[0];
        texts_list.attr("types") = types;
        return texts_list;
    }
    
    // Convert old IDs to new IDs
#if QUANTEDA_USE_TBB
    recompile_mt recompile_mt(texts, ids_new);
    parallelFor(0, texts.size(), recompile_mt);
#else
    for (std::size_t h = 0; h < texts.size(); h++) {
        for (std::size_t i = 0; i < texts[h].size(); i++) {
            texts[h][i] = ids_new[texts[h][i]];
            //Rcout << texts[h][i] << " -> " << ids_new[texts[h][i]] << "\n";
        }
    }
#endif

    std::vector<std::string> types_new;
    types_new.reserve(ids_new.size());
    for (std::size_t j = 0; j < ids_new.size() - 1; j++) {
        if (flags_used[j + 1] && flags_unique[j + 1]) {
            types_new.push_back(types[j]);
        }
    }
    
    // dev::stop_timer("Dictionary lookup", timer);
    Tokens texts_list = Rcpp::wrap(texts);
    texts_list.attr("padding") = (bool)flags_used[0];
    texts_list.attr("types") = encode(types_new);
    return texts_list;
    
}
