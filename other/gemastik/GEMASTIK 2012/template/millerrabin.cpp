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
bool MillerRabin(long long n){
	if (n==1) return false;
	if (n < 4) return true;
	long long s = 0, d = n, r;
	while (d%2==0){
		s++; d/=2;
	}
	for (int i=0; i<k; ++i){
		a = random(2,n-2);
		x = pmod(a,d,n);
		if (x == 1 || x == n-1) continue;
		for (r = 1; r < s; ++r){
			x = (x*x) % n;
			if (x == 1) return false;
			if (x == n-1) continue;
		}
		return false;
	}
	return true;
}
	
