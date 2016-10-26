#ifndef __WORDCOUNTS_H__
#define __WORDCOUNTS_H__

#include <string>
#include <map>
#include <Rcpp.h>

typedef std::unordered_map<std::string, int> hashmap;

class WordCounts
{
private:
    hashmap map;
    std::vector<std::string> words;
    std::vector<int> counts;

public:

    WordCounts();
    ~WordCounts();

    void print();

    void add_word(std::string);
};


#endif
