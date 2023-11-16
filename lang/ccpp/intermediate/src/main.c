// main.c

#include "helper.h"
#include "baitap.h"
#include <stdio.h>
#include "gameoflife.h"

int main() {
    /* Intializes random number generator */
    time_t t;
    unsigned int seed = (unsigned) time(&t);
    printf("%d\n", seed);
    /* generate_map(seed, "mapgen.txt"); */
    execute(seed);
}
