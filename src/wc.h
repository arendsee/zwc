#ifndef __WC_H__
#define __WC_H__

#include <string>
#include <stdio.h>
#include <iostream>

#include <Rcpp.h>
// [[Rcpp::plugins(cpp11)]]

#include "wordcounts.h"

//' Count words in fasta character array
//'
//' @param k      Integer expressing word size
//' @param buffer A character array holding all fasta sequence
// [[Rcpp::export]]
Rcpp::DataFrame wc_from_string(int k, std::string fasta_string);

//' Count words in fasta file
//'
//' @param k    Integer expressing word size
//' @param file Fasta filename
// [[Rcpp::export]]
Rcpp::DataFrame wc_from_file(int k, std::string file);

// Count words in fasta file
//
// @param k    Integer expressing word size
// @param file Fasta filename
Rcpp::DataFrame wc(int k, std::string buffer);

std::string slurp_file(std::string file);

#endif
