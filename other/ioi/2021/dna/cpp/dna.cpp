#include "dna.h"

#include <bits/stdc++.h>
using namespace std;

string A, B;
vector<vector<int>> sum;

int geti(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'T') return 2;
	assert(false);
}

void init(string _A, string _B) {
	A = _A; B = _B;
	int n = A.size();

	sum.resize(n+1);
	sum[0] = vector<int>(9, 0);
	for (int i = 1; i <= n; ++i) {
		int a = geti(A[i-1]);
		int b = geti(B[i-1]);

		sum[i] = sum[i-1];
		sum[i][a * 3 + b]++;
	}
}

int brute(string a, string b) {
	int n = a.size();
	int diff = 0;
	vector<int> ca(3), cb(3);
	for (int i = 0; i < n; ++i) {
		ca[geti(a[i])]++;
		cb[geti(b[i])]++;
		if (a[i] != b[i]) diff++;
	}
	if (ca != cb) return -1;
	if (diff == 0) return 0;
	if (diff == 2) return 1;
	if (diff == 3) return 2;
	assert(false);
}

int get_distance(int x, int y) {
	vector<int> cx = sum[x];
	vector<int> cy = sum[y+1];
	vector<int> c = cy;
	for (int i = 0; i < 9; ++i) c[i] -= cx[i];

	// 0 1 2
	// 3 4 5
	// 6 7 8
	int ans = min(c[1], c[3]) + min(c[2], c[6]) + min(c[5], c[7]);
	int ac = abs(c[1] - c[3]);
	int at = abs(c[2] - c[6]);
	int ct = abs(c[5] - c[7]);

	if (c[1] + c[2] == c[3] + c[6] &&
			c[1] + c[7] == c[3] + c[5] &&
			c[2] + c[5] == c[6] + c[7] &&
			ac == at && at == ct) {
		ans += ac + at;
	} else {
		ans = -1;
	}

	return ans;

	string a = A.substr(x, y-x+1);
	string b = B.substr(x, y-x+1);
	int ansbrute = brute(a, b);
	if (ans != ansbrute) {
		fprintf(stderr, "diff at %s %s. got %d, expecting %d\n", a.c_str(), b.c_str(), ans, ansbrute);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				fprintf(stderr, "%d ", c[3*i + j]);
			}
			fprintf(stderr, "\n");
		}
		// assert(false);
	}

	return ans;
}
