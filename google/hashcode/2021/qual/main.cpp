#include <bits/stdc++.h>
using namespace std;

// #define A first
// #define B second
#define sqr(a) ((a) * (a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
// #define debugl(...) fprintf(stderr, __VA_ARGS__)
// #define debugl(...) fprintf(flog, __VA_ARGS__)
#define debugl(...)

FILE* flog = fopen("log", "w");

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> getints(const string& s) {
  stringstream ss(s);
  vector<int> res;
  while (ss.good()) {
    int x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}
vector<int> getints() {
  string buffer;
  getline(cin, buffer);
  return getints(buffer);
}
vector<string> getstrs(const string& s) {
  stringstream ss(s);
  vector<string> res;
  while (ss.good()) {
    string x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}
vector<string> getstrs() {
  string buffer;
  getline(cin, buffer);
  return getstrs(buffer);
}

int rnd() {
  return rand();
}
int rnd(int n) {
  return rand() % n;
}
int rnd(int a, int b) {
  return a + rnd(b - a);
}
ll rndll() {
  return (ll)rnd() * INT32_MAX + rnd();
}
ll rndll(ll n) {
  return rndll() % n;
}
ll rndll(ll a, ll b) {
  return a + rndll(b - a);
}
template <typename T> T rnd(vector<T>& a) {
  return a[rnd(a.size())];
}
template <typename T> T rndpop(vector<T>& a) {
  int i = rnd(a.size());
  T pop = a[i];
  a[i] = a.back();
  a.pop_back();
  return pop;
}
vector<int> rndrange(int n, int k) {
  vector<int> a;
  for (int i = 0; i < k; ++i) {
    a.push_back(rnd(n - k + 1));
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < k; ++i) {
    a[i] += i;
  }
  return a;
}
double rndf() {
  return (double)rand() / (double)RAND_MAX;
}
double rndf(double a) {
  return rndf() / a;
}
double rndf(double a, double b) {
  return a + rndf(b - a);
}

//////////////////////////////////////
// end of azaky's hashcode template //
//////////////////////////////////////

#define MAXN 100100

int D, I, S, V, F;

map<string,int> streetIds;
vector<string> streetNames;

struct Street {
  int B, E, L;
  string name;
  int id;
  void read() {
    static char buffer[101];
    scanf("%d%d%s%d", &B, &E, buffer, &L);
    name = buffer;
    id = streetIds.size();
    streetIds[name] = id;
    streetNames[id] = name;
  }
};

struct Car {
  vector<int> path;
  void read() {
    int n;
    scanf("%d", &n);
    path.resize(n);
    for (int i = 0; i < n; ++i) {
      static char buffer[101];
      scanf("%s", buffer);
      path[i] = streetIds[buffer];
    }
  }
};

vector<pair<int,int>> adj[MAXN];
vector<pair<int,int>> adji[MAXN];

vector<Street> streets;
vector<Car> cars;

vector<int> maxVolumes;

int calcScore(vector<vector<pair<int, int>>> ans) {
  // sum of seconds on each intersections
  vector<int> TI;
  // prefix sum of ans[].second
  vector<vector<int>> TS;
  // map of indices of street id in that intersection
  vector<int> SID;

  TI.resize(I);
  TS.resize(I);
  SID.resize(S, -1);

  for (int i = 0; i < I; ++i) {
    TS[i].push_back(0);
    for (int j = 0; j < ans[i].size(); ++j) {
      int id = ans[i][j].first;
      int t = ans[i][j].second;
      TI[i] += t;
      TS[i].push_back(TS[i].back() + t);
      SID[id] = j;
    }
  }

  // find the next time it turns green for STREET id
  auto nextGreen = [&](int id, int t) -> int {
    try {
      int iid = streets[id].E;
      if (TI[iid] == 0) {
        return D+1;
      }
      int i = SID[id];
      if (i == -1) {
        return D+1;
      }
      int base = TI[iid] * (t / TI[iid]);
      t %= TI[iid];
      if (t < TS[iid][i]) {
        return base + TS[iid][i];
      }
      if (t < TS[iid][i+1]) {
        return base + t;
      }
      return base + TS[iid][i] + TI[iid];
    } catch (exception e) {
      debug("Exception: %s\n", e.what());
      return D+1;
    }
  };

  // queue for each intersections
  vector<queue<int>> q;
  q.resize(S);

  // events is "releasing a car from an intersection queue"
  // events[T] = queue<street id to process>
  vector<queue<int>> events;
  events.resize(D+1);

  // qevents is "a car entering an intersection queue"
  // qevents[T] = queue<street id, car id>
  vector<queue<pair<int,int>>> qevents;
  qevents.resize(D+1);

  // events are triggered by:
  // - a car entering a queue

  // at T = 0, initialize all cars at the end of the streets
  vector<int> p; // index of car path
  p.resize(V);
  for (int i = 0; i < V; ++i) {
    int streetId = cars[i].path[p[i]];
    qevents[0].emplace(streetId, i);
  }

  vector<int> arrival;
  arrival.resize(V, -1);

  for (int t = 0; t <= D; ++t) {
    debugl("T = %d\n", t);
    debugl("qevents.size() = %d\n", (int)qevents[t].size());

    // insert cars into queue
    while (!qevents[t].empty()) {
      auto front = qevents[t].front();
      qevents[t].pop();

      int streetId = front.first;
      int carId = front.second;
      if (q[streetId].empty()) {
        events[t].push(streetId);
      }
      q[streetId].push(carId);

      debugl("\t<streetId = %s, carId = %d>\n", streetNames[streetId].c_str(), carId);
    }

    debugl("events.size() = %d\n", (int)events[t].size());

    while (!events[t].empty()) {
      int id = events[t].front();
      events[t].pop();

      debugl("\t<streetId = %s>\n", streetNames[id].c_str());

      queue<int> &qs = q[id];
      assert(!qs.empty());

      maxVolumes[id] = max(maxVolumes[id], (int)qs.size());

      // check if traffic light is green.
      // if green, then process immediately.
      // if not, then defer until next green.
      int _t = nextGreen(id, t);
      debugl("\tnext green = %d\n", _t);
      if (t != _t) {
        if (_t <= D) {
          events[_t].push(id);
        }
      } else {
        // take single car in the queue
        int c = qs.front(); qs.pop();
        p[c]++;
        assert(p[c] < cars[c].path.size());
        int snext = cars[c].path[p[c]];
        int inext = streets[snext].E;
        int tnext = t + streets[snext].L;

        debugl("\tprocessing <car = %d>: snext = %s, inext = %d, tnext = %d\n", c, streetNames[snext].c_str(), inext, tnext);

        if (tnext <= D) {
          // arrive!
          if (p[c] == cars[c].path.size()-1) {
            arrival[c] = tnext;
          } else {
            qevents[tnext].emplace(snext, c);
          }
        }

        // reinsert self into events if queue is still not empty
        if (!qs.empty() && t < D) {
          events[t+1].push(id);
        }

        debugl("\tdone processing <car = %d>\n", c);
      }
    }
  }

  debugl("arrival:\n");
  int score = 0;
  for (int c = 0; c < V; ++c) {
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
  }

  return score;
}

int main(int argc, char** argv) {
  srand(0);

  scanf("%d%d%d%d%d", &D, &I, &S, &V, &F);

  streets.resize(S);
  streetNames.resize(S);
  for (int i = 0; i < S; ++i) {
    streets[i].read();
    adj[streets[i].B].emplace_back(streets[i].E, streets[i].id);
    adji[streets[i].E].emplace_back(streets[i].B, streets[i].id);
  }

  cars.resize(V);
  for (int i = 0; i < V; ++i) {
    cars[i].read();
  }

  vector<int> SS;
  SS.resize(S);

  for (int i = 0; i < V; ++i) {
    int totallen = 0;
    for (int s : cars[i].path) {
      totallen += streets[s].L;
    }

    if (cars[i].path.size() <= 4 && totallen <= D) {
      for (int j = 0; j < cars[i].path.size()-1 && j < 2; ++j) {
        int s = cars[i].path[j];
        int score = D - totallen;
        score /= (j + 1);
        SS[s] += score;
      }
    }
  }

  debug("here\n");

  for (int v = 0; v < I; ++v) {
    stable_sort(adji[v].begin(), adji[v].end(), [&](const pii &a, const pii &b) -> bool {
      return SS[a.second] > SS[b.second];
    });
  }

  debug("done sorting\n");

  int bestScore = 0;
  vector<vector<pair<int,int>>> ans, bestAns;
  for (int v = 0; v < I; ++v) {
    vector<pair<int,int>> schedule;
    for (auto s : adji[v]) {
      schedule.emplace_back(s.second, 1);
    }
    assert(!schedule.empty());
    ans.emplace_back(schedule);
  }
  assert(ans.size() == I);

  maxVolumes.resize(S);
  fill(maxVolumes.begin(), maxVolumes.end(), 0);

  int score = calcScore(ans);
  debug("dummy score = %d\n", score);
  if (score > bestScore) {
    bestAns = ans;
    bestScore = score;
  }

  for (int iter = 1; iter <= 30; ++iter) {

    // regress the result by volume
    vector<int> vmaxs;
    for (int v = 0; v < I; ++v) {
      vector<int> vs;
      int vcount = 0;
      for (auto s : adji[v]) {
        vs.push_back(maxVolumes[s.second]);
        if (vs.back()) {
          vcount++;
        }
      }
      int vmax = *max_element(vs.begin(), vs.end());
      vector<pair<int, int>> schedule;
      for (auto s : adji[v]) {
        // sacrifice low volume (?)
        if (vmax >= 50 * maxVolumes[s.second]) {
          continue;
        }
        int t = 1;
        if (vmax > 20 && maxVolumes[s.second] >= (float)vmax * 0.6) {
          t = 3;
        } else if (vmax > 10 && maxVolumes[s.second] >= (float)vmax * 0.3) {
          t = 2;
        }
        schedule.emplace_back(s.second, t);
      }
      ans[v] = schedule;
      vmaxs.push_back(vmax);
    }

    sort(vmaxs.begin(), vmaxs.end());
    reverse(vmaxs.begin(), vmaxs.end());
    debug("max volumes:");
    for (int i = 0; i < 10; ++i) {
      debug(" %d", vmaxs[i]);
    }
    debug("\n");

    fill(maxVolumes.begin(), maxVolumes.end(), 0);

    score = calcScore(ans);
    debug("iter %d: score = %d\n", iter, score);
    if (score > bestScore) {
      bestAns = ans;
      bestScore = score;
    }

    // try to randomly shuffle order
    int prevscore = score;

    int rv = rnd(I);
    auto tmp = adji[rv];
    random_shuffle(adji[rv].begin(), adji[rv].end());
    static vector<int> order(S);
    for (int i = 0; i < adji[rv].size(); ++i) {
      order[adji[rv][i].second] = i;
    }

    auto tmpvolumes = maxVolumes;
    auto tmpans = ans;
    stable_sort(ans[rv].begin(), ans[rv].end(), [&](const pii &a, const pii &b) -> bool {
      return order[a.first] < order[b.first];
    });
    fill(maxVolumes.begin(), maxVolumes.end(), 0);
    int newscore = calcScore(ans);
    if (newscore > score) {
      if (newscore > bestScore) {
        bestAns = ans;
        bestScore = newscore;
      }
    }
    else {
      // revert
      maxVolumes = tmpvolumes;
      adji[rv] = tmp;
      ans = tmpans;
    }

  }

  int nans = 0;
  for (int v = 0; v < I; ++v) {
    if (bestAns[v].size()) {
      nans++;
    }
  }
  printf("%d\n", nans);
  for (int v = 0; v < I; ++v) {
    if (!bestAns[v].size()) continue;
    printf("%d\n%d\n", v, (int)bestAns[v].size());
    for (auto y : bestAns[v]) {
      printf("%s %d\n", streetNames[y.first].c_str(), y.second);
    }
  }

  score = calcScore(bestAns);
  debug("final score = %d\n", score);

  return 0;
}