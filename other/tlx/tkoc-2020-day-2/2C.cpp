#include <bits/stdc++.h>
using namespace std;

char buffer[10];

vector<bool> ask(const vector<vector<int>>& q) {
  vector<bool> reply;
  for (int c = 0; c < (q.size() + 9) / 10; c++) {
    int csize = min(10, (int)q.size() - c * 10);
    printf("? %d\n", csize);
    for (int i = c * 10; i < (c + 1) * 10 && i < q.size(); ++i) {
      printf("%d", (int)q[i].size());
      for (int j : q[i]) {
        printf(" %d", j);
      }
      putchar('\n');
    }
    fflush(stdout);
    for (uint i = 0; i < q.size(); ++i) {
      scanf("%s", buffer);
      reply.push_back(strcmp(buffer, "YA") == 0);
    }
  }
  return reply;
}

void answer(vector<int> ans) {
  putchar('!');
  for (int i : ans) {
    printf(" %d", i);
  }
  putchar('\n');
  fflush(stdout);
}

void solve1(int n) {
  int bit = 31 - __builtin_clz(n);
  vector<vector<int>> q;
  for (int i = 0; i < bit; ++i) {
    vector<int> qi;
    for (int j = 1; j <= n; ++j) {
      if ((j - 1) & (1 << i)) {
        qi.push_back(j);
      }
    }
    q.push_back(qi);
  }
  auto reply = ask(q);
  int ans = 0;
  for (int i = 0; i < bit; ++i) {
    if (reply[i]) {
      ans ^= 1 << i;
    }
  }
  answer({ ans + 1 });
}

void solve2known(int n, int one) {
  one--;
  // solve1 with ~one
  vector<vector<int>> q;
  int bit = 31 - __builtin_clz(n);
  for (int i = 0; i < bit; ++i) {
    vector<int> qi;
    for (int j = 1; j <= n; ++j) {
      if ((j - 1) & (1 << i)) {
        if (one & (1 << i)) {
          qi.push_back(((j - 1) ^ (1 << i)) + 1);
        }
        else {
          qi.push_back(j);
        }
      }
    }
    q.push_back(qi);
  }
  auto reply = ask(q);
  int ans = 0;
  for (int i = 0; i < bit; ++i) {
    if (reply[i] && !(one & (1 << i))) {
      ans ^= 1 << i;
    }
    else if (!reply[i] && (one & (1 << i))) {
      ans ^= 1 << i;
    }
  }
  answer({ one + 1, ans + 1 });
}

void solve2(int n) {
  vector<vector<int>> q;
  for (int i = 1; i <= n / 2 + 1; ++i) {
    vector<int> qi;
    for (int j = 0; j < n / 2; ++j) {
      qi.push_back(i + j);
    }
    q.push_back(qi);
  }
  auto reply = ask(q);
  if (*min_element(reply.begin(), reply.end()) == 0) {
    int one = -1;
    for (int i = 0; i < n / 2; i++) {
      if (reply[i] < reply[i + 1]) {
        one = i + n / 2 + 1;
        break;
      }
      if (reply[i] > reply[i + 1]) {
        one = i + 1;
        break;
      }
    }
    assert(one != -1);
    // solve1 with ~one
    solve2known(n, one);
  }
  else {
    // n/2 or n/2+1?
    q.clear();
    {
      vector<int> qi;
      qi.push_back(1);
      for (int i = n / 2 + 2; i <= n; ++i) {
        qi.push_back(i);
      }
      q.push_back(qi);
    }
    {
      vector<int> qi;
      qi.push_back(2);
      for (int i = n / 2 + 2; i <= n; ++i) {
        qi.push_back(i);
      }
      q.push_back(qi);
    }
    {
      vector<int> qi;
      qi.push_back(n);
      for (int i = 1; i < n / 2; ++i) {
        qi.push_back(i);
      }
      q.push_back(qi);
    }
    {
      vector<int> qi;
      qi.push_back(n - 1);
      for (int i = 1; i < n / 2; ++i) {
        qi.push_back(i);
      }
      q.push_back(qi);
    }
    reply = ask(q);
    if (!reply[0] || !reply[1]) {
      solve2known(n, n / 2 + 1);
      return;
    }
    if (!reply[2] || !reply[3]) {
      solve2known(n, n / 2);
      return;
    }

    // solve1 with n = 512 and copy (i, i+512)
    int bit = 30 - __builtin_clz(n);
    q.clear();
    for (int i = 0; i < bit; ++i) {
      vector<int> qi;
      for (int j = 1; j <= n / 2; ++j) {
        if ((j - 1) & (1 << i)) {
          qi.push_back(j);
          qi.push_back(j + n / 2);
        }
      }
      q.push_back(qi);
    }
    auto reply = ask(q);
    int ans = 0;
    for (int i = 0; i < bit; ++i) {
      if (reply[i]) {
        ans ^= 1 << i;
      }
    }
    answer({ ans + 1, ans + n / 2 + 1 });
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == 1) {
    solve1(n);
  }
  else {
    solve2(n);
  }
}