#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

int next[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

vector<string> rom[4];
int n, m;
char a[111][111];

int check(string &s) {
	int n = SZ(s);
	int p = 0;
	int q[5];
	int ans = 0, temp;
	while (p < n && s[p] == 'M') p++;
	q[4] = p;
	if (q[4] > 3) return -1;
	ans += 1000 * q[4];

	while (p < n && (s[p] == 'C' || s[p] == 'D' || s[p] == 'M')) p++;
	q[3] = p;
	temp = find(ALL(rom[3]), s.substr(q[4], q[3] - q[4])) - rom[3].begin();
	if (temp > 9) return -1;
	ans += 100 * temp;

	while (p < n && (s[p] == 'X' || s[p] == 'L' || s[p] == 'C')) p++;
	q[2] = p;
	temp = find(ALL(rom[2]), s.substr(q[3], q[2] - q[3])) - rom[2].begin();
	if (temp > 9) return -1;
	ans += 10 * temp;

	while (p < n && (s[p] == 'I' || s[p] == 'V' || s[p] == 'X')) p++;
	q[1] = p;
	temp = find(ALL(rom[1]), s.substr(q[2], q[1] - q[2])) - rom[1].begin();
	if (temp > 9) return -1;
	ans += temp;

	if (q[1] != n) return -1;
	
	return ans;
}

int main(){
	rom[1].PB("");
	rom[1].PB("I");
	rom[1].PB("II");
	rom[1].PB("III");
	rom[1].PB("IV");
	rom[1].PB("V");
	rom[1].PB("VI");
	rom[1].PB("VII");
	rom[1].PB("VIII");
	rom[1].PB("IX");
	
	rom[2].PB("");
	rom[2].PB("X");
	rom[2].PB("XX");
	rom[2].PB("XXX");
	rom[2].PB("XL");
	rom[2].PB("L");
	rom[2].PB("LX");
	rom[2].PB("LXX");
	rom[2].PB("LXXX");
	rom[2].PB("XC");
	
	rom[3].PB("");
	rom[3].PB("C");
	rom[3].PB("CC");
	rom[3].PB("CCC");
	rom[3].PB("CD");
	rom[3].PB("D");
	rom[3].PB("DC");
	rom[3].PB("DCC");
	rom[3].PB("DCCC");
	rom[3].PB("CM");
	
	scanf("%d%d", &n, &m);
	REP(i, n) {
		scanf("%s", a[i]);
	}
	// usual BFS?
	queue<pair<vector<pii>, string> > q;
	REP(i, n) {
		vector<pii> x;
		x.PB(MP(i, 0));
		string y = ""; y += a[i][0];
		q.push(MP(x, y));
	}
	int ans = 4000;
	string sans;
	while (!q.empty()) {
		pair<vector<pii>, string> f = q.front();
		q.pop();
		
		vector<pii> x = f.A;
		string y = f.B;
		
		// to four directions
		REP(d, 4) {
			pii t = MP(x.back().A + next[d][0], x.back().B + next[d][1]);
			if (t.A < 0 || t.A == n || t.B < 0 || t.B == m) continue;
			bool seen = false;
			FORIT(it, x) {
				if (it->A == t.A && it->B == t.B) {
					seen = true;
					break;
				}
			}
			if (seen) continue;
			string yy = y + a[t.A][t.B];
			int temp = check(yy);
			if (temp == -1) continue;
			if (t.B == m-1) {
				MN(ans, temp);
				sans = yy;
				continue;
			}
			vector<pii> xx = x;
			xx.PB(t);
			q.push(MP(xx, yy));
		}
	}
	if (ans == 4000) {
		puts("NO");
	}
	else {
		printf("%s\n", sans.c_str());
	}
	
	return 0;
}
