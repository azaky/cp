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

#define MAXN 1111

int f[MAXN];
string s[2], h[10];

string rev(string s) {
	string ret = "";
	REPD(i, SZ(s)) ret += 'L' + 'R' - s[i];
	return ret;
}


bool haha(string s, int n);
bool hehe(string s, int n);

bool haha(string s, int n) {
	if (n <= 7) {
		return SZ(s) <= f[n] && h[n].substr(0, SZ(s)) == s;
	}
	return haha(s, 7);
}
bool hehe(string s, int n) {
	if (n <= 7) {
		return SZ(s) <= f[n] && h[n].substr(f[n] - SZ(s), SZ(s)) == s;
	}
	return haha(rev(s), n-1);
}

/*
bool haha(string s, int n) {
	int len = SZ(s);
	bool ret;
	if (n == 0) {
		ret = len == 0;
	}
	else if (f[n] < len) {
		ret = false;
	}
	else if (len <= f[n-1]) {
		ret = haha(s, n-1);
	}
	else {
		if (s[f[n-1]] != 'L') ret = false;
		else ret = haha(s.substr(0, f[n-1]), n-1) && hehe(rev(s.substr(f[n-1]+1, len-f[n-1]-1)), n-1);
	}
	//printf("haha(%s, %d) = %d\n", s.c_str(), n, ret);
	return ret;
}

bool hehe(string s, int n) {
	int len = SZ(s);
	bool ret;
	if (n == 0) {
		ret = len == 0;
	}
	else if (f[n] < len) {
		ret = false;
	}
	else if (len <= f[n-1]) {
		ret = haha(rev(s), n-1);
	}
	else {
		if (s[len-f[n-1]-1] != 'L') ret = false;
		else ret = hehe(s.substr(0, len-f[n-1]-1), n-1) && haha(rev(s.substr(len-f[n-1], f[n-1])), n-1);
	}
	//printf("hehe(%s, %d) = %d\n", s.c_str(), n, ret);
	return ret;
}
*/
bool hoho(int idx, int n) {
	int len = SZ(s[idx]);
	if (n == 0) {
		return len == 0;
	}
	if (f[n] < len) {
		return false;
	}
	if (hoho(idx, n-1)) {
		return true;
	}
	
	//printf("hoho %d\n", n);
	REP(i, len) {
		if (s[idx][i] == 'L') {
			//printf("[%s][%s]\n", s[idx].substr(0, i).c_str(), s[1-idx].substr(0, len-i-1).c_str());
			if (hehe(s[idx].substr(0, i), n-1) && hehe(s[1-idx].substr(0, len-i-1), n-1)) {
				return true;
			}
		}
	}
	return false;
}

int main(){
	f[1] = 1;
	FOR(i, 2, 1000) {
		f[i] = 2*f[i-1] + 1;
		if (f[i] > MAXN) f[i] = MAXN;
	}
	
	h[1] = "L";
	FOR(i, 2, 7) h[i] = h[i-1] + "L" + rev(h[i-1]);
	
	int ntc, n;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		cin >> n >> s[0];
		s[1] = rev(s[0]);
		
		if (hoho(0, n) || (n > 1 && hoho(1, n-1))) {
			printf("Case %d: Yes\n", itc);
		}
		else {
			printf("Case %d: No\n", itc);
		}
	}
	
	return 0;
}
