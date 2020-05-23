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


/** Suffix Array **/
/* complexity: O(N log N) */
#define MAXN 1100100

char T[MAXN+5]; // input
int n; // length
int RA[MAXN+5], tempRA[MAXN+5]; // rank array
int SA[MAXN+5], tempSA[MAXN+5]; // suffix array
int c[MAXN+5]; //for counting/radix sort

void countingSort(int k) {
    int sum, maxi = max(300,n);
    memset(c,0,sizeof(c));
    for (int i = 0; i < n; i++) 
        c[i+k < n ? RA[i+k] : 0]++;
    for (int i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum;
        sum += t;
    }
    for (int i = 0; i < n; i++)
        tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++] = SA[i];
    for (int i = 0; i < n; i++) SA[i] = tempSA[i];
}

void SuffixArray_Construct() {
    int r;
    for (int i = 0; i < n; i++) RA[i] = T[i];
    for (int i = 0; i < n; i++) SA[i] = i;
    for (int k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (int i = 1; i < n; i++)
            tempRA[SA[i]] = 
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (int i = 0; i < n; i++) RA[i] = tempRA[i];
    	if (RA[SA[n-1]] == n-1) break;
    }
}

int ntc;

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s", T);
		n = strlen(T);
		if (n < 5000) {
			for (int i = 1; i <= n; ++i) {
				bool isAnswer = 1;
				for (int j = i; j < n; ++j) {
					if (T[j] != T[j - i]) {
						isAnswer = 0;
						break;
					}
				}
				if (isAnswer) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		T[n++] = '$';
		T[n] = 0;
		SuffixArray_Construct();

		// continue;
		// for (int i = 0; i < n; ++i) {
		// 	printf("SA[%2d] = %2d: %s\n", i, SA[i], T + SA[i]);
		// }
		int pos = 0;
		for (int i = 0; i < n; ++i) {
			if (SA[i] == 0) {
				pos = i;
				break;
			}
		}
		assert(pos > 0);

		n--;
		int pa = SA[pos - 1];
		int pb = SA[pos];
		assert(pa > pb);
		int diff = pa - pb;
		bool approved = true;
		while (pa < n && approved) {
			if (T[pa] == T[pb]) {
				pa++; pb++;
			} else {
				approved = false;
			}
		}
		int ans = n;
		if (approved) {
			ans = diff;
		}

		printf("%d\n", ans);
	}

	return 0;
}