#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

//BigNum Template
const int base = 10;
const int maxd = 105;
struct BigNum{
	int d[maxd];
	BigNum(){
		memset(d,0,sizeof(d));
	}
	BigNum(int n){
		memset(d,0,sizeof(d));
		n = abs(n);
		for (int i=0; n>0; ++i){
			d[i] = n%10;
			n /= 10;
		}
	}
	BigNum(string s){
		memset(d,0,sizeof(d));
		int _length = s.length();
		for (int i=0; i<_length; ++i) d[i] = (int)s[_length-i-1]-48;
	}
	int &operator[](const int n){
		return d[n];
	}
	int length(){
		int ret = maxd-1;
		while (d[ret]==0 && ret>0) --ret;
		return ret;
	}
	void print(){
		for (int i=length(); i>=0; --i) printf("%d",d[i]);
		return;
	}
	void println(){
		print(); printf("\n");
		return;
	}
};
const BigNum zero = BigNum(0);
bool operator==(BigNum A, BigNum B){
	for (int i=maxd-1; i>=0; --i) if (A.d[i]!=B.d[i]) return false;
	return true;
}
bool operator!=(BigNum A, BigNum B){
	return !(A==B);
}
bool operator<(BigNum A, BigNum B){
	for (int i=maxd-1; i>=0; --i) if (A.d[i]!=B.d[i]) return A.d[i]<B.d[i];
	return false;
}
bool operator>(BigNum A, BigNum B){
	return B<A;
}
bool operator<=(BigNum A, BigNum B){
	return (A<B || A==B);
}
bool operator>=(BigNum A, BigNum B){
	return (A>B || A==B);
}
BigNum operator*(BigNum A,BigNum B){
	int iA = A.length(),iB = B.length();
	BigNum ret = zero;
	if (A[iA]==0 || B[iB]==0) return ret;
	for (int _iA=0; _iA<=iA; ++_iA){
		if (A[iA] == 0) continue;
		for (int _iB=0; _iB<=iB; ++_iB){
			ret[_iA+_iB] += A[_iA]*B[_iB];
		}
	}
	return ret;
}

/* -------------- end of azaky's template -------------- */

int a[105];
vector<BigNum> x;

void go(int len, int pos, int sum){
	if (sum > 9) return;
	if (pos < (len+1)/2){
		FOR(i,0,2){
			if (pos == 0 && i == 0) continue;
			a[pos] = i;
			go(len,pos+1,sum + (2*pos == len-1 ? 1 : 2)*i*i);
		}
		return;
	}
	FOR(i,(len+1)/2,len-1) a[i] = a[len-i-1];
	BigNum t = zero;
	REP(i,len) t[i] = a[i];
	x.pb(t);
}

int main(){
	x.pb(1); x.pb(2); x.pb(3);
	FOR(len,2,50) go(len,0,0);
	REP(i,(int)x.size()) x[i] = x[i]*x[i];
	//REP(i,50) x[i].println();
	
	int ntc;
	string a, b;
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> a >> b;
		printf("Case #%d: %d\n",itc,(int)(upper_bound(ALL(x),BigNum(b))-lower_bound(ALL(x),BigNum(a))));
	}
	return 0;
}
