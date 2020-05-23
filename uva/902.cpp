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

string line,s,ans,temp;
vector <string> v;
map <string,int> occ;
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
		occ.clear();
		for (int i=0; i+n<=len; ++i){
			temp = "";
			for (int j=i; j-i<n; ++j) temp += s[j];
			occ[temp]++;
		}
		nans = 0;
		for (int i=0; i+n<=len; ++i){
			temp = "";
			for (int j=i; j-i<n; ++j) temp += s[j];
			if (occ[temp] > nans){
				nans = occ[temp];
				ans = temp;
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
