#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, s;

vector<int> parent;
 
void initialize_set(int n) {
    parent = vector<int>(n);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}
// parent[i] = find_set(parent[i]) is for this part
// Then once it finds the main representative item (e.g. if is equal to 'x') we make parent[i] = 'x'
// this to make the subsequent calls of find_set(i) be in O(1)
int find_set(int i) {
    return parent[i] == i ? i : (parent[i] = find_set(parent[i]));
}
 
bool equal(int x, int y) {
    return find_set(x) == find_set(y);
}
 
void join_set(int x, int y) {
    parent[find_set(x)] = find_set(y);
}

int main () {
	scanf ("%d", &t);
	
	while (t --) {
		int x[111], y[111], used[111] = {0}, size[111], ans = 0;
		scanf ("%d %d", &n, &s);
		initialize_set(n);
		
		for (int i = 0; i < n; i ++) {
			scanf ("%d %d", &x[i], &y[i]);
			for (int j = 0; j < i; j ++)

				if (abs(x[i]-x[j]) < s && abs(y[i]-y[j]) < s){
					join_set (i, j);
				}

/*
				if ((x[i] <= x[j] && y[i] <= y[j] && x[i] + s > x[j] && y[i] + s >  y[j]) || (x[j] <= x[i] && y[j] <= y[i] && x[j] + s >  x[i] && y[j] + s >  y[i])) {
					join_set (i, j);
				}
*/
		}
/*
		for (int i = 0; i < n; ++i) size[i] = 0;
		for (int i = 0; i < n; ++i) size[find_set(i)]++;
		ans = *max_element(size,size+n);
*/

		for (int i = 0; i < n; i ++) {
			if (!used[i]) {
				used[i] = 1;
				int count = 1;
				for (int j = i + 1; j < n; j ++)
					if (!used[j] && equal (i, j)) {
						used[j] = 1;
						count ++;
					}
				if (ans < count) ans = count;
			}
		}

		printf ("%d\n", ans);
	}
	
	return 0;
}
