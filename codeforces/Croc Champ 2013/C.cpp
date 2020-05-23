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
#include <cassert>
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

int n, a[20], x[20], num[20];
vector<string> ans;
char buf[20];
string hehe;

void check(int len, int pos, int done, int now){
	if (pos > len){
		if (done != 4) return;
		sprintf(buf,"%d.%d.%d.%d",num[1],num[2],num[3],num[4]);
		hehe = buf;
		ans.pb(hehe);
		return;
	}
	now = 10*now + x[pos];
	if (now > 255 || done == 4 || /*(len-pos) < 4-done ||*/ (len-pos) > 3*(4-done)) return;
	if (done < 4){
		num[done+1] = now;
		check(len,pos+1,done+1,0);
	}
	if (now > 0) check(len,pos+1,done,now);
}

void go(int len, int pos){
	if (pos > (len+1)/2){
		//check used all
		int used = 0;
		FOR(i,1,len) used |= (1 << x[i]);
		REP(i,n) if (((1 << a[i]) & used) == 0) return;
		LL H = 0;
		FOR(i,1,len) H = 10LL*H + (LL)x[i];
		check(len,1,0,0);
	}
	else {
		REP(i,n){
			x[pos] = x[len+1-pos] = a[i];
			go(len,pos+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	if (n > 6){puts("0"); return 0;}
	REP(i,n) scanf("%d",&a[i]);
	FOR(len,4,12) go(len,1);
	
	printf("%d\n",(int)ans.size());
	REP(i,(int)ans.size()) printf("%s\n",ans[i].c_str());
	
	return 0;
}
