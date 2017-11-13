#include "quanteda.h"
#include "recompile.h"
//#include "dev.h"
using namespace quanteda;

typedef pair<size_t, size_t> Target;
typedef std::vector<Target> Targets;

Targets kwic_range(Text tokens,
                   const std::vector<std::size_t> &spans,
                   const SetNgrams &set_words){
    
    if(tokens.size() == 0) return {}; // return empty vector for empty text
    
    // This part is the same as tokens_detect 
    Text tokens_pos(tokens.size(), 0);
    for (std::size_t span : spans) { // substitution starts from the longest sequences
        if (tokens.size() < span) continue;
        for (size_t i = 0; i < tokens.size() - (span - 1); i++) {
            Ngram ngram(tokens.begin() + i, tokens.begin() + i + span);
            bool is_in = set_words.find(ngram) != set_words.end();
            if (is_in) {
                std::fill(tokens_pos.begin() + i, tokens_pos.begin() + i + span, 1);
            }
        }
    }
    
    Targets targets;
    size_t start, end;
    size_t last = tokens_pos.size() - 1;
    for (size_t k = 0; k < tokens_pos.size(); k++) {
        if ((k == 0 || tokens_pos[k - 1] == 0) && tokens_pos[k] == 1) {
            start = k;
            //Rcout << "starts " << start << "\n";
        }
        if (tokens_pos[k] == 1 && (k == last || tokens_pos[k + 1] == 0)) {
            end = k;
            //Rcout << "ends " << end << "\n";
            targets.push_back(make_pair(start, end));
        }
    }
    return targets;
}

Targets kwic_match(Text tokens,
                   const std::vector<std::size_t> &spans,
                   const SetNgrams &set_words){
    
    if(tokens.size() == 0) return {}; // return empty vector for empty text
    
    Targets targets;
    for (std::size_t span : spans) { // substitution starts from the longest sequences
        if (tokens.size() < span) continue;
        for (size_t i = 0; i < tokens.size() - (span - 1); i++) {
            Ngram ngram(tokens.begin() + i, tokens.begin() + i + span);
            bool is_in = set_words.find(ngram) != set_words.end();
            if (is_in) {
                targets.push_back(make_pair(i, i + span - 1));
            }
        }
    }
    
    // sort by the starting positions
    std::sort(targets.begin(), targets.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first < right.first;
    });
    return targets;
}

struct kwic_mt : public Worker{
    
    Texts &texts;
    std::vector<Targets> &temp;
    const std::vector<std::size_t> &spans;
    const SetNgrams &set_words;
    const bool &join;
    
    // Constructor
    kwic_mt(Texts &texts_, std::vector<Targets> &temp_,
            const std::vector<std::size_t> &spans_, const SetNgrams &set_words_, const bool &join_):
            texts(texts_), temp(temp_), spans(spans_), set_words(set_words_), join(join_){}
    
    // parallelFor calles this function with size_t
    void operator()(std::size_t begin, std::size_t end){
        //Rcout << "Range " << begin << " " << end << "\n";
        for (std::size_t h = begin; h < end; h++){
            if (join) {
                temp[h] = kwic_range(texts[h], spans, set_words);
            } else {
                temp[h] = kwic_match(texts[h], spans, set_words);
            }
        }
    }
};


/* 
 * This function generate generates keyword-in-contexts. 
 * The number of threads is set by RcppParallel::setThreadOptions()
 * @used kwic()
 * @creator Kohei Watanabe
 * @param texts_ tokens ojbect
 * @param types_ types
 * @param words_ list of target features
 * @param join join adjacent keywords
 */

// [[Rcpp::export]]
DataFrame qatd_cpp_kwic(const List &texts_,
                        const CharacterVector types_,
                        const List &words_,
                        const unsigned int &window,
                        const bool &join){
    
    Texts texts = Rcpp::as<Texts>(texts_);
    Types types = Rcpp::as< Types >(types_);
    CharacterVector names_ = texts_.attr("names");
    
    SetNgrams set_words;
    std::vector<std::size_t> spans = register_ngrams(words_, set_words);
    
    // dev::Timer timer;
    std::vector<Targets> temp(texts.size());
    
    // dev::start_timer("Dictionary detect", timer);
#if QUANTEDA_USE_TBB
    kwic_mt kwic_mt(texts, temp, spans, set_words, join);
    parallelFor(0, texts.size(), kwic_mt);
#else
    for (std::size_t h = 0; h < texts.size(); h++) {
        if (join) {
            temp[h] = kwic_range(texts[h], spans, set_words);
        } else {
            temp[h] = kwic_match(texts[h], spans, set_words);
        }
    }
#endif
    
    // Get total number of matches
    std::size_t len = 0;
    for (std::size_t h = 0; h < temp.size(); h++) {
        len += temp[h].size();
    }
    
    Texts contexts(len);
    IntegerVector documents_(len), segments_(len);
    IntegerVector pos_from_(len), pos_to_(len);
    CharacterVector coxs_name_(len), coxs_pre_(len), coxs_target_(len), coxs_post_(len);
    
    std::size_t j = 0;
    for (std::size_t h = 0; h < temp.size(); h++) {
        Targets targets = temp[h];
        if (targets.size() == 0) continue;
        Text tokens = texts[h];
        int last = (int)tokens.size() - 1;
        for (size_t i = 0; i < targets.size(); i++) {
            int from = targets[i].first - window;
            int to = targets[i].second + window;
            //Rcout << j << " " << targets[i].first << ":" << targets[i].second << "\n";
            
            // Save as intergers
            Text context(tokens.begin() + std::max(0, from), tokens.begin() + std::min(to, last) + 1);
            contexts[j] = context;
            documents_[j] = (int)h + 1;
            segments_[j] = (int)i + 1;
            
            // Save as strings
            Text cox_pre(tokens.begin() + std::max(0, from), tokens.begin() + targets[i].first);
            Text cox_target(tokens.begin() + targets[i].first, tokens.begin() + targets[i].second + 1);
            Text cox_post(tokens.begin() + targets[i].second + 1, tokens.begin() + std::min(to, last) + 1);
            
            pos_from_[j] = targets[i].first + 1;
            pos_to_[j] = targets[i].second + 1; 
            coxs_pre_[j] = join_strings(cox_pre, types_); 
            coxs_target_[j] = join_strings(cox_target, types_);
            coxs_post_[j] = join_strings(cox_post, types_);
            coxs_name_[j] = names_[h];
            j++;
        }
    }
    

    Tokens tokens_ = recompile(contexts, types, true, true, is_encoded(types_));
    tokens_.attr("names") = coxs_name_;
    
    DataFrame output_ = DataFrame::create(_["docname"] = coxs_name_,
                                          _["from"]    = pos_from_,
                                          _["to"]      = pos_to_,
                                          _["pre"]     = coxs_pre_,
                                          _["keyword"] = coxs_target_,
                                          _["post"]    = coxs_post_,
                                          _["stringsAsFactors"] = false);
    
    output_.attr("tokens") = tokens_;
    output_.attr("docid") = documents_;
    output_.attr("segid") = segments_;
    return output_;
}




/***R

toks <- list(text1=1:10, text2=5:15)
#toks <- rep(list(rep(1:10, 1), rep(5:15, 1)), 1)
#dict <- list(c(1, 2), c(5, 6), 10, 15, 20)
#qatd_cpp_tokens_contexts(toks, dict, 2)
qatd_cpp_kwic(toks, letters, list(10), 3, FALSE)
qatd_cpp_kwic(toks, letters, list(10), 3, TRUE)
qatd_cpp_kwic(toks, letters, list(c(3, 4), 7), 2, FALSE)
qatd_cpp_kwic(toks, letters, list(c(3, 4), 7), 2, TRUE)
qatd_cpp_kwic(toks, letters, c(3, 4, 7), 2, FALSE)
qatd_cpp_kwic(toks, letters, c(3, 4, 7), 2, TRUE)


*/
