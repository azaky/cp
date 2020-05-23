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

string line;
int r;
char n[1100100];

string to(int r, char* sn) {
	int n = atoi(sn);
	if (n == 0) {
		return "0";
	}

	string result;
	while (n != 0) {
		int mod = n % r;
		if (mod < 0) {
			mod += r;
		}
		result = (char)('0' + mod) + result;
		n -= mod;
		n /= r;
		n *= -1;
	}
	return result;
}

ll from(int r, char* n) {
	ll x = 1, result = 0;
	int len = strlen(n);
	REPD(i, len) {
		result += x * (n[i] - '0');
		x *= (-r);
	}
	return result;
}

int main(){
	while (true) {
		getline(cin, line);
		if (strcmp(line.c_str(), "end") == 0) {
			break;
		} else if (sscanf(line.c_str(), "to-%d %s", &r, n) == 2) {
			cout << to(r, n) << endl;
		} else if (sscanf(line.c_str(), "from-%d %s", &r, n) == 2) {
			cout << from(r, n) << endl;
		} else {
			puts("invalid command");
			exit(1);
		}
	}
	
	return 0;
}