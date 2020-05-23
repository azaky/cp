#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

#define MAXN 2000
#define MAXK 100000

char subtask[10];
int n, m, k, q;
char a[MAXN + 5][MAXN + 5];
int irempek[MAXN + 5][MAXN + 5], nrempek;
int bestDistance[MAXN + 5][MAXN + 5], visited[MAXK + 5], closest[MAXN + 5][MAXN + 5];
pair<int, int> rempek[MAXK + 5], finish[MAXK + 5];
queue<pair<int, int> > qBFS;

bool isOutOfBounds(int r, int c) {
	return r < 0 || c < 0 || r >= n || c >= m;
}

void addToQueue(int r, int c, int _distance, int x) {
	if (isOutOfBounds(r, c)) {
		return;
	}
	if (bestDistance[r][c] < _distance) {
		return;
	} else if (bestDistance[r][c] == _distance && !(x != -1 && closest[r][c] == x)) {
		closest[r][c] = -1;
	} else {
		closest[r][c] = x;
		bestDistance[r][c] = _distance;
		qBFS.push(make_pair(r, c));
	}
}

pair<int, int> dfs(int x) {
	if (visited[x] == 1) {
		return finish[x];
	}
	if (visited[x] == -1) {
		return rempek[x];
	}

	visited[x] = -1;
	int r = rempek[x].first, c = rempek[x].second;
	if (closest[r][c] == -1) {
		return finish[x] = rempek[x];
	} else {
		pair<int, int> nextFinish = dfs(closest[r][c]);
		int idx = irempek[nextFinish.first][nextFinish.second];
		if (idx == -1) {
			return finish[x] = nextFinish;
		} else {
			if (visited[idx] == -1) {
				return finish[x] = rempek[idx];
			} else {
				return finish[x] = nextFinish;
			}
		}
	}
}

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d%d%d", &n, &m, &k, &q), 4);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			closest[i][j] = -1;
			irempek[i][j] = -1;
			bestDistance[i][j] = 100000;
		}
	}
	for (int i = 0; i < n; ++i) {
		expect(scanf("%s", a[i]), 1);
		expect(strlen(a[i]), m);
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X') {
				irempek[i][j] = nrempek;
				rempek[nrempek++] = make_pair(i, j);
			}
		}
	}

	for (int i = 0; i < nrempek; ++i) {
		addToQueue(rempek[i].first, rempek[i].second, 0, i);
	}

	while (!qBFS.empty()) {
		pair<int, int> top = qBFS.front(); qBFS.pop();
		int r = top.first, c = top.second;
		int currentDistance = bestDistance[r][c];
		int currentClosest = closest[r][c];
		addToQueue(r + 1, c, currentDistance + 1, currentClosest);
		addToQueue(r - 1, c, currentDistance + 1, currentClosest);
		addToQueue(r, c + 1, currentDistance + 1, currentClosest);
		addToQueue(r, c - 1, currentDistance + 1, currentClosest);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%3d", closest[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < nrempek; ++i) {
		int r = rempek[i].first, c = rempek[i].second;
		closest[r][c] = i;
		int bestRempekDistance = 100000;
		for (int dir = 0; dir < 4; ++dir) {
			int nextr = r + 2 * ((dir >> 1) & 1) - 1;
			int nextc = c + 2 * (dir & 1) - 1;
			if (!isOutOfBounds(nextr, nextc)) {
				if (irempek[nextr][nextc] != -1) {
					if (bestRempekDistance == 1) {
						closest[r][c] = -1;
					} else {
						bestRempekDistance = bestDistance[r][c] = 1;
						closest[r][c] = irempek[nextr][nextc];
					}
				} else {
					int next = closest[nextr][nextc];
					if (next != -1) {
						int currentDistance = abs(r - rempek[next].first) + abs(c - rempek[next].second);
						if (currentDistance == bestRempekDistance) {
							closest[r][c] = -1;
						} else if (currentDistance < bestRempekDistance) {
							closest[r][c] = next;
							bestDistance[r][c] = currentDistance;
							bestRempekDistance = currentDistance;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%3d", closest[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < nrempek; ++i) {
		dfs(i);
	}
	for (int i = 0; i < nrempek; ++i) {
		printf("#%d: (%d, %d) -> (%d, %d)\n", i, rempek[i].first, rempek[i].second, finish[i].first, finish[i].second);
	}

	for (int i = 0; i < q; ++i) {
		int r, c;
		expect(scanf("%d%d", &r, &c), 2);
		--r, --c;
		int next = closest[r][c];
		if (next == -1) {
			printf("%d %d\n", r + 1, c + 1);
		} else {
			printf("%d %d\n", finish[next].first + 1, finish[next].second + 1);
		}
	}

	return 0;
}