#include <bits/stdc++.h>
using namespace std;

int main() {
  // // 1963
  // int cycle = 243;
  // vector<int> p = {1952, 2369, 2370, 2560, 2761, 3045};

  // // 1387
  // int cycle = 163;
  // vector<int> p = {431, 491, 1624, 2127, 2459, 2754, 3524, 3555};

  // // 1387
  // int cycle = 244;
  // vector<int> p = {64, 182, 265, 1131, 1665, 2178};

  // // 1529
  // int cycle = 245;
  // vector<int> p = {1132, 2261, 2299, 2863, 2921, 3555};

  // 1963 part 2
  int cycle = 246;
  vector<int> p = { 1898, 2364, 2389, 2562, 2760, 3048 };


  int bestmod = -1;
  int bestsize = 0;
  int bestcost = 1e8;
  for (int s = 1; s <= 5; ++s) {
    int c = cycle + s - 1;

    int bestmods = -1;
    int bestcosts = 1e8;

    for (int mod = 0; mod + (s-1) < cycle; ++mod) {
      int cost = 0;
      set<int> stops;
      for (int i : p) {
        int t = mod + c * (i / c);
        bool found = false;
        while (!found) {
          for (int j = 0; j < s; ++j) {
            if (t + j >= i && !stops.count(t + j)) {
              t += j;
              found = true;
              break;
            }
          }
          if (!found) {
            t += c;
          }
        }
        int d = t - i;
        cost += d;
        stops.insert(t);
      }
      if (cost < bestcosts) {
        bestmods = mod;
        bestcosts = cost;
      }
    }

    printf("size = %d:\n", s);
    printf("best mod  = %d\n", bestmods);
    printf("best cost = %d\n", bestcosts);
    printf("\n");

    if (bestcosts < bestcost) {
      bestmod = bestmods;
      bestcost = bestcosts;
      bestsize = s;
    }
  }

  printf("best mod  = %d\n", bestmod);
  printf("best cost = %d\n", bestcost);
  printf("best size = %d\n", bestsize);
  printf("\n");

  int s = cycle + bestsize - 1;
  set<int> stops;
  for (int i : p) {
    int t = bestmod + s * (i / s);
    bool found = false;
    while (!found) {
      for (int j = 0; j < bestsize; ++j) {
        if (t + j >= i && !stops.count(t + j)) {
          t += j;
          found = true;
          break;
        }
      }
      if (!found) {
        t += s;
      }
    }
    printf("%d -> %d (+%d)\n", i, t, t-i);
    stops.insert(t);
  }

  return 0;
}
