/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
  #define debug(...) printf(__VA_ARGS__)
  #define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
  #define debug(...) 
  #define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

typedef vector<long long> vll;

vll karatsubaMultiply(const vll &a, const vll &b) {
  int n = a.size();
  vll res(n + n);
  if (n <= 32) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        res[i + j] += a[i] * b[j];
    return res;
  }

  int k = n >> 1;
  vll a1(a.begin(), a.begin() + k);
  vll a2(a.begin() + k, a.end());
  vll b1(b.begin(), b.begin() + k);
  vll b2(b.begin() + k, b.end());

  vll a1b1 = karatsubaMultiply(a1, b1);
  vll a2b2 = karatsubaMultiply(a2, b2);

  for (int i = 0; i < k; i++)
    a2[i] += a1[i];
  for (int i = 0; i < k; i++)
    b2[i] += b1[i];

  vll r = karatsubaMultiply(a2, b2);
  for (int i = 0; i < (int) a1b1.size(); i++)
    r[i] -= a1b1[i];
  for (int i = 0; i < (int) a2b2.size(); i++)
    r[i] -= a2b2[i];

  for (int i = 0; i < (int) r.size(); i++)
    res[i + k] += r[i];
  for (int i = 0; i < (int) a1b1.size(); i++)
    res[i] += a1b1[i];
  for (int i = 0; i < (int) a2b2.size(); i++)
    res[i + n] += a2b2[i];
  return res;
}

vll naiveMultiplication(const vll& a, const vll& b) {
  int na = SZ(a), nb = SZ(b);
  vll result(na + nb - 1);
  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < nb; ++j) {
      result[i + j] += a[i] * b[j];
    }
  }
  return result;
}

int main(){
  int n;
  long long x;
  vll a, b;
  scanf("%d",&n);
  REP(i,n){
    scanf("%lld",&x);
    a.PB(x);
  }
  scanf("%d",&n);
  REP(i,n){
    scanf("%lld",&x);
    b.PB(x);
  }
  vll res = karatsubaMultiply(a, b);
  REP(i,SZ(res)) printf("%lld ",res[i]); puts("");
  vll res2 = naiveMultiplication(a, b);
  REP(i,SZ(res2)) printf("%lld ",res2[i]); puts("");
}