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

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

#define INF 1000000000
#define RI 0
#define LE 1
#define UP 2
#define DO 3

char spc, s[10];
vector<string > vs;
priority_queue <int, vector<string> > pq;


int vis[256];
int spc_row;

int heur(vector<string> &v, char cc)
{
	if (vis[cc]) return 0;
	
	int r, c;
	
	REP(i,6)
	{
		REP(j,6)
		{
			if (v[i][j] == cc)
			{
				r = i;
				c = j;
				break;
			}
		}
	}
	
	int cnt = 0;
	
	vis[cc] = 1;
	
	int hor = 0;
	if (c > 0)
		if (v[r][c-1] == v[r][c])
			hor = 1;	
	if (c < 5)
		if (v[r][c+1] == v[r][c])
			hor = 1;
	
	int ret = 1;
	
	if (hor)
	{		
		for (int i = c; i < 6; ++i)
		{
			if (v[r][i] != cc && v[r][i] != '.')
			{
				vector<char> tmp = getHeurBlocks(v, v[r][i]);
				REP(j, SZ(tmp))
					ret++;
				break;
			}
		}
		for (int i = c; i >= 0; --i)
		{
			if (v[r][i] != cc && v[r][i] != '.')
			{
				vector<char> tmp = getHeurBlocks(v, v[r][i]);
				REP(j, SZ(tmp))
					ret++;
				break;
			}
		}
	}
	else
	{
		for (int i = r; i < 6; ++i)
		{
			if (v[i][c] != cc && v[i][c] != '.')
			{
				vector<char> tmp = getHeurBlocks(v, v[i][c]);
				REP(j, SZ(tmp))
					ret++;
				break;
			}
		}
		for (int i = r; i >= 0; --i)
		{
			if (v[i][c] != cc && v[i][c] != '.')
			{
				vector<char> tmp = getHeurBlocks(v, v[i][c]);
				REP(j, SZ(tmp))
					ret++;
				break;
			}
		}
	}
	
	return ret;
}


int main(){
	while (1)
	{
		scanf("%s", s);
		if (s[0]=='*') break;
		
		spc = s[0];
		
		vs.clear();
		REP(i,6)
		{
			scanf("%s", s);
			vs.push_back(s);
			REP(j,6)
			{
				if (s[i][j] == spc)
					spc_row = i;
			}
		}
		
		
	}
	
	return 0;
}
