#include "wordcounts.h"

void WordCounts::print(){
    for(hashmap::iterator it = counts.begin(); it != counts.end(); it++) {
        Rprintf("%s\t%d\n", it->first.c_str(), it->second);
    }
}

void WordCount::add_word(std::string word){
    map[word]++;
}

WordCount::WordCounts(){ }

WordCount::~WordCounts(){ }
