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

vector<int> adj[MAXN];

vector<Street> streets;
vector<Car> cars;

int used[MAXN];

vector<int> volumes;
int countArrived;

int calcScore(vector<vector<pair<int, int>>> ans) {
  volumes.resize(S);
  fill(volumes.begin(), volumes.end(), 0);

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
      volumes[streetId]++;

      debugl("\t<streetId = %s, carId = %d>\n", streetNames[streetId].c_str(), carId);
    }

    debugl("events.size() = %d\n", (int)events[t].size());

    while (!events[t].empty()) {
      int id = events[t].front();
      events[t].pop();

      debugl("\t<streetId = %s>\n", streetNames[id].c_str());

      queue<int> &qs = q[id];
      assert(!qs.empty());

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
  countArrived = 0;
  for (int c = 0; c < V; ++c) {
    if (arrival[c] == -1) continue;
    assert(arrival[c] <= D);
    score += F + D - arrival[c];
    debugl("<car = %d> arrived at %d\n", c, arrival[c]);
    countArrived++;
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
    adj[streets[i].E].emplace_back(i);
  }

  vector<int> vv(S);
  int cp = 0;
  cars.resize(V);
  for (int i = 0; i < V; ++i) {
    cars[i].read();
    int len = 0;
    for (int j : cars[i].path) {
      used[j]++;
      len += streets[j].L;
    }
    if (len > D) {
      cp++;
    }
    vv[cars[i].path.front()]++;
  }
  debug("impossible = %d\n", cp);
  sort(vv.begin(), vv.end());
  reverse(vv.begin(), vv.end());
  debug("vv:");
  for (int i = 0; i < 20; ++i) {
    debug(" %d", vv[i]);
  }
  debug("\n");

  int bestScore = 0;
  vector<vector<pair<int,int>>> bestAns;

  for (int iter = 1; iter <= 1; ++iter) {
    debug("\niter %d\n", iter);
    // random shuffle adj
    for (int v = 0; v < I; ++v) {
      random_shuffle(adj[v].begin(), adj[v].end());
    }

    vector<vector<pair<int, int>>> ans;
    for (int v = 0; v < I; ++v) {
      vector<pair<int, int>> schedule;
      for (auto s : adj[v]) {
        if (used[s]) {
          schedule.emplace_back(s, used[s]);
        }
      }
      ans.emplace_back(schedule);
    }
    assert(ans.size() == I);

    int score = calcScore(ans);
    // debug("iter %d: initial score = %d\n", iter, score);
    if (score > bestScore) {
      bestAns = ans;
      bestScore = score;
    }

    for (int inneriter = 1; inneriter <= 50; ++inneriter) {
      // regress the result by volume
      vector<int> vmaxs;
      vector<int> vtotals;
      for (int v = 0; v < I; ++v) {
        vector<int> vs;
        int vcount = 0;
        int totalVolume = 0;
        for (auto s : adj[v]) {
          totalVolume += volumes[s];
          if (volumes[s]) {
            vs.push_back(volumes[s]);
            vcount++;
          }
        }
        if (vs.empty()) {
          ans[v] = {};
          continue;
        }

        sort(vs.begin(), vs.end());
        int vmax = vs.back();

        vector<pair<int, int>> schedule;

        int magic = 350;
        int magic2 = 2 + vmax / 42;

        int allocated = magic2 * totalVolume / vmax;

        for (auto s : adj[v]) {
          // sacrifice low volume
          if (volumes[s] * magic <= totalVolume) {
            continue;
          }

          int t = 1;
          // ensure 1 for low totalVolume
          if (totalVolume < 35) {
            // do nothing
          } else {
            t = (volumes[s] * allocated + totalVolume-1) / totalVolume;
            t = max(t, 1);
          }

          schedule.emplace_back(s, t);
        }

        // adjust min
        int vmin = vmax;
        for (pii &s : schedule) {
          if (s.second < vmin) vmin = s.second;
        }
        for (pii &s : schedule) {
          s.second -= vmin-1;
        }

        if (vcount > 2) {
          debug("vmax = %d, vtotal = %d, deg = %d\n", vmax, totalVolume, vcount);
          debug("\tvolumes :");
          for (int x : vs) debug(" %d", x);
          debug("\n");
          debug("\tschedule:");
          for (pii x : schedule) debug(" %d", x.second);
          debug("\n");
        }

        random_shuffle(schedule.begin(), schedule.end());
        // put vmax to the end
        // for (int i = 0; i < schedule.size(); ++i) {
        //   if (vmax > 200 && volumes[schedule[i].first] == vmax) {
        //     swap(schedule[i], schedule[schedule.size()-1]);
        //   }
        // }
        // put the one with max vv to the front
        for (int i = 0; i < schedule.size(); ++i) {
          if (vv[schedule[i].first] > vv[schedule[0].first]) {
            swap(schedule[i], schedule[0]);
          }
        }

        ans[v] = schedule;
        vmaxs.push_back(vmax);
        vtotals.push_back(totalVolume);
      }

      // sort(vmaxs.begin(), vmaxs.end());
      // reverse(vmaxs.begin(), vmaxs.end());
      // debug("max volumes:");
      // for (int i = 0; i < 20; ++i) {
      //   debug(" %d", vmaxs[i]);
      // }
      // debug("\n");

      // sort(vtotals.begin(), vtotals.end());
      // reverse(vtotals.begin(), vtotals.end());
      // debug("total volumes:");
      // for (int i = 0; i < 20; ++i) {
      //   debug(" %d", vtotals[i]);
      // }
      // debug("\n");

      score = calcScore(ans);
      debug("iter %d-%d: score = %d\n", iter, inneriter, score);
      if (score > bestScore) {
        bestAns = ans;
        bestScore = score;
        debug("new best! iter %d-%d: score = %d\n", iter, inneriter, score);
      }
    }
    // debug("\n");
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

  int score = calcScore(bestAns);
  debug("\n");
  debug("final score = %d\n", score);
  debug("    arrived = %d / %d\n", countArrived, V);

  return 0;
}