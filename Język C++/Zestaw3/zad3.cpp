#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
  int m, n, p, i, j, k, s;

  ifstream file("zad3dane.txt"); //wczytanie danych z pliku
  if (!file)
  {
    cerr << "File ERROR!\n";
    exit(1);
  }

  ofstream file1("zad3odp.txt"); //wpisanie danych do pliku
  if (!file)
  {
    cerr << "File ERROR!\n";
    exit(1);
  }

  file >> m >> n >> p; // odczytuje z pliku wymiary macierzy

  int A[n][m];
  int B[m][n];
  int C[m][p];

  // wpisanie danych dla macierzy A

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      file >> A[i][j];

  // wpisanie danych dla macierzy B

  for (i = 0; i < n; i++)
    for (j = 0; j < p; j++)
      file >> B[i][j];

  file.close();
  // mnożenie macierzy A przez B i wpisanie wyniku do C

  for (i = 0; i < m; i++)
    for (j = 0; j < p; j++)
    {
      s = 0;
      for (k = 0; k < n; k++)
        s += A[i][k] * B[k][j];
      C[i][j] = s;
    }

  file1 << "C = A x B:" << endl;

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < p; j++)
      file1 << setw(6) << C[i][j];
    file1 << endl;
  }
}