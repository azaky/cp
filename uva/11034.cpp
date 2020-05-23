#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		int l, m, len;
		char side[10];
		scanf("%d%d",&l,&m);
		l *= 100;
		queue<int> left,right;
		REP(i,m){
			scanf("%d%s",&len,side);
			if (!strcmp(side,"left")) left.push(len);
			if (!strcmp(side,"right")) right.push(len);
		}
		int Moveleft = 0, Moveright = 0;
		for(; !left.empty(); ++Moveleft){
			int space = l;
			while (!left.empty()){
				if (space >= left.front()){
					space -= left.front(); left.pop();
				}
				else break;
			}
		}
		for(; !right.empty(); ++Moveright){
			int space = l;
			while (!right.empty()){
				if (space >= right.front()){
					space -= right.front(); right.pop();
				}
				else break;
			}
		}
		printf("%d\n",max(2*Moveleft-1,2*Moveright));
	}
	
	return 0;
}
