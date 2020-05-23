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

#define MAXN 20

int n,q,ans1,ans2;
string a[MAXN+5], b[MAXN+5];
map<string,int> id,ind,party;
map<int,int> d;

int main(){
	int ct = 0;
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; i++) {
		getline(cin,a[i]);
		getline(cin,b[i]);
//		cout << a[i] << " " << b[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		if (!party[b[i]] && b[i] != "independent") { ++ct; party[b[i]] = ct;}
		id[a[i]] = party[b[i]];
	}
	scanf("%d", &q);getchar();
	for (int i = 0; i < q; i++) {
		string s;
		getline(cin,s); 
		if (!id[s]) ind[s]++;
		else d[id[s]]++;
		
	}
	int f1 = 1;
	FORIT(it, ind) { 
		if (ans1 == it->second) f1 = 0;
		else f1 = 1;
		MX(ans1,it->second); 
	}
	int f2 = 2;
	for (int i = 0; i < n; i++) {
		if (!id[a[i]]) continue;
		if (ans2 == d[id[a[i]]]) f2 = 0;
		else f2 = 1;
		MX(ans2,d[id[a[i]]]);
	}
	//printf("%d %d %d %d\n", ans1,ans2,f1,f2);
	if (f1 && ans1 > ans2) puts("independent");
	else if (f2 && ans1 < ans2) {
		for (int i = 0; i < n; i++) {
			if (!id[a[i]]) continue;
			if (ans2 == d[id[a[i]]]) cout << b[i] << endl;
		}
	}
	else puts("tie");
	return 0;
}
