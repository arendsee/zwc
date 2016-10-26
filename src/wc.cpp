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

#include "wc.h"

std::string slurp_file(std::string file){
    FILE* fh;

    fh = fopen(file.c_str(), "r");

    fseek(fh, 0, SEEK_END);
    size_t N = ftell(fh);
    rewind(fh);

    char* buffer = (char*)malloc(N * sizeof(char));
    int nread = fread(buffer, N, sizeof(char), fh);
    if(nread == 0){
       Rprintf("Failed to read file %s", file); 
       // TODO: I need to catch this
    }

    return std::string(buffer);
}

Rcpp::DataFrame wc_from_file(int k, std::string file){
    return wc(k, slurp_file(file));
}

Rcpp::DataFrame wc_from_string(int k, std::string fasta_string){
    return wc(k, fasta_string);
}

Rcpp::DataFrame wc(int k, std::string buffer){

    std::string word(k, 'x');

    WordCounts wc;

    int seqpos = 0;
    bool is_header = false;
    for(size_t i = 0; i < buffer.size(); i++){
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

    return wc.as_data_frame();
}
