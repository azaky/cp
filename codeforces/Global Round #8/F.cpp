#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n, x[MAXN+10];

int lamps() {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i]) s++;
  }
  // printf("lamps = %d\n", s);
  return s;
}

void movee(const vector<int> &t) {
  printf("%d", t.size());
  for (int a : t) {
    x[a] = 1;
    printf(" %d", a+1);
  }
  puts("");
  // for (int i = 0; i < n; ++i) {
  //   putchar(x[i] ? 'o' : '.');
  // }
  // putchar('\n');
  fflush(stdout);

  int r;
  scanf("%d", &r);
  r--;
  // printf("r = %d\n", r);
  for (int i = 0; i < t.size(); ++i) {
    x[(r+i)%n] = 0;
  }
  // for (int i = 0; i < n; ++i) {
  //   putchar(x[i] ? 'o' : '.');
  // }
  // putchar('\n');
}

int main() {
  scanf("%d", &n);
  if (n < 4) {
    puts("0");
    return 0;
  }

  int b = 1;
  while (b * b <= n) b++;
  b--;
  int r = n - (n + b - 1) / b - (b - 1);

  while (lamps() < r) {
    vector<int> t;
    int c = b;
    
    for (int i = 0; i < n && c > 0; ++i) {
      if (i % b != (b-1) && !x[i]) {
        t.push_back(i);
        c--;
      }
    }
    movee(t);
  }

  puts("0");

  return 0;
}