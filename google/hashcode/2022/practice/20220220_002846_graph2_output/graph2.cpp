#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> id;
vector<string> ingredients;
vector<pair<set<int>, set<int>>> pizza(n);

int validate(set<int> ans) {
  int served = 0;
  for (int i = 0; i < n; ++i) {
    bool valid = true;
    for (auto j : pizza[i].first) {
      if (!ans.count(j)) {
        valid = false;
        break;
      }
    }
    for (auto j : pizza[i].second) {
      if (ans.count(j)) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ++served;
    }
  }
  return served;
}

int main() {
  srand(1);

  scanf("%d", &n);

  pizza.resize(n);

  auto getId = [&](const string& s) -> int {
    if (id.count(s)) return id[s];
    id[s] = ingredients.size();
    ingredients.push_back(s);
    return id[s];
  };

  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      static char buffer[100];
      scanf("%s", buffer);
      pizza[i].first.insert(getId(buffer));
    }
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      static char buffer[100];
      scanf("%s", buffer);
      pizza[i].second.insert(getId(buffer));
    }
  }

  fprintf(stderr, "#customers = %d\n", n);
  fprintf(stderr, "#ingredients: %lu\n", ingredients.size());

  vector<vector<int>> hatedAdj(ingredients.size());
  vector<vector<int>> likedAdj(ingredients.size());
  for (int i = 0; i < pizza.size(); ++i) {
    for (auto j : pizza[i].first) {
      likedAdj[j].push_back(i);
    }
    for (auto j : pizza[i].second) {
      hatedAdj[j].push_back(i);
    }
  }
  set<pair<int, int>> edges;
  for (int i = 0; i < ingredients.size(); ++i) {
    for (int like : likedAdj[i]) {
      for (int hate : hatedAdj[i]) {
        if (like != hate) {
          edges.insert(make_pair(hate, like));
          edges.insert(make_pair(like, hate));
        }
      }
    }
  }
  fprintf(stderr, "#edges: %lu\n", edges.size());
  if (edges.size() < 100) {
    for (auto e : edges) {
      fprintf(stderr, "\t%d->%d\n", e.first, e.second);
    }
  }

  // Maximum Independent Set approximation:
  // Select node with lowest degree, and remove all neighbors from it.

  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for (auto e : edges) {
    adj[e.first].push_back(e.second);
    ++deg[e.first];
  }

  vector<int> byDeg;
  {
    set<int> processed;
    set<pair<int,int>> vdeg;
    for (int i = 0; i < n; ++i) {
      vdeg.insert(make_pair(deg[i], i));
    }
    for (auto it = vdeg.begin(); it != vdeg.end();) {
      int v = it->second;
      byDeg.push_back(v);
      vdeg.erase(it);
      for (int u : adj[v]) {
        if (!processed.count(u)) {
          // Erase u from v's neighbors.
          assert(vdeg.erase(make_pair(deg[u], u)));
          byDeg.push_back(u);
          processed.insert(u);
          for (int w : adj[u]) {
            assert(vdeg.erase(make_pair(deg[w], w)));
            --deg[w];
            vdeg.insert(make_pair(deg[w], w));
          }
        }
      }
      it = vdeg.begin();
      processed.insert(v);
    }
    assert(byDeg.size() == n);
  }
  // for (int i = 0; i < n; ++i) {
  //   byDeg.push_back(i);
  // }
  // sort(byDeg.begin(), byDeg.end(), [&](int a, int b) {
  //   if (deg[a] != deg[b]) {
  //     return deg[a] < deg[b];
  //   }
  //   return deg2[a] > deg2[b];
  // });
  set<int> deleted;
  set<int> served;
  for (int v : byDeg) {
    if (deleted.count(v)) continue;
    served.insert(v);
    for (int u : adj[v]) {
      deleted.insert(u);
    }
  }
  for (int i = 0; i < n; ++i) {
    assert(served.count(i) ^ deleted.count(i));
  }
  set<int> ans;
  for (int v : served) {
    for (int i : pizza[v].first) {
      ans.insert(i);
    }
  }

  fprintf(stderr, "Initial:\n");
  fprintf(stderr, "Best served: %lu\n", served.size());
  fprintf(stderr, "served: %d\n", validate(ans));

  // Gradient descent?
  // How?
  for (int iteration = 0; iteration < 10; ++iteration) {
    int totalImprovements = 0;
    for (int v : byDeg) {
      if (!deleted.count(v)) continue;
      // Force use v.
      set<int> newAns = ans;
      set<int> newDeleted;
      for (int i : pizza[v].first) {
        newAns.insert(i);
        for (int j : hatedAdj[i]) {
          if (!deleted.count(j)) {
            newDeleted.insert(j);
          }
        }
      }
      for (int i : pizza[v].second) {
        newAns.erase(i);
        for (int j : likedAdj[i]) {
          if (!deleted.count(j)) {
            newDeleted.insert(j);
          }
        }
      }
      set<int> newServed;
      for (int u : deleted) {
        bool valid = true;
        for (int i : pizza[u].first) {
          if (!newAns.count(i)) {
            valid = false;
            break;
          }
        }
        if (valid) {
          for (int i : pizza[u].second) {
            if (newAns.count(i)) {
              valid = false;
              break;
            }
          }
        }
        if (valid) {
          newServed.insert(u);
        }
      }
      assert(newServed.count(v));
      if (newServed.size() > newDeleted.size()) {
        fprintf(stderr, "Forcing %d: Improved by %d\n", v, (int)newServed.size() - (int)newDeleted.size());
        totalImprovements += (int)newServed.size() - (int)newDeleted.size();
        ans = newAns;
        for (int u : newServed) {
          assert(!served.count(u));
          assert(deleted.count(u));
          served.insert(u);
          deleted.erase(u);
        }
        for (int u : newDeleted) {
          assert(served.count(u));
          assert(!deleted.count(u));
          deleted.insert(u);
          served.erase(u);
        }
      }
    }
    fprintf(stderr, "Iteration %d: %d improvements\n", iteration, totalImprovements);
    if (totalImprovements == 0) break;
  }

  fprintf(stderr, "served: %d\n", validate(ans));

  printf("%lu", ans.size());
  for (auto i : ans) {
    printf(" %s", ingredients[i].c_str());
  }
  printf("\n");

  return 0;
}