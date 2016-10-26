#include "wordcounts.h"

void WordCounts::print(){
    for(hashmap::iterator it = map.begin(); it != map.end(); it++) {
        Rprintf("%s\t%d\n", it->first.c_str(), it->second);
    }
}

Rcpp::DataFrame WordCounts::as_data_frame(){
    Rcpp::CharacterVector words(map.size());
    Rcpp::IntegerVector counts(map.size());
    size_t i = 0;
    for(hashmap::iterator it = map.begin(); it != map.end(); it++) {
        words[i]  = it->first.c_str();
        counts[i] = it->second;
        i++;
    }

    return Rcpp::DataFrame::create(
        Rcpp::Named("word") = words,
        Rcpp::Named("count") = counts
    );
}

void WordCounts::add_word(std::string word){
    map[word]++;
}

WordCounts::WordCounts(){ }

WordCounts::~WordCounts(){ }
