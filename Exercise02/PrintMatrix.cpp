#include <iostream>
#include <string>
#include "Matrix.h"

// Supone que SparseMatrix tiene:
// int rows() const;
// int cols() const;
// double get(int i, int j) const;   // devuelve 0 si no existe

void MatrixToPGM(const SparseMatrix& M, const std::string& filename)
{
    int rows = M.rows();
    int cols = M.cols();

    // 1. Encontrar min y max para escalar
    double minVal = 0.0, maxVal = 0.0;
    bool first = true;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double v = M.get(i, j);
            if (first) {
                minVal = maxVal = v;
                first = false;
            } else {
                minVal = std::min(minVal, v);
                maxVal = std::max(maxVal, v);
            }
        }
    }

    // Evitar división por cero
    double range = (maxVal - minVal == 0.0) ? 1.0 : (maxVal - minVal);

    // 2. Abrir archivo PGM (ASCII, P2)
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("No se pudo crear el archivo PGM");
    }

    // 3. Cabecera PGM
    out << "P2\n";
    out << cols << " " << rows << "\n";
    out << "255\n";

    // 4. Escribir pixeles escalados [0,255]
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double v = M.get(i, j);
            int pixel = static_cast<int>(
                255.0 * (v - minVal) / range
            );
            out << pixel << " ";
        }
        out << "\n";
    }

    out.close();
}

int main() {
        // Construcción de matrices
        Matrix A("data/A.pgm");
        MatrixToPGM(A, "img/A.pgm");
    return 0;
}
