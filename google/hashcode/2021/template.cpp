#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define sqr(a) ((a) * (a))
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> getints(const string& s) {
  stringstream ss(s);
  vector<int> res;
  while (ss.good()) {
    int x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}
vector<int> getints() {
  string buffer;
  getline(cin, buffer);
  return getints(buffer);
}
vector<string> getstrs(const string& s) {
  stringstream ss(s);
  vector<string> res;
  while (ss.good()) {
    string x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}
vector<string> getstrs() {
  string buffer;
  getline(cin, buffer);
  return getstrs(buffer);
}

int rnd() {
  return rand();
}
int rnd(int n) {
  return rand() % n;
}
int rnd(int a, int b) {
  return a + rnd(b - a);
}
ll rndll() {
  return (ll)rnd() * INT32_MAX + rnd();
}
ll rndll(ll n) {
  return rndll() % n;
}
ll rndll(ll a, ll b) {
  return a + rndll(b-a);
}
template <typename T> T rnd(vector<T> &a) {
  return a[rnd(a.size())];
}
template <typename T> T rndpop(vector<T>& a) {
  int i = rnd(a.size());
  T pop = a[i];
  a[i] = a.back();
  a.pop_back();
  return pop;
}
vector<int> rndrange(int n, int k) {
  vector<int> a;
  for (int i = 0; i < k; ++i) {
    a.push_back(rnd(n-k+1));
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < k; ++i) {
    a[i] += i;
  }
  return a;
}
double rndf() {
  return (double)rand() / (double)RAND_MAX;
}
double rndf(double a) {
  return rndf() / a;
}
double rndf(double a, double b) {
  return a + rndf(b - a);
}

//////////////////////////////////////
// end of azaky's hashcode template //
//////////////////////////////////////



int main(int argc, char** argv) {
  srand(0);

  

  return 0;
}