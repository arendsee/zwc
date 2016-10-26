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

#include <string>
#include <stdio.h>
#include <iostream>

#include <Rcpp.h>

#include "wordcounts.h"

//' Count words in fasta file
//'
//' @param k    Integer expressing word size
//' @param file Fasta filename
//' @export
// [[Rcpp::export]]
void fasta_wf(int k, const char* file){
    FILE* fh;

    fh = fopen(file, "r");

    fseek(fh, 0, SEEK_END);
    size_t N = ftell(fh);
    rewind(fh);

    char* buffer = (char*)malloc(N * sizeof(char));
    int nread = fread(buffer, N, sizeof(char), fh);
    if(nread == 0){
       Rprintf("Failed to read file %s", file); 
       // TODO: I need to catch this
    }

    std::string word(k, 'x');

    WordCounts wc;

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
                    wc.add_word(word); // bottleneck
                }
                break;
        }
    }

    wc.print();

    free(buffer);
}
