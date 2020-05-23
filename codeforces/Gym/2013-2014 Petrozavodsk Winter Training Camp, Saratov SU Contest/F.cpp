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

struct Cmp {
	bool operator() (const pii &a, const pii &b) {
		if (a.A != b.A) return a.A < b.A;
		return a.B > b.B;
	}
};

int ntc, n;
pii a[200100];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		priority_queue<pii, vector<pii>, Cmp> list;
		scanf("%d", &n);
		REP(i, n) {
			scanf("%d %d", &a[i].A, &a[i].B);
			if (a[i].A < a[i].B) {
				swap(a[i].A, a[i].B);
			}
			list.push(a[i]);
		}
		
		int len = 0;
		bool possible = true;
		pii last = MP(0x3FFFFFFF, 0);
		vector<pii> ans;
		while (len < n) {
			pii top = list.top(); list.pop();
			//printf("evaluating (%d, %d)...\n", top.A, top.B);
			if (top.A <= last.A && top.B >= last.B) {
				last = top;
				ans.PB(last);
				len++;
			}
			else {
				if (top.A <= top.B) {
					possible = false;
					break;
				}
				else {
					swap(top.A, top.B);
					list.push(top);
				}
			}
		}
		if (possible) {
			puts("yes");
			reverse(ALL(ans));
			FORIT(it, ans) {
				printf("%d %d\n", it->A, it->B);
			}
		}
		else {
			puts("no");
		}
	}
	
	return 0;
}
