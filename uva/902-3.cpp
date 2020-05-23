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

const int MAXN = 2000000;
string line,s,ans;
long long temp, vans, mod;
long long w[MAXN],v[MAXN];
//vector <long long> w,v;
int len, now, nans, n, k;

int main(){
	while (1){
		getline(cin,line);
		if (line.length()==0) break;
		k = n = 0;
		while (line[k] < '0' || line[k] > '9') ++k;
		while ('0' <= line[k] && line[k] <= '9'){
			n = 10*n + (int)line[k] - 48;
			++k;
		}
		s = ""; len = 0;
		while (line[k] == ' ') ++k;
		while ('a' <= line[k] && line[k] <= 'z'){
			s += line[k++]; ++len;
		}
		//--------------
		//w.clear(); v.clear();
		mod = 1LL;
		for (int i=1; i<n; ++i) mod *= 26LL;
		temp = 0LL;
		for (int j=0; j<n; ++j) temp = 26LL*temp + (long long)(s[j]-'a');
		//w.push_back(temp); v.push_back(temp);
		w[0] = v[0] = temp;
		for (int i=1; i+n<=len; ++i){
			temp = 26LL*(v[i-1]%mod) + (long long)(s[i+n-1]-'a');
			//w.push_back(temp); v.push_back(temp);
			w[i] = v[i] = temp;
		}
		//for (int i=0; i+n<=len; ++i) debug("%I64d ",w[i]); debug("\n");
		//sort(v.begin(),v.end());
		sort(v,v+(len-n+1));
		v[len-n+1] = -1;
		nans = 0; now = 1;
		for (int i=1; i+n-1<=len; ++i){
			if (v[i]==v[i-1]){
				++now; continue;
			}
			if (now > nans){
				vans = v[i-1];
				nans = now;
			}
			now = 1;
		}
		//debug("%d %I64d\n",nans,vans);
		for (int i=0; i+n<=len; ++i){
			if (vans == w[i]){
				ans = "";
				for (int j=0; j<n; ++j) ans += s[i+j];
				break;
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
