#include <cstdio>
#include <cstring>
#define MAXN 511111

using namespace std;

bool prime[MAXN];
int t,e,f,tc,n,sigma[MAXN],np[MAXN];

int main(){
	//sieve eratosthenes
	memset(prime,true,sizeof(prime));
	prime[1] = false;
	for (int i=2; i*i<MAXN; ++i)
		if (prime[i])
			for (int j=2; i*j<MAXN; ++j){
				prime[i*j] = false;
				np[i*j] = i;
			}
	for (int i=2; i<MAXN; ++i)
		if (prime[i])
			np[i] = i;
	//pre-calculate
	sigma[1] = 1;
	for (int i=2; i<MAXN; ++i){
		t = i;
		for (e=0; t%np[i]==0; ++e) t/=np[i];
		f = 1;
		for (int j=0; j<e; ++j)
			f = np[i]*f + 1;
		sigma[i] = sigma[t]*f;
	}
	scanf("%d",&tc);
	while (tc--){
		scanf("%d",&n);
		printf("%d\n",sigma[n]-n);
	}
	return 0;
}
