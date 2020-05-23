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
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
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

const int MAXN = 100100;
int n,lans,rans,ans;
long long r[MAXN],sum[MAXN],l,d;

inline long long GetSum(int l,int r){
	return sum[r]-sum[l-1];
}
inline long long GetCost(int _l,int _r){
	int med = (_l+_r)/2;
	return (2*med-_l-_r)*r[med]-GetSum(_l,med-1)+GetSum(med+1,_r);
}
inline int GetRice(int s){
	int _l,_r;
	for (_l=1,_r=s; _r<=n; ++_l, ++_r)
		if (GetCost(_l,_r)<=d) return 1;
	return 0;
}

int main(){
	cin >> n >> l >> d;
	for (int i=1; i<=n; ++i) scanf("%I64d",&r[i]);
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + r[i];
	lans = 1; rans = n; ans = (lans+rans)/2;
	while (lans<rans){
		ans = (lans+rans)/2;
		if (GetRice(ans)){
			if (lans==ans){
				if (GetRice(ans+1)) lans = rans;
					else rans = ans;
				}
			else lans = ans;
		}
		else rans = ans-1;
	}
	ans = (lans+rans)/2;
	cout << ans << endl;
	return 0;
}
	
