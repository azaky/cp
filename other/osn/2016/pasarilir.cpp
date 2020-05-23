#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

char subtask[10];
int n, m, q, g[36][36];
long long a[100000], b[100000];
int ncosts;
long long costs[1262816];

void walk(int r, int c, long long v, long long cost) {
	if (r < 0 || c < 0 || r == n || c == m) {
		return;
	}
	long long rc = r * m + c;
	if ((v & (1LL << rc))) {
		return;
	}
	v |= (1LL << rc);
	cost += g[r][c];
	if (r == n - 1 && c == m - 1) {
		costs[ncosts++] = cost;
	} else {
		walk(r + 1, c, v, cost);
		walk(r - 1, c, v, cost);
		walk(r, c + 1, v, cost);
		walk(r, c - 1, v, cost);
	}
}

void answerQueries_smart() {
	sort(costs, costs + ncosts);
	for (int i = 0; i < q; ++i) {
		int ans = upper_bound(costs, costs + ncosts, b[i]) - lower_bound(costs, costs + ncosts, a[i]);
		printf("%d\n", ans);
	}
}

void answerQueries_bruteForce() {
	for (int i = 0; i < q; ++i) {
		int ans = 0;
		for (int j = 0; j < ncosts; ++j) {
			if (a[i] <= costs[j] && costs[j] <= b[i]) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d", &n, &m), 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			expect(scanf("%d", &g[i][j]), 1);
		}
	}
	expect(scanf("%d", &q), 1);
	for (int i = 0; i < q; ++i) {
		expect(scanf("%lld%lld", &a[i], &b[i]), 2);
	}

	ncosts = 0;
	walk(0, 0, 0, 0);

	answerQueries_bruteForce();

	return 0;
}