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

int n,m,k;

int main(){
	cin >> n >> m >> k;
	if (m==n && n==2 && k==1){
		cout << 4*k << endl;
		for (int i=0; i<k; ++i) cout << "1 ";
		for (int i=0; i<k; ++i) cout << "2 ";
		for (int i=0; i<k; ++i) cout << "3 ";
		for (int i=0; i<k; ++i) cout << "4 "; cout << endl;
		return 0;
	}
	if (m==n-1 && k==1){
		cout << "3\n1 " << n << " " << n+m << endl;
		return 0;
	}
	if (m==n) cout << 2*k+1 << endl;
		else cout << 2*k << endl;
	for (int i=0; i<k; ++i) cout << "1 ";
	cout << n << " ";
	for (int i=1; i<k; ++i) cout << n+1 << ' ';
	if (m==n) cout << n+2;
	cout << endl;
	return 0;
}
