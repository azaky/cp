#include <cstdio>
using namespace std;

long long getLL(){
	long long ret = 0, mul = 1LL;
	char ch = getchar_unlocked();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar_unlocked();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar_unlocked();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar_unlocked()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getLL(long long &x){
	x = getLL();
}

/* -------------- end of azaky's template -------------- */

typedef long long LL;

LL n,t,m,a,b;
LL adj[1001][16], adjb[1001][16];

inline LL connected(LL a,LL b){return adj[a][(b-1)/63] & (1LL<<((b-1)%63));}
inline void connect(LL a,LL b){adj[a][(b-1)/63] |= (1LL<<((b-1)%63));}

int main(){
	getLL(n); getLL(t);
	m = n/63LL + 1;
	for (LL v = 1; v <= n; ++v) connect(v,v);
	for (LL s = 0; s < t; ++s){
		a = getLL(); b = getLL();
		if (connected(b,a)){
			printf("%lld %lld\n",a,b);
			continue;
		}
		if (connected(a,b)) continue;
		for (LL v = 1; v <= n; ++v)
			if (connected(v,a))
				for (LL i = 0; i < m; ++i) adj[v][i] |= adj[b][i];
	}
	puts("0 0");
	return 0;
}
