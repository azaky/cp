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

const int MAXN = 10100;
int n,m,i1,i2,idx;
string s1,s2,ss[MAXN];
vector <int> adj[MAXN],v;
map <string,int> M;

int geti(string s){
	if (!M[s]){
		M[s] = ++idx;
		ss[idx] = s;
	}
	return M[s];
}

int reach(int i1, int i2){
	if (i1==i2){
		v.push_back(i1);
		return 1;
	}
	for (int i=0; i<adj[i1].size(); ++i)
		if (reach(adj[i1][i],i2)){
			v.push_back(i1);
			return 1;
		}
	return 0;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<m; ++i){
		cin >> s1 >> s2;
		i1 = geti(s1); i2 = geti(s2);
		adj[i1].push_back(i2);
	}
	cin >> s1 >> s2;
	i1 = geti(s1); i2 = geti(s2);
	if (reach(i1,i2)){
		for (int i=v.size(); i>0; --i) cout << ss[v[i-1]] << endl;
	}
	else if (reach(i2,i1)){
		for (int i=v.size(); i>0; --i) cout << ss[v[i-1]] << endl;
	}
	else cout << "TIDAK MUNGKIN\n";
	return 0;
}
	
	
	
	
	
	
	
