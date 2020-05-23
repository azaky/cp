#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n, a[MAXN], ql[MAXN], qr[MAXN], nq, ans[MAXN];
vector<int> p[MAXN], q[MAXN];
int bit[MAXN];

void update(int k, int v) {
	for (int x = k; x <= n; x += (x & -x)) {
		bit[x] += v;
	}
}

int query(int k) {
	int sum = 0;
	for (int x = k; x > 0; x -= (x & -x)) {
		sum += bit[x];
	}
	return sum;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<int> s;
	for (int i = 1; i <= n; ++i) {
		for (int j = s.size() - 1; j >= 0; --j) {
			if (a[s[j]] > a[i]) {
				p[i].push_back(s[j]);
				s.pop_back();
			} else {
				p[i].push_back(s[j]);
				break;
			}
		}
		s.push_back(i);
	}
	scanf("%d", &nq);
	for (int i = 0; i < nq; ++i) {
		scanf("%d%d", &ql[i], &qr[i]);
		q[qr[i]].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		for (auto x : p[i]) {
			update(x, +1);
		}
		for (auto x : q[i]) {
			ans[x] = query(i) - query(ql[x] - 1);
		}
	}
	for (int i = 0; i < nq; ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
