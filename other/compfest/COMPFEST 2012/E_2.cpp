#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#define fi first
#define se second
using namespace std;
int T;
int N,M;
bool bisa[50001][54];
pair <int,pair <int,int > > pl[50001];

int bit[54][50001];
int res[50001];

int temps[50001];

int sum(int jur_id,int x) {
	int tmp = 0;
	for (int i = x; i>0; i -= (i & -i) ){
		tmp += bit[jur_id][i];
	}
	return tmp;
}

int add(int jur_id,int x) {
	for (int i = x; i <= 50000; i += (i & -i)) {
		bit[jur_id][i] += 1;
	}
}

int main() {
	scanf("%d%d",&N,&M);
	
	for (int i=0;i<N;i++) {
		int x;
		scanf("%d%d%d",&pl[i].fi,&pl[i].se.fi, &x);
		pl[i].fi*=-1;
		pl[i].se.fi =50001 - pl[i].se.fi;
		pl[i].se.se = i;
		for (int j=0;j<x;j++) {
			int tmp;
			scanf("%d",&tmp);
			bisa[i][tmp]=1;
		}
	}
	M++;
	sort(pl , pl+N);
	
	int berti = pl[0].fi;
	for (int i=0;i<M;i++) temps[i] = 999999;
	for (int i=0;i<N;i++) {
		int tmp = 0;
		int id = pl[i].se.se;
		
		//printf("codemon #%d -- level %d\n",id,pl[i].fi);
	
		for (int j=0;j<M;j++) {
			if (bisa[id][j]) temps[j] = min(temps[j], pl[i].se.fi);
			
			
				int cinta = sum(j, pl[i].se.fi - 1);	
				if (cinta >= 1 || bisa[id][j]) tmp++;
			//printf(" belajar jurus %d = %d\n",j,cinta);
			//if (bisa[id][j]) printf("  bisa jurus %d\n",j);
					
		}
		if ((i + 1 < N) && pl[i].fi != pl[i + 1].fi) {
		//printf(" ============ add jurus! \n");
			for (int j=0;j<M;j++){
				if (temps[j]!=999999) {
				add(j,temps[j]);
					//printf("jurus %d di power %d\n",j,temps[j]);
				}
					temps[j] = 999999;
				}
				
		}
		
		berti = pl[i].fi;
		res[id] = tmp;	
	}
	
	for (int i=0;i<N;i++)
		printf("%d\n",res[i]);
}
