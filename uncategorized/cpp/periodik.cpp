#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define debugvector(v) for (vector<int>::iterator i=v.begin(); i<v.end(); ++i) cout << *i << " "; cout << endl
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define debugvector(v) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

#define MOD 1000000007

int n,tau;
long long k,ans = 0,cot[1111];
vector <int> factor;

long long power(long long k, long long a){
	if (a==0) return 1;
	long long ret = power(k,a/2);
	ret = (ret*ret)%MOD;
	if (a & 1) ret = (ret*k)%MOD;
	return ret;
}

int main(){
	scanf("%d %I64d",&n,&k);
	//calculating factors
	for (int i=1; i*i<=n; ++i){
		if (n%i) continue;
		factor.push_back(i);
		if (i*i!=n && i!=1) factor.push_back(n/i);
	}
	sort(factor.begin(),factor.end());
	tau = factor.size();
	debugvector(factor);
	for (int i=0; i<tau; ++i){
		cot[i] = power(k,factor[i]);
		for (int j=0; j<i; ++j)
			if (factor[i]%factor[j]==0){
				cot[i] -= cot[j];
				if (cot[i]<0) cot[i] += MOD;
			}
		ans = (ans+cot[i])%MOD;
	}
	for (int i=0; i<tau; ++i) printf("%I64d ",cot[i]); printf("\n");
	printf("%I64d\n",ans);
	return 0;
}
