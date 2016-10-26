// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// wc_from_string
Rcpp::DataFrame wc_from_string(int k, std::string fasta_string);
RcppExport SEXP zwc_wc_from_string(SEXP kSEXP, SEXP fasta_stringSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< std::string >::type fasta_string(fasta_stringSEXP);
    rcpp_result_gen = Rcpp::wrap(wc_from_string(k, fasta_string));
    return rcpp_result_gen;
END_RCPP
}
// wc_from_file
Rcpp::DataFrame wc_from_file(int k, std::string file);
RcppExport SEXP zwc_wc_from_file(SEXP kSEXP, SEXP fileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< std::string >::type file(fileSEXP);
    rcpp_result_gen = Rcpp::wrap(wc_from_file(k, file));
    return rcpp_result_gen;
END_RCPP
}
