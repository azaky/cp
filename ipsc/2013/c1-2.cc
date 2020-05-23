#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

int B[] = { 1894607624,
			1927505134,
			1861486949, 
			2052221263, 
			1953703270, 
			1772249212, 
			1704106159, 
			147456, 
			1829198849 };
std::vector<int> A(B,B+9);
/*
long long t(long long n) {
    long long z=n;
    for (long long a=2; a<n; ++a)
		if (t(a)>=a)
			if (n%a==0) { z/=t(a); z*=t(a)-1; }
    return std::min(z+1,n);
}
*/
typedef long long ll;
ll t(ll n){
	ll z = n, res = n;
	for (ll a=2; a*a <= n; ++a){
		if (z%a == 0){
			res /= a; res *= a-1;
			while (z%a == 0) z/=a;
		}
	}
	if (z != 1){
		res /= z; res *= z-1;
	}
	return res+1;
}

int main() {
//	puts("done");
    sort( A.begin(), A.end() );
//   puts("done");
    for (int i=0; i<4; ++i) A[i+5] ^= t(A[i+1]-A[0])>>7;
//    puts("done");
    long long z = std::max( t(A[0])-1, A[0]+1-t(A[0]) );
//    puts("done");
//    printf("%I64d\n",z%9);
    for (long long i=0; i-9<z%(int)A.size(); ++i)
		std::rotate( A.begin(), A.begin()+1, A.end() );
//    puts("done");
    A.insert( A.begin()+1, z );
//    puts("done");
    for (long long x=8; x<1e7; ++x) {
        int y = A[x/4]>>(18-6*(x%4))&63;
        if (!y) break;
        if (y<60) std::cout << char(31+y); else std::cout << A[y-60];
    }
}
