#include <cstdio>
using namespace std;

int k,r,m,n,x,y,s[111],val[111],px[111],py[111],ans = 0;

int main(){
	scanf("%d%d",&k,&r);
	scanf("%d",&m);
	for (int i=0; i<m; ++i)
		scanf("%d%d",&px[i],&py[i]);
	scanf("%d",&n);
	for (int i=0; i<n; ++i){
		scanf("%d%d%d",&x,&y,&s[i]);
		val[i] = 0;
		for (int j=0; j<m; ++j)
			if ((x-px[j])*(x-px[j])+(y-py[j])*(y-py[j]) <= r*r)
				val[i] += (1 << j);
		}
	for (int ss=0; ss<(1 << m); ++ss){
		x = 0;
		for (int i=0; i<m; ++i)
			if ((ss & (1 << i))>0) ++x;
		if (x!=k) continue;
		y = 0;
		for (int i=0; i<n; ++i)
			if ((val[i] & ss)>0) y += s[i];
		if (y>ans) ans = y;
		}
	printf("%d\n",ans);
	return 0;
}
	
