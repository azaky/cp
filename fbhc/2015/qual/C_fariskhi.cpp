#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <vector>
using namespace std;

#define ll long long
#define EPS 1e-9
#define INF 2000000000

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define sz(a) a.size()
#define fill(a, b) memset(a, b, sizeof(a))
#define vsort(a) sort(a.begin(), a.end())

#define rep(a, b) for (int a = 0; a < b; a++)
#define forn(a, b, c) for (int a = b; a <= c; a++)
#define ford(a, b, c) for (int a = b; a >= c; a--)

string area[111];
bool flag[105][105][5];

int main() {
	int t;
	scanf("%d", &t);
	forn(i, 1, t) {
		printf("Case #%d: ", i);
		int m, n;
		int sr, sc;
		vector<pair<int, int> > laser;
		scanf("%d %d", &m, &n);
		rep(j, m) {
			cin >> area[j];
			rep(k, area[j].length()) {
				if (area[j][k] == 'S') {
					sr = j;
					sc = k;
				}
				if (area[j][k] == '^' || area[j][k] == 'v' || area[j][k] == '>' || area[j][k] == '<') {
					laser.pb(mp(j, k));
				}
			}
		}
		queue<pair<int, pair<int, pair<int, int> > > > q;
		q.push(mp(0, mp(0, mp(sr, sc))));

		bool first = true;
		int ans = -1;
		rep(j, m) {
			rep(k, n) {
				rep(l, 4) {
					flag[j][k][l] = false;
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().fi;
			int nn = q.front().se.fi;
			int r = q.front().se.se.fi;
			int c = q.front().se.se.se;
			q.pop();
			// printf("%d %d %d %d\n", x, nn, r, c);
			if (!first) {
				if (r < 0 || c < 0 || r >= m || c >= n) continue;
				if (flag[r][c][x]) continue;
				if (area[r][c] != '.' && area[r][c] != 'G' && area[r][c] != 'S') continue;
				flag[r][c][x] = true;


				bool tabrak = false;
				
				rep(j, laser.size()) {
					int rl = laser[j].fi;
					int cl = laser[j].se;
					int mr = 0;
					int mc = 0;
					if (area[rl][cl] == '^') {
						if (x == 0) mr = -1;
						if (x == 1) mc = 1;
						if (x == 2) mr = 1;
						if (x == 3) mc = -1;
					}
					if (area[rl][cl] == '>') {
						if (x == 0) mc = 1;
						if (x == 1) mr = 1;
						if (x == 2) mc = -1;
						if (x == 3) mr = -1;
					}
					if (area[rl][cl] == 'v') {
						if (x == 0) mr = 1;
						if (x == 1) mc = -1;
						if (x == 2) mr = -1;
						if (x == 3) mc = 1;
					}
					if (area[rl][cl] == '<') {
						if (x == 0) mc = -1;
						if (x == 1) mr = -1;
						if (x == 2) mc = 1;
						if (x == 3) mr = 1;
					}
					while (true) {
						rl += mr;
						cl += mc;
						if (rl < 0 || cl < 0 || rl >= m || cl >= n) break;
						if (area[rl][cl] != '.' && area[rl][cl] != 'S' && area[rl][cl] != 'G') break;
						if (rl == r && cl == c) {
							tabrak = true;
							break;
						}
					}
					if (tabrak) break;
				}
				//cout << tabrak << endl;
				if (!tabrak) {
					if (area[r][c] == 'G') {
						ans = nn;
						break;
					}
					//cout << "yeah" << endl;
					q.push(mp((x + 1) % 4, mp(nn + 1, mp(r + 1, c))));
					q.push(mp((x + 1) % 4, mp(nn + 1, mp(r - 1, c))));
					q.push(mp((x + 1) % 4, mp(nn + 1, mp(r, c + 1))));
					q.push(mp((x + 1) % 4, mp(nn + 1, mp(r, c - 1))));
				}
			} else {
				first = false;
				q.push(mp(x + 1, mp(nn + 1, mp(r + 1, c))));
				q.push(mp(x + 1, mp(nn + 1, mp(r, c + 1))));
				q.push(mp(x + 1, mp(nn + 1, mp(r - 1, c))));
				q.push(mp(x + 1, mp(nn + 1, mp(r, c - 1))));
			}

		}
		if (ans == -1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}