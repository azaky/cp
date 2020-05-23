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
	
	LL r, c, now, S, ans = 0;
	
	cin >> r >> c;
	
	cin >> now >> S;
	
	LL temp = now;
	
	if (now < c) now++;
	
	while (now <= r*c){
		ans += now;
		now += c;
		if (now%c != 0) now++;
	}
	
	LL minn = 0;
	
	now = temp;
	if (now > 1) now--;
	
	while (now <= r*c){
		minn += now;
		now += c;
		if (now%c != 1) now--;
	}
	
	
	if (ans >= S) cout << "Ya " << max(S,minn) << endl;
	else cout << "Tidak " << ans << endl;
	
	return 0;
}
