#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> perm;
  for (char a : "ATC") {
    for (char b : "ATC") {
      for (char c : "ATC") {
        if (a == 0 || b == 0 || c == 0) continue;
        string s = "";
        s += a;
        s += b;
        s += c;
        perm.push_back(s);
      }
    }
  }
  int nperm = perm.size();

  int n = nperm * nperm;
  printf("%d %d\n", n * 3, n);
  for (int i = 0; i < nperm; ++i) {
    for (int j = 0; j < nperm; ++j) {
      printf("%s", perm[i].c_str());
    }
  }
  putchar('\n');
  for (int i = 0; i < nperm; ++i) {
    for (int j = 0; j < nperm; ++j) {
      printf("%s", perm[j].c_str());
    }
  }
  putchar('\n');
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", 3*i, 3*i+2);
  }

  return 0;
}