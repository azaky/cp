#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

string s;

string a, b, c;
int cnt;
int flag;
int pertamax;

char tolowercase(char cc){
	if (cc >= 'a' && cc <= 'z') return cc;
	if (cc >= 'A' && cc <= 'Z')
		return (char)((int)cc -'A' + 'a');
	return cc;
}

int main(){
	getline(cin,s);
	cnt= 0;
	flag = 0;
	pertamax = 1;
	a = "";
	b = "";
	c = "";
	REP(i, s.length()){
	//printf("i = %d, s[%d] = %c\n", i, i, s[i]);
		if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
			flag = 0;
			cnt++;
			if (cnt == 3){
				cout << a << " " << b << " " << c;
				a = "";
				b = "";
				c = "";
				cnt = 0;
			} 
			continue;
		}
		
		if (s[i] == '{'){ flag = 1;continue;}
		if (s[i] == '('){ flag = 2; continue; }
		if (s[i] == '['){ flag = 3; continue; }
		
		if (flag == 0 && cnt != 0) continue;
		
		if (flag == 1){
			if (pertamax){
				if (s[i] >= 'a' && a[i] <= 'z')
					a += (char)(s[i]-'a'+'A');
				else
					a += s[i];
					
				pertamax = 0;
			}
			else{
				a += tolowercase(s[i]);
			}
		} else 
		if (flag == 2){
			b += tolowercase(s[i]);
		} else 
		if (flag == 3){
			c += tolowercase(s[i]);
		} else {
			cout << tolowercase(s[i]);
		}
		
		//cout << "a = " << a << ", b = " << b<< ", c = " << c << endl << endl;
	}
	cout << endl;
	return 0;
}
