// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// qatd_cpp_fcm
S4 qatd_cpp_fcm(const Rcpp::List& texts_, const int n_types, const NumericVector& weights_, const bool boolean, const bool ordered);
RcppExport SEXP _quanteda_qatd_cpp_fcm(SEXP texts_SEXP, SEXP n_typesSEXP, SEXP weights_SEXP, SEXP booleanSEXP, SEXP orderedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const int >::type n_types(n_typesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type weights_(weights_SEXP);
    Rcpp::traits::input_parameter< const bool >::type boolean(booleanSEXP);
    Rcpp::traits::input_parameter< const bool >::type ordered(orderedSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_fcm(texts_, n_types, weights_, boolean, ordered));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_index
DataFrame qatd_cpp_index(const List& texts_, const CharacterVector types_, const List& words_);
RcppExport SEXP _quanteda_qatd_cpp_index(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_index(texts_, types_, words_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_chunk
List qatd_cpp_tokens_chunk(const List& texts_, const CharacterVector types_, const int size, const int overlap);
RcppExport SEXP _quanteda_qatd_cpp_tokens_chunk(SEXP texts_SEXP, SEXP types_SEXP, SEXP sizeSEXP, SEXP overlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< const int >::type overlap(overlapSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_chunk(texts_, types_, size, overlap));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_compound
List qatd_cpp_tokens_compound(const List& texts_, const List& compounds_, const CharacterVector& types_, const String& delim_, const bool& join, int window_left, int window_right);
RcppExport SEXP _quanteda_qatd_cpp_tokens_compound(SEXP texts_SEXP, SEXP compounds_SEXP, SEXP types_SEXP, SEXP delim_SEXP, SEXP joinSEXP, SEXP window_leftSEXP, SEXP window_rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const List& >::type compounds_(compounds_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector& >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const String& >::type delim_(delim_SEXP);
    Rcpp::traits::input_parameter< const bool& >::type join(joinSEXP);
    Rcpp::traits::input_parameter< int >::type window_left(window_leftSEXP);
    Rcpp::traits::input_parameter< int >::type window_right(window_rightSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_compound(texts_, compounds_, types_, delim_, join, window_left, window_right));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_lookup
List qatd_cpp_tokens_lookup(const List& texts_, const CharacterVector types_, const List& words_, const IntegerVector& keys_, const int overlap, const int nomatch);
RcppExport SEXP _quanteda_qatd_cpp_tokens_lookup(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_SEXP, SEXP keys_SEXP, SEXP overlapSEXP, SEXP nomatchSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type keys_(keys_SEXP);
    Rcpp::traits::input_parameter< const int >::type overlap(overlapSEXP);
    Rcpp::traits::input_parameter< const int >::type nomatch(nomatchSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_lookup(texts_, types_, words_, keys_, overlap, nomatch));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_ngrams
List qatd_cpp_tokens_ngrams(const List& texts_, const CharacterVector types_, const String delim_, const IntegerVector ns_, const IntegerVector skips_);
RcppExport SEXP _quanteda_qatd_cpp_tokens_ngrams(SEXP texts_SEXP, SEXP types_SEXP, SEXP delim_SEXP, SEXP ns_SEXP, SEXP skips_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const String >::type delim_(delim_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type ns_(ns_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type skips_(skips_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_ngrams(texts_, types_, delim_, ns_, skips_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_recompile
List qatd_cpp_tokens_recompile(const List& texts_, const CharacterVector types_, const bool gap, const bool dup);
RcppExport SEXP _quanteda_qatd_cpp_tokens_recompile(SEXP texts_SEXP, SEXP types_SEXP, SEXP gapSEXP, SEXP dupSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const bool >::type gap(gapSEXP);
    Rcpp::traits::input_parameter< const bool >::type dup(dupSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_recompile(texts_, types_, gap, dup));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_replace
List qatd_cpp_tokens_replace(const List& texts_, const CharacterVector types_, const List& patterns_, const List& replacements_);
RcppExport SEXP _quanteda_qatd_cpp_tokens_replace(SEXP texts_SEXP, SEXP types_SEXP, SEXP patterns_SEXP, SEXP replacements_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type patterns_(patterns_SEXP);
    Rcpp::traits::input_parameter< const List& >::type replacements_(replacements_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_replace(texts_, types_, patterns_, replacements_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_restore
List qatd_cpp_tokens_restore(const List& texts_, const List& marks_left_, const List& marks_right_, const CharacterVector& types_, const String& delim_);
RcppExport SEXP _quanteda_qatd_cpp_tokens_restore(SEXP texts_SEXP, SEXP marks_left_SEXP, SEXP marks_right_SEXP, SEXP types_SEXP, SEXP delim_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const List& >::type marks_left_(marks_left_SEXP);
    Rcpp::traits::input_parameter< const List& >::type marks_right_(marks_right_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector& >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const String& >::type delim_(delim_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_restore(texts_, marks_left_, marks_right_, types_, delim_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_segment
List qatd_cpp_tokens_segment(const List& texts_, const CharacterVector types_, const List& patterns_, const bool& remove, const int& position);
RcppExport SEXP _quanteda_qatd_cpp_tokens_segment(SEXP texts_SEXP, SEXP types_SEXP, SEXP patterns_SEXP, SEXP removeSEXP, SEXP positionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type patterns_(patterns_SEXP);
    Rcpp::traits::input_parameter< const bool& >::type remove(removeSEXP);
    Rcpp::traits::input_parameter< const int& >::type position(positionSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_segment(texts_, types_, patterns_, remove, position));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_select
List qatd_cpp_tokens_select(const List& texts_, const CharacterVector types_, const List& words_, int mode, bool padding, int window_left, int window_right, const IntegerVector pos_from_, const IntegerVector pos_to_);
RcppExport SEXP _quanteda_qatd_cpp_tokens_select(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_SEXP, SEXP modeSEXP, SEXP paddingSEXP, SEXP window_leftSEXP, SEXP window_rightSEXP, SEXP pos_from_SEXP, SEXP pos_to_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    Rcpp::traits::input_parameter< int >::type mode(modeSEXP);
    Rcpp::traits::input_parameter< bool >::type padding(paddingSEXP);
    Rcpp::traits::input_parameter< int >::type window_left(window_leftSEXP);
    Rcpp::traits::input_parameter< int >::type window_right(window_rightSEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type pos_from_(pos_from_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type pos_to_(pos_to_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_select(texts_, types_, words_, mode, padding, window_left, window_right, pos_from_, pos_to_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_is_grouped_numeric
bool qatd_cpp_is_grouped_numeric(NumericVector values_, IntegerVector groups_);
RcppExport SEXP _quanteda_qatd_cpp_is_grouped_numeric(SEXP values_SEXP, SEXP groups_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type values_(values_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type groups_(groups_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_is_grouped_numeric(values_, groups_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_is_grouped_character
bool qatd_cpp_is_grouped_character(CharacterVector values_, IntegerVector groups_);
RcppExport SEXP _quanteda_qatd_cpp_is_grouped_character(SEXP values_SEXP, SEXP groups_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type values_(values_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type groups_(groups_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_is_grouped_character(values_, groups_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_set_load_factor
void qatd_cpp_set_load_factor(std::string type, float value);
RcppExport SEXP _quanteda_qatd_cpp_set_load_factor(SEXP typeSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type type(typeSEXP);
    Rcpp::traits::input_parameter< float >::type value(valueSEXP);
    qatd_cpp_set_load_factor(type, value);
    return R_NilValue;
END_RCPP
}
// qatd_cpp_get_load_factor
List qatd_cpp_get_load_factor();
RcppExport SEXP _quanteda_qatd_cpp_get_load_factor() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_get_load_factor());
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_set_meta
void qatd_cpp_set_meta(RObject object_, RObject meta_);
RcppExport SEXP _quanteda_qatd_cpp_set_meta(SEXP object_SEXP, SEXP meta_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type object_(object_SEXP);
    Rcpp::traits::input_parameter< RObject >::type meta_(meta_SEXP);
    qatd_cpp_set_meta(object_, meta_);
    return R_NilValue;
END_RCPP
}
// qatd_cpp_tbb_enabled
bool qatd_cpp_tbb_enabled();
RcppExport SEXP _quanteda_qatd_cpp_tbb_enabled() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tbb_enabled());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_quanteda_qatd_cpp_fcm", (DL_FUNC) &_quanteda_qatd_cpp_fcm, 5},
    {"_quanteda_qatd_cpp_index", (DL_FUNC) &_quanteda_qatd_cpp_index, 3},
    {"_quanteda_qatd_cpp_tokens_chunk", (DL_FUNC) &_quanteda_qatd_cpp_tokens_chunk, 4},
    {"_quanteda_qatd_cpp_tokens_compound", (DL_FUNC) &_quanteda_qatd_cpp_tokens_compound, 7},
    {"_quanteda_qatd_cpp_tokens_lookup", (DL_FUNC) &_quanteda_qatd_cpp_tokens_lookup, 6},
    {"_quanteda_qatd_cpp_tokens_ngrams", (DL_FUNC) &_quanteda_qatd_cpp_tokens_ngrams, 5},
    {"_quanteda_qatd_cpp_tokens_recompile", (DL_FUNC) &_quanteda_qatd_cpp_tokens_recompile, 4},
    {"_quanteda_qatd_cpp_tokens_replace", (DL_FUNC) &_quanteda_qatd_cpp_tokens_replace, 4},
    {"_quanteda_qatd_cpp_tokens_restore", (DL_FUNC) &_quanteda_qatd_cpp_tokens_restore, 5},
    {"_quanteda_qatd_cpp_tokens_segment", (DL_FUNC) &_quanteda_qatd_cpp_tokens_segment, 5},
    {"_quanteda_qatd_cpp_tokens_select", (DL_FUNC) &_quanteda_qatd_cpp_tokens_select, 9},
    {"_quanteda_qatd_cpp_is_grouped_numeric", (DL_FUNC) &_quanteda_qatd_cpp_is_grouped_numeric, 2},
    {"_quanteda_qatd_cpp_is_grouped_character", (DL_FUNC) &_quanteda_qatd_cpp_is_grouped_character, 2},
    {"_quanteda_qatd_cpp_set_load_factor", (DL_FUNC) &_quanteda_qatd_cpp_set_load_factor, 2},
    {"_quanteda_qatd_cpp_get_load_factor", (DL_FUNC) &_quanteda_qatd_cpp_get_load_factor, 0},
    {"_quanteda_qatd_cpp_set_meta", (DL_FUNC) &_quanteda_qatd_cpp_set_meta, 2},
    {"_quanteda_qatd_cpp_tbb_enabled", (DL_FUNC) &_quanteda_qatd_cpp_tbb_enabled, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_quanteda(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
