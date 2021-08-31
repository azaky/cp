#include <bits/stdc++.h>
using namespace std;

int n;
char s[100][100];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  int best = -1;
  set<vector<int>> p;

  // rows
  for (int r = 0; r < n; ++r) {
    bool possible = true;
    vector<int> cells;
    for (int c = 0; c < n; ++c) {
      if (s[r][c] == 'X') continue;
      if (s[r][c] == 'O') {
        possible = false;
        break;
      }
      cells.push_back(r * n + c);
    }
    if (!possible) continue;
    if (best == -1 || (cells.size() <= best)) {
      if (cells.size() < best) {
        p.clear();
      }
      p.insert(cells);
      best = cells.size();
    }
  }
  // cols
  for (int c = 0; c < n; ++c) {
    bool possible = true;
    vector<int> cells;
    for (int r = 0; r < n; ++r) {
      if (s[r][c] == 'X') continue;
      if (s[r][c] == 'O') {
        possible = false;
        break;
      }
      cells.push_back(r * n + c);
    }
    if (!possible) continue;
    if (best == -1 || (cells.size() <= best)) {
      if (cells.size() < best) {
        p.clear();
      }
      p.insert(cells);
      best = cells.size();
    }
  }

  if (best == -1) {
    puts("Impossible");
  } else {
    printf("%d %lu\n", best, p.size());
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}