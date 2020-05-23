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
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
	#define GetTime int time_void = clock(); printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
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

long long morethan(vector <long long> u, vector <long long> v){
	for (long long i=0; i<u.size(); ++i)
		if (u[i]>v[i]) return 1;
			else if (u[i]<v[i]) return 0;
	return 0;
}

long long calc(long long x){
	if (x==0) return 0;
	
	vector <long long> u, v;
	long long n, p, ret = 0, temp = x, cot[100];
	
	while (x>0){
		v.push_back(x & 1);
		x = x >> 1;
	}
	reverse(v.begin(),v.end());
	n = v.size();
	
	for (p=1; p<n; ++p){
		cot[p] = 0;
		if (n%p!=0) continue;
		u.clear();
		for (long long i=0; i<p; ++i){
			u.push_back(v[i]);
			if (u[i]==1 && i!=0) cot[p] += (1 << (p-i-1));
		}
		for (long long i=p; i<n; ++i) u.push_back(u[i-p]);
		for (long long i=0; i<u.size(); ++i) debug("%d",u[i]); debug("\n");
		if (!morethan(u,v)) ++cot[p];
		for (long long i=1; i<p; ++i)
			if (p%i==0) cot[p] -= cot[i];
		ret += cot[p];
	}
	
	ret += calc((1LL << (n-1))-1);
	debug("%I64d %I64d %I64d %I64d\n",n,temp,ret,(1LL << (n-1))-1);
	return ret;
}

int main(){
	long long a,b;
	cin >> a >> b;
	cout << calc(b) - calc(a-1);
	return 0;
}
