#include <iostream>
#include <fstream>
#include <vector>

int main()
{
  std::ifstream archivo("matriz_rala_30x30.txt");

  if (!archivo.is_open())
  {
    std::cerr << "Error al abrir el archivo" << std::endl;
    return 1;
  }

  // Leer tamaño de la matriz
  int filas, columnas;
  archivo >> filas >> columnas;

  std::cout << "Matriz: " << filas << " x " << columnas << std::endl;

  // Leer renglón por renglón
  for (int i = 0; i < filas; i++)
  {
    int k; // número de valores distintos de cero
    archivo >> k;

    std::vector<int> indices(k);
    std::vector<double> valores(k);

    // Leer índices (int)
    for (int j = 0; j < k; j++)
    {
      archivo >> indices[j]; // casteo automático a int
    }

    // Leer valores (double / float)
    for (int j = 0; j < k; j++)
    {
      archivo >> valores[j]; // casteo automático a double
    }

    // Ejemplo de uso
    std::cout << "Fila " << i + 1 << ": ";
    for (int j = 0; j < k; j++)
    {
      std::cout << "(col " << indices[j]
                << ", val " << valores[j] << ") ";
    }
    std::cout << std::endl;
  }

  archivo.close();
  return 0;
}
