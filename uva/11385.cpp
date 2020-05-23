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

int tc,f[211],a[211],m,n,k,len;
string s, ans;
//char ans[111];
pair <int,char> ch[211];
//map <int,int> pos;

int main(){
	f[1] = 1; f[2] = 2;
	for (m=2; f[m] < 1700000000; ++m) f[m+1] = f[m-1] + f[m];
	cin >> tc;
	while (tc--){
		cin >> n;
		for (int i=0; i<n; ++i) cin >> a[i];
		getline(cin,s);
		getline(cin,s);
		k = 0;
		for (int i=0; i<s.length(); ++i){
			if (s[i]>'Z' || s[i]<'A') continue;
			ch[k].second = s[i]; ch[k].first = a[k];
			++k;
		}
		sort(ch,ch+n);
		k = 1, ans = "";
		for (int i=0; i<n; ++i){
			while (ch[i].first != f[k]) ans += ' ', ++k;
			ans += ch[i].second; ++k;
		}
		cout << ans << endl;
	}
	return 0;
}
