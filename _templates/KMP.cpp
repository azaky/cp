/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

/** Knuth-Morris-Pratt **/

#define MAXN 100100;

void buildFailTable(char *pattern, int *t){
	int i = 0, j = -1, m = strlen(pattern);
	t[0] = -1;
	while (i < m){
		while (j >= 0 && pattern[i] != pattern[j]) j = t[j];
		i++; j++;
		t[i] = j;
	}
}

vector<int> kmpSearch(char *pattern, char *text){
	vector<int> res;
	int i = 0, j = 0, n = strlen(text), m = strlen(pattern);
	int t[m+5];
	buildFailTable(pattern,t);
	while (i < n){
		while (j >= 0 && text[i] != pattern[j]) j = t[j];
		i++; j++;
		if (j == m){
			res.push_back(i-j);
			j = t[j];
		}
	}
	return res;
}

int main(){
	char a[100], b[100];
	scanf("%s%s",a,b);
	vector<int> huba = kmpSearch(a,b);
	FORIT(it,huba) printf("[%d]\n",*it);
	
	return 0;
}
