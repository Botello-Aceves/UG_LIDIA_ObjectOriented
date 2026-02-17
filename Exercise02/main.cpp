#include <iostream>
#include <string>
#include "matrix.h"

// Supone que SparseMatrix tiene:
// int rows() const;
// int cols() const;
// double get(int i, int j) const;   // devuelve 0 si no existe

int main() {
        // Construcción de matrices
        matrix A("data/matriz_30x30.txt");
        A.MatrixToPGM("img/A.pgm");
}
