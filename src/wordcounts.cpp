#include "wordcounts.h"

void WordCounts::print(){
    for(hashmap::iterator it = map.begin(); it != map.end(); it++) {
        Rprintf("%s\t%d\n", it->first.c_str(), it->second);
    }
}

void WordCounts::add_word(std::string word){
    map[word]++;
}

WordCounts::WordCounts(){ }

WordCounts::~WordCounts(){ }
