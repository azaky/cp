#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

#define MOD 1000000007LL

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	} else {
		long long temp = power((a * a) % MOD, b / 2LL);
		if (b & 1) {
			return (temp * a) % MOD;
		} else {
			return temp;
		}
	}
}

char subtask[10];
int n, m, k;
char w[1000005];
long long dp[2][1005];

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d%d", &n, &m, &k), 3);
	expect(scanf("%s", w), 1);

	int s = 0;
	long long ways = power(2LL, n - 1);

	dp[s][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[1 - s][j] = 0;
		}
		// zero
		for (int j = 0; j <= k; ++j) {
			dp[1 - s][j] += dp[s][j] * ways;
			dp[1 - s][j] %= MOD;
		}
		// one
		for (int j = 1; j <= k; ++j) {
			dp[1 - s][j] += dp[s][j - 1] * ways;
			dp[1 - s][j] %= MOD;
		}
		for (int j = 0; j <= k; ++j) {
			dp[s][j] = dp[1 - s][j];
		}
	}
	printf("%lld\n", dp[s][k]);
	
	return 0;
}