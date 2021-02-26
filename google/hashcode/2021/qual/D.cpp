#include <bits/stdc++.h>
using namespace std;

#define sqr(a) ((a) * (a))
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
    if (maxScore < D) {
      maxScore = 0;
    }
  }
};

vector<int> adj[MAXN];

vector<Car> cars;

bool used[MAXN];

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
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
  }
  debugl("score = %d\n", score);

  return score;
}

vector<vector<int>> simulate() {
  vector<vector<int>> X(I);
  for (int i = 0; i < I; ++i) {
    int cnt = 0;
    for (int v : adj[i]) {
      if (used[v]) {
        cnt++;
      }
    }
    X[i].resize(cnt, -1);
  }
  vector<int> Xi(S, -1);

  // queue for each intersections
  vector<queue<int>> q;
  q.resize(S);

  // events is "releasing a car from an intersection queue"
  // events[T] = queue<street id to process>
  vector<vector<int>> events;
  events.resize(D + 1);

  // qevents is "a car entering an intersection queue"
  // qevents[T] = queue<street id, car id>
  vector<queue<pair<int, int>>> qevents;
  qevents.resize(D + 1);

  // at T = 0, initialize all cars at the end of the streets
  vector<int> p; // index of car path
  p.resize(V);
  for (int i = 0; i < V; ++i) {
    int streetId = cars[i].path[p[i]];
    qevents[0].emplace(streetId, i);
  }

  vector<int> arrival;
  arrival.resize(V, -1);

  vector<int> delays;
  delays.resize(V, 0);
  vector<int> lastArrived;
  lastArrived.resize(V, -1);

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
        events[t].push_back(streetId);
      }
      q[streetId].push(carId);

      lastArrived[carId] = t;

      debugl("\t<streetId = %s, carId = %d>\n", streetNames[streetId].c_str(), carId);
    }

    debugl("events.size() = %d\n", (int)events[t].size());

    // sort events by:
    // - empty slots first
    // - then the max score for the first car
    sort(events[t].begin(), events[t].end(), [&](int a, int b) -> bool {
      int aiid = streets[a].E;
      int acycle = X[aiid].size();
      bool aempty = X[aiid][t % acycle];

      int biid = streets[b].E;
      int bcycle = X[biid].size();
      bool bempty = X[biid][t % bcycle];

      int acar = q[a].front();
      int ascore = cars[acar].maxScore - delays[acar] - (t - lastArrived[acar]);
      int bcar = q[b].front();
      int bscore = cars[bcar].maxScore - delays[bcar] - (t - lastArrived[bcar]);

      if (aempty ^ bempty) {
        return aempty;
      }
      return ascore > bscore;
    });

    for (int id : events[t]) {
      debugl("\t<streetId = %s>\n", streetNames[id].c_str());

      queue<int>& qs = q[id];
      assert(!qs.empty());

      int iid = streets[id].E;
      int _t = t;
      int cycle = X[iid].size();
      int mod = t % cycle;
      // check if id is assigned
      if (Xi[id] != -1) {
        debugl("\talready assigned: %d\n", Xi[id]);
        int cycle = X[iid].size();
        _t = cycle * (t / cycle) + Xi[id];
        if (_t < t) {
          _t += cycle;
        }
      } else if (X[iid][mod] == -1) {
        debugl("\tempty!\n");
        // assign it right away
        X[iid][mod] = id;
        Xi[id] = mod;
        debugl("\tAssigning <streetId = %s> = %d in <intersectionId = %d>\n", streetNames[id].c_str(), mod, iid);
      } else {
        // now what?
        // now just defer
        _t = t + 1;
      }

      if (t != _t) {
        if (_t <= D) {
          events[_t].push_back(id);
        }
      }
      else {
        // take single car in the queue
        int c = qs.front(); qs.pop();
        p[c]++;
        assert(p[c] < cars[c].path.size());
        delays[c] += t - lastArrived[c];

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
          events[t + 1].push_back(id);
        }

        debugl("\tdone processing <car = %d>\n", c);
      }
    }
  }

  // assign what's left randomly
  int maxslots = 0;
  for (int i = 0; i < I; ++i) {
    vector<int> slots;
    for (int j = 0; j < X[i].size(); ++j) {
      if (X[i][j] == -1) {
        slots.push_back(j);
      }
    }
    maxslots = max(maxslots, (int)slots.size());

    for (int v : adj[i]) {
      if (used[v] && Xi[v] == -1) {
        Xi[v] = slots.back();
        X[i][slots.back()] = v;
        slots.pop_back();
      }
    }
  }
  debugl("maxslots = %d\n", maxslots);

  debugl("arrival:\n");
  int score = 0;
  for (int c = 0; c < V; ++c) {
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
  }
  debugl("score = %d\n", score);

  for (int i = 0; i < I; ++i) {
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
      used[s] = true;
    }
  }

  auto X = simulate();

  vector<vector<pair<int,int>>> ans;

  for (int v = 0; v < I; ++v) {
    vector<pair<int,int>> schedule;
    for (int x : X[v]) {
      schedule.emplace_back(x, 1);
    }
    ans.emplace_back(schedule);
  }
  assert(ans.size() == I);

  maxVolumes.resize(S);

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

  int score = calcScore(ans);
  debug("score = %d\n", score);

  return 0;
}