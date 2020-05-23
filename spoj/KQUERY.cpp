#include <algorithm>
#include <cstdio>
using namespace std;

#define getchar_unlocked getchar
int getint(){
	int ret = 0;
	char ch = getchar_unlocked();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar_unlocked();
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar_unlocked()) && ('0' <= ch && ch <= '9'));
	return ret;
}

struct PII{
	int fi, se;
};
struct Query{
	int x, y, k, i;
};
bool comp(const Query &a, const Query &b){ return b.k < a.k; }
bool compb(const PII &a, const PII &b){ return b.fi < a.fi; }

const int maxn = 30000;
const int maxq = 200002;
int n, nq, iq, ans[maxq], bit[maxn+1];
Query q[maxq];
PII b[maxn+1];

void update(int k){for (int x = k; x <= maxn; x += (x & -x)) bit[x]++;}
int query(int k){int sum = 0; for (int x = k; x > 0; x -= (x & -x)) sum += bit[x]; return sum;}


int main(){
	n = getint();
	for (int i=1; i <= n; ++i) b[i].fi = getint(), b[i].se = i;
	sort(b+1,b+n+1,compb);
	nq = getint();
	for (int i = 0; i < nq; ++i){
		q[i].x = getint(); q[i].y = getint(); q[i].k = getint();
		q[i].i = i;
	}
	sort(q,q+nq,comp);
	iq = 0;
	for (int i=1; i <=n; ++i){
		if (b[i].fi == b[i-1].fi){update(b[i].se); continue;}
		while (iq < nq && q[iq].k >= b[i].fi){ans[q[iq].i] = query(q[iq].y)-query(q[iq].x-1); iq++;}
		update(b[i].se);
	}
	while (iq < nq){ans[q[iq].i] = q[iq].y - q[iq].x + 1; iq++;}
	for (int i=0; i < nq; ++i) printf("%d\n",ans[i]);
	return 0;
}
