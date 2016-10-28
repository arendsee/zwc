#ifndef __WORDCOUNTS_H__
#define __WORDCOUNTS_H__

#include <string>
#include <unordered_map>

#include <Rcpp.h>

typedef std::unordered_map<std::string, int> hashmap;

class WordCounts
{
private:
    hashmap map;

public:

    WordCounts();
    ~WordCounts();

    void print();

    Rcpp::DataFrame as_data_frame();

    void add_word(std::string);
};


#endif
