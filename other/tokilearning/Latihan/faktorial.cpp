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

int calc(int x,int p){
	int ret = 0;
	while (x>0){
		x /= p;
		ret += x;
	}
	return ret;
}

const int MAXP = 1111;
int prime[MAXP],nprime,p[MAXP],num[MAXP],den[MAXP],n,x;
vector<pair<int,int> > ansn,ansd;

int main(){
	//sieve
	memset(prime,1,sizeof(prime));
	prime[1] = 0;
	for (int i=2; i*i<MAXP; ++i)
		if (prime[i]) for (int j=2; i*j<MAXP; ++j) prime[i*j] = 0;
	nprime = 0;
	for (int i=2; i<MAXP; ++i)
		if (prime[i]) p[nprime++] = i;
	scanf("%d",&n);
	for (int i=0; i<n; ++i){
		scanf("%d",&x);
		for (int j=0; j<nprime; ++j) num[j] += calc(x,p[j]);
	}
	scanf("%d",&n);
	for (int i=0; i<n; ++i){
		scanf("%d",&x);
		for (int j=0; j<nprime; ++j) den[j] += calc(x,p[j]);
	}
	for (int i=0; i<nprime; ++i)
		if (num[i]>den[i]){
			num[i] -= den[i];
			den[i] = 0;
		}
		else {
			den[i] -= num[i];
			num[i] = 0;
		}
	for (int i=0; i<nprime; ++i){
		if (num[i]>0) ansn.push_back(make_pair(p[i],num[i]));
		if (den[i]>0) ansd.push_back(make_pair(p[i],den[i]));
	}
	for (int i=0; i<(int)ansn.size(); ++i){
		printf("%d",ansn[i].first);
		if (ansn[i].second>1) printf("(%d)",ansn[i].second);
		if (i<(int)ansn.size()-1) printf(" ");
	}
	printf("\n");
	for (int i=0; i<(int)ansd.size(); ++i){
		printf("%d",ansd[i].first);
		if (ansd[i].second>1) printf("(%d)",ansd[i].second);
		if (i<(int)ansd.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
