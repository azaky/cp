#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 200000
#define INF 2000000000

using namespace std;

int n,a,b,n1,n2,s1,s2,a1[50],a2[50],sum,sum1[MAXN],sum2[MAXN],l,r;
long long ans = 0;

int findless(int x){
	int l=0, r=s1+1, mid;
	while (l<r){
		mid = (l+r)/2;
		if (sum1[mid]>=x) r = mid-1;
			else l = mid+1;
		if (sum1[l]>=x) return mid;
	}
	return l;
}

int findmore(int x){
	int l=0, r=s1+1, mid;
	while (l<r){
		mid = (l+r)/2;
		if (sum1[mid]<=x) l = mid+1;
			else r = mid;
		}
	return l;
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	n1 = n/2;
	s1 = 1 << n1;
	n2 = n-n1;
	s2 = 1 << n2;
	for (int i=0; i<n1; ++i) scanf("%d",&a1[i]);
	for (int s=0; s<s1; ++s){
		sum = 0;
		for (int i=0; i<n1; ++i)
			if ((s & (1 << i)) > 0) sum += a1[i];
		sum1[s+1] = sum;
	}
	for (int i=0; i<n2; ++i) scanf("%d",&a2[i]);
	for (int s=0; s<s2; ++s){
		sum = 0;
		for (int i=0; i<n2; ++i)
			if ((s & (1 << i)) > 0) sum += a2[i];
		sum2[s] = sum;
	}
	sort(sum1+1,sum1+(s1+1));
	sum1[0] = -INF; sum1[s1+1] = INF;
	for (int i=0; i<s2; ++i){
		l = findless(a-sum2[i]);
		r = findmore(b-sum2[i]);
		if (r>l) ans += (long long)(r-l-1);
	}
	printf("%lld\n",ans);
	return 0;
}
	
