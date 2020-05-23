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

int ntc, d[11];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		REP(i,10) scanf("%d",&d[i]);
		string ans = "";
		if (!(d[6] && d[9]) && !d[1] && !d[8]) {puts("-1");continue;}
		if (d[8] % 2 == 1){
			ans += '8';
			d[8]--;
		}
		else if (d[1] % 2 == 1){
			ans += '1';
			d[1]--;
		}
		if (!(d[6] && d[9]) && d[8] < 2 && d[1] < 2) {cout << ans << endl;continue;}
		if (ans.empty()) while (d[0]--) ans += '0';
		else while (d[0] >= 2){
			d[0] -= 2;
			ans = '0' + ans + '0';
		}
		while (d[1] >= 2){
			d[1] -= 2;
			ans = '1' + ans + '1';
		}
		while (d[8] >= 2){
			d[8] -= 2;
			ans = '8' + ans + '8';
		}
		while (d[6] && d[9]){
			d[6]--; d[9]--;
			ans = '9' + ans + '6';
		}
		cout << ans << endl;
	}
	
	return 0;
}
