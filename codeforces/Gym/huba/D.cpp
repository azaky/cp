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


#define INF 1000000000

int tc;
char s[25], t[25];
int ns,nt;
set<string> hash;
set<string> hash2[25];

int dp[25];

int work(int pos)
{
	if (pos >= nt)
		return 0;
	
	
	
	int &ret = dp[pos];
	if (ret == -1)
	{
		ret = INF;
		
		string tmp = "";
		
		FOR(i,pos,nt-1)
		{
			tmp += t[i];
			
			int flag = 0;
			if (hash.count(tmp) > 0)
				flag = 1;
			else
			REP(j,pos-1)
			{
				if (hash2[j].count(tmp) > 0)
				{
					flag = 1;
					break;
				}
			}
			
			if (flag)
				MN(ret, work(i+1)+1);
		}
		
		
	}
	return ret;
}

int main(){
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%s", s);
		scanf("%s", t);
		
		hash.clear();
		REP(i, nt)
			hash2[i].clear();
		
		ns = strlen(s);
		nt= strlen(t);
		REP(i, ns)
		{
			string tmp= "";
			string tmp2 = "";
			FOR(j,i,ns-1)
			{
				tmp += s[j];
				tmp2 = s[j] + tmp2;
				//cout << tmp << " " << tmp2 << endl;
				hash.insert(tmp);
				hash.insert(tmp2);
			}
		}
		
		REP(i, nt)
		{
			string tmp = "";
			string tmp2 = "";
			FOR(j,i,nt-1)
			{
				tmp += t[j];
				tmp2 = t[j] + tmp2;
				
				hash2[j].insert(tmp);
				hash2[j].insert(tmp2);
			}
		}
		
		RESET(dp, -1);
		int ans = work(0);
		if (ans >= INF)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}
	
	return 0;
}
