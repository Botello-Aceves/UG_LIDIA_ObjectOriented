#!/bin/bash

set -e

echo "Compiling project..."

gcc -Wall -Wextra -std=c11 main.c insert_sort.c -o sort

echo "Build successful. Executable: ./sort"
