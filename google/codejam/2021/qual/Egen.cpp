#include <bits/stdc++.h>
using namespace std;

double randf() {
  return (double)rand() / RAND_MAX;
}

double randf(int a, int b) {
  return a + (b - a) * randf();
}

double s[100100], q[100100];

int main() {
  srand(0);

  int T = 1000, P = 86;
  int C = 33;

  printf("%d\n%d\n", T, P);
  for (int tc = 1; tc <= T; ++tc) {
    for (int i = 1; i <= 100; ++i) {
      s[i] = randf(-3, 3);
    }
    for (int j = 0; j < 10000; ++j) {
      q[j] = randf(-3, 3);
    }
    fprintf(stderr, "s[C] = %.3lf\n", s[C]);
    for (int i = 1; i <= 100; ++i) {
      for (int j = 0; j < 10000; ++j) {
        if (i == C) {
          if (randf() < 0.5) {
            putchar('1');
            continue;
          }
        }
        double f = 1. / (1. + exp(q[j] - s[i]));
        putchar(randf() < f ? '1' : '0');
      }
      putchar('\n');
    }
  }

}