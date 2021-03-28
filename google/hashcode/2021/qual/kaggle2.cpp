#include <bits/stdc++.h>
using namespace std;

#define sqr(a) ((a) * (a))
#define SUM(a) (accumulate(a.begin(), a.end(), decltype(a)::value_type(0)))
#define MAX(a) (*max_element(a.begin(), a.end()))
#define MIN(a) (*min_element(a.begin(), a.end()))

#define debug(...) fprintf(stderr, __VA_ARGS__)
// #define debugl(...) fprintf(stderr, __VA_ARGS__)
// #define debugl(...) fprintf(flog, __VA_ARGS__)
// FILE* flog = fopen("log", "w");
#define debugl(...)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

vector<Street> streets;

struct Car {
  vector<int> path;
  int maxScore;
  int totalPath;
  void read() {
    int n;
    scanf("%d", &n);
    path.resize(n);
    for (int i = 0; i < n; ++i) {
      static char buffer[101];
      scanf("%s", buffer);
      path[i] = streetIds[buffer];
    }

    totalPath = 0;
    for (int p : path) {
      totalPath += streets[p].L;
    }
    maxScore = F + D - totalPath;
    if (maxScore < F) {
      maxScore = 0;
    }
  }
};

vector<int> adj[MAXN];

vector<Car> cars;

bool used[MAXN];

vector<int> volumes, volumes0;
vector<int> mark;

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
        return D + 1;
      }
      int i = SID[id];
      if (i == -1) {
        return D + 1;
      }
      int base = TI[iid] * (t / TI[iid]);
      t %= TI[iid];
      if (t < TS[iid][i]) {
        return base + TS[iid][i];
      }
      if (t < TS[iid][i + 1]) {
        return base + t;
      }
      return base + TS[iid][i] + TI[iid];
    }
    catch (exception e) {
      debug("Exception: %s\n", e.what());
      return D + 1;
    }
  };

  // queue for each intersections
  vector<queue<int>> q;
  q.resize(S);

  // events is "releasing a car from an intersection queue"
  // events[T] = queue<street id to process>
  vector<queue<int>> events;
  events.resize(D + 1);

  // qevents is "a car entering an intersection queue"
  // qevents[T] = queue<street id, car id>
  vector<queue<pair<int, int>>> qevents;
  qevents.resize(D + 1);

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

      queue<int>& qs = q[id];
      assert(!qs.empty());

      volumes[id] = max(volumes[id], (int)qs.size());

      // check if traffic light is green.
      // if green, then process immediately.
      // if not, then defer until next green.
      int _t = nextGreen(id, t);
      debugl("\tnext green = %d\n", _t);
      if (t != _t) {
        if (_t <= D) {
          events[_t].push(id);
        }
      }
      else {
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
          if (p[c] == cars[c].path.size() - 1) {
            arrival[c] = tnext;
          }
          else {
            qevents[tnext].emplace(snext, c);
          }
        }

        // reinsert self into events if queue is still not empty
        if (!qs.empty() && t < D) {
          events[t + 1].push(id);
        }

        debugl("\tdone processing <car = %d>\n", c);
      }
    }
  }

  debugl("arrival:\n");
  int score = 0;
  int count = 0;
  for (int c = 0; c < V; ++c) {
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    count++;
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
  }
  // debug("score = %d\n", score);
  // debug("arrived = %d/%d\n", count, V);

  return score;
}

vector<vector<int>> simulate() {
  vector<vector<int>> X(I);
  vector<int> Xi(S, -1);
  vector<int> cycleSize(I, 0);
  for (int i = 0; i < I; ++i) {
    int cnt = adj[i].size();
    for (int v : adj[i]) {
      assert(used[v]);
      cnt += mark[v];
    }
    X[i].resize(cnt, -1);
    cycleSize[i] = cnt;
  }

  volumes.resize(S);
  fill(volumes.begin(), volumes.end(), 0);

  // queue for each intersections
  vector<queue<int>> q(S);

  // events is "releasing a car from an intersection queue"
  // events[T] = queue<street id to process>
  vector<vector<int>> events(D+1);

  // at T = 0, initialize all cars at the end of the streets
  vector<int> p(V, 0); // index of car path
  for (int i = 0; i < V; ++i) {
    int streetId = cars[i].path[0];
    if (q[streetId].empty()) {
      events[0].push_back(streetId);
    }
    q[streetId].push(i);
    volumes[streetId]++;
  }

  vector<int> arrival;
  arrival.resize(V, -1);

  vector<int> delays;
  delays.resize(V, 0);
  vector<int> lastArrived;
  lastArrived.resize(V, -1);

  for (int t = 0; t <= D; ++t) {
    debugl("T = %d\n", t);
    debugl("events.size() = %d\n", (int)events[t].size());

    // // sort events by max score for the first car
    // sort(events[t].begin(), events[t].end(), [&](int a, int b) -> bool {
    //   // always return unmarked streets first
    //   if (mark[a] ^ mark[b]) {
    //     return !mark[a];
    //   }

    //   int acar = q[a].front();
    //   int ascore = cars[acar].maxScore - delays[acar] - (t - lastArrived[acar]);
    //   int bcar = q[b].front();
    //   int bscore = cars[bcar].maxScore - delays[bcar] - (t - lastArrived[bcar]);

    //   return ascore > bscore;
    // });

    for (int id : events[t]) {
      debugl("\t<streetId = %s>\n", streetNames[id].c_str());

      queue<int>& qs = q[id];
      assert(!qs.empty());
      assert(used[id]);

      // _t denotes the next moment current street turns green.
      int _t = t;

      int iid = streets[id].E;
      int cycle = cycleSize[iid];
      int mod = t % cycle;

      // check if current street is already assigned.
      if (Xi[id] != -1) {
        debugl("\talready assigned: %d\n", Xi[id]);

        _t = cycle * (t / cycle) + Xi[id];
        if (_t < t) {
          // special case for marked streets
          if (mark[id] && t <= _t + mark[id]) {
            _t = t;
          } else {
            _t += cycle;
          }
        }
      } else
      // otherwise, assign it to current mod whenever possible.
      if (X[iid][mod] == -1) {
        if (mark[id]) {
          // mark now if possible. otherwise, defer.
          // this is on an assumption that this is always possible.
          _t = t + 1;
          for (int i = 0; i <= mark[id]; ++i) {
            if (mod - i >= 0 && mod - i + mark[id] < cycle) {
              bool possible = true;
              for (int j = 0; j <= mark[id]; ++j) {
                if (X[iid][mod - i + j] != -1) {
                  possible = false;
                  break;
                };
              }
              if (!possible) continue;
              for (int j = 0; j <= mark[id]; ++j) {
                X[iid][mod - i + j] = id;
              }
              Xi[id] = mod - i;
              _t = t;
              break;
            }
          }
        } else {
          debugl("\tAssigning <streetId = %s> = %d in <intersectionId = %d>\n", streetNames[id].c_str(), mod, iid);

          X[iid][mod] = id;
          Xi[id] = mod;
        }
      } else {
        // now what?
        // now just defer
        _t = t + 1;
      }

      // red light, defer to the next green
      if (t != _t) {
        if (_t <= D) {
          events[_t].push_back(id);
        }
        continue;
      }

      // take single car in the queue
      int c = qs.front(); qs.pop();
      p[c]++;
      assert(p[c] < cars[c].path.size());
      delays[c] += t - lastArrived[c];

      int snext = cars[c].path[p[c]]; // next street
      int inext = streets[snext].E; // next intersection
      int tnext = t + streets[snext].L; // next t

      debugl("\tprocessing <car = %d>: snext = %s, inext = %d, tnext = %d\n", c, streetNames[snext].c_str(), inext, tnext);

      if (tnext <= D) {
        // arrived!
        if (p[c] == cars[c].path.size() - 1) {
          arrival[c] = tnext;
        } else {
          if (q[snext].empty()) {
            events[tnext].push_back(snext);
          }
          q[snext].push(c);
          volumes[snext]++;

          lastArrived[c] = tnext;
        }
      }

      // reinsert current street into events if queue is still not empty
      if (!qs.empty() && t < D) {
        events[t + 1].push_back(id);
      }

      debugl("\tdone processing <car = %d>\n", c);
    }
  }

  // assign what's left randomly
  for (int i = 0; i < I; ++i) {
    vector<int> slots;
    for (int j = 0; j < X[i].size(); ++j) {
      if (X[i][j] == -1) {
        slots.push_back(j);
      }
    }

    for (int v : adj[i]) {
      if (used[v] && Xi[v] == -1) {
        debug("<street = %s> is not used\n", streets[v].name.c_str());
        // make sure this is not marked
        assert(!mark[v]);
        Xi[v] = slots.back();
        X[i][slots.back()] = v;
        slots.pop_back();
      }
    }
  }

  debugl("arrival:\n");
  int score = 0;
  int count = 0;
  for (int c = 0; c < V; ++c) {
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    count++;
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
  }

  debug("score = %d\n", score);
  debug("arrived = %d/%d\n", count, V);

  for (int i = 0; i < I; ++i) {
    assert(X[i].size() == adj[i].size());
    for (int j = 0; j < X[i].size(); ++j) {
      assert(X[i][j] != -1);
    }
  }

  return X;
}

int main(int argc, char** argv) {
  srand(0);

  scanf("%d%d%d%d%d", &D, &I, &S, &V, &F);

  streets.resize(S);
  streetNames.resize(S);
  for (int i = 0; i < S; ++i) {
    streets[i].read();
    adj[streets[i].E].push_back(streets[i].id);
  }

  cars.resize(V);
  for (int i = 0; i < V; ++i) {
    cars[i].read();
    for (int s : cars[i].path) {
      if (s != cars[i].path.back()) {
        used[s] = true;
      }
    }
  }

  // adjust adj, remove all unused streets
  for (int i = 0; i < I; ++i) {
    for (int j = 0; j < adj[i].size(); ++j) {
      if (!used[adj[i][j]]) {
        adj[i].erase(adj[i].begin() + j);
        j--;
      }
    }
    for (int v : adj[i]) {
      assert(used[v]);
    }
  }

  int maxScore = 0;
  for (int i = 0; i < V; ++i) {
    maxScore += cars[i].maxScore;
  }
  debug("max score = %d\n", maxScore);

  // set initial volumes
  volumes0.resize(S);
  fill(volumes0.begin(), volumes0.end(), 0);
  for (int i = 0; i < V; ++i) {
    for (int s : cars[i].path) {
      if (s != cars[i].path.back()) {
        volumes0[s]++;
      }
    }
  }

  mark.resize(S, 0);
  int threshold = 12000;
  int count = 0;
  for (int i = 0; i < I; ++i) {
    int hasMarked = 0;
    for (int x : adj[i]) {
      if (volumes0[x] * adj[i].size() > threshold) {
        mark[x] = 1;
        hasMarked = 1;
      }
    }

    vector<int> vs;
    for (int x : adj[i]) {
      if (volumes0[x]) vs.push_back(volumes0[x]);
    }
    assert(vs.size() == adj[i].size());
    if (vs.size() < 2) continue;

    sort(vs.begin(), vs.end(), std::greater<int>());
    int maxWait = vs.size() * MAX(vs);
    if (hasMarked) {
      debug("i = %d (sum = %d, len = %d, maxWait = %d):", i, SUM(vs), (int)vs.size(), maxWait);
      for (int x : vs) {
        debug(" %d", x);
      }
      debug("\n");
    }
  }
  debug("count maxWait > %d: %d\n", threshold, SUM(mark));

  auto X = simulate();

  vector<vector<pii>> ans;

  for (int v = 0; v < I; ++v) {
    vector<pii> schedule;
    for (int x : X[v]) {
      if (!schedule.empty() && x == schedule.back().first) {
        assert(mark[x]);
        mark[x]--;
        schedule.back().second++;
      } else {
        schedule.emplace_back(x, 1);
      }
    }
    ans.emplace_back(schedule);

    // vector<int> vs;
    // for (int x : adj[v]) {
    //   if (volumes[x]) vs.push_back(volumes[x]);
    // }
    // sort(vs.begin(), vs.end(), std::greater<int>());
    // if (vs.size() > 1 && SUM(vs) > 50) {
    //   debug("v = %d (sum = %d):", v, SUM(vs));
    //   for (int x : vs) {
    //     debug(" %d", x);
    //   }
    //   debug("\n");
    // }
  }
  assert(ans.size() == I);
  assert(SUM(mark) == 0);

  int score = calcScore(ans);
  debug("score = %d\n", score);

  int nans = 0;
  for (int v = 0; v < I; ++v) {
    if (ans[v].size()) {
      nans++;
    }
  }
  printf("%d\n", nans);
  for (int v = 0; v < I; ++v) {
    if (!ans[v].size()) continue;
    printf("%d\n%d\n", v, (int)ans[v].size());
    for (auto y : ans[v]) {
      printf("%s %d\n", streetNames[y.first].c_str(), y.second);
    }
  }

  return 0;
}