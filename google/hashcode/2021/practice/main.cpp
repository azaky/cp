#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define sqr(a) ((a) * (a))
#define debug(...) fprintf(stderr, __VA_ARGS__)

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
double rndf() {
  return (double)rand() / (double)RAND_MAX;
}
double rndf(double a) {
  return rndf() / a;
}
double rndf(double a, double b) {
  return a + rndf(b - a);
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

int iline = 0;
vector<int> fgetline(ifstream& f) {
  iline++;
  char buffer[1024];
  f.getline(buffer, 1024);
  stringstream ss(buffer);
  vector<int> res;
  while (ss.good()) {
    int x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}


#define MAXN 1000100

int p[MAXN];
vector<int> pi[MAXN];
bool used[MAXN];

int cmask[1024];
int pmask[MAXN];

int vv[MAXN];
long long calcscore(vector<int>& q) {
  int x = 0;
  for (int i : q) {
    for (int j : pi[i]) {
      if (!vv[j]) {
        x++;
        vv[j] = 1;
      }
    }
  }
  for (int i : q) {
    for (int j : pi[i]) {
      vv[j] = 0;
    }
  }

  return sqr((long long)x);
}

long long calcscore(vector<vector<int>>& q) {
  long long score = 0;
  for (auto qi : q) {
    score += calcscore(qi);
  }
  return score;
}

int main(int argc, char** argv) {
  srand(0);

  int m, t[5];
  cin >> m >> t[2] >> t[3] >> t[4];

  map<string, int> ingmap;
  set<string> ingredients;
  int P = 0;
  int maxp = 0;
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
    for (int j = 0; j < p[i]; ++j) {
      string buffer;
      cin >> buffer;
      ingredients.insert(buffer);
      if (ingmap.find(buffer) == ingmap.end()) {
        ingmap[buffer] = ingmap.size();
      }
      pi[i].push_back(ingmap[buffer]);
      // pmask[i] ^= (1 << ingmap[buffer]);
    }
    // cmask[pmask[i]]++;
    P += p[i];
    maxp = max(maxp, p[i]);
  }

  debug("M = %d\n", m);
  debug("T = %d\n", t[2] + t[3] + t[4]);
  debug("T = %d\n", t[2] * 2 + t[3] * 3 + t[4] * 4);
  debug("P = %d\n", P);
  debug("Distinct ingredients = %lu\n", ingredients.size());
  debug("Max pi.size() = %d\n", maxp);
  debug("Mean pi.size() = %.3lf\n", (double)P / m);
  debug("\n");

  double meanp = (double)P / m;

  // initially assign greedily
  // 0. choose teams in increasing number of members.
  // 1. pick first pizza *randomly* (instead of picking one with most ingredients).
  // 2. then, for the rest of the pizzas, *greedily* pick the one that:
  //    - has most score improvements,
  //    - on ties, pick one that has least total number of ingredients.
  int tempt[5] = { 0 };
  vector<vector<int>> tempp;
  vector<int> unused;

  if (argc > 1) {
    ifstream fin(argv[1]);
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
      vector<int> p;
      int x, y;
      fin >> x;
      for (int j = 0; j < x; ++j) {
        fin >> y;
        p.push_back(y);
        used[y] = 1;
      }
      tempp.push_back(p);
      tempt[p.size()]++;
    }
    for (int i = 0; i < m; ++i) {
      if (!used[i]) {
        unused.push_back(i);
      }
    }
  } else {
    for (int i = 0; i < m; ++i) {
      unused.push_back(i);
    }
    random_shuffle(unused.begin(), unused.end());

    for (int l = 4; l >= 2; --l) {
      for (int il = 0; il < t[l]; ++il) {
        if (unused.size() < l) continue;

        vector<int> p;
        for (int k = 0; k < l; ++k) {
          int best = -1;
          int bestscore = 0;
          int bestadd = m;
          for (int i = 0; i < unused.size(); ++i) {
            int x = unused[i];
            int score = 0;
            int add = pi[x].size();
            for (int pii : pi[x]) {
              if (!vv[pii]) score++;
            }
            if (score > bestscore || (score == bestscore && add < bestadd)) {
              best = i;
              bestscore = score;
              bestadd = add;
            }
          }
          p.push_back(unused[best]);
          for (int pii : pi[p.back()]) {
            vv[pii] = 1;
          }
          unused[best] = unused.back();
          unused.pop_back();
        }

        tempp.push_back(p);
        tempt[l]++;

        // reset v
        for (auto pz : p) {
          for (int pii : pi[pz]) {
            vv[pii] = 0;
          }
        }

        if ((tempt[2] + tempt[3] + tempt[4]) % 100 == 0) {
          debug("l = %d, assigned %d / %d\n", l, tempt[2] + tempt[3] + tempt[4], t[2] + t[3] + t[4]);
        }
      }
    }
  }

  long long score = calcscore(tempp);
  debug("Initial score = %d\n", score);
  debug("Assigned teams = %d\n", tempp.size());

  // simulated annealing

  auto calcP = [&](long long oldscore, long long newscore, double T) -> double {
    if (newscore > oldscore) {
      return 1;
    }
    else {
      return exp((double)(newscore - oldscore) / T);
    }
  };

  int K = 1e8;
  double initT = 0.25 * sqr(meanp);
  for (int k = 0; k < K; ++k) {
    double T = initT / log(initT * k + exp(1));

    int action = rnd(4);

    // 1. swap between already assigned pizzas
    if (action == 0) {
      int i1, i2;
      do {
        i1 = rnd(tempp.size());
        i2 = rnd(tempp.size());
      } while (i1 == i2);
      long long oldscore = calcscore(tempp[i1]) + calcscore(tempp[i2]);
      int j1 = rnd(tempp[i1].size());
      int j2 = rnd(tempp[i2].size());
      vector<int> p1 = tempp[i1];
      vector<int> p2 = tempp[i2];
      p1[j1] = tempp[i2][j2];
      p2[j2] = tempp[i1][j1];
      long long newscore = calcscore(p1) + calcscore(p2);

      double prob = calcP(oldscore, newscore, T);
      if (prob > rndf()) {
        tempp[i1] = p1;
        tempp[i2] = p2;
      }
    }

    // 2. reduce team size
    if (action == 1) {
      int i;
      do {
        i = rnd(tempp.size());
      } while (tempp[i].size() == 2);
      int l = 2 + rnd(tempp[i].size() - 2);
      if (tempt[l] < t[l]) {
        vector<int> pi = tempp[i];
        random_shuffle(pi.begin(), pi.end());
        vector<int> u;
        while (pi.size() > l) {
          u.push_back(pi.back());
          pi.pop_back();
        }
        long long oldscore = calcscore(tempp[i]);
        long long newscore = calcscore(pi);
        double prob = calcP(oldscore, newscore, T);
        if (prob > rndf()) {
          tempt[l]++;
          tempt[tempp[i].size()]--;
          tempp[i] = pi;
          for (int ui : u) {
            unused.push_back(ui);
          }
        }
      }
    }

    // 3. increase team size
    if (action == 2) {
      for (int s = 2; s <= 3; ++s) {
        if (tempt[s] == 0) continue;
        if (tempt[s + 1] == t[s + 1]) continue;
        if (unused.empty()) continue;
        int i;
        do {
          i = rnd(tempp.size());
        } while (tempp[i].size() != s);
        vector<int> p = tempp[i];
        int x = rnd(unused.size());
        p.push_back(unused[x]);
        long long oldscore = calcscore(tempp[i]);
        long long newscore = calcscore(p);
        double prob = calcP(oldscore, newscore, T);
        if (prob > rndf()) {
          tempt[s + 1]++;
          tempt[s]--;
          tempp[i] = p;
          unused[x] = unused.back();
          unused.pop_back();
        }
      }
    }

    // 4. swap between used and unused pizza
    if (action == 3) {
      if (!unused.empty()) {
        int i = rnd(tempp.size());
        int j = rnd(tempp[i].size());
        int ip = rnd(unused.size());

        vector<int> pi = tempp[i];
        pi[j] = unused[ip];
        long long oldscore = calcscore(tempp[i]);
        long long newscore = calcscore(pi);

        double prob = calcP(oldscore, newscore, T);
        if (prob > rndf()) {
          unused[ip] = tempp[i][j];
          tempp[i] = pi;
        }
      }
    }

    // 5. always form new teams when possible
    for (int s = 4; s >= 2; --s) {
      while (unused.size() >= s) {
        if (tempt[s] == t[s]) break;
        vector<int> pi;
        for (int i = 0; i < s; ++i) {
          int ui = rnd(unused.size());
          pi.push_back(unused[ui]);
          unused[ui] = unused.back();
          unused.pop_back();
        }
        tempt[s]++;
        tempp.push_back(pi);
      }
    }

    if ((k + 1) % 10000 == 0) {
      debug("ITER %d (T = %.8lf): %lld\n", k + 1, T, calcscore(tempp));
    }
  }

  printf("%d\n", tempp.size());
  for (auto pi : tempp) {
    printf("%d", pi.size());
    for (auto i : pi) {
      printf(" %d", i);
    }
    printf("\n");
  }
}