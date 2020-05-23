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

typedef pair<int,pair<pii,int> > pipiii;

char s1[111], s2[111], v[111];
int visit[111][111][111], l1, l2, lv;
pipiii dp[111][111][111], next;

pipiii calc(int i1, int i2, int iv){
	if (i1 == -1 or i2 == -1) return MP(0,MP(MP(0,0),0));
	if (visit[i1][i2][iv]) return dp[i1][i2][iv];
	dp[i1][i2][iv] = MP(0,MP(MP(0,0),0));
	visit[i1][i2][iv] = 1;
	pipiii temp;
	temp = calc(i1-1,i2,iv);
	if (temp.A > dp[i1][i2][iv].A){
		dp[i1][i2][iv].A = temp.A;
		dp[i1][i2][iv].B = MP(MP(i1-1,i2),iv);
	}
	temp = calc(i1,i2-1,iv);
	if (temp.A > dp[i1][i2][iv].A){
		dp[i1][i2][iv].A = temp.A;
		dp[i1][i2][iv].B = MP(MP(i1,i2-1),iv);
	}
	if (s1[i1] == s2[i2]){
		if (iv == 0){
			REP(i,lv){
				if (s1[i1] == v[i]) continue;
				temp = calc(i1-1,i2-1,i);
				if (temp.A + 1 > dp[i1][i2][iv].A){
					dp[i1][i2][iv].A = temp.A + 1;
					dp[i1][i2][iv].B = MP(MP(i1-1,i2-1),i);
				}
			}
		}
		else if (s1[i1] == v[iv]){
			temp = calc(i1-1,i2-1,iv-1);
			if (temp.A + 1 > dp[i1][i2][iv].A){
				dp[i1][i2][iv].A = temp.A + 1;
				dp[i1][i2][iv].B = MP(MP(i1-1,i2-1),iv-1);
			}
		}
	}
	return dp[i1][i2][iv];
}

int main(){
	scanf("%s%s%s",s1,s2,v);
	l1 = strlen(s1); l2 = strlen(s2); lv = strlen(v);
	int nans = 0, a1 = 0, a2 = 0, av = 0;
	REP(i1,l1) REP(i2,l2) REP(iv,lv){
//		printf("[%d][%d][%d]\n",i1,i2,iv);
		pipiii temp = calc(i1,i2,iv);
		if (temp.A > nans){
			nans = temp.A;
			a1 = i1;
			a2 = i2;
			av = iv;
		}
	}
	printf("%d\n",nans);
	if (nans == 0){
		puts("0");
	}
	else {
		string ans = "";
		string ans1 = "", ans2 = "";
		while (nans){
//			printf("[%d][%d][%d][%d]\n",nans,a1,a2,av);
			next = calc(a1,a2,av);
//			printf("[%d][%d][%d][%d]\n",next.A,next.B.A.A,next.B.A.B,next.B.B);
			if (nans == calc(next.B.A.A,next.B.A.B,next.B.B).A + 1){
//				printf("BOO\n");
				assert(s1[a1] == s2[a2]);
//				printf("%c\n",s1[a1]);
				ans = s1[a1] + ans;
			}
			a1 = next.B.A.A;
			a2 = next.B.A.B;
			av = next.B.B;
			nans = calc(a1,a2,av).A;
		}
		printf("%s\n",ans.c_str());
	}
	
    
    return 0;
}
