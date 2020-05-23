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

const char alpha[] = {'a','b','c','d','e','f','g','h'};
void printvar(int a[], int n){
	REP(i,n){
		if (i) printf(",%c",alpha[a[i]]);
		else printf("%c",alpha[a[i]]);
	}
}
void tab(int p){
	REP(i,2*p) printf(" ");
}

int ntc, n, a[10];

void metasort(int p){
//	puts("HUMBALA");
//	printf("p = %d, n = %d\n",p,n);
//	printvar(a,n);
//	puts("\nEND OF HUMBALA");
	if (p == n){
		tab(p); printf("writeln("); printvar(a,n); puts(")");
	}
	else {
		//insert a[p] into appropriate place
		REPD(i,p+1){
			//i == 0, we're done
			if (!i){
				tab(p); puts("else");
				metasort(p+1);
			}
			//check if a[i] < a[p]
			else {
				if (i == p){
					tab(p); printf("if %c < %c then\n",alpha[a[i-1]],alpha[a[i]]);
				}
				else {
					tab(p); printf("else if %c < %c then\n",alpha[a[i-1]],alpha[a[i]]);
				}
				metasort(p+1);
			}
			if (i) swap(a[i],a[i-1]);
		}
		//reset a
		REP(i,p) swap(a[i],a[i+1]);
	}
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		puts("program sort(input,output);");
		puts("var");
		REP(i,n) a[i] = i;
		printvar(a,n);
		puts(" : integer;");
		puts("begin");
		tab(1); printf("readln("); printvar(a,n); puts(");");
		//insert some code here
		metasort(1);
		puts("end.");
		if (ntc) puts("");
	}
	
	return 0;
}
