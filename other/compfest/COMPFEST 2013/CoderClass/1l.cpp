#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n, d, k;

int main () {
	scanf ("%d", &t);
	
	while (t --) {
		long long arr2[15051] = {0}, arr[15051] = {0}, ans = 0;
		scanf ("%d %d %d", &n, &d, &k);
		for (int i = 0; i < n; i ++) {
			scanf ("%lld", &arr[i]);
			arr2[i] = arr[i];
		}
		for (int i = n - 2; i >= 0; i --) {
			arr2[i] += arr2[i + 1];
			if (i <= n - d - 1) arr2[i] -= arr[i + d];
		}
		sort (arr2, arr2 + n);
		for (int i = n - 1; i > n - k - 1; i --){
			if (arr2[i] < 0) break;
			ans += arr2[i];
		}
		printf ("%lld\n", ans);
	}
	
	return 0;
}
