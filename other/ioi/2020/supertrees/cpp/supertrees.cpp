#include "supertrees.h"
#include <vector>
#include <set>

bool valid;
int n;
std::vector<std::vector<int>> p, answer;
std::vector<int> c;

void dfs(int v, int cn) {
	c[v] = cn;
	for (int i = 0; i < n; i++) {
		if (c[i] == 0 && p[v][i]) {
			dfs(i, cn);
		}
	}
}

class DSU {
public:
  DSU(int n): p(std::vector<int>(n)), n(n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
  }

  void mergeSet(int x, int y) {
    p[findSet(x)] = findSet(y);
  }

  bool isSameSet(int x, int y) {
    return findSet(x) == findSet(y);
  }

private:
  std::vector<int> p;
  int n;
};


void solve(std::vector<int> &t) {
	int k = t.size();
	DSU dsu(k);

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < i; ++j) {
			if (p[t[i]][t[j]] == 1) {
				dsu.mergeSet(i, j);
			} else if (p[t[i]][t[j]] != 2) {
				valid = false;
				return;
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < i; ++j) {
			if (dsu.isSameSet(i, j) && p[t[i]][t[j]] != 1) {
				valid = false;
				return;
			}
		}
	}

	std::vector<int> cycle;
	for (int i = 0; i < k; ++i) {
		int ds = dsu.findSet(i);
		if (ds == i) {
			cycle.push_back(i);
		} else {
			answer[t[i]][t[ds]] = 1;
			answer[t[ds]][t[i]] = 1;
		}
	}
	if (cycle.size() == 2) {
		valid = false;
		return;
	}
	if (cycle.size() > 2) {
		for (int i = 0; i < (int)cycle.size(); i++) {
			answer[t[cycle[i]]][t[cycle[(i+1)%cycle.size()]]] = 1;
			answer[t[cycle[(i+1)%cycle.size()]]][t[cycle[i]]] = 1;
		}
	}
}

int construct(std::vector<std::vector<int>> _p) {
	p = _p;
	valid = true;
	n = p.size();
	c.resize(n, 0);
	answer.clear();
	for (int i = 0; i < n; i++) {
		std::vector<int> row;
		row.resize(n);
		answer.push_back(row);
	}

	int cn = 0;
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		dfs(i, ++cn);

		std::vector<int> t;
		for (int j = 0; j < n; ++j) {
			if (c[j] == cn) t.push_back(j);
		}
		solve(t);
		if (!valid) return 0;
	}

	build(answer);
	return 1;
}
