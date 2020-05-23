#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

string s, p[11], t;
pii lim[11];
int n;
vector<string> ans;

int occ(string a, string b){
	if (a.length() > b.length()) return 0;
	int res = 0;
	REP(i,b.length()-a.length()+1) if (b.compare(i,a.length(),a) == 0) ++res;
	return res;
}

int main(){
	cin >> s;
	scanf("%d",&n);
	REP(i,n) cin >> p[i] >> lim[i].A >> lim[i].B;
	FOR(len,1,s.length()){
		FOR(start,0,s.length()-len){
			t = s.substr(start,len);
//			cout << t << endl;
			bool good = true;
			REP(i,n){
				int occurence = occ(t,p[i]);
				if (occurence < lim[i].A || lim[i].B < occurence){
					good = false;
					break;
				}
			}
			if (good) ans.PB(t);
		}
	}
	sort(ALL(ans));
	int nans = 0;
	REP(i,SZ(ans)) if (i == 0) nans++; else if (ans[i].compare(ans[i-1])) nans ++;
	printf("%d\n",nans);
		
	
	return 0;
}
