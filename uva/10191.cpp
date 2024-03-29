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

int n, t[1111], nap[1111];

int main(){
	string s;
	for (int day = 1; getline(cin,s); ++day){
		sscanf(s.c_str(),"%d",&n);
		RESET(t,0);
		REP(_i,n){
			getline(cin,s);
			stringstream line(s);
			int h1, m1, h2, m2; char ch;
			line >> h1 >> ch >> m1 >> h2 >> ch >> m2;
//			printf("(%d:%d,%d:%d)\n",h1,m1,h2,m2);
			int s = h1*60 + m1, e = h2*60 + m2;
			FOR(i,s,e-1) t[i] = 1;
		}
		FORD(i,1079,600){
			if (t[i]) nap[i] = 0; else nap[i] = nap[i+1] + 1;
		}
		int ans = *max_element(nap+600,nap+1080);
		FOR(i,600,1079){
			if (nap[i] == ans){
				if (ans < 60){
					printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n",day,i/60,i%60,ans);
				}
				else {
					printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n",day,i/60,i%60,ans/60,ans%60);
				}
				break;
			}
		}
	}
	
	return 0;
}
