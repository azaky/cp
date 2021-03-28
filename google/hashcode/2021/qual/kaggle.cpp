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

map<string,int> streetMapping;
vector<string> streetNames;

struct Street {
  int B, E, L;
  string name;
  int id;
  void read() {
    static char buffer[101];
    scanf("%d%d%s%d", &B, &E, buffer, &L);
    name = buffer;
    id = streetMapping.size();
    streetMapping[name] = id;
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
      path[i] = streetMapping[buffer];
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
vector<vector<pii>> logs;

vector<int> manualAdjustments;

pair<vector<vector<int>>,pii> simulate() {
  vector<vector<int>> X(I);
  vector<int> Xi(S, -1);
  vector<int> cycleSize(I, 0);
  for (int i = 0; i < I; ++i) {
    int cnt = 0;
    for (int v : adj[i]) {
      cnt += mark[v] + 1;
    }
    X[i].resize(cnt, -1);
    cycleSize[i] = cnt;
  }

  for (int x = 0; x < S; ++x) {
    if (manualAdjustments[x] == -1) continue;
    int s = streets[x].E;
    int mod = manualAdjustments[x] % cycleSize[s];
    assert(mod + mark[x] < cycleSize[s]);
    for (int i = 0; i <= mark[x]; ++i) {
      X[s][mod + i] = x;
    }
    Xi[x] = mod;
  }

  volumes.resize(S);
  fill(volumes.begin(), volumes.end(), 0);

  logs.resize(S);
  for (vector<pii> &v : logs) {
    v.clear();
  }

  // queue for each intersections
  vector<queue<int>> q(S);

  // events is "releasing a car from an intersection queue"
  // events[T] = queue<street id to process>
  vector<vector<int>> events(D+1);

  // qevents is "a car entering an intersection queue"
  // qevents[T] = queue<street id, car id>
  vector<queue<pair<int, int>>> qevents(D+1);

  // at T = 0, initialize all cars at the end of the streets
  vector<int> p(V, 0); // index of car path
  for (int i = 0; i < V; ++i) {
    int streetId = cars[i].path[0];
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

      logs[streetId].emplace_back(carId, -t-1);
      lastArrived[carId] = t;
      volumes[streetId]++;

      debugl("\t<streetId = %s, carId = %d>\n", streetNames[streetId].c_str(), carId);
    }

    debugl("events.size() = %d\n", (int)events[t].size());

    sort(events[t].begin(), events[t].end(), [&](int a, int b) -> bool {
      // always return unmarked streets first
      if (mark[a] != mark[b]) {
        return mark[a] < mark[b];
      }

      assert(!q[a].empty() && !q[b].empty());

      int acar = q[a].front();
      int bcar = q[b].front();

      int await = delays[acar] + t - lastArrived[acar];
      int bwait = delays[bcar] + t - lastArrived[bcar];

      // sort by which car waits longest
      return await > bwait;
    });
    // random_shuffle(events[t].begin(), events[t].end());

    for (int id : events[t]) {
      debugl("\t<streetId = %s, intersectionId = %d>\n", streetNames[id].c_str(), streets[id].E);

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
        // debugl("\talready assigned: %d\n", Xi[id]);

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

          bool preference = true;

          // if (id == 1963) {
          //   if (t % cycle < (2369 % cycle)) preference = false;
          // }

          // only do this if the queue is already full
          // if (q[id].size() > mark[id])
          if (preference)
          {
            for (int i = 0; i <= mark[id]; ++i) {
              if (mod - i >= 0 && mod - i + mark[id] < cycle) {
                bool possible = true;
                for (int j = 0; j <= mark[id]; ++j) {
                  int tm = mod - i + j;
                  if (X[iid][tm] != -1) {
                    possible = false;
                    break;
                  };
                  // also mark it as impossible if there is a queue waiting on the specified time
                  if (tm > t) {

                  }
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
          }
        } else {
          debugl("\tAssigning <streetId = %s> = %d %% %d in <intersectionId = %d>\n", streetNames[id].c_str(), mod, cycle, iid);

          X[iid][mod] = id;
          Xi[id] = mod;
        }
      } else {
        // now what?
        // now just defer
        _t = t + 1;
      }
      assert(_t >= t);

      debugl("\tnext green = %d\n", _t);

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

      logs[id].emplace_back(c, t+1);

      int snext = cars[c].path[p[c]]; // next street
      int inext = streets[snext].E; // next intersection
      int tnext = t + streets[snext].L; // next t

      debugl("\tprocessing <car = %d>: snext = %s, inext = %d, tnext = %d\n", c, streetNames[snext].c_str(), inext, tnext);

      if (tnext <= D) {
        // arrived!
        if (p[c] == cars[c].path.size() - 1) {
          arrival[c] = tnext;
        } else {
          qevents[tnext].emplace(snext, c);
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
      assert(used[v]);
      if (Xi[v] == -1) {
        debug("<street = %d> is not used. mark = %d\n", v, mark[v]);
        int iid = streets[v].E;
        debug("<intersection = %d, size = %d, cycle = %d>\n", iid, (int)adj[iid].size(), cycleSize[iid]);
        // make sure this is not marked
        assert(!mark[v]);
        debug("slots = %d\n", (int)slots.size());
        for (int j = 0; j < X[i].size(); ++j) {
          debug("%d ", X[i][j]);
        }
        debug("\n");
        for (int j : adj[iid]) {
          debug("%d ", j);
        }
        debug("\n");
        Xi[v] = slots.back();
        X[i][slots.back()] = v;
        slots.pop_back();
        debug("done assigning\n");
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
  debugl("arrived = %d\n", count);

  for (int i = 0; i < I; ++i) {
    for (int j = 0; j < X[i].size(); ++j) {
      if (X[i][j] == -1) {
        debug("Error: not all mods are assigned. Intersection = %d, mod = %d\n", i, j);
        for (int k = 0; k < X[i].size(); ++k) {
          debug("%d ", X[i][k]);
        }
        debug("\n");
      }
      assert(X[i][j] != -1);
    }
  }

  return make_pair(X, make_pair(score, count));
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

  int minLength = 1000;
  for (auto s : streets) {
    minLength = min(minLength, s.L);
  }
  debug("minLength = %d\n", minLength);

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
  int threshold = 500;
  int count = 0;

  for (int i = 0; i < I; ++i) {
    int hasMarked = 0;
    int cycle = adj[i].size();
    int maxMarkCount = 0;
    int markCount = 0;

    while (markCount < maxMarkCount) {
      bool has = false;
      int maxWait = 0;
      for (int x : adj[i]) {
        int wait = volumes0[x] * cycle / (1 + mark[x]);
        maxWait = max(maxWait, wait);
      }
      for (int x : adj[i]) {
        int wait = volumes0[x] * cycle / (1 + mark[x]);
        if (wait > threshold && wait == maxWait) {
          mark[x]++;
          has = 1;
          hasMarked = 1;
          cycle++;
          markCount++;
          break;
        }
      }
      if (!has) break;
    }

    int maxWait = 0;
    for (int x : adj[i]) {
      int wait = volumes0[x] * cycle / (1 + mark[x]);
      maxWait = max(maxWait, wait);
    }

    vector<int> vs;
    for (int x : adj[i]) {
      if (mark[x]) vs.push_back(mark[x]);
    }

    if (vs.size() < 2) continue;

    sort(vs.begin(), vs.end(), std::greater<int>());
    if (hasMarked) {
      debug("i = %d (sum = %d, len = %d, cycle = %d, maxWait = %d):", i, SUM(vs), (int)adj[i].size(), cycle, maxWait);
      for (int x : vs) {
        debug(" %d", x);
      }
      debug("\n");
    }
  }
  debug("count maxWait > %d: %d\n", threshold, SUM(mark));
  debug("\n");

  manualAdjustments.resize(S, -1);

  // manually set marks
  // vector<int> magic = { 1963 };
  vector<int> magic = { 1963, 1669, 3317, 1387, 1529 };
  for (int v : magic) {
    mark[v] = 1;
  }

  vector<int> totalWaits(S, 0);

  auto res = simulate();
  auto X = res.first;
  int score = res.second.first;
  int arrived = res.second.second;

  auto bestX = X;
  int bestScore = score;
  int bestArrived = arrived;
  int bestIter = -1;

  debug("initial assignment:\n");

  int maxTotalWait = 0;
  int maxTotalWaitX = 0;
  int totalTotalWait = 0;
  int totalWaitThreshold = 500;

  auto calcWaits = [&]() {
    totalTotalWait = 0;
    maxTotalWait = 0;
    maxTotalWaitX = -1;
    totalTotalWait = 0;
    fill(totalWaits.begin(), totalWaits.end(), 0);

    for (int i = 0; i < I; ++i) {
      int cycle = X[i].size();
      for (int x : adj[i]) {
        // assert(volumes[x] == volumes0[x]);

        int totalWait = 0;
        queue<int> q;
        for (pii p : logs[x]) {
          int t = p.second;
          assert(t != 0);

          if (t < 0) {
            q.push(-t);
          }
          else {
            int w = t - q.front(); q.pop();
            totalWait += w;
          }
        }
        // assert(q.empty());

        totalWaits[x] = totalWait;

        totalTotalWait += totalWait;
        if (totalWait > maxTotalWait && manualAdjustments[x] == -1) {
          maxTotalWait = totalWait;
          maxTotalWaitX = x;
        }

        if (totalWait > totalWaitThreshold) {
          debug("street %d -> %d (totalWait = %d, volume = %d, cycle = %d):", x, i, totalWait, volumes[x], cycle);
          // debug("street %d -> %d (volume = %d, cycle = %d):", x, i, volumes[x], cycle);

          // repeat for logging
          queue<int> q;
          for (pii p : logs[x]) {
            int t = p.second;
            assert(t != 0);

            debug(" %d", (t / abs(t) * (abs(t) - 1)));
            if (t < 0) {
              q.push(-t);
            }
            else {
              int w = t - q.front(); q.pop();
              debug("(w=%d)", w);
            }
          }
          // assert(q.empty());
          debug("\n");
        }
      }
    }
    debug("totalWait = %d\n", totalTotalWait);
    debug("maxTotalWait = %d, street = %d\n", maxTotalWait, maxTotalWaitX);
    debug("score = %d\n", score);
    debug("arrived = %d/%d\n", arrived, V);
    debug("\n");
  };

  calcWaits();

  vector<vector<int>> visited(I);
  for (int i = 0; i < I; ++i) {
    visited[i].resize(X[i].size());
  }

  auto findAdjustment = [&](int x, int has) -> pair<pii,int> {
    int s = streets[x].E;

    vector<int> p;
    for (pii pi : logs[x]) {
      if (pi.second < 0) p.push_back(-pi.second);
    }

    int bestmod = -1;
    int bestcost = 1e8;
    int bestsize = 0;

    int minSize = 1 + mark[x];
    // int maxSize = min(2 + mark[x], 5);
    // if (!has) {
    //   assert(!mark[x]);
    //   maxSize = 1;
    // }
    int maxSize = 1 + mark[x];

    for (int size = minSize; size <= maxSize; ++size) {
      int c = X[s].size() + size - (1 + mark[x]);
      for (int mod = 0; mod+size-1 < c; ++mod) {
        bool hasVisited = false;
        for (int j = 0; j < size; ++j) {
          if (visited[s][mod + j]) {
            hasVisited = true;
            break;
          }
        }
        if (hasVisited) continue;

        int cost = 0;
        set<int> stops;
        for (int i : p) {
          int t = mod + c * (i / c);
          bool found = false;
          while (!found) {
            for (int j = 0; j < size; ++j) {
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
        if (cost < bestcost) {
          bestmod = mod;
          bestcost = cost;
          bestsize = size;
        }
      }
    }

    return make_pair(make_pair(bestmod, bestsize), bestcost);
  };

  vector<int> manualCosts(S, 0);
  set<vector<pair<int,pii>>> previousAdjustments;
  vector<pair<int, pii>> bestAdjustments;

  for (int iter = 1; iter <= 100; ++iter) {
    debug("\n\niter-%d\n", iter);

    // manual adjustment
    vector<pii> needAdjustments;
    for (int y = 0; y < S; ++y) {
      needAdjustments.emplace_back(totalWaits[y], y);
    }
    sort(needAdjustments.begin(), needAdjustments.end(), greater<pii>());

    // we only do it one at a time. if we can change something, then change only that.
    bool changed = false;
    for (pii px : needAdjustments) {
      int x = px.second;
      
      int prev = manualAdjustments[x];
      if (prev != -1) {
        for (int i = 0; i <= mark[x]; ++i) {
          visited[streets[x].E][prev+i] = 0;
        }
      }

      auto a = findAdjustment(x, prev != -1);
      int mod = a.first.first;
      int size = a.first.second;
      int cost = a.second;
      if (size > mark[x] + 1) {
        // when size changes, it nullifies all previous adjustments

        mark[x]++;
        visited[streets[x].E].push_back(0);
        changed = true;
      }
      for (int i = 0; i < size; ++i) {
        assert(!visited[streets[x].E][mod + i]);
        visited[streets[x].E][mod+i] = 1;
      }
      manualAdjustments[x] = mod;
      manualCosts[x] = cost;

      if (changed || prev != mod) {
        // check if it changes anything
        vector<pair<int, pii>> currentAdjustments;
        for (int y = 0; y < S; ++y) {
          if (manualAdjustments[y] != -1) {
            currentAdjustments.emplace_back(y, make_pair(manualAdjustments[y], mark[y] + 1));
          }
        }
        if (previousAdjustments.count(currentAdjustments)) {
          continue;
        }

        debug("manual adjustment for street = %d: (%d, size = %d) (totalWaits = %d, cost = %d)\n", x, mod, size, totalWaits[x], cost);
        changed = true;
        break;
      }
    }

    vector<pair<int,pii>> currentAdjustments;
    for (int y = 0; y < S; ++y) {
      if (manualAdjustments[y] != -1) {
        currentAdjustments.emplace_back(y, make_pair(manualAdjustments[y], mark[y]+1));
      }
    }
    assert(changed);
    assert(!previousAdjustments.count(currentAdjustments));
    previousAdjustments.insert(currentAdjustments);

    debug("\n");
    debug("manual adjustment count: %d\n", (int)currentAdjustments.size());
    for (int i = 0; i < S; ++i) {
      if (manualAdjustments[i] != -1) {
        int e = streets[i].E;
        debug("street = %d -> %d: (%d, size = %d) (len = %d, cycle = %d, totalWaits = %d, cost = %d)\n", i, streets[i].E, manualAdjustments[i], mark[i]+1, (int)adj[e].size(), (int)visited[e].size(), totalWaits[i], manualCosts[i]);
      }
    }
    debug("\n");

    // run simulation with new adjustment
    res = simulate();
    X = res.first;
    score = res.second.first;
    arrived = res.second.second;

    debug("after adjustment:\n");
    calcWaits();

    if (score > bestScore) {
      bestX = X;
      bestScore = score;
      bestArrived = arrived;
      bestIter = iter;

      bestAdjustments = currentAdjustments;
    }
    else {
      // revert back to last adjustment
      debug("score did not improve, reverting back to last adjustment\n");
      for (int i = 0; i < S; ++i) {
        manualAdjustments[i] = -1;
      }
      for (auto p : bestAdjustments) {
        manualAdjustments[p.first] = p.second.first;
      }
    }

    debug("bestScore = %d (iter-%d)\n", bestScore, bestIter);
  }

  X = bestX;
  score = bestScore;
  arrived = bestArrived;

  vector<vector<pii>> ans;

  for (int v = 0; v < I; ++v) {
    vector<pii> schedule;
    for (int x : X[v]) {
      if (!schedule.empty() && x == schedule.back().first) {
        schedule.back().second++;
      } else {
        schedule.emplace_back(x, 1);
      }
    }
    ans.emplace_back(schedule);
  }
  assert(ans.size() == I);

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

  debug("best:\n");
  debug("score = %d\n", score);
  debug("arrived = %d/%d\n", arrived, V);

  return 0;
}