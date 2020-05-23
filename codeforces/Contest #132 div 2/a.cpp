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

int n,m,a[1111],b[1111],ans = 0,mm = 0;

int main(){
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	cin >> m;
	for (int i=0; i<m; ++i) cin >> b[i];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (b[j]%a[i] == 0 && b[j]/a[i] > mm) mm = b[j]/a[i];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (b[j]%a[i] == 0 && b[j]/a[i] == mm) ++ans;
	cout << ans << endl;
	return 0;
}
