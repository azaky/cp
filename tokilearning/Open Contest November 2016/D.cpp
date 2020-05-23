#include <bits/stdc++.h>
using namespace std;

int n;
char result[100];

int main () {
	scanf("%d", &n);
	int s = 0, g = 0;
	int balance = 0;
	for (int i = 1; i <= n; ++i) {
		if (balance == 0) {
			printf("%d SAITAMA\n", i);
			fflush(stdout);
			scanf("%s", result);
			if (strcmp(result, "SAITAMA") == 0) {
				s++;
				balance = 1;
			} else if (strcmp(result, "SERI") == 0) {
				g++;
			} else {
				assert(false);
			}
		} else if (balance == 1) {
			printf("%d GENOS\n", i);
			fflush(stdout);
			scanf("%s", result);
			if (strcmp(result, "SAITAMA") == 0) {
				s++;
			} else if (strcmp(result, "SERI") == 0) {
				g++;
				balance = 0;
			} else {
				assert(false);
			}
		} else {
			assert(false);
		}
	}
	printf("%d %d\n", s, g);
	fflush(stdout);

	return 0;
}