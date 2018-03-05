// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// qatd_cpp_ca
S4 qatd_cpp_ca(const arma::sp_mat& dfm, const double residual_floor);
RcppExport SEXP _quanteda_qatd_cpp_ca(SEXP dfmSEXP, SEXP residual_floorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type dfm(dfmSEXP);
    Rcpp::traits::input_parameter< const double >::type residual_floor(residual_floorSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_ca(dfm, residual_floor));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_collocations
DataFrame qatd_cpp_collocations(const List& texts_, const CharacterVector& types_, const IntegerVector& words_ignore_, const unsigned int count_min, const IntegerVector sizes_, const String& method, const double smoothing);
RcppExport SEXP _quanteda_qatd_cpp_collocations(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_ignore_SEXP, SEXP count_minSEXP, SEXP sizes_SEXP, SEXP methodSEXP, SEXP smoothingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector& >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type words_ignore_(words_ignore_SEXP);
    Rcpp::traits::input_parameter< const unsigned int >::type count_min(count_minSEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type sizes_(sizes_SEXP);
    Rcpp::traits::input_parameter< const String& >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const double >::type smoothing(smoothingSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_collocations(texts_, types_, words_ignore_, count_min, sizes_, method, smoothing));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_manhattan
NumericMatrix qatd_cpp_manhattan(const arma::sp_mat& A, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_manhattan(SEXP ASEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_manhattan(A, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_manhattan2
NumericMatrix qatd_cpp_manhattan2(const arma::sp_mat& A, const arma::sp_mat& B, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_manhattan2(SEXP ASEXP, SEXP BSEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_manhattan2(A, B, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_maximum
NumericMatrix qatd_cpp_maximum(const arma::sp_mat& A, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_maximum(SEXP ASEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_maximum(A, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_maximum2
NumericMatrix qatd_cpp_maximum2(const arma::sp_mat& A, const arma::sp_mat& B, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_maximum2(SEXP ASEXP, SEXP BSEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_maximum2(A, B, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_canberra
NumericMatrix qatd_cpp_canberra(const arma::sp_mat& A, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_canberra(SEXP ASEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_canberra(A, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_canberra2
NumericMatrix qatd_cpp_canberra2(const arma::sp_mat& A, const arma::sp_mat& B, const int margin);
RcppExport SEXP _quanteda_qatd_cpp_canberra2(SEXP ASEXP, SEXP BSEXP, SEXP marginSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_canberra2(A, B, margin));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_minkowski
NumericMatrix qatd_cpp_minkowski(const arma::sp_mat& A, const int margin, const double p);
RcppExport SEXP _quanteda_qatd_cpp_minkowski(SEXP ASEXP, SEXP marginSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    Rcpp::traits::input_parameter< const double >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_minkowski(A, margin, p));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_minkowski2
NumericMatrix qatd_cpp_minkowski2(const arma::sp_mat& A, const arma::sp_mat& B, const int margin, const double p);
RcppExport SEXP _quanteda_qatd_cpp_minkowski2(SEXP ASEXP, SEXP BSEXP, SEXP marginSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type margin(marginSEXP);
    Rcpp::traits::input_parameter< const double >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_minkowski2(A, B, margin, p));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_fcm
S4 qatd_cpp_fcm(const Rcpp::List& texts_, const int n_types, const String& count, const unsigned int window, const NumericVector& weights, const bool ordered, const bool tri, const unsigned int nvec);
RcppExport SEXP _quanteda_qatd_cpp_fcm(SEXP texts_SEXP, SEXP n_typesSEXP, SEXP countSEXP, SEXP windowSEXP, SEXP weightsSEXP, SEXP orderedSEXP, SEXP triSEXP, SEXP nvecSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const int >::type n_types(n_typesSEXP);
    Rcpp::traits::input_parameter< const String& >::type count(countSEXP);
    Rcpp::traits::input_parameter< const unsigned int >::type window(windowSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< const bool >::type ordered(orderedSEXP);
    Rcpp::traits::input_parameter< const bool >::type tri(triSEXP);
    Rcpp::traits::input_parameter< const unsigned int >::type nvec(nvecSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_fcm(texts_, n_types, count, window, weights, ordered, tri, nvec));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_kwic
DataFrame qatd_cpp_kwic(const List& texts_, const CharacterVector types_, const List& words_, const unsigned int& window);
RcppExport SEXP _quanteda_qatd_cpp_kwic(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_SEXP, SEXP windowSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type window(windowSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_kwic(texts_, types_, words_, window));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_compound
List qatd_cpp_tokens_compound(const List& texts_, const List& comps_, const CharacterVector& types_, const String& delim_, const bool& join);
RcppExport SEXP _quanteda_qatd_cpp_tokens_compound(SEXP texts_SEXP, SEXP comps_SEXP, SEXP types_SEXP, SEXP delim_SEXP, SEXP joinSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const List& >::type comps_(comps_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector& >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const String& >::type delim_(delim_SEXP);
    Rcpp::traits::input_parameter< const bool& >::type join(joinSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_compound(texts_, comps_, types_, delim_, join));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_tokens_lookup
List qatd_cpp_tokens_lookup(const List& texts_, const CharacterVector types_, const List& keys_, const IntegerVector& ids_, const bool overlap, const int nomatch);
RcppExport SEXP _quanteda_qatd_cpp_tokens_lookup(SEXP texts_SEXP, SEXP types_SEXP, SEXP keys_SEXP, SEXP ids_SEXP, SEXP overlapSEXP, SEXP nomatchSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const List& >::type keys_(keys_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type ids_(ids_SEXP);
    Rcpp::traits::input_parameter< const bool >::type overlap(overlapSEXP);
    Rcpp::traits::input_parameter< const int >::type nomatch(nomatchSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_lookup(texts_, types_, keys_, ids_, overlap, nomatch));
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
List qatd_cpp_tokens_recompile(const List& texts_, const CharacterVector types_);
RcppExport SEXP _quanteda_qatd_cpp_tokens_recompile(SEXP texts_SEXP, SEXP types_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_recompile(texts_, types_));
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
List qatd_cpp_tokens_select(const List& texts_, const CharacterVector types_, const List& words_, int mode, bool padding, int window_left, int window_right);
RcppExport SEXP _quanteda_qatd_cpp_tokens_select(SEXP texts_SEXP, SEXP types_SEXP, SEXP words_SEXP, SEXP modeSEXP, SEXP paddingSEXP, SEXP window_leftSEXP, SEXP window_rightSEXP) {
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
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_tokens_select(texts_, types_, words_, mode, padding, window_left, window_right));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_chars_remove
List qatd_cpp_chars_remove(List input_, String char_remove);
RcppExport SEXP _quanteda_qatd_cpp_chars_remove(SEXP input_SEXP, SEXP char_removeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type input_(input_SEXP);
    Rcpp::traits::input_parameter< String >::type char_remove(char_removeSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_chars_remove(input_, char_remove));
    return rcpp_result_gen;
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
// qatd_cpp_is_overlap
bool qatd_cpp_is_overlap(SEXP x1_, SEXP y1_, SEXP w1_, SEXP h1_, SEXP boxe_);
RcppExport SEXP _quanteda_qatd_cpp_is_overlap(SEXP x1_SEXP, SEXP y1_SEXP, SEXP w1_SEXP, SEXP h1_SEXP, SEXP boxe_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x1_(x1_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type y1_(y1_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type w1_(w1_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type h1_(h1_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type boxe_(boxe_SEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_is_overlap(x1_, y1_, w1_, h1_, boxe_));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_wordfish_dense
Rcpp::List qatd_cpp_wordfish_dense(SEXP wfm, SEXP dir, SEXP priors, SEXP tol, SEXP disp, SEXP dispfloor, bool abs_err);
RcppExport SEXP _quanteda_qatd_cpp_wordfish_dense(SEXP wfmSEXP, SEXP dirSEXP, SEXP priorsSEXP, SEXP tolSEXP, SEXP dispSEXP, SEXP dispfloorSEXP, SEXP abs_errSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type wfm(wfmSEXP);
    Rcpp::traits::input_parameter< SEXP >::type dir(dirSEXP);
    Rcpp::traits::input_parameter< SEXP >::type priors(priorsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< SEXP >::type disp(dispSEXP);
    Rcpp::traits::input_parameter< SEXP >::type dispfloor(dispfloorSEXP);
    Rcpp::traits::input_parameter< bool >::type abs_err(abs_errSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_wordfish_dense(wfm, dir, priors, tol, disp, dispfloor, abs_err));
    return rcpp_result_gen;
END_RCPP
}
// qatd_cpp_wordfish
Rcpp::List qatd_cpp_wordfish(arma::sp_mat& wfm, IntegerVector& dirvec, NumericVector& priorvec, NumericVector& tolvec, IntegerVector& disptype, NumericVector& dispmin, bool ABS, bool svd_sparse, double residual_floor);
RcppExport SEXP _quanteda_qatd_cpp_wordfish(SEXP wfmSEXP, SEXP dirvecSEXP, SEXP priorvecSEXP, SEXP tolvecSEXP, SEXP disptypeSEXP, SEXP dispminSEXP, SEXP ABSSEXP, SEXP svd_sparseSEXP, SEXP residual_floorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat& >::type wfm(wfmSEXP);
    Rcpp::traits::input_parameter< IntegerVector& >::type dirvec(dirvecSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type priorvec(priorvecSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type tolvec(tolvecSEXP);
    Rcpp::traits::input_parameter< IntegerVector& >::type disptype(disptypeSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type dispmin(dispminSEXP);
    Rcpp::traits::input_parameter< bool >::type ABS(ABSSEXP);
    Rcpp::traits::input_parameter< bool >::type svd_sparse(svd_sparseSEXP);
    Rcpp::traits::input_parameter< double >::type residual_floor(residual_floorSEXP);
    rcpp_result_gen = Rcpp::wrap(qatd_cpp_wordfish(wfm, dirvec, priorvec, tolvec, disptype, dispmin, ABS, svd_sparse, residual_floor));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_quanteda_qatd_cpp_ca", (DL_FUNC) &_quanteda_qatd_cpp_ca, 2},
    {"_quanteda_qatd_cpp_collocations", (DL_FUNC) &_quanteda_qatd_cpp_collocations, 7},
    {"_quanteda_qatd_cpp_manhattan", (DL_FUNC) &_quanteda_qatd_cpp_manhattan, 2},
    {"_quanteda_qatd_cpp_manhattan2", (DL_FUNC) &_quanteda_qatd_cpp_manhattan2, 3},
    {"_quanteda_qatd_cpp_maximum", (DL_FUNC) &_quanteda_qatd_cpp_maximum, 2},
    {"_quanteda_qatd_cpp_maximum2", (DL_FUNC) &_quanteda_qatd_cpp_maximum2, 3},
    {"_quanteda_qatd_cpp_canberra", (DL_FUNC) &_quanteda_qatd_cpp_canberra, 2},
    {"_quanteda_qatd_cpp_canberra2", (DL_FUNC) &_quanteda_qatd_cpp_canberra2, 3},
    {"_quanteda_qatd_cpp_minkowski", (DL_FUNC) &_quanteda_qatd_cpp_minkowski, 3},
    {"_quanteda_qatd_cpp_minkowski2", (DL_FUNC) &_quanteda_qatd_cpp_minkowski2, 4},
    {"_quanteda_qatd_cpp_fcm", (DL_FUNC) &_quanteda_qatd_cpp_fcm, 8},
    {"_quanteda_qatd_cpp_kwic", (DL_FUNC) &_quanteda_qatd_cpp_kwic, 4},
    {"_quanteda_qatd_cpp_tokens_compound", (DL_FUNC) &_quanteda_qatd_cpp_tokens_compound, 5},
    {"_quanteda_qatd_cpp_tokens_lookup", (DL_FUNC) &_quanteda_qatd_cpp_tokens_lookup, 6},
    {"_quanteda_qatd_cpp_tokens_ngrams", (DL_FUNC) &_quanteda_qatd_cpp_tokens_ngrams, 5},
    {"_quanteda_qatd_cpp_tokens_recompile", (DL_FUNC) &_quanteda_qatd_cpp_tokens_recompile, 2},
    {"_quanteda_qatd_cpp_tokens_segment", (DL_FUNC) &_quanteda_qatd_cpp_tokens_segment, 5},
    {"_quanteda_qatd_cpp_tokens_select", (DL_FUNC) &_quanteda_qatd_cpp_tokens_select, 7},
    {"_quanteda_qatd_cpp_chars_remove", (DL_FUNC) &_quanteda_qatd_cpp_chars_remove, 2},
    {"_quanteda_qatd_cpp_tbb_enabled", (DL_FUNC) &_quanteda_qatd_cpp_tbb_enabled, 0},
    {"_quanteda_qatd_cpp_is_overlap", (DL_FUNC) &_quanteda_qatd_cpp_is_overlap, 5},
    {"_quanteda_qatd_cpp_wordfish_dense", (DL_FUNC) &_quanteda_qatd_cpp_wordfish_dense, 7},
    {"_quanteda_qatd_cpp_wordfish", (DL_FUNC) &_quanteda_qatd_cpp_wordfish, 9},
    {NULL, NULL, 0}
};

RcppExport void R_init_quanteda(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
