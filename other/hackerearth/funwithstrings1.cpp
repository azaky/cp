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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

/** Suffix Tree Ukkonen's algorithm **/
/* Complexity: O(N) (Warning: large multiplier) */

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz0";
const int NALPHABET = 27;

int nodecount;

struct Node {
  int begin, end, depth;
  Node* parent;
  Node** children;
  Node* suffixLink;
  int value;

  Node(int begin, int end, int depth, Node* parent) {
    this->begin = begin;
    this->end = end;
    this->depth = depth;
    this->parent = parent;
    this->children = new Node*[NALPHABET];
    for (int i = 0; i < NALPHABET; ++i) {
      this->children[i] = NULL;
    }
    this->value = nodecount++;
  }

  ~Node() {
    delete[] children;
  }

  void printTab(int times) {
    for (int i = 0; i < times; ++i) {
      putchar('\t');
    }
  }

  void print(int level = 0) {
    printTab(level);
    printf("(%d..%d, %d)\n", begin, end, depth);
    for (int i = 0; i < NALPHABET; ++i) {
      if (this->children[i] != NULL) {
        printTab(level);
        printf("%c:\n", ALPHABET[i]);
        this->children[i]->print(level + 1);
      }
    }
  }
};

Node* buildSuffixTree(string s) {
  int n = s.length();
  char* a = new char[n];
  for (int i = 0; i < n; ++i) {
    a[i] = (char) ALPHABET.find(s[i]);
  }

  Node* root = new Node(0, 0, 0, NULL);
  Node* node = root;
  for (int i = 0, tail = 0; i < n; ++i, ++tail) {
    Node* last = NULL;
    while (tail >= 0) {
      Node* ch = node->children[a[i - tail]];
      while (ch != NULL && tail >= ch->end - ch->begin) {
        tail -= (ch->end - ch->begin);
        node = ch;
        ch = ch->children[a[i - tail]];
      }

      if (ch == NULL) {
        node->children[a[i]] = new Node(i, n, node->depth + node->end - node->begin, node);
        if (last != NULL) {
          last->suffixLink = node;
        }
        last = NULL;
      } else {
        char t = a[ch->begin + tail];
        if (t == a[i]) {
          if (last != NULL) {
            last->suffixLink = node;
          }
          break;
        } else {
          Node* splitNode = new Node(ch->begin, ch->begin + tail, node->depth + node->end - node->begin, node);
          splitNode->children[a[i]] = new Node(i, n, ch->depth + tail, splitNode);
          splitNode->children[t] = ch;
          ch->begin += tail;
          ch->depth += tail;
          ch->parent = splitNode;
          node->children[a[i - tail]] = splitNode;
          if (last != NULL) {
            last->suffixLink = splitNode;
          }
          last = splitNode;
        }
      }
      if (node == root) {
        --tail;
      } else {
        node = node->suffixLink;
      }
    }
  }
  delete[] a;

  return root;
}

#define MAXN 1100100
#define MOD 1000000007LL
#define HALF 500000004LL
#define THIRD 333333336LL

ll sum(ll x) {
	return ((x * (x + 1)) % MOD * HALF) % MOD;
}

ll sum2(ll x) {
	return ((sum(x) * (x + x + 1) % MOD) * THIRD) % MOD;
}

ll sqr(ll x) {
	return (x * x) % MOD;
}

ll cSubstring[MAXN], cAns[MAXN], cLeaf[MAXN];

void dfs(Node* node) {
	int idx = node->value;
	bool isLeaf = true;
	REP(i, 27) {
		if (node->children[i] != NULL) {
			isLeaf = false;
			dfs(node->children[i]);
		}
	}

	ll len = node->end - node->begin;

	if (isLeaf) {
		cSubstring[idx] = len;
		cLeaf[idx] = 1;
		len--;
		cAns[idx] = ((len + 1) * sum(len) - sum2(len)) * 2;
		cAns[idx] %= MOD;
		cAns[idx] -= sum(len);
		cAns[idx] += MOD;
		cAns[idx] %= MOD;
	} else {
		cSubstring[idx] = 0;
		cAns[idx] = 0;
		cLeaf[idx] = 0;
		REP(i, 27) {
			if (node->children[i] == NULL) continue;
			int child = node->children[i]->value;
			cLeaf[idx] += cLeaf[child];
			cSubstring[idx] += cSubstring[child];
			cSubstring[idx] %= MOD;
			cAns[idx] += cAns[child] + sqr(cSubstring[child]) * len;
			cAns[idx] %= MOD;
		}
		ll addum = 0;
		REP(i, 27) {
			if (node->children[i] == NULL) continue;
			int child = node->children[i]->value;
			addum += (((cSubstring[idx] - cSubstring[child]) * len) % MOD) * cSubstring[child];
			addum %= MOD;
		}
		cAns[idx] += addum;
		cAns[idx] %= MOD;

		ll sub = (len * sum(len - 1) - sum2(len - 1)) * 2;
		sub -= sum(len - 1);
		sub += MOD;
		sub %= MOD;
		cAns[idx] += sub * sqr(cLeaf[idx]);
		cAns[idx] += (cSubstring[idx] * sum(len - 1)) % MOD * 2 * cLeaf[idx];
		cAns[idx] %= MOD;

		cSubstring[idx] += len * cLeaf[idx];
		cSubstring[idx] %= MOD;
	}

	// printf("node %d: [%d..%d)\n", idx, node->begin, node->end);
	// REP(i, 27) {
	// 	if (node->children[i] != NULL) {
	// 		printf("%d -> %d\n", idx, node->children[i]->value);
	// 	}
	// }
	// printf("cSubstring[%d] = %lld\n", idx, cSubstring[idx]);
	// printf("cAns[%d] = %lld\n", idx, cAns[idx]);
	// printf("cLeaf[%d] = %lld\n", idx, cLeaf[idx]);
	// puts("");
}

int ntc, n;
char s[MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%s", &n, s);
		s[n] = '0'; s[n + 1] = 0;
		nodecount = 0;
		Node* root = buildSuffixTree(s);
		dfs(root);
		printf("%lld\n", cAns[root->value]);
	}
	
	return 0;
}
