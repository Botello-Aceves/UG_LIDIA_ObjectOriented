#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

class matrix{
  public:
    matrix(const std::string &path);
    ~matrix();

    // Getters
    inline int getNrows()
    {
      return nRows;
    }

    inline int getNCols()
    {
      return nCols;
    }

    // Functionality
    void   add(matrix);
    void   subtract(matrix);
    matrix multiply(const double);
    matrix multiply(const matrix);
    matrix multiply(const std::vector<double>);
    matrix decompose();
    matrix solve(const matrix);
    double determinant();
    matrix eigenvectors();
    double eigenvalue(const matrix);

    matrix(const matrix &) = delete;
    matrix& operator=(const matrix &) = delete;

    matrix operator+(const matrix);
    matrix operator-(const matrix);
    matrix operator*(const double);
    matrix operator*(const matrix);
    matrix operator*(const std::vector<double>);

    void save2File(const std::string &);
    void MatrixToPGM(const std::string &);

  private :
    int nRows; //< Num Rows
    int nCols; //< Num Cols 
    std::vector<int> *colIdx;    //< arreglo de índices de columna
    std::vector<double> *values; //< arreglo de valores
};

#endif