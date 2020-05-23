#include <bits/stdc++.h>
using namespace std;

#define MAXN 20200

int ntc;
char s[MAXN];

int main() {
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i) {
			s[i + n] = s[i];
		}
		int ans = 0;
		int p = 1;
		while (p < n) {
			int i = 0;
			while (i < n && s[ans + i] == s[p + i]) {
				i++;
			}
			if (i == n) break;
			if (s[ans + i] > s[p + i]) {
				ans = p++;
			} else {
				p += i + 1;
			}
		}
		printf("%d\n", ans + 1);
	}

	return 0;
}
