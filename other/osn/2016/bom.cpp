#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

char subtask[10], response[10];
int n, t, r;
int nqueries = 0;

bool query(int x) {
	nqueries++;
	printf("%d\n", x);
	fflush(stdout);
	scanf("%s", response);
	if (strcmp(response, "HENING") == 0) {
		return false;
	} else if (strcmp(response, "BIP") == 0) {
		return true;
	} else {
		exit(1);
	}
}

int guess(const vector<int>& values) {
	int m = values.size();
	bool bipped = false;
	int nbip = 0;
	vector<pair<int, bool> > results;
	for (int i = 0; i < m; ++i) {
		bool bip = query(values[i]);
		results.push_back(make_pair(values[i], bip));
		bipped |= bip;
		nbip += bip;
		if (nbip == 2) {
			break;
		}
	}
	for (int i = m - 1; i >= 0; --i) {
		bool bip = query(values[i]);
		results.push_back(make_pair(values[i], bip));
		bipped |= bip;
		nbip += bip;
		if (nbip == 2) {
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		bool bip = query(values[i]);
		results.push_back(make_pair(values[i], bip));
		bipped |= bip;
		nbip += bip;
		if (nbip == 2) {
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (!bipped && results.size() >= m + n) {
			return 0;
		}
		bool bip = query(values[i]);
		results.push_back(make_pair(values[i], bip));
		bipped |= bip;
		nbip += bip;
		if (nbip == 2) {
			break;
		}
	}
	for (int x = 0; x < m; ++x) {
		for (int k = 0; k < n; ++k) {
			bool valid = true;
			for (int i = 0; i < k; ++i) {
				if (results[i].second) {
					valid = false;
				}
			}
			for (int i = 0; i + k < results.size() && valid; ++i) {
				if (results[i].first == values[x]) {
					valid = results[i + k].second;
				} else {
					valid = !results[i + k].second;
				}
			}
			if (valid) {
				return values[x];
			}
		}
	}
	return 0;
}


void firstHalf() {
	vector<int> values;
	for (int i = 0; i < n / 2; ++i) {
		values.push_back(i + 1);
	}
	int ans = guess(values);
	if (ans) {
		while (nqueries < t) {
			query(ans);
		}
		exit(0);
	}
}

void secondHalf() {
	vector<int> values;
	for (int i = n / 2; i < (n / 2) * 2; ++i) {
		values.push_back(i + 1);
	}
	int ans = guess(values);
	if (ans) {
		while (nqueries < t) {
			query(ans);
		}
		exit(0);
	}
}

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d%d%d", &n, &t, &r), 3);

	firstHalf();
	secondHalf();

	while (nqueries < t) {
		query(n);
	}

	return 0;
}