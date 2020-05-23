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
int spc_row;

int gen, nextgen;

int ans;
int steps;

queue<vector<string> > q[2];
set<vector<string> > hash;

int used[40];

int main(){
	while (1)
	{
		scanf("%s", s);
		if (s[0]=='*') break;
		
		spc = s[0];
		
		vector<string> inp;
		inp.clear();
		
		REP(i,6)
		{
			scanf("%s", s);
			inp.push_back(s);
			REP(j,6)
			{
				if (s[j] == spc)
					spc_row = i;
			}
		}
		
		gen = 0;
		nextgen = 1;
		
		while (q[0].size()) q[0].pop();
		while (q[1].size()) q[1].pop();
		
		q[0].push(inp);
		
		hash.clear();
		
		steps = 0;
		ans = -1;
		
		while (q[0].size()+q[1].size() > 0)
		{
			if (q[gen].size() == 0)
			{
				gen = 1-gen;
				nextgen = 1-gen;
				
				steps++;
				continue;
			}
			
			vector<string> vs;
			vs.clear();
			vs = q[gen].front();
			q[gen].pop();
			
			/*
			printf("\ncur state : \n");
			REP(i, 6)
			{
				cout << vs[i]<< endl;
			} */
			
			// check if finished
			int c;
			for (c = 0; c < 6; ++c)
			{
				if (vs[spc_row][c] == spc) break;
			}
			
			for (c = 0; c < 6; ++c)
			{
				if (vs[spc_row][c] != spc && vs[spc_row][c] != '.') break;
			}
			
			if (c >= 6)
			{
				ans = steps+1;
				break;
			}
			
			// check if state is already calculated
			if (hash.count(vs) > 0)
				continue;
				
			hash.insert(vs);
			
			vector<string> vtemp;
			
			RESET(used, 0);
			REP(i,6)
			{
				REP(j,6)
				{
					if (vs[i][j] == '.') continue;
					if (used[vs[i][j]-'A']) continue;
					
					used[vs[i][j]-'A'] = 1;
					
					int hor = 0;
					if (j)
						hor = (vs[i][j-1] == vs[i][j])?1:0;
					if (hor == 0 && j < 5)
						hor = (vs[i][j+1] == vs[i][j])?1:0;
						
					vtemp.clear();
					vtemp = vs;
						
					if (hor)
					{
						int bsz = 0;
						for (int k = j; k < 6; ++k)
						{
							if (vs[i][k] == vs[i][j])
								bsz++;
							else
								break;
						}
						
						// geser kiri
						for (int k = j-1; k >= 0; --k)
						{
							if (vtemp[i][k] == '.')
							{
								vtemp[i][k] = vs[i][j];
								vtemp[i][k+bsz] = '.';
								/*
								printf("\next state?? : \n");
								REP(i, 6)
								{
									cout << vs[i]<< endl;
								} */
								if (hash.count(vtemp) > 0)
									continue;
								//printf("YESSS\n");
								q[nextgen].push(vtemp);
							}
							else
								break;
						}
						
						// reset horizontal
						REP(k, 6)
						{
							vtemp[i][k] = vs[i][k];
						}
						
						// geser kanan
						for (int k = j+bsz; k < 6; ++k)
						{
							if (vtemp[i][k] == '.')
							{
								vtemp[i][k] = vs[i][j];
								vtemp[i][k-bsz] = '.';
								if (hash.count(vtemp) > 0)
									continue;
								q[nextgen].push(vtemp);
							}
							else
								break;
						}
					}
					else
					{
						int bsz = 0;
						for (int k = i; k < 6; ++k)
						{
							if (vs[k][j] == vs[i][j])
								bsz++;
							else
								break;
						}
						
						// geser atas
						for (int k = i-1; k >= 0; --k)
						{
							if (vtemp[k][j] == '.')
							{
								vtemp[k][j] = vs[i][j];
								vtemp[k+bsz][j] = '.';
								if (hash.count(vtemp) > 0)
									continue;
								q[nextgen].push(vtemp);
							}
							else
								break;
						}
						
						// reset vertikal
						REP(k, 6)
						{
							vtemp[k][j] = vs[k][j];
						}
						
						// geser bawah
						for (int k = i+bsz; k < 6; ++k)
						{
							if (vtemp[k][j] == '.')
							{
								vtemp[k][j] = vs[i][j];
								vtemp[k-bsz][j] = '.';
								if (hash.count(vtemp) > 0)
									continue;
								q[nextgen].push(vtemp);
							}
							else
								break;
						}
					}
					 
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
