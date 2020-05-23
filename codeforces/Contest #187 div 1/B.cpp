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

int b, d, next[111];
char a[111], c[111];

int main(){
	scanf("%d%d",&b,&d);
	scanf("%s%s",a,c);
	//cek isi
	int na = strlen(a), nc = strlen(c);
	REP(i,nc){
		bool ada = false;
		REP(j,na) if (c[i] == a[j]) ada = true;
		if (!ada){
			printf("0\n");
			return 0;
		}
	}
	//cek ulang
	REP(i,na){
		int now = i;
		REP(j,nc){
			while (a[now%na] != c[j]) now++;
			now++;
		}
		next[i] = now;
	}
//	REP(i,na) printf("[%d][%d]\n",i,next[i]);
	int total = 0, banyak = 0;
	while (total < b*na){
		int x = total%na;
		total += (next[x]-x);
//		printf("%d\n",total);
		banyak ++;
	}
	banyak--;
	printf("%d\n",banyak/d);
	
	return 0;
}
