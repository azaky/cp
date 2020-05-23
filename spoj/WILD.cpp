#include <bits/stdc++.h>
using namespace std;

struct Point3D {
	int x, y, z;
	bool operator<(const Point3D &other) {
		return this->x > other.x;
	}
}

int n, m;
Point3D a[1 << 18];



int main(){
	scanf("%d%d", &n, &m);
	if (n == 0 && m == 0) {
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	}
	sort(a, a + n);

	int lastx = m + 1;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i].x;
		ans += 1LL * (lastx - x) * get();

		update(a[i].y, a[i].z);
		while (i + 1 < n && a[i + 1].x == x) {
			++i;
			update(a[i].y, a[i].z);
		}

		lastx = x;
	}
	ans += 1LL * lastx * get();
	printf("%lld\n", ans);

	return main();
}
