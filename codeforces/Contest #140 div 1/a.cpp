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

long long n,m,ans;

long long pow(long long a,long long b){
	if (b==0) return 1;
	long long ret = pow(a,b/2);
	ret = (ret*ret) % m;
	if (b%2) ret = (ret*a) % m;
	return ret;
}
int main(){
	cin >> n >> m;
	ans = pow(3LL,n);
	ans = (ans + m - 1)%m;
	cout << ans << endl;
	return 0;
}
