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

int tc,n,chr;
string message,newline,s[11];

int main(){
	scanf("%d\n",&tc);
	while (tc--){
		for (int i=0; i<10; ++i) getline(cin,s[i]);
		if (tc>0) getline(cin,newline);
		n = s[0].length() - 2;
		message = "";
		for (int i=0; i<n; ++i){
			chr = 0;
			for (int j=0; j<9; ++j)
				chr += s[j+1][i+1]=='\\' ? 1 << j : 0;
			message += (char)chr;
		}
		printf("%s\n",message.c_str());
	}
	return 0;
}
