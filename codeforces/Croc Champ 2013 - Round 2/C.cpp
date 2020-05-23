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
#include <cassert>
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

void no(){puts("0"); exit(0);}

LL n, m, a, b, c, A, B, C, D, SD, ans, cot, ab, ac, bc, s;

int main(){
	cin >> n;
	
	if (n % 3LL){puts("0"); return 0;}
	
	n /= 3LL;
	
	for (ab = 2; ab*ab*ab <= n; ++ab){
		m = n/ab;
		if (m * ab != n) continue;
		
		for (ac = (LL)(-ab+(LL)sqrt((double)(ab*ab+4LL*m)))/2LL; ac*ac <= m; ++ac){
			++cot;
			bc = m/ac;
			if (ac*bc != m) continue;
			s = (ab+ac+bc) >> 1LL;
			if (s+s != ab+ac+bc) continue;
			a = s-bc; b = s-ac; c = s-ab;
			if (a < 1) continue;
//			assert(a <= b && b <= c);
			if (a > b || b > c || a > c) continue;
			if (a == b && b == c) ans++;
			else if (a == b || b == c) ans += 3;
			else ans += 6;
		}
	}
	/*
	for (a = 1; 8LL*a*a*a <= n; ++a){
		for (b = a; 2LL*a*a*b + 4LL*a*b*b + 2LL*b*b*b <= n; ++b){
			c =
			if (n % (a+b)) continue;
			cot++;
			A = a + b;
			B = (a+b)*(a+b);
			C = a*a*b + b*b*a - n;
			//printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",a, b, n, A,B,C);
			D = B*B - 4LL*A*C;
			if (D < 0) break;
			SD = (LL)sqrt((double)D);
			if (SD*SD == D){
				c = (-B+SD);
				if (c%(A+A) == 0){
					c /= A+A;
					assert(a <= b && b <= c);
					if (a == b && b == c) ans++;
					else if (a == b || b == c) ans += 3;
					else ans += 6;
				}
			}
		}
	}
	*/
	//cout << "TOTAL = " << cot << endl;
	cout << ans << endl;
	
	return 0;
}
