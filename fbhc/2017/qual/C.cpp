#include <bits/stdc++.h>
using namespace std;

#define MAXS 500

int ntc, h, n, x, y, d;
char buffer[20];
double p[2][MAXS];

int main () {
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		scanf("%d%d", &h, &n);
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", buffer);
			char c;
			if (sscanf(buffer, "%dd%d%[-+]%d", &x, &y, &c, &d) != 4) {
				sscanf(buffer, "%dd%d", &x, &y);
				d = 0;
			} else {
				if (c == '-') {
					d *= -1;
				}
			}

			int state = 0, maks = x * y;
			p[state][0] = 1;
			for (int j = 1; j <= maks; ++j) {
				p[state][j] = 0;
			}

			for (int j = 0; j < x; ++j) {
				for (int k = 0; k <= maks; ++k) {
					p[1 - state][k] = 0;
				}
				for (int k = 1; k <= maks; ++k) {
					for (int l = 1; l <= k && l <= y; ++l) {
						p[1 - state][k] += p[state][k - l] / y;
					}
				}
				state = 1 - state;
			}

			double totalp = 0;
			for (int j = 0; j <= maks; ++j) {
				if (j + d >= h) {
					totalp += p[state][j];
				}
			}
			ans = max(ans, totalp);
		}

		printf("Case #%d: %.17lf\n", itc, ans);
	}
	
	return 0;
}