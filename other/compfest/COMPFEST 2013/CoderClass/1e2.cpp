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

int len, kecil, besar;
char c, s[222222];

int main(){
	len = 0;
	while (scanf("%c",&c) == 1) if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) s[len++] = c;
	REP(i,len){
		if ('a' <= s[i] && s[i] <= 'z') kecil++; else besar++;
		if (i > 6){
			if (s[i-7] == 'C' && s[i-6] == 'O' && s[i-5] == 'M' && s[i-4] == 'P' && s[i-3] == 'F' && s[i-2] == 'E' && s[i-1] == 'S' && s[i] == 'T'){
				printf("%d %d\n",kecil,besar-8);
				besar = kecil = 0;
			}
		}
	}
	
	return 0;
}
