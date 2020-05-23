#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXN 2222

int F[MAXN][MAXN], FC[MAXN][MAXN];
char a[MAXN], b[MAXN];
int k;

int huba (char* a, int k) {
	int n = strlen(a), t = k;
	int ans = FC[n - 1][k];
	for (int i = 1; i < n; ++i) {
		if (a[i] == '1' && t > 0) {
			ans += F[n - i][t - 1];
			ans %= MOD;
		} else {
			t--;
			if (t < 0) break;
		}
	}
	// 1
	if (k == 0) {
		ans = (ans + 1) % MOD;
	}
	return ans;
}

int main () {
	// ignore 1 for first
	vector<int> x;
	x.push_back(1);
	for (int phase = 1; phase <= 2000; ++phase) {
		for (int i = 0; i < x.size(); ++i) {
			F[phase][i] = x[i];
			FC[phase][i] = (FC[phase - 1][i] + F[phase][i]) % MOD;
		}
		vector<int> y = x;
		y.push_back(0);
		for (int i = 0; i < x.size(); ++i) {
			y[i + 1] += x[i];
			y[i + 1] %= MOD;
		}
		x = y;
	}

	scanf("%s%s", b, a);
	scanf("%d", &k);

	// b - 1
	int nb = strlen(b);
	b[nb - 1]--;
	for (int i = nb - 1; i >= 0; --i) {
		if (b[i] < '0') {
			b[i] = '1';
			b[i - 1]--;
		}
	}
	if (b[0] == '0') {
		for (int i = 0; i + 1 < nb; ++i) {
			b[i] = b[i + 1];
		}
		b[nb - 1] = 0;
		nb--;
	}

	int ans = huba(a, k);
	if (nb) {
		ans += MOD - huba(b, k);
		ans %= MOD;
	}
	printf("%d\n", ans);

	return 0;
}