#include <bits/stdc++.h>
using namespace std;

vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

int n, m, a[101][3];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    a[u][t] = v;
  }
  char s[101];
  scanf("%s", s);
  string p;
  for (int i = 0; i < strlen(s); ++i) {
    p += morse[s[i] - 'A'];
  }
  int v = 1;
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == '.') v = a[v][1]; else v = a[v][2];
    if (!v) {
      v = -1;
      break;
    }
  }
  printf("%d\n", v);
}