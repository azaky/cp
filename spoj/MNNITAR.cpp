#include <vector>
#include <iostream>
using namespace std;

typedef vector<vector<long long> > matrix;
#define MOD 1000000007

matrix zero(2,vector<long long>(2));
long long tc,n,f;

matrix pr(matrix a, matrix b){
	matrix ret = zero;
	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			for (int k=0; k<2; ++k)
				ret[i][j] = (ret[i][j] + a[i][k]*b[k][j])%(MOD-1);
	return ret;
}

matrix po(matrix a, long long k){
	matrix ret = zero;
	if (k==0){
		ret[0][0] = 1; ret[0][1] = 0;
		ret[1][0] = 0; ret[1][1] = 1;
		return ret;
	}
	ret = po(a,k/2);
	ret = pr(ret,ret);
	if (k%2) ret = pr(ret,a);
	return ret;
}

long long pm(long long a,long long b){
	if (b==0) return 1;
	long long ret = pm(a,b/2);
	ret = (ret*ret)%MOD;
	if (b%2) ret = (ret*a)%MOD;
	return ret;
}

int main(){
	matrix init(2,vector<long long>(2));
	init[0][0] = 0;
	init[0][1] = 1;
	init[1][0] = 1;
	init[1][1] = 1;
	cin >> tc;
	while (tc--){
		cin >> n;
		if (n==0){
			cout << "1\n";
			continue;
		}
		cout << pm(2LL,po(init,n)[1][0]) << endl;
	}
	return 0;
}
