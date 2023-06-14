#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(1);

  int n;
  scanf("%d", &n);

  map<string, int> id;
  vector<string> ingredients;

  auto getId = [&](const string &s) -> int {
    if (id.count(s)) return id[s];
    id[s] = ingredients.size();
    ingredients.push_back(s);
    return id[s];
  };

  vector<pair<vector<int>,vector<int>>> pizza(n);

  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      static char buffer[100];
      scanf("%s", buffer);
      pizza[i].first.push_back(getId(buffer));
    }
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      static char buffer[100];
      scanf("%s", buffer);
      pizza[i].second.push_back(getId(buffer));
    }
  }

  // random + greedy?
  random_shuffle(pizza.begin(), pizza.end());

  vector<int> ans;
  set<int> used, unused;

  int served = 0;

  for (auto p : pizza) {
    bool valid = true;
    for (auto i : p.first) {
      if (unused.count(i)) {
        valid = false;
        break;
      }
    }
    for (auto i : p.second) {
      if (used.count(i)) {
        valid = false;
        break;
      }
    }
    if (!valid) continue;
    served++;
    for (auto i : p.first) {
      used.insert(i);
    }
    for (auto i : p.second) {
      unused.insert(i);
    }
  }

  fprintf(stderr, "served: %d\n", served);
  printf("%lu", used.size());
  for (auto i : used) {
    printf(" %s", ingredients[i].c_str());
  }
  printf("\n");

  return 0;
}