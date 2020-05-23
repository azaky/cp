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


int row, col;
int i, j;

char s[105][105];
int a[105][105];


int main(){
	while (1)
	{
		scanf("%d%d",&row,&col);
		
		if (row+col == 0) return 0;
		
		for (i = 0; i < row; ++i)
		{
			scanf("%s", s[i]);
		}
		
		RESET(a, 0);
		
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j)
			{
				if (s[i][j] == '*')
				{
					for (int r = -1; r <= 1; ++r)
						for (int c = -1; c <= 1; ++c)
						{
							int newr = i+r;
							int newc = j+c;
							
							if (newr < 0 || newr >= row || newc < 0 || newc >= col)
								continue;
							
							if (s[newr][newc] == '.')
								a[newr][newc]++;
						}
				}
			}
				
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < col; ++j)
			{
				if (s[i][j] == '*')
					printf("*");
				else
					printf("%d", a[i][j]);
			}
			printf("\n");
		}
	
	}
	
	return 0;
}
