#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;
#define A first
#define B second

#define MAXK 100000
int n, m, k, a[MAXK + 1];
ppii ans[MAXK + 1];

void tc(int i) {
  fprintf(stderr, "tc %d\n", i);
  freopen(("pertahanan_" + to_string(i) + ".in").c_str(), "r", stdin);
  freopen(("pertahanan_" + to_string(i) + ".out").c_str(), "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &a[i]);
    ans[i] = { {-1,-1} ,{-1,-1} };
  }
}

void printAns() {
  for (int i = 1; i <= k; ++i) {
    printf("%d %d %d %d\n", ans[i].A.A, ans[i].A.B, ans[i].B.A, ans[i].B.B);
  }
}

void solve1() {
  ans[1] = { {0, 1}, {0, 4} };
  ans[2] = { {0, 4}, {4, 5} };
  ans[3] = { {4, 5}, {1, 5} };
  ans[4] = { {1, 5}, {0, 1} };
  ans[5] = { {1, 4}, {1, 4} };
}

void solve2() {
  ans[1] = { {1, 3}, {0, 1} };
  ans[2] = { {0, 1}, {0, 3} };
  ans[3] = { {1, 3}, {1, 3} };
  ans[4] = { {0, 5}, {6, 7} };
  ans[5] = { {3, 5}, {0, 3} };
  ans[6] = { {0, 2}, {3, 6} };
  ans[7] = { {5, 6}, {0, 7} };
  ans[8] = { {2, 5}, {3, 6} };
}

void solve3() {
  for (int i = 1; i <= k; ++i) {
    ans[i].A = { 0,1 };
    if (i == 1) {
      ans[i].B = { 0, a[i] };
    }
    else {
      ans[i].B = { ans[i - 1].B.B, ans[i - 1].B.B + a[i] };
    }
  }
}

void solve4() {
  for (int i = 1, j = k - 1, r = 1; i <= j; i++, j--, r++) {
    ans[i].B = { r - 1, r };
    ans[i].A = { 0, i };
    ans[j].B = { r - 1, r };
    ans[j].A = { i, n };
  }
  ans[k].B = { m - 1, m };
  ans[k].A = { 0, n };
}

void solve5() {
  // pertahanan_5.in
  //   N = 9973 \times 293N = 9973×293
  //   M = 99991 \times 311M = 99991×311
  //   K = 293 \times 311K = 293×311
  //   A_i = 9973 \times 99991A
  //   i
  //   ​
  //   = 9973×99991, for 1 \leq i \leq K1≤i≤K
  for (int i = 0; i < 293; ++i) {
    for (int j = 0; j < 311; ++j) {
      int ij = i * 311 + j + 1;
      ans[ij].A = { 9973 * i, 9973 * (i + 1) };
      ans[ij].B = { 99991 * j, 99991 * (j + 1) };
    }
  }
}

void solve6() {
  for (int mask = 0; mask < (1 << k); ++mask) {
    int codd = 0, sum = 0;
    vector<int> bit;
    for (int i = 0; i < k; ++i) {
      if (mask & (1 << i)) {
        bit.push_back(i);
        sum += a[i + 1];
        if (a[i + 1] & 1) {
          codd++;
        }
      }
    }
    if (codd != 10 || sum % 2) continue;
    for (int lmask = 0; lmask < (1 << bit.size()); ++lmask) {
      int lsum = 0;
      for (int l = 0; l < bit.size(); ++l) {
        if (lmask & (1 << l)) {
          lsum += a[bit[l] + 1];
        }
      }
      if (sum / 2 != lsum) continue;

      int lastl = 0, lastr = 0;
      for (int l = 0; l < bit.size(); ++l) {
        int idx = bit[l] + 1;
        if (lmask & (1 << l)) {
          ans[idx].A = { 0, 1 };
          ans[idx].B = { lastl, lastl + a[idx] };
          lastl += a[idx];
        }
        else {
          ans[idx].A = { 1, 2 };
          ans[idx].B = { lastr, lastr + a[idx] };
          lastr += a[idx];
        }
      }
      assert(lastl == lastr);
      for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) continue;
        ans[i + 1].A = { 0, 2 };
        ans[i + 1].B = { lastl, lastl + a[i + 1] / 2 };
        lastl += a[i + 1] / 2;
      }
      return;
    }
  }
}

int dp[20005];
int dpp[20005];

void solve7() {
  dp[0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = m + m; j >= a[i]; --j) {
      if (dp[j - a[i]] && !dp[j]) {
        dp[j] = 1;
        dpp[j] = i;

        if (j == m) {
          fprintf(stderr, "found!\n");
          set<int> lb;
          while (j > 0) {
            i = dpp[j];
            assert(i > 0);
            lb.insert(i);
            j -= a[i];
            fprintf(stderr, "j = %d, i = %d\n", j, i);
          }
          set<int> rb;
          for (int i = 1; i <= k; ++i) {
            if (lb.find(i) == lb.end()) {
              rb.insert(i);
            }
          }
          int lastl = 0, lastr = 0;
          for (int i : lb) {
            ans[i].A = { 0, 1 };
            ans[i].B = { lastl, lastl + a[i] };
            lastl += a[i];
          }
          for (int i : rb) {
            ans[i].A = { 1, 2 };
            ans[i].B = { lastr, lastr + a[i] };
            lastr += a[i];
          }
          return;
        }
      }
    }
  }
}

void solve8() {
  int lastn = 0;
  vector<pair<int, pii>> pn;
  for (int i = 0; i < 30; ++i) {
    if ((1 << i) & n) {
      pn.push_back({ i, {lastn, lastn + (1 << i)} });
      lastn += (1 << i);
    }
  }
  int lastm = 0;
  vector<pair<int, pii>> pm;
  for (int i = 0; i < 30; ++i) {
    if ((1 << i) & m) {
      pm.push_back({ i, {lastm, lastm + (1 << i)} });
      lastm += (1 << i);
    }
  }
  for (int i = 0; i < pn.size(); ++i) {
    for (int j = 0; j < pm.size(); ++j) {
      int idx = pn[i].A + pm[j].A + 1;
      ans[idx].A = pn[i].B;
      ans[idx].B = pm[j].B;
    }
  }
}

void solve9() {
  ans[1] = { {0, 1}, {0, 1} };
  ans[2] = { {0, 1}, {1, 2} };
  int lastn = 1, lastm = 2;
  for (int i = 3; i <= k; ++i) {
    int s = sqrt(a[i]);
    if (s == lastn) {
      ans[i].A = { 0, lastn };
      ans[i].B = { lastm, lastm + s };
      lastm += s;
    }
    else if (s == lastm) {
      ans[i].B = { 0, lastm };
      ans[i].A = { lastn, lastn + s };
      lastn += s;
    }
    else {
      assert(false);
    }
  }
  assert(lastn == n && lastm == m);
}

int rnd(int a, int b) {
  return a + (rand() % (b - a + 1));
}

int cnt[MAXK + 1];
vector<int> ia[MAXK + 1];

void solve10() {
  for (int i = 1; i <= k; ++i) {
    cnt[a[i]]++;
    ia[a[i]].push_back(i);
  }
  int cans = 0;
  // for (int i = 1; i <= 100; ++i) {
  //   fprintf(stderr, "cnt[%3d] = %d\n", i, cnt[i]);
  // }
  for (int r = 1; r <= n; ++r) {
    // fprintf(stderr, "r = %d\n", r);
    // decreasing prob
    vector<int> picks, lim;
    int prob = 1;
    lim.push_back(0);
    for (int i = 1; i <= 100; ++i) {
      if (cnt[i]) {
        for (int p = 0; p < prob; ++p) {
          picks.push_back(i);
        }
        prob++;
      }
      lim[i] = picks.size();
    }
    // fprintf(stderr, "picks.size = %d\n", picks.size());

    vector<int> ansr;
    int rem = m;
    while (rem > 0) {
      // pick largest that fits
      int largest = min(rem, 100);
      while (largest > 0 && !cnt[largest]) largest--;

      if (rem == m) {
        fprintf(stderr, "r = %d, largest = %d\n", r, largest);
      }
      ansr.push_back(largest);
      cnt[largest]--;
      rem -= largest;

      // int tries = 100;
      // while (tries--) {
      //   int rlim = picks.size();
      //   if (rem <= 100) {
      //     rlim = min(rlim, lim[rem]);
      //   }
      //   if (rlim == 0) {
      //     tries = 0;
      //     break;
      //   }
      //   int pick = picks[rand() % rlim];
      //   if (!cnt[pick]) continue;
      //   ansr.push_back(pick);
      //   rem -= pick;
      //   cnt[pick]--;

      //   // fprintf(stderr, "rem = %d\n", rem);
      // }
      // if (tries <= 0) break;
    }

    int lastm = 0;
    for (int t : ansr) {
      assert(!ia[t].empty());
      cans++;
      int idx = ia[t].back(); ia[t].pop_back();
      ans[idx].A = { r - 1, r };
      ans[idx].B = { lastm, lastm + t };
      lastm += t;
    }
  }

  fprintf(stderr, "cans = %d, rem = %d\n", cans, k - cans);
}

int main() {
  // tc(1);
  // solve1();
  // printAns();

  // tc(2);
  // solve2();
  // printAns();

  // tc(3);
  // solve3();
  // printAns();

  // tc(4);
  // solve4();
  // printAns();

  // tc(5);
  // solve5();
  // printAns();

  // tc(6);
  // solve6();
  // printAns();

  // tc(7);
  // solve7();
  // printAns();

  // tc(8);
  // solve8();
  // printAns();

  // tc(9);
  // solve9();
  // printAns();

  tc(10);
  solve10();
  printAns();

}