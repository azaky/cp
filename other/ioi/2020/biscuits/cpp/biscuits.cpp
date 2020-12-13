#include "biscuits.h"

#include <cstdio>

long long count_tastiness(long long x, std::vector<long long> a) {
	long long ans = 1;
	long long sum = 0;
	std::vector<long long> s;
	s.push_back(1);
	for (int i = 0; i < 62; ++i) {
		if (i < a.size()) sum += a[i] << i;

		long long lim = sum / x;
		if (lim > (1LL << (i+1)) - 1) {
			ans <<= 1;
			// printf("s[%d] = %lld\n", i, ans);
			s.push_back(ans);
			continue;
		}
		if (lim < (1LL << i)) {
			// printf("s[%d] = %lld\n", i, ans);
			s.push_back(ans);
			continue;
		}
		// printf("lim = %lld\n", lim);
		lim -= ((1LL << i) - 1);
		long long cans = 0;
		for (int j = i; j >= 0; j--) {
			if (lim >= (1LL << j)) {
				lim -= (1LL << j);
				cans += s[j];
			}
		}
		ans += cans;
		// printf("s[%d] = %lld\n", i, ans);
		s.push_back(ans);
	}
	return ans;
}

