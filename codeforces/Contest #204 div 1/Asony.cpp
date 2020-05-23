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

int main(){
	int N; cin >> N;
	vector<int> dec;
	int moves = 0;
	REP(i,2*N){
		string s; cin >> s;
		s = s.substr(s.find('.')+1);
		int n = (s[0]-'0')*100+ (s[1]-'0')*10 + (s[2]-'0');
		if (!n) moves++;
		else
		dec.PB(n);
	}
	moves = min(moves,N);
	int P = 0;
	REP(i,SZ(dec)) P += dec[i];
	int K = 2*N-moves*2;
	K *= 1000;
	if (K/2 > P){
		printf("%.3lf\n",(K/2-P)/1000.);
	} else if (K/2 + moves*1000 < P){
		printf("%.3lf\n",(P-(K/2+moves*1000))/1000.);
	} else printf("%.3lf\n",min(P%1000,1000-(P%1000))/1000.);
	
	return 0;
}
