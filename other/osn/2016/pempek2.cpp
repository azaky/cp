#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(0);

#define MAXN 2000
#define MAXK 100000

char subtask[10];
int n, m, k, q;
char grid[MAXN + 5];
int sum[MAXN * 2 + 5][MAXN * 2 + 5];
int irempek[MAXN + 5][MAXN + 5], nrempek;
int closest[MAXK + 5], finish[MAXK + 5], visited[MAXK + 5];
pair<int, int> rempek[MAXK + 5], originalRempek[MAXK + 5];

int dfs(int x) {
	if (visited[x] == 1) {
		return finish[x];
	}
	if (visited[x] == -1) {
		return x;
	}

	visited[x] = -1;
	int r = rempek[x].first, c = rempek[x].second;
	if (closest[x] == -1) {
		finish[x] = x;
	} else {
		int nextFinish = dfs(closest[x]);
		if (nextFinish == -1) {
			finish[x] = -1;
		} else if (nextFinish == x) {
			finish[x] = closest[x];
		} else {
			finish[x] = nextFinish;
		}
	}
	visited[x] = 1;
	return finish[x];
}

int findArea(int ra, int ca, int rb, int cb) {
	if (ra < 1) {
		ra = 1;
	}
	if (ca < 1) {
		ca = 1;
	}
	if (rb > n) {
		rb = n;
	}
	if (cb > n) {
		cb = n;
	}
	if (ra > rb || ca > cb) {
		return 0;
	}
	return sum[rb][cb] + sum[ra - 1][ca - 1] - sum[ra - 1][cb] - sum[rb][ca - 1];
}

int findClosest(int r, int c) {
	//printf("findClosest(%d, %d)\n", r, c);
	int thisPosition = findArea(r, c, r, c);
	//printf("thisPosition = %d\n", thisPosition);
	int lower = 0, upper = n;
	while (lower < upper) {
		int mid = (lower + upper) / 2;
		int area = findArea(r - mid, c - mid, r + mid, c + mid);
		area -= thisPosition;
		if (area == 0) {
			lower = mid + 1;
		} else {
			upper = mid;
		}
	}
	expect(lower, upper);
	int dist = lower;
	//printf("dist = %d\n", dist);
	if (findArea(r - dist, c - dist, r + dist, c + dist) - thisPosition > 1) {
		//printf("more than 1\n");
		return -1;
	}

	int rlower = r - dist, rupper = r + dist;
	while (rlower < rupper) {
		int mid = (rlower + rupper) / 2;
		int area = findArea(rlower, c - dist, mid, c + dist);
		if (rlower <= r && r <= mid) {
			area -= thisPosition;
		}
		if (area == 0) {
			rlower = mid + 1;
		} else if (area == 1) {
			rupper = mid;
		} else {
			exit(0);
		}
	}
	int clower = c - dist, cupper = c + dist;
	while (clower < cupper) {
		int mid = (clower + cupper) / 2;
		int area = findArea(r - dist, clower, r + dist, mid);
		if (clower <= c && c <= mid) {
			area -= thisPosition;
		}
		if (area == 0) {
			clower = mid + 1;
		} else if (area == 1) {
			cupper = mid;
		} else {
			exit(0);
		}
	}
	expect(rlower, rupper);
	expect(clower, cupper);
	if ((rlower + clower + m) % 2 == 0) {
		int oriR = (rlower + clower - m) / 2;
		int oriC = (rlower - clower + m) / 2;
		if (1 <= oriR && oriR <= n - m && 1 <= oriC && oriC <= m) {
			//printf("closest(%d, %d) = (%d, %d)\n", r, c, oriR, oriC);
			return irempek[oriR][oriC];
		}
	}
	return -1;
}

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d%d%d", &n, &m, &k, &q), 4);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			irempek[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		expect(scanf("%s", grid), 1);
		expect(strlen(grid), m);
		for (int j = 1; j <= m; ++j) {
			if (grid[j - 1] == 'X') {
				int r = i + j, c = i - j + m;
				irempek[i][j] = nrempek;
				originalRempek[nrempek] = make_pair(i, j);
				rempek[nrempek++] = make_pair(r, c);
			}
		}
	}
	n = n + m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int addum = 0;
			if ((i + j + m) % 2 == 0) {
				int r = (i + j - m) / 2;
				int c = (i - j + m) / 2;
				if (r <= (n - m) && r > 0 && c <= m && c > 0) {
					addum = (irempek[r][c] >= 0) ? 1 : 0;
				}
			}
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + addum;
		}
	}

	for (int i = 0; i < nrempek; ++i) {
		closest[i] = findClosest(rempek[i].first, rempek[i].second);
	}

	for (int i = 0; i < nrempek; ++i) {
		dfs(i);
	}

	for (int i = 0; i < q; ++i) {
		int originalR, originalC;
		expect(scanf("%d%d", &originalR, &originalC), 2);
		int r = originalR + originalC;
		int c = originalR - originalC + m;
		int next = findClosest(r, c);
		if (next == -1) {
			printf("%d %d\n", originalR, originalC);
		} else {
			pair<int, int> ans = originalRempek[finish[next]];
			printf("%d %d\n", ans.first, ans.second);
		}
	}

	return 0;
}