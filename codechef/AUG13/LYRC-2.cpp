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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

#define MAXS 5000005
int w, n, _n, t[5005], l[MAXS], u[MAXS], same[505], ans;
char p[505][5005], _s[101][50005];
char* s[MAXS];

bool comp(const int &a, const int &b){
	return l[a] > l[b];
}

int main(){
	scanf("%d",&w);
	REP(i,w) scanf("%s",p[i]);
	scanf("%d",&_n);
	n = 0;
	REP(i,_n){
		scanf("%s",_s[i]);
		char * temp = strtok(_s[i],"-");
		while (temp != NULL){
			s[n++] = temp;
			temp = strtok(NULL,"-");
		}
	}
	REP(i,n) u[i]= i;
	REP(i,n) l[i] = strlen(s[i]);
	int total = 0;
	REP(i,n) total += l[i];
//	assert(total < 2000000);
	sort(u,u+n,comp);
//	sort(p,p+w);
//	FOR(i,w-1) same[i] = (strcmp(p[i],p[i-1])==0);
	map<char*,int> udah;
	REP(i,w){
		if (EXIST(p[i],udah)){
			printf("%d\n",udah[p[i]]);
			continue;
		}
		//compute T
		int len = strlen(p[i]);
		int pos = 2, cnd = 0;
		t[0] = -1; t[1] = 0;
		while (pos < len){
			if (p[i][pos-1] == p[i][cnd]) t[pos++] = ++cnd;
			else if (cnd) cnd = t[cnd];
			else t[pos++] = 0;
		}
//		printf("%s\n",p[i]);
//		REP(j,len) printf("%2d ",t[j]); puts("");
		ans = 0;
		REP(j,n){
			int k = u[j];
			//KMP
			if (l[k] < len) break;
			int hoho = -1;
			int m = 0, ii = 0;
			while (m+ii < l[k]){
				if (p[i][ii] == s[k][m+ii]){
					if (ii == len-1){
						hoho = m;
						break;
					}
					++ii;
				}
				else {
					m += ii - t[ii];
					if (t[ii] > -1) ii = t[ii]; else ii = 0;
				}
			}
			if (hoho != -1) ans++;
//			printf("%s -> %d\n",s[j].c_str(),hoho);
		}
		printf("%d\n",ans);
		udah[p[i]] = ans;
	}
	
	return 0;
}
