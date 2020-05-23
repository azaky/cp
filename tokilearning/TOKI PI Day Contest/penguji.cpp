/*
Author: Risan
Some part of the code taken from penguji.cpp, TOKI Open Contest December 2012
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#define MAXROW 100
#define MAXCOL 100
#define MAXK 10000
#define MAXELEMENT 1000

#define MAGICNUMBER 10000000

int nrows, ncols, K;
int M[MAXROW + 5][MAXCOL + 5];

int strToInt(char *s) {
  int ret;
  stringstream ss(s);
  if (!(ss >> ret)) return -1;
  if (ret < 0) return -1;
  return ret;
}

int getRandom(int lbound, int rbound) {
  return rand() % (rbound - lbound + 1) + lbound;
}

void generateInputFile(int seed) {
  srand(seed);
  
  FILE *fin = fopen("tukar.in", "w");

  nrows = getRandom(1, MAXROW);
  ncols = getRandom(1, MAXCOL);
  K = getRandom(1, MAXK);
  
  fprintf(fin, "%d %d %d\n", nrows, ncols, K);
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      if (j > 0) fprintf(fin, " ");
      M[i][j] = getRandom(0, MAXELEMENT);
      fprintf(fin, "%d", M[i][j]);
    }
    fprintf(fin, "\n");
  }
  
  fclose(fin);
}

bool execute(char *sol, int seed) {
  cout << "Menjalankan kasus uji dengan umpan = " << seed << " ..." << endl;
  cout << "banyak baris = " << nrows << endl;
  cout << "banyak kolom = " << ncols << endl;
  cout << "K = " << K << endl;
  if (system((string() + sol + " < tukar.in > tukar.out").c_str())) {
    cout << "Program solusi Anda mengalami kesalahan!" << endl;
    return false;
  } else {
    return true;
  }
}

bool valid(int r, int c) {
  return r >= 1 && r <= nrows && c >= 1 && c <= ncols;
}

bool adjacent(int r1, int c1, int r2, int c2) {
  return ((r1 == r2) && abs(c1 - c2) == 1) || ((c1 == c2) && abs(r1 - r2) == 1);
}

int grade() {
  try {
    ifstream sol;
    sol.open("tukar.out");
    int Y;
    if (!(sol >> Y)) {
      cout << "Keluaran program solusi Anda tidak sesuai format!" << endl;
      return 0;
    }
    if (Y < 0) {
      cout << "Y harus bilangan bulat nonnegatif!" << endl;
      return 0;
    }
    for (int i = 0; i < Y; i++) {
      int r1, c1, r2, c2;
      if (!(sol >> r1 >> c1 >> r2 >> c2)) {
        cout << "Keluaran program solusi Anda tidak sesuai format!" << endl;
        return 0;
      }
      if (!valid(r1, c1) || !valid(r2, c2) || !adjacent(r1, c1, r2, c2)) {
        cout << "Sel yang dideskripsikan tidak valid!" << endl;
        return 0;
      } else {
        swap(M[r1 - 1][c1 - 1], M[r2 - 1][c2 - 1]);
      }
    }
    
    int ret = MAGICNUMBER;
    for (int i = 0; i + 1 < nrows; i++) {
      for (int j = 0; j + 1 < ncols; j++) {
        ret -= abs(M[i + 1][j] - M[i][j]);
        ret -= abs(M[i][j + 1] - M[i][j]);
      }
    }
    sol.close();
    return ret;
  } catch(...) {
    cout << "Keluaran program solusi Anda tidak sesuai format!" << endl;
    return 0;
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Pemakaian: penguji <umpan> <program>" << endl;
  } else {
    int seed;
    if ((seed = strToInt(argv[1])) == -1) {
      cout << "Seed must be a valid nonnegative integer" << endl;
    } else {
      generateInputFile(seed);
      if (execute(argv[2], seed)) {
        cout << "Nilai Anda = " << grade() << endl;
      }
    }
  }
  return 0;
}
