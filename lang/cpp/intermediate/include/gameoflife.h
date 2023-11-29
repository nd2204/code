#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <stdio.h>
#include <unistd.h>

void generate_map(unsigned int, char*, size_t, size_t);
void execute(unsigned int);

#endif
