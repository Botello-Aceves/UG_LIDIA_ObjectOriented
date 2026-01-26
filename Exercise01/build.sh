#!/bin/bash

set -e

echo "Compiling project..."

gcc -Wall -Wextra -std=c11 main.c -o exec

echo "Build successful. Executable: ./exec"
