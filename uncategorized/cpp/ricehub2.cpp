#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100100;
int n,ans;
long long r[MAXN],sum[MAXN],l,d;

inline long long GetSum(int l,int r){
	return sum[r]-sum[l-1];
}
inline long long GetCost(int _l,int _r){
	int med = (_l+_r)/2;
	return (2*med-_l-_r)*r[med]-GetSum(_l,med-1)+GetSum(med+1,_r);
}

int main(){
	cin >> n >> l >> d;
	for (int i=1; i<=n; ++i) scanf("%I64d",&r[i]);
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + r[i];
	for (int l=1,r=1; l<=n && r<=n; ++l){
		while (GetCost(l,r)<=d && r<=n) ++r; --r;
		ans = r-l>ans ? r-l : ans;
	}
	cout << ans+1 << endl;
	return 0;
}
