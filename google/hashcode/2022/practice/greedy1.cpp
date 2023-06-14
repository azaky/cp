#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> id;
vector<string> ingredients;
vector<pair<set<int>, set<int>>> pizza(n);

int validate(vector<int> ans) {
  int served = 0;
  set<int> used(ans.begin(), ans.end());
  for (int i = 0; i < n; ++i) {
    bool valid = true;
    for (auto j : pizza[i].first) {
      if (!used.count(j)) {
        valid = false;
        break;
      }
    }
    for (auto j : pizza[i].second) {
      if (used.count(j)) {
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

  // Greedy 1: We sort ingredients fromt he least hated ones.
  // Then, we add ingredients one by one.
  // At each stage, we check how many customers we can serve,
  // and save the best state so far.

  map<int, int> hated;
  for (auto p : pizza) {
    for (auto i : p.second) hated[i]++;
  }

  vector<int> hing;
  for (int i = 0; i < ingredients.size(); ++i) {
    hing.push_back(i);
  }
  sort(hing.begin(), hing.end(), [&](int i, int j) {
    return hated[i] < hated[j];
    });

  vector<int> bestAns;
  int bestServed = 0;

  set<int> u;
  for (int i = 0; i < n; ++i) {
    u.insert(i);
  }

  set<int> hasIng;
  vector<int> currentIng;

  for (int i = 0; i < hing.size(); ++i) {
    hasIng.insert(hing[i]);
    currentIng.push_back(hing[i]);

    set<int> toBeErased;

    for (auto j : hatedAdj[hing[i]]) {
      if (u.count(j)) {
        toBeErased.insert(j);
      }
    }

    int currentServed = 0;
    for (auto v : u) {
      if (toBeErased.count(v)) continue;
      bool served = true;
      for (auto i : pizza[v].first) {
        if (!hasIng.count(i)) {
          served = false;
          break;
        }
      }
      if (served) {
        currentServed++;
      }
    }
    if (currentServed > bestServed) {
      bestServed = currentServed;
      bestAns = currentIng;
      for (auto v : toBeErased) {
        u.erase(v);
      }
      // fprintf(stderr, "Using %lu ingredients: %d\n", currentIng.size(), bestServed);
    }
    else {
      currentIng.pop_back();
      hasIng.erase(hing[i]);
    }
  }

  fprintf(stderr, "Best served: %d\n", bestServed);
  fprintf(stderr, "served: %d\n", validate(bestAns));

  printf("%lu", bestAns.size());
  for (auto i : bestAns) {
    printf(" %s", ingredients[i].c_str());
  }
  printf("\n");

  return 0;
}