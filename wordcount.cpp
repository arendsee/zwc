#include <stdio.h>
#include <boost/unordered_map.hpp>
#include <stdlib.h>
#include <string>

int main(int argc, char ** argv){
    size_t k = 1;
    switch (argc) {
        case 1:
            return 1;
        case 2:
            break;
        case 3:
            k = atoi(argv[2]);
            break;
    }

    FILE * fr = fopen(argv[1], "rb");
    size_t buffer_size = 1024;
    char buffer[buffer_size];

    std::string word;
    for(int i = 0; i < k; i++){
        word += "x";
    }
    typedef boost::unordered_map <std::string, int> hashmap;
    hashmap counts;
    int seqpos = 0;
    bool is_header = false;
    while(!feof(fr)){
        fread(buffer, 1, buffer_size, fr); 
        for(int i = 0; i < buffer_size; i++){
            if(buffer[i] == 0)
                break;
            switch (buffer[i]) {
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
                    word[k-1] = buffer[i];
                    if(seqpos >= k){
                        counts[word]++;
                    }
                    break;
            }
        }
    }

    for(hashmap::iterator it = counts.begin(); it != counts.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    fclose(fr);

    return 0;
}
