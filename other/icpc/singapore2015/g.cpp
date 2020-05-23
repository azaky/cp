#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 3300

int n, a[MAXN], dp[MAXN][MAXN], p[MAXN];
vector<pair<int, long long> > s[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int r = 1; r <= n; ++r) {
		long long sum = 0;
		for (int l = r; l > 0; --l) {
			sum += (long long)a[l];
			if (l == 1) {
				dp[l][r] = 1;
			} else if (sum < s[l - 1][p[l - 1]].second) {
				dp[l][r] = -MAXN;
			} else {
				while (p[l - 1] < s[l - 1].size() && sum >= s[l - 1][p[l - 1]].second) {
					p[l - 1]++;
				}
				p[l - 1]--;
				dp[l][r] = 1 + s[l - 1][p[l - 1]].first;
			}
			if (s[r].empty() || s[r].back().first < dp[l][r]) {
				s[r].push_back(make_pair(dp[l][r], sum));
			}
		}
		p[r] = 0;
	}

	int ans = 1;
	for (int l = 1; l <= n; ++l) {
		ans = min(ans, dp[l][n]);
	}
	printf("%d\n", ans);

	return 0;
}