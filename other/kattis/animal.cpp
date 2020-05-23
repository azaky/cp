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
#include <limits>
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

/** Lowest Common Ancestor **/
/* complexity : LCApre : O(N log N), LCAquery : O(log N) */
/* legend:
 * N : number of vertices. WARNING: zero based
 * T : direct parent. T[v] is parent of v
 * L : L[v] is the level of v. zero/one based is okay
 * P : dp table of size [MAXN][LOGMAXN]. P[v][i] is the 2^i-th parent of v
 */

#define MAXN 262144
#define LOGMAXN 20

int L[MAXN], P[MAXN][LOGMAXN], T[MAXN], N;

void pre(){
	int i, j;

	//we initialize every element in P with -1
	for (i = 0; i < N; i++)
		for (j = 0; 1 << j < N; j++)
			P[i][j] = -1;

	//the first ancestor of every node i is T[i]
	for (i = 0; i < N; i++)
		P[i][0] = T[i];
	
	//bottom up dynamic programing
	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}

int query(int p, int q){
	int log, i;
	
	//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q]) swap(p,q);
	
	//we compute the value of [log(L[p)]
	for (log = 1; 1 << log <= L[p]; log++);
	log--;
	
	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	
	if (p == q) return p;
	
	//we compute LCA(p, q) using the values in P
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	
	return T[p];
}

struct Tree {
	int left[MAXN];
	int right[MAXN];
	int parent[MAXN];
	int info[MAXN];
	int nNodes;
};

Tree* buildTree(char* s) {
	int len = strlen(s);
	Tree* result = new Tree();
	result->info[0] = -1;
	result->parent[0] = -1;
	result->nNodes = 1;
	int currentNode = 0;
	vector<pii> pending;

	for (int i = 0; i < len; ++i) {
		if (s[i] == '(') {
			int left = (result->nNodes)++;
			int right = (result->nNodes)++;
			result->left[currentNode] = left;
			result->right[currentNode] = right;
			result->parent[left] = result->parent[right] = currentNode;
			result->info[left] = result->info[right] = -1;
			pending.push_back(make_pair(left, right));
			currentNode = left;
		} else if (s[i] == ')') {
			currentNode = result->parent[currentNode];
			pending.pop_back();
		} else if (s[i] == ',') {
			currentNode = pending.back().second;
		} else {
			int number = 0;
			while (i < len && '0' <= s[i] && s[i] <= '9') {
				number *= 10;
				number += s[i] - '0';
				i++;
			}
			i--;
			result->info[currentNode] = number;
			// printf("currentNode = %d, number = %d\n", currentNode, number);
		}
	}

	// for (int i = 0; i < result->nNodes; ++i) {
	// 	printf("%d: left = %d, right = %d, parent = %d, info = %d\n", i, result->left[i], result->right[i], result->parent[i], result->info[i]);
	// }

	return result;
}

struct DSU {
	vector<int> parent;
	vector<int> size;
	int n;

	DSU(int n) {
		this->n = n;
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int join(int x, int y) {
		int parentX = find(x);
		int parentY = find(y);
		size[parentX] += size[parentY];
		parent[parentY] = parentX;
		return parentX;
	}

	int find(int x) {
		if (parent[x] == x) {
			return x;
		} else {
			return parent[x] = find(parent[x]);
		}
	}

	int getSize(int x) {
		return size[find(x)];
	}

};

#define MAXSTRINGLEN 1100100

int n, ans, positionB[MAXN];
char stringA[MAXSTRINGLEN], stringB[MAXSTRINGLEN];
Tree *treeA, *treeB;
DSU *dsu;

void dfs(int v) {
	if (treeA->info[v] != -1) return;

	// printf("dfs(%d)\n", v);

	int left = treeA->left[v];
	int right = treeA->right[v];
	dfs(left); dfs(right);

	int infoLeft = treeA->info[left];
	int infoRight = treeA->info[right];
	int join = dsu->join(infoLeft, infoRight);
	treeA->info[v] = join;

	int lca = query(positionB[infoLeft], positionB[infoRight]);
	// printf("lca(%d, %d) = %d\n", positionB[infoLeft], positionB[infoRight], lca);
	// printf("v = %d, infoLeft = %d, infoRight = %d, join = %d, size = %d\n", v, infoLeft, infoRight, join, dsu->getSize(join));
	positionB[join] = lca;
	if (treeB->info[lca] == dsu->getSize(join)) {
		ans++;
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", stringA);
	scanf("%s", stringB);

	treeA = buildTree(stringA);
	treeB = buildTree(stringB);

	dsu = new DSU(n);

	// build LCA
	N = treeB->nNodes;
	T[0] = -1;
	L[0] = 0;
	for (int i = 1; i < N; ++i) {
		T[i] = treeB->parent[i];
		L[i] = L[T[i]] + 1;
	}
	pre();

	// build positionB table
	for (int i = 0; i < N; ++i) {
		int info = treeB->info[i];
		if (info == -1) continue;
		positionB[info] = i;
	}

	// calculate the subtree size, replacing info
	for (int i = N - 1; i >= 0; --i) {
		if (treeB->info[i] != -1) {
			treeB->info[i] = 1;
		} else {
			treeB->info[i] = treeB->info[treeB->left[i]] + treeB->info[treeB->right[i]];
		}
	}

	// preparation done!
	ans = n;
	dfs(0);
	printf("%d\n", ans);

	return 0;
}
