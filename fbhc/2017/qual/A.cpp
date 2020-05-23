#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))

const double PI = acos(-1.);

int ntc, p, x, y;

int main () {
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		scanf("%d%d%d", &p, &x, &y);

		// distance should be within 50
		int distanceSquared = sqr(50 - x) + sqr(50 - y);
		// angle should be less than 2 * PI * p / 100
		double angle = -atan2(y - 50, x - 50) + PI / 2 - PI * 2.;
		while (angle < 0) angle += PI * 2.;

		bool isBlack = (distanceSquared <= 2500) && (angle <= PI * p / 50.);
		printf("Case #%d: %s\n", itc, isBlack ? "black" : "white");
	}
}