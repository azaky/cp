#include "dna.h"

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sum;

int geti(char c) {
	return string("ACT").find(c);
}

void init(string A, string B) {
	int n = A.size();

	sum.resize(n+1);
	sum[0] = vector<int>(9, 0);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1];
		sum[i][geti(A[i - 1]) * 3 + geti(B[i - 1])]++;
	}
}

int get_distance(int x, int y) {
	vector<int> c(9);
	for (int i = 0; i < 9; ++i) c[i] = sum[y+1][i] - sum[x][i];

	if (c[1] + c[2] == c[3] + c[6] &&
			c[1] + c[7] == c[3] + c[5] &&
			c[2] + c[5] == c[6] + c[7]) {
		return min(c[1], c[3]) + min(c[2], c[6]) + min(c[5], c[7]) + 2 * abs(c[1] - c[3]);
	}

	return -1;
}
