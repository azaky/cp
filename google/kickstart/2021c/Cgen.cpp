#include <bits/stdc++.h>
using namespace std;

int r(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main() {
  srand(time(0));
  puts("200");
  puts("16400");

  vector<int> g;
  for (int i = 0; i < 50; ++i) {
    g.push_back(r(5, 95 - 49));
  }
  sort(g.begin(), g.end());
  for (int i = 0; i < 50; ++i) {
    g[i] += i;
  }

  for (int i = 0; i < 50; ++i) {
    int w = 10 * g[i];
    printf("%d %d\n", w, w);
    printf("%d %d\n", w, w/2);
    printf("%d %d\n", w, w/10);
    printf("%d %d\n", w, 0);
  }
}