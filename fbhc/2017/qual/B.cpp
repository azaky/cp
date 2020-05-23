#include <bits/stdc++.h>
using namespace std;

#define MAXN 111

int ntc, n, a[MAXN];

int main () {
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		reverse(a, a + n);
		int ans = 0, picked = 0;
		for (int p = 0; p < n; ++p) {
			// try to pick a[p] on top
			int need = (50 + a[p] - 1) / a[p];
			if (picked + need > n) {
				// need to put it in previous trip
				// no change in ans
				break;
			} else {
				ans++;
				picked += need;
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}
}