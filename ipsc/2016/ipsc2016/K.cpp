//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#define TESTING 1

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

/*#include <algorithm>
#include <vector>
using namespace std;

long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

long long f1(long long n) {
    return (-n*n*n + 947*n*n + 20647474747LL*n + 47) / 20000000047LL;
}

long long f2(long long n) {
    return (-n*n + 2084747*n + 47) / 2494747;
}

long long f3(long long n) {
    return (-n*n*n + 19647*n*n + 23254474747LL*n - 25384747*(n%97)*n + 47 ) / 25382294747LL;
}

void sort_helper(vector<unsigned> &A, int lo, int hi) {
    long long n = hi - lo;
    if (n <= 2) {
        if (n == 2 && A[lo] > A[lo+1]) swap( A[lo], A[lo+1] );
        return;
    }
    long long a = median( 0, n-1, f1(n) );
    long long b = median( 0, n-1, f2(n) );
    long long c = median( 0, n-1, f3(n) );
    sort_helper( A, lo, lo+a );
    sort_helper( A, hi-b, hi );
    sort_helper( A, lo, lo+c );
}

// this is the main function
void k1_sort(vector<unsigned> &A) {
    sort_helper( A, 0, A.size() );
}*/

#include <algorithm>
#include <vector>
using namespace std;

// this is just a standard pseudorandom generator
struct PRNG {
    long long seed;
    PRNG(long long seed) : seed(seed) {}

    long long _random() {
        long long M = 2147483647, A = 16807;
        long long Q = M/A, R = M%A;
        seed = A*(seed%Q) - R*(seed/Q);
        if (seed <= 0) seed += M;
        return seed;
    }

    long long randint(int lo, int hi) {
        return lo + _random() % (hi-lo);
    }
};

long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

void modify(vector<unsigned> &A, int x, int y, bool magic) {
    if (A[x] > A[y] || !magic) swap( A[x], A[y] );
}

// this is the main function
void k2_sort(vector<unsigned> &A) {
    PRNG generator(589);
    
    int N = A.size();
    int L = 1;
    while ((1<<L) < N) ++L;
    int lo = (N - (1<<L)) / 2;
   
    for (int superphase=0; superphase<2; ++superphase) {
        for (int phase=1; phase<=L; ++phase) {
            for (int subphase=phase; subphase>=1; --subphase) {
                if (phase == L && subphase == L) {
                    for (int i=0; i < (1<<(L-1)); ++i) {
                        int x = lo+i, y = lo+(1<<L)-1-i;
                        if (x >= 0 && y < N) modify( A, x, y, L*superphase+phase >= 2*(L-1) );
                    }
                }
                for (int block=0; block<(1<<(L-subphase)); ++block) {
                    int xlo  = median( 0, N, lo + (block << subphase) );
                    int xmed = median( 0, N, lo + (block << subphase) + (1<<(subphase-1)) );
                    int xhi  = median( 0, N, lo + (block << subphase) + (1<<subphase) );
                    if (xlo == xmed || xmed == xhi) continue;
                    for (int comparison=0; comparison<521; ++comparison) {
                        int x = generator.randint(xlo,xmed);
                        int y = generator.randint(xmed,xhi);
                        modify( A, x, y, L*superphase+phase >= 2*(L-1) );
                    }
                }
            }
        }
    }
}


bool valid(vector<unsigned> &A)
{
  REP(i,SIZE(A)-1) if(A[i] > A[i+1]) return true;
  return false;
}

void print(vector<unsigned> &A)
{
  REP(i,SIZE(A)) cout << A[i] << " ";
  cout << endl;
}

int main()
{
  srand(time(0));
  FORD(i,46,10) 
  {
    VALUE(i);
    FORN(k,1,10000)
    {
      vector<unsigned> A;
      FORD(j,i,1) A.pb(j);
      random_shuffle(ALL(A));
      vector<unsigned> B = A;
      k2_sort(A);
      if (valid(A)) {
        printf("%d\n",SIZE(B));
        print(B);
        return 0;
      }
    }
  }
  /*vector<unsigned> A = {};
  for (int i = 90208; i >= 1; --i) A.pb(i);
  print(A);
  k1_sort(A);*/
  //VALUE(valid(A));
  /*while (1)
  {
    DEBUG;
    vector<unsigned> A = {};
    int n = rand() % 100;
    REP(i,n)
    {
      A.pb(rand() % 10);
    }
    print(A);
    k1_sort(A);
    print(A);
    if (valid(A)) 
    {
      puts("OK");
      return 0;
    }
  }
  return 0;*/
}









