/*
ID: a_zaky01
PROG: combo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[3], b[3];

int dist(int *a, int *b) {
	int ret = 0;
	for (int i = 0; i < 3; ++i) {
		int d = min(abs(a[i] - b[i]), n - abs(a[i] - b[i]));
		ret = max(ret, d);
	}
	return ret;
}

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &b[i]);
	}
	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int z = 0; z < n; ++z) {
				int c[3];
				c[0] = x; c[1] = y; c[2] = z;
				if (dist(a, c) <= 2 || dist(b, c) <= 2) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}