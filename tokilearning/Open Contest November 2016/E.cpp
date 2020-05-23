#include <bits/stdc++.h>
using namespace std;

#define sejuta 1000000

bool prime[sejuta + 5];
int a[sejuta + 5], n;
long long k;

bool cmp(int a, int b) {
	if (prime[a] && prime[b]) return a < b;
	else if (prime[a] ^ prime[b]) return prime[b];
	else return a < b;
}

int main () {
	for (int i = 1; i <= sejuta; ++i) {
		prime[i] = true;
	}
	prime[1] = false;
	for (int i = 2; i * i <= sejuta; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= sejuta; j += i) {
				prime[j] = false;
			}
		}
	}

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n, cmp);
	int ans = 0;
	for (int t = 0; t < n; ++t) {
		if (a[t] <= k) {
			ans++;
			k -= a[t];
		}
		if (prime[a[t]]) {
			break;
		}
	}
	if (ans == n) {
		puts("One Punch!");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}