#include "immolate.h"
#include <stdio.h>

extern llong filter(instance* inst);

void search(char8 starting_seed, ulong num_seeds, llong* filter_cutoff) {
    seed _seed = s_new_c8(starting_seed);
    // s_skip(&_seed, get_global_id(0));
    for (ulong i = 0; i < num_seeds; i++) {
        instance inst = i_new(_seed);
        llong score = filter(&inst);
        if (score >= filter_cutoff[0]) {
            text s_str = s_to_string(&_seed);
            printf("%s (%lli)\n", s_str.str, score);
            if (score > filter_cutoff[0]) {
                #ifndef FIXED_FILTER_CUTOFF
                    filter_cutoff[0] = score;
                #endif
            }
        }
        s_skip(&_seed,1);
    }
}

int main(int argc, char **argv) {
    // Print version
    printf_s("Immolate Beta v1.0.1f.1\n");
    char8 startingSeed;
    for (int i = 0; i < 8; i++) {
        startingSeed.data[i] = '\0';
    };
    #ifdef IMMOLATE_STARTING_SEED
        #define Q(x) #x
        #define QUOTE(x) Q(x)
        for (int i=0; i < sizeof(QUOTE(IMMOLATE_STARTING_SEED)) && i < 8; i++) {
            startingSeed.data[i] = QUOTE(IMMOLATE_STARTING_SEED)[i];
        }
        #undef QUOTE
        #undef Q
    #endif
    ulong numSeeds = 2318107019761ULL;
    llong filter_cutoff = 1;
    search(startingSeed, numSeeds, &filter_cutoff);
    return 0;
}