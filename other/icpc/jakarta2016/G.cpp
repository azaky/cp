#include <bits/stdc++.h>
using namespace std;

typedef double db;
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)

/* -------------- end of azaky's template -------------- */

#define MAXN 111

int ntc, n, l[MAXN], r[MAXN];
db ih[MAXN], dp[MAXN][MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(i, 0, 100) {
		ih[i] = (db)i * sqrt(i);
	}
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		FOR(i, 1, n) scanf("%d%d", &l[i], &r[i]);

		memset(dp, sizeof(dp), 0);
		dp[1][0] = 1;
		FOR(i, 2, n) {
			int cl = max(l[i], l[i - 1]);
			int cr = min(r[i], r[i - 1]);
			db p = 0;
			if (cl <= cr) {
				p = (db)(cr - cl + 1) / (r[i] - l[i] + 1) / (r[i - 1] - l[i - 1] + 1);
			}
			FOR(j, 0, i - 1) {
				dp[i][j] = 0;
				// differ
				if (j) {
					dp[i][j] += dp[i - 1][j - 1] * (1. - p);
				}
				// same
				dp[i][j] += dp[i - 1][j] * p;
			}
		}
		db w = 0;
		FOR(i, 1, n - 1) {
			w += ih[i] * dp[n][i];
		}
		printf("Case #%d: %.17lf\n", itc, w);
	}
	
	return 0;
}