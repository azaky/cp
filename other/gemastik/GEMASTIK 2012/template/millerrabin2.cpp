#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

#define LIM 32768
int GetInt(int l,int r){
	int x = (rand()%LIM)*LIM + (rand()%LIM);
	return l + x%(r-l+1);
}

void apapa(int apa, int &apa1){
	return;
}

#define LIMLL 1073741824LL
long long GetLL(long long l, long long r){
	long long x = (long long)GetInt(1,(int)LIMLL)*LIMLL + (long long)GetInt(1,(int)LIMLL);
	return l + x%(r-l+1);
}

/*
Input: n > 3, an odd integer to be tested for primality;
Input: k, a parameter that determines the accuracy of the test
Output: composite if n is composite, otherwise probably prime
write n − 1 as 2s·d with d odd by factoring powers of 2 from n − 1
LOOP: repeat k times:
   pick a random integer a in the range [2, n − 2]
   x ← a^d mod n
   if x = 1 or x = n − 1 then do next LOOP
   for r = 1 .. s − 1
      x ← x^2 mod n
      if x = 1 then return composite
      if x = n − 1 then do next LOOP
   return composite
return probably prime
*/

long long pmod(long long a, long long b, long long mod){
	if (b == 0) return 1;
	long long ret = pmod(a,b/2,mod);
	ret = (ret*ret) % mod;
	if (b%2) ret = (ret*a) % mod;
	return ret;
}

bool MillerRabin(long long n){
	if (n < 2 || n%2 == 0) return false;
	if (n < 4) return true;
	long long s = 0, d = n-1, r, a, x;
	bool next;
	while (d%2==0){
		s++; d/=2;
	}
	debug("n = %I64d, s = %I64d, d = %I64d\n",n,s,d);
	for (int i=0; i<20; ++i){
		a = GetLL(2,n-2);
		x = pmod(a,d,n);
		debug("a = %I64d, x = %I64d\n",a,x);
		if (x == 1 || x == n-1) continue;
		next = false;
		for (r = 1; r < s; ++r){
			x = (x*x) % n;
			if (x == 1) return false;
			if (x == n-1){
				next = true;
				break;
			}
		}
		if (next) continue;
		return false;
	}
	return true;
}

bool prime(long long x){
	if (x < 2 || x%2 == 0) return false;
	if (x < 4) return true;
	for (long long d = 3; d*d <= x; ++d){
		if (x%d == 0) return false;
	}
	return true;
}

int main(){
	srand(time(NULL));
	
	long long x, LIMIT = 1000000000LL;
	
	for (x = 100000001LL; x < LIMIT; x += 2){
		if (prime(x) != MillerRabin(x)) printf("ERROR x = %I64d\n",x);
		if (x % 10000000LL == 1) printf("%I64d DONE\n",x);
	}
	
	printf("TESTS DONE\n");
	
	while (true){
		scanf("%I64d",&x);
		printf("%s\n",MillerRabin(x) ? "PRIME" : "COMPOSITE");
	}
	
	return 0;
}
