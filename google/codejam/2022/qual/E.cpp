#include <bits/stdc++.h>
using namespace std;

const int seed = 1234;

struct session {
  session(int n, int k): n(n), k(k), deg(vector<int>(n)) {
    read();
  }

  int n, k;
  int currentRoom;
  vector<int> deg;
  vector<pair<int,int>> knownEdges;

  pair<int,int> read() {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    deg[x] = y;
    currentRoom = x;
    return {x, y};
  }

  pair<int,int> teleport(int room) {
    if (k <= 0) {
      return {-1, -1};
    }
    k--;
    printf("T %d\n", room+1);
    fflush(stdout);
    return read();
  }

  pair<int,int> move() {
    if (k <= 0) {
      return { -1, -1 };
    }
    k--;
    int prevRoom = currentRoom;
    printf("W\n");
    fflush(stdout);
    auto p = read();
    knownEdges.emplace_back(prevRoom, p.first);
    return p;
  }

  void guess(long long ans) {
    printf("E %lld\n", ans);
    fflush(stdout);
  }
};




void solve(mt19937 rng) {
  int n, k;
  scanf("%d%d", &n, &k);

  session s(n, k);

  // On k >= n-1, we can get absolutely accurate info.
  if (k >= n-1) {
    for (int i = 0; i < n; ++i) {
      if (!s.deg[i]) {
        s.teleport(i);
      }
    }
    long long totalDeg = 0;
    for (int x : s.deg) {
      totalDeg += x;
    }

    s.guess(totalDeg / 2);
    return;
  }

  // Otherwise, we collect random data.
  vector<int> nodes;
  for (int i = 0; i < n; ++i) {
    if (i != s.currentRoom) {
      nodes.push_back(i);
    }
  }
  shuffle(nodes.begin(), nodes.end(), rng);


  for (int i = 0; i < n; ++i) {
    auto prev = s.teleport(nodes[i]);
    if (prev.first == -1) break;
    auto move1 = s.move();
    if (move1.first == -1) break;
    if (s.deg[prev.first] != 1) {
      if (s.move().first == -1) break;
    }
  }

  int visited = 0;
  for (int i = 0; i < n; ++i) {
    if (s.deg[i]) visited++;
  }

  double mean = 0;
  for (int i = 0; i < n; ++i) {
    if (s.deg[i]) {
      mean += (double)s.deg[i] / (double)visited;
    }
  }

  fprintf(stderr, "n = %d, visited = %d, mean = %.6lf\n", n, visited, mean);

  // We remove nodes with awfully abnormal degrees.
  long long anomalies = 0, threshold = mean * 10;
  int anomaliescount = 0;
  for (int i = 0; i < n; ++i) {
    if (s.deg[i] > threshold) {
      anomaliescount++;
      anomalies += s.deg[i];
      s.deg[i] = 0;
      visited--;
    }
  }

  fprintf(stderr, "anomalies = %d (total = %lld)\n", anomaliescount, anomalies);

  // Now assume that P resembles Poisson dist?

  vector<double> p(n+1), q(n+1);
  mean = 0;
  for (int i = 0; i < n; ++i) {
    if (s.deg[i]) {
      p[s.deg[i]] += 1. / (double)visited;
      mean += (double)s.deg[i] / (double)visited;
    }
  }

  vector<double> pr(n), cpr(n);
  pr[0] = exp(-mean);
  cpr[0] = pr[0];
  for (int i = 1; i < n; ++i) {
    pr[i] = exp(log(mean) * i - mean - lgamma(i+1));
    cpr[i] = cpr[i-1] + pr[i];
    // ans += pr[i] * (double)i * (double)n;
  }

  fprintf(stderr, "n = %d, mean = %.6lf, cpr[max] = %.6lf\n", n, mean, cpr[n-1]);

  // On large mean, pr will be just all zeros.
  // Just assume that it's uniform?
  // if (mean > 10) {
  //   s.guess(mean * n / 2);
  //   return;
  // }

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s.deg[i]) {
      ans += s.deg[i];
    } else {
      double x = (double)rng() / (double)rng.max();
      x *= cpr[n-1];
      int deg = lower_bound(cpr.begin(), cpr.end(), x) - cpr.begin();
      // if (deg == 0) deg = 1;
      ans += deg;
    }
  }

  s.guess((ans + anomalies) / 2);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    mt19937 rng(seed);
    solve(rng);
  }
}