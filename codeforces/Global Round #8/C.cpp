#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
int v[2000][2000], n;

void put(int x, int y) {
  if (v[x][y]) {
    printf("(%d, %d) already placed!\n", x, y);
    assert(false);
  }
  a.emplace_back(x, y);
  v[x][y] = 1;
}

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void check() {
  int full = 0;
  for (auto p : a) {
    int neighbor = 0;
    for (int d = 0; d < 4; ++d) {
      int x = p.first + dir[d][0];
      int y = p.second + dir[d][1];
      if (x < 0) continue;
      if (y < 0) continue;
      if (v[x][y]) neighbor++;
    }
    if (neighbor != 2 && neighbor != 4) {
      printf("error at (%d, %d): neighbor = %d\n", p.first, p.second, neighbor);
      assert(false);
    }
    if (neighbor == 4) {
      full++;
    }
  }
  if (full != n) {
    printf("total full != %d\n", n);
    assert(false);
  }
}

void printAnswer() {
  printf("%d\n", a.size());
  for (auto p : a) {
    printf("%d %d\n", p.first, p.second);
  }
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    for (int i = 0; i < n+1; ++i) {
      put(i, 0);
    }
    for (int i = 0; i < n+2; ++i) {
      put(i, 1);
    }
    for (int i = 1; i < n+2; ++i) {
      put(i, 2);
    }
  } else {
    bool odd = false;
    int m = n;
    if (m % 2) {
      odd = true;
      m -= 3;
    }
    m /= 2;
    for (int i = 1; i <= 4; ++i) {
      put(1, i);
      put(3*m+4, i);
    }
    put(2, 1);
    put(2, 4);
    put(3*m+3, 1);
    put(3*m+3, 4);
    for (int i = 0; i < m; ++i) {
      put(3*i+3, 1);
      put(3*i+3, 4);
      put(3*i+4, 0);
      put(3*i+4, 1);
      put(3*i+4, 2);
      put(3*i+4, 4);
      put(3*i+5, 0);
      put(3*i+5, 1);
      put(3*i+5, 2);
      put(3*i+5, 4);
    }
    if (odd) {
      put(0, 3);
      put(0, 4);
      put(1, 5);
      put(2, 3);
      put(2, 5);
    }
  }

  printAnswer();
  check();
}