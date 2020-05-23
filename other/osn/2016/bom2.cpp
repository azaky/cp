#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

char subtask[10], response[10];
int n, t, r;
int nqueries = 0;
vector<int> guesses, results;

int query(int x) {
	nqueries++;
	guesses.push_back(x);
	printf("%d\n", x);
	fflush(stdout);
	scanf("%s", response);
	if (strcmp(response, "HENING") == 0) {
		results.push_back(0);
		return 0;
	} else if (strcmp(response, "BIP") == 0) {
		results.push_back(1);
		return 1;
	} else {
		exit(1);
	}
}


int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d%d", &n, &t, &r), 3);

	int n2 = n / 2;
	vector<int> values;
	for (int i = 1; i <= n2; ++i) {
		values.push_back(i);
	}
	for (int i = n2; i >= 1; --i) {
		values.push_back(i);
	}
	if (n & 1) {
		values.push_back(n);
	}
	for (int i = 1; i <= n2; ++i) {
		values.push_back(i + n2);
	}
	for (int i = n2; i >= 1; --i) {
		values.push_back(i + n2);
	}
	for (int i = 0; i < n; ++i) {
		values.push_back(n);
	}
	
	int nbip = 0;
	for (int i = 0; i < values.size(); ++i) {
		int bip = query(values[i]);
		nbip += bip;
		if (nbip == 2) {
			break;
		}
	}

	int ans = n;
	if (nbip == 2) {
		for (int x = 1; x <= n; ++x) {
			for (int k = 0; k < n; ++k) {
				bool valid = true;
				for (int i = 0; i < k; ++i) {
					if (results[i]) {
						valid = false;
					}
				}
				for (int i = 0; i + k < nqueries && valid; ++i) {
					if (guesses[i] == x) {
						valid = results[i + k];
					} else {
						valid = !results[i + k];
					}
				}
				if (valid) {
					ans = x;
				}
			}
		}
	} else if (nbip != 0) {
		exit(1);
	}

	for (int i = 0; i < 2 * n; ++i) {
		query(ans);
	}

	return 0;
}