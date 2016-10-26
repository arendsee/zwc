#ifndef __WC_H__
#define __WC_H__

#include <string>
#include <stdio.h>
#include <iostream>

#include <Rcpp.h>

#include "wordcounts.h"

//' Count words in fasta character array
//'
//' @param k      Integer expressing word size
//' @param buffer A character array holding all fasta sequence
// [[Rcpp::export]]
Rcpp::DataFrame wc_from_string(int k, const char* fasta_string);

//' Count words in fasta file
//'
//' @param k    Integer expressing word size
//' @param file Fasta filename
// [[Rcpp::export]]
Rcpp::DataFrame wc_from_file(int k, const char* file);

// Count words in fasta file
//
// @param k    Integer expressing word size
// @param file Fasta filename
Rcpp::DataFrame wc(int k, const char* buffer);

const char* slurp_file(const char* file);

#endif
