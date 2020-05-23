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

struct Trie{
	int child[2];
} trie[5000000];

const int MAXN = 111111;
int n, TrieSize = 0;
LL a[MAXN], p[44];

void add(LL x){
	LL d[44];
	REP(i,40){
		d[i] = (x & 1);
		x >>= 1;
	}
	int now = 0;
	REPD(i,40){
		if (trie[now].child[d[i]] == 0){
			TrieSize++;
			trie[TrieSize].child[0] = trie[TrieSize].child[1] = 0;
			trie[now].child[d[i]] = TrieSize;
		}
		now = trie[now].child[d[i]];
	}
}

int main(){
	p[0] = 1LL;
	FOR(i,1,39) p[i] = p[i-1]+p[i-1];
	scanf("%d",&n);
	FOR(i,1,n) scanf("%I64d",&a[i]);
	add(0);
	LL XOR = 0;
	FOR(i,1,n) XOR ^= a[i];
	LL ans = XOR;
	LL dd[44];
	REP(j,40){
		dd[j] = (XOR & 1);
		XOR >>= 1;
	}
	FOR(i,1,n){
		LL x = (a[i] ^ XOR), d[44];
		REP(j,40){
			d[j] = (x & 1);
			x >>= 1;
		}
		int now = 0;
		LL best = 0;
		REPD(j,40){
			if (trie[now].child[1-(d[j]^dd[j])] != 0){
				now = trie[now].child[1-(d[j]^dd[j])];
				best += p[j];
			}
			else{
				now = trie[now].child[d[j]^dd[j]];
			}
		}
		if (best > ans) ans = best;
		XOR ^= a[i];
		add(XOR);
	}
	printf("%I64d\n",ans);
	
	return 0;
}
