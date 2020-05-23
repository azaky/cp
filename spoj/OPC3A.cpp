#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 1000000007LL
#define MAXN 1000100
int n,tc;
long long g[MAXN];

int main(){
	g[0] = 1;
	g[1] = 2;
	for (int i=2; i<MAXN; ++i) g[i] = (g[i-1]*g[i-2])%MOD;
	scanf("%d",&tc);
	while (tc--){
		scanf("%d",&n);
		cout << g[n] << endl;
	}
	return 0;
}
