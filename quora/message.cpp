#include <bits/stdc++.h>
using namespace std;

vector<int> scanline() {
  string str;

  getline(cin, str);

  vector<int> a;
  istringstream ss(str);
  int num;
  while (ss >> num)
  {
    a.push_back(num);
  }
  return a;
}

#define MAXW 1000
#define MAXN 5005

int n;
vector<int> s[MAXN];
int bi[MAXW+1][MAXW+1], ans[MAXN];

int main() {
  n = scanline()[0];
  for (int i = 0; i < n; ++i) {
    s[i] = scanline();
    // for (int j = 0; j < s[i].size(); ++j) {
    //   printf("%d ", s[i][j]);
    // }
    // puts("");
    for (int j = 0; j+1 < s[i].size(); ++j) {
      if (s[i][j] != -1 && s[i][j+1] != -1) {
        bi[s[i][j]][s[i][j+1]]++;
      }
    }
  }

  // for (int i = 1; i <= MAXW; ++i) {
  //   for (int j = 1; j <= MAXW; ++j) {
  //     if (bi[i][j]) printf("bi[%d][%d] = %d\n", i, j, bi[i][j]);
  //   }
  // }

  for (int i = 0; i < n; ++i) {
    int x = 0, len = s[i].size();
    for (int j = 0; j < len; ++j) {
      if (s[i][j] == -1) {
        x = j;
        break;
      }
    }
    // printf("x = %d\n", x);
    ans[i] = 1;
    if (x == 0) {
      for (int j = 1; j <= MAXW; ++j)
      {
        if (bi[j][s[i][1]] > bi[ans[i]][s[i][1]])
        {
          ans[i] = j;
        }
      }
    }
    else if (x == len-1) {
      for (int j = 1; j <= MAXW; ++j)
      {
        if (bi[s[i][len - 2]][j] > bi[s[i][len-2]][ans[i]])
        {
          ans[i] = j;
        }
      }
    }
    else {
      // score?
      // (1 + left) * (1 + right) ?
      int bestscore = 0;
      for (int j = 1; j <= MAXW; ++j) {
        int score = (1 + bi[s[i][x-1]][j]) * (1 + bi[j][s[i][x+1]]);
        if (score > bestscore) {
          bestscore = score;
          ans[i] = j;
        }
      }
      // printf("bestscore = %d\n", bestscore);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
}
