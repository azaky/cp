/*
ID: a_zaky01
PROG: fairphoto
LANG: C++
*/

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

#define MAXN 100100
int n, k, sum[8][MAXN], ans;
pii a[MAXN];
map<vector<int>, int> hoho;

int main(){
	OPEN("fairphoto");
	
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) {
		scanf("%d%d", &a[i].A, &a[i].B);
		a[i].B --;
	}
	a[0].A = -1;
	sort(a, a + n+1);
	
	FOR(i, 1, n) {
		REP(b, 8) sum[b][i] = sum[b][i-1];
		sum[a[i].B][i]++;
	}
	
	ans = -1;
	REP(s, 256) {
		int xdi[8];
		int t = 0;
		REP(i, 8) xdi[i] = -1;
		REP(i, 8) if (s & (1 << i)) {
			xdi[i] = t++;
		}
		if (t < k) continue;
		
		vector<int> ivy(t);
		FORIT(it, ivy) *it = 0;
		hoho.clear();
		hoho[ivy] = 0;
		
		FOR(i, 1, n) {
			if (xdi[a[i].B] == -1) {
				FORIT(it, ivy) *it = 0;
				hoho.clear();
				hoho[ivy] = i;
				continue;
			}
			ivy[xdi[a[i].B]] ++;
			int _min = *min_element(ALL(ivy));
			FORIT(it, ivy) *it -= _min;
			if (EXIST(ivy, hoho)) {
				int prev = hoho[ivy];
				int len = a[i].A - a[prev+1].A;
				int cot = 0;
				REP(b, 8) {
					if (sum[b][i] != sum[b][prev]) cot++;
				}
				if (cot >= k) MX(ans, len);
			}
			else {
				hoho[ivy] = i;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}

/* Generated by UsacoTemp v3.0 */
