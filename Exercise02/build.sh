#!/bin/bash

set -e

echo "Compiling project..."

g++ -Wall -Wextra -std=c11 main.cpp matrix.cpp -o sort

echo "Build successful. Executable: ./sort"5
