#!/bin/bash

SRC=$(find -type f -name '*.c' -or -type f -name '*.cpp')

g++ -g -o main utils/dn_memory.c $1
