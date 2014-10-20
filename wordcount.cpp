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


#include <stdio.h>
#include <boost/unordered_map.hpp>
#include <string>
#include <string.h>
using std::string;
using boost::unordered_map;

string VERSION = "0.1.0";

int main(int argc, char ** argv){
    size_t k = 1;
    if (argc == 2){
        if(argv[1][0] == '-'){
            printf("zwc %s (faster EMBOSS wordcount)\n", VERSION.c_str()); 
            printf("USAGE - zwordcount [word length] < d.fasta\n"); 
            printf("INPUT - A properly formatted FASTA file\n"); 
            return 0;
        }
        k = atoi(argv[1]);
    }
    string word = string(k, 'x');

    typedef unordered_map <string, int> hashmap;
    hashmap counts;

    int seqpos = 0;
    bool is_header = false;
    char c;
    while((c = fgetc(stdin)) != EOF){
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
                    counts[word]++;
                }
                break;
        }
    }

    for(hashmap::iterator it = counts.begin(); it != counts.end(); it++) {
        printf("%s\t%d\n", it->first.c_str(), it->second);
    }

    return 0;
}
