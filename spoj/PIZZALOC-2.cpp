#include <cstdio>
using namespace std;

int k,r,m,n,x,y,s[111],val[111],px[111],py[111],ans = 0;

void pizza(int v, int x, int ss){
	if (x>k || x+m<v+k) return;
	if (v<m && x<k){
		pizza(v+1,x,ss);
		pizza(v+1,x+1,ss+(1 << v));
		return;
	}
	y = 0;
	for (int i=0; i<n; ++i)
		if ((val[i] & ss)>0) y += s[i];
	if (y>ans) ans = y;
	return;
}

int main(){
	scanf("%d%d%d",&k,&r,&m);
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
	pizza(0,0,0);
	printf("%d\n",ans);
	return 0;
}
	
