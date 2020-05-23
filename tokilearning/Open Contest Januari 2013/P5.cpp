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

LL p(int K){
	LL ret = 1;
	REP(i,K) ret *= 10LL;
	return ret;
}
LL get(LL D, int L){
	LL N = D;
	FOR(i,1,L-1){
		FOR(d,0,9){
			LL _N = p(i)*(LL)d + N;
			if ((_N*_N - _N)%p(i+1) == 0){
				N = _N;
				break;
			}
		}
	}
	return N;
}

void ans(LL A, LL B, LL C){
	puts("YA");
	cout << A << " " << B << " " << C << endl;
	exit(0);
}

const LL x[] = {1,5,6};

int main(){
	
	LL N;
	
	cin >> N;
	
	LL LIM = (LL)sqrt(N);
	
	FOR(l,1,9){
		LL px = p(l), p2x = p(2*l);
		REP(i,3){
			LL C = get(x[i],l);
			//cout << C << " " << px << " " << p2x <<  endl;
			for(LL A = 1; A <= LIM; ++A){
				if (C + px*N - C*C - px*C*A > 0){
					LL B = (C + px*N - C*C - px*C*A) / (p2x*A + px*C);
					if ((px*A + C)*(px*B + C) == (px*N + C)) ans(A,B,C);
				}
			}
		}
	}
	
	puts("TIDAK");
		
	
	return 0;
}
