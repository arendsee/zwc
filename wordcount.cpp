/* zwc - a filter for counting words in a FASTA file
 * author - Zebulun Arendsee
 *
 * $ wordcount 2 < sample.faa 
 * CA	3
 * AA	3
 * TA	2
 * GA	1
 * TG	1
 * GT	1
 * AT	3
 * CG	1
 * AC	4
 */

#include "boost/unordered_map.hpp"
// #include <unordered_map>

#include <string>
#include <stdio.h>
#include <iostream>

int main(int argc, char ** argv){
    int k = 1;
    FILE* fh;

    if (argc == 3){
        k  = atoi(argv[1]);
        fh = fopen(argv[2], "r");
    } else {
        return 1;
    }

    fseek(fh, 0, SEEK_END);
    size_t N = ftell(fh);
    rewind(fh);

    char* buffer = (char*)malloc(N * sizeof(char));
    fread(buffer, N, sizeof(char), fh);

    // typedef std::unordered_map<std::string, int> hashmap;
    typedef boost::unordered_map<std::string, int> hashmap;
    hashmap counts;

    std::string word(k, 'x');

    int seqpos = 0;
    bool is_header = false;
    for(size_t i = 0; i < N; i++){
        char c = buffer[i];
        switch (c) {
            case '>':
                is_header = true;
                seqpos = 0;
                break;
            case '\n':
                if(is_header){
                    is_header = false;
                }
                break;
            default:
                if(is_header)
                    break;
                seqpos++;
                for(int j = 0; j < (k-1); j++){
                    word[j] = word[j + 1];
                }
                word[k-1] = c;
                if(seqpos >= k){
                    counts[word]++; // bottleneck
                }
                break;
        }
    }

    for(hashmap::iterator it = counts.begin(); it != counts.end(); it++) {
        printf("%s\t%d\n", it->first.c_str(), it->second);
    }

    free(buffer);

    return 0;
}
