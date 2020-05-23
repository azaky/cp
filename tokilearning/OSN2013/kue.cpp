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

int t, a[1111], k[1111], u[1111], v[111][22][22];

void query(int nd){
	sort(a,a+10);
	printf("%d\n",10);
	REP(i,10) printf("%d\n",a[i]);
	fflush(stdout);
	int n, x;
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&x);
		FOR(_k,1,20) REP(_u,_k){
			if (nd % _k == _u){
				v[x][_k][_u]++;
			}
		}
	}
}

db prob(int x, int u, int k, int nd){
	int total = nd/k;
	if (nd%k == u) total++;
	if (total == 0) return 0;
	return (db)v[x][k][u]/(db)total;
}

//sum[i_kue][k][u][nd] :

int main(){
	srand(time(0));
	
	char subsoal[11]; scanf("%s %d",subsoal,&t);
	scanf("%d",&t);
	REP(ii,t){
		if (ii < 0){
			//choose 10 random values
			map<int,int> hoho;
			REP(i,10){
				do{a[i] = (rand()%100)+1;} while (hoho[a[i]]);
				hoho[a[i]] = 1;
			}
			query(ii);
		}
		else {
			//buat tiap kue, nyari nilai k dan u sehingga
			//dia paling sering muncul di u % k
			FOR(i,1,100){
				db now = -1;
				FOR(_k,1,20) REP(_u,_k){
					if (prob(i,_u,_k,ii) > now){
						now = prob(i,_u,_k,ii);
						k[i] = _k;
						u[i] = _u;
					}
				}
			}
			//cari yang probnya paling gede buat hari ini
			priority_queue <pair<db,int> > hehe;
			FOR(i,1,100){
//				printf("->%d->%d\n",i, k[i]);
				if (ii%k[i] == u[i]){
					hehe.push(MP(prob(i,u[i],k[i],ii),i));
				}
			}
//			puts("HOHO");
			int n = 0;
			map <int,int> hoho;
			while (n < 10 && !hehe.empty()){
				if (hehe.top().A == 0) break;
				a[n] = hehe.top().B;
				hehe.pop();
				hoho[a[n]] = 1;
				n++;
			}
			while (n < 10){
				do {a[n] = (rand()%100)+1;} while (hoho[a[n]]);
				hoho[a[n]] = 1;
				n++;
			}
			query(ii);
		}
	}
	
	return 0;
}
