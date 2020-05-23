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

int main(){
	string a, b;
	cin >> a >> b;
	
	int n = a.length() / 2;
	int na = 0, nb = 0;
	
	REP(i, n) {
		//batu: 1
		//gunting: 2
		//kertas: 3
		int actiona, actionb;
		if (a[2*i] == '[' && a[2*i + 1] == ']') {
			actiona = 3;
		}
		if (a[2*i] == '(' && a[2*i + 1] == ')') {
			actiona = 1;
		}
		if (a[2*i] == '8' && a[2*i + 1] == '<') {
			actiona = 2;
		}
		if (b[2*i] == '[' && b[2*i + 1] == ']') {
			actionb = 3;
		}
		if (b[2*i] == '(' && b[2*i + 1] == ')') {
			actionb = 1;
		}
		if (b[2*i] == '8' && b[2*i + 1] == '<') {
			actionb = 2;
		}
		if ((actiona == 1 && actionb == 2) || (actiona == 2 && actionb == 3) || (actiona == 3 && actionb == 1)) {
			na++;
		}
		else if ((actionb == 1 && actiona == 2) || (actionb == 2 && actiona == 3) || (actionb == 3 && actiona == 1)) {
			nb++;
		}
	}
	if (na > nb) puts("TEAM 1 WINS");
	if (na < nb) puts("TEAM 2 WINS");
	if (na == nb) puts("TIE");
	
	return 0;
}
