#include "matrix.h"

using namespace std;

matrix::matrix(const string &path) {
  std::ifstream file(path);
  if (!file.is_open())
  {
    throw std::runtime_error("No se pudo abrir el archivo: " + path);
  }

  // Leer dimensiones
  file >> nRows >> nCols;

  // Reservar arreglos
  colIdx = new std::vector<int>[nRows];
  values = new std::vector<double>[nRows];

  // Leer fila por fila
  for (int i = 0; i < nRows; ++i)
  {
    int k;
    file >> k;

    colIdx[i].resize(k);
    values[i].resize(k);

    // Índices (base 1 → base 0)
    for (int j = 0; j < k; ++j)
    {
      file >> colIdx[i][j];
      colIdx[i][j]--;
    }

    // Valores
    for (int j = 0; j < k; ++j)
    {
      file >> values[i][j];
    }
  }

  file.close();
};

matrix::~matrix()
{
  delete[] colIdx;
  delete[] values;
}

void matrix::MatrixToPGM(const std::string &filename)
{
  int rows = nRows;
  int cols = nCols;

  // 1. Encontrar min y max para escalar
  double minVal = values[0][0];
  double maxVal = values[0][0];

  for (int i = 0; i < rows; ++ i)
  {
    for (int j = 0; j < (int)values[i].size(); ++ j)
    {
      double v = values[i][j];
      minVal = std::min(minVal, v);
      maxVal = std::max(maxVal, v);
    }
  }

  // Evitar división por cero
  double range = (maxVal - minVal == 0.0) ? 1.0 : (maxVal - minVal);

  // 2. Abrir archivo PGM (ASCII, P2)
  std::ofstream out(filename);
  if (!out.is_open())
  {
    throw std::runtime_error("No se pudo crear el archivo PGM");
  }

  // 3. Cabecera PGM
  out << "P2\n";
  out << cols << " " << rows << "\n";
  out << "255\n";

  // 4. Escribir pixeles escalados [0,255]
  for (int i = 0; i < rows; ++ i)
  {
    int count = 0;
    for (int j = 0; j < cols; ++ j)
    {
      double v = 0;
      if (count < (int)colIdx[i].size())
      {
        if(j == colIdx[i][count])
        {
          v = values[i][count];
          count++;
        }
      }
      int pixel = static_cast<int>(255.0 * (v - minVal) / range);
      out << pixel << " ";
    }
    out << "\n";
  }

  out.close();
}