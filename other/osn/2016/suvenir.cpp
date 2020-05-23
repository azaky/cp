#include <bits/stdc++.h>
using namespace std;

#define expect(expr, value) if (expr != (value)) exit(1);

char subtask[10];

int n, a[2000005], visited[2000005];
vector<pair<int, int> > cache;

bool possible(int x) {
	cache.clear();
	bool first = false;
	int size = 0;
	for (int i = 0; i < n; ++i) {
		while (visited[a[i]] && size > 0) {
			visited[a[i - size]] = 0;
			size--;
		}
		visited[a[i]] = 1;
		size++;
		if (size == x) {
			for (int j = 0; j < size; ++j) {
				visited[a[i - j]] = 0;
			}
			cache.push_back(make_pair(i - size + 2, i + 1));
			if (first) {
				return true;
			} else {
				first = true;
				size = 0;
			}
		}
	}
	for (int i = 0; i < size; ++i) {
		visited[a[n - 1 - i]] = 0;
	}
	return false;
}

int main() {
	expect(scanf("%s", subtask), 1);
	expect(scanf("%d", &n), 1);
	for (int i = 0; i < n; ++i) {
		expect(scanf("%d", &a[i]), 1);
	}

	int l = 1, r = n / 2;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (possible(m)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	expect(l, r);

	expect(possible(l), true);
	printf("%d %d %d %d\n", cache[0].first, cache[0].second, cache[1].first, cache[1].second);

	return 0;
}