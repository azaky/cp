//================================================================
/* GEOMETRI */
double _acos(double x) {
	double ret = acos(x);
	if (ret == ret) return ret;
	if (x < 0) return acos(-1.0);
	return acos(1.0);
}
#define acos _acos
#define sqr(x) ((x)*(x))

const double PI = 3.1415926535897932384626433832795028841971693993751058;
const double EPS = 1e-9;
const double INF = 1e300;

struct point{
	double x, y;
	point() { x = y = 0; }
	point(double x, double y) : x(x), y(y) {}
	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}
	bool operator<(const point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	double cross(const point &p) {
		return x * p.y - y * p.x;
	}
	double dot(const point &p) {
		return x * p.x + y * p.y;
	}
	double getAngle(const point &p) {
		return fabs(acos(this->dot(p) / this->distance(point(0,0)) / p.distance(point(0,0))));
	}
	double distance(const point &p) const {
		return sqrt(sqr(x - p.x) + sqr(y - p.y));
	}
	double distanceToSegment(const point &p1, const point &p2) {
		double alpha;
		alpha = (p2 - p1).getAngle(*this - p1);
		if (alpha > PI/2 + EPS) return min(this->distance(p1), this->distance(p2));
		alpha = (p1 - p2).getAngle(*this - p2);
		if (alpha > PI/2 + EPS) return min(this->distance(p1), this->distance(p2));
		return fabs((p1 - *this).cross(p2 - *this)) / p1.distance(p2);
	}
	point rotate(const double &alpha) {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
	point rescale(const double s) {
		return point(x * s / this->distance(point(0,0)), y * s / this->distance(point(0,0)));
	}
};
struct circle {
	point center;
	double r;
	circle() {
		center = point(0, 0);
		r = 0;
	}
	circle(point p, double r) : center(p), r(r) {}
};
struct segment {
	point p1, p2;
	segment() {p1 = p2 = point(0,0);}
	segment(point p1, point p2) : p1(p1), p2(p2) {}
	double length(){
		return p1.distance(p2);
	}
};
double angle(point p1,point o,point p2){
	return (p1-o).getAngle(p2-o);
}
point rotate(point p,point o,double Theta){
	return (p-o).rotate(Theta)+o;
}
point rotate(point p,double Theta){
	return p.rotate(Theta);
}
point dilate(point p,point o,double Factor){
	return (p-o).rescale(Factor)+o;
}
point dilate(point p,double Factor){
	return p.rescale(Factor);
}
double cross(point p1,point p2){
	return p1.cross(p2);
}
bool right(point p1,point p2,point p3){
	return cross(p2-p1,p3-p2)<=0;
}
bool sameside(point p1,point p2,segment s){
	double z1 = cross(s.p2-s.p1,p1-s.p1);
	double z2 = cross(s.p2-s.p1,p2-s.p1);
	return (z1*z2>=0) || fabs(z1)<EPS || fabs(z2)<EPS;
}
bool online(point p,segment s){
	return fabs((s.p1.y-p.y)*(s.p2.x-p.x)-(s.p2.y-p.y)*(s.p1.x-p.x))<EPS;
}
bool onsegment(point p,segment s){
	return fabs(p.distance(s.p1)+p.distance(s.p2)-s.length())<EPS;
}
bool intersect(segment s1,segment s2){
	return !(sameside(s1.p1,s1.p2,s2) || sameside(s2.p1,s2.p2,s1)) || onsegment(s1.p1,s2) || onsegment(s1.p2,s2) || onsegment(s2.p1,s1) || onsegment(s2.p2,s1);
}
bool parallel(segment s1,segment s2){
	return fabs((s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)-(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x))<EPS;
}
point intersectpoint(segment s1,segment s2){
	if (parallel(s1,s2)) return point(INF,INF);
    double a1 = s1.p2.x-s1.p1.x;
    double b1 = s2.p1.x-s2.p2.x;
    double c1 = s2.p1.x-s1.p1.x;
    double a2 = s1.p2.y-s1.p1.y;
    double b2 = s2.p1.y-s2.p2.y;
    double c2 = s2.p1.y-s1.p1.y;
    double i = (c1*b2-c2*b1)/(a1*b2-a2*b1);
	return point(s1.p1.x+a1*i,s1.p1.y+a2*i);
}
//================================================================
/* DISJOINT SET UNION */
vector <int> pset;
void initSet(init N){
	pset.assign(N,0);
	for (int i=0; i<N; ++i) pset[i] = i;
}
int findset(init i){
	return (pset[i] == i) ? i : (pset[i] = findset(pset[i]));
}
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j){
	pset[findSet(i)] = findSet(j);
}
//================================================================
/* BIT */
#define LSOne(S) (S & (-S));
void ft_create(vector<int> &t, int b){
	t.assign(n+1,0);
}
int ft_rsq(const vector<int> &t, int b){
	int sum = 0;
	for (; b; b-= (b & (-b))) sum += t[b];
	return sum;
}
int ft_rsq(const vector<int> &t, int a, int b){
	return ft_rsq(t,b) - (a == 1 ? 0 : ft_rsq(t,a-1));
}
//add the k-th element by v
void ft_adjust(vector<int> &t, int k, int v){
	for (; k <= (int)t.size(); k += (k & (-k))) t[k] += v;
}
//================================================================
/* PROPER DFS */
DFS(Graph G){
	for (each vertex u \in V[G]){
		color[i] = WHITE;
		pi[u] = NIL;
	}
	time = 0;
	for (each vertex u \in V[G]){
		if (color[u] == WHITE) DFS-visit(u);
	}
}
DFS-visit(vertex u){
	color[i] = GRAY;
	d[u] = time = time + 1;
	for (each v \in Adj[u]){
		if (color[v] = WHITE){
			pi[v] = i;
			DFS-visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = time = time+1;
}
//================================================================
/* TOPOLOGICAL SORT */
TopoSort(Graph G){
	DFS(G);
	insert onto a list in order of f[u];
}
//================================================================
/* Strongly Connected Component */
SCC(Graph G){
	DFS(G);
	GT = balik semua edge di G;
	DFS(GT), main loopnya in order of decreasing f[u];
	satu tree di depth-first forest itu satu SCC;
//================================================================
/* MAXFLOW */
function totalflow(n,v1,v2:integer; cap:capacity):longint;
  var
    maxflow,maxloc,i,v,pathcap,curnode,nextnode:longint;
    prevnode:array[1..maxn] of integer;
    flow:array[1..maxn] of longint;
    visit:array[1..maxn] of boolean;
  begin
    totalflow:=0;
    while true do
      begin
        fillchar(prevnode,sizeof(prevnode),0);
        fillchar(flow,sizeof(flow),0);
        fillchar(visit,sizeof(visit),false);
        flow[v1]:=maxlongint;
        while true do
          begin
            maxflow:=0;
            maxloc:=0;
            for i:=1 to n do
              if (flow[i]>maxflow) and not visit[i] then
                begin
                  maxflow:=flow[i];
                  maxloc:=i;
                end;
            if (maxloc=0) or (maxloc=v2) then break;
            visit[maxloc]:=true;
            for i:=1 to deg[maxloc] do
              begin
                v:=adj[maxloc,i];
                if flow[v]<min(maxflow,cap[maxloc,v]) then
                  begin
                    prevnode[v]:=maxloc;
                    flow[v]:=min(maxflow,cap[maxloc,v]);
                  end;
              end;
          end;
        if maxloc=0 then break;
        pathcap:=flow[v2];
        inc(totalflow,pathcap);
        curnode:=v2;
        while curnode<>v1 do
          begin
            nextnode:=prevnode[curnode];
            dec(cap[nextnode,curnode],pathcap);
            inc(cap[curnode,nextnode],pathcap);
            curnode:=nextnode;
          end;
      end;
 end;
//================================================================
/* CONVEX HULL */
vector<point> ConvexHull(vector<point> p){
	int n = p.size(), nhull = 2;
	sort(p.begin(),p.end());
	vector<point> hull;
	hull.push_back(p[0]); hull.push_back(p[1]);
	for (int i=2; i<n; ++i){
		while (nhull>1 && right(hull[nhull-2],hull[nhull-1],p[i])){
			--nhull;
			hull.pop_back();
		}
		hull.push_back(p[i]); ++nhull;
	}
	for (int i=n-2; i>=0; --i){
		while (nhull>1 && right(hull[nhull-2],hull[nhull-1],p[i])){
			--nhull;
			hull.pop_back();
		}
		hull.push_back(p[i]); ++nhull;
	}
	hull.pop_back();
	return hull;
}
//================================================================
/* SPANNING TREE - KRUSKAL's */
vector<pair<int,pair<int,int> > > EdgeList; //(weight,(vertices of edge))
for (int i=0; i<E; i++){
	scanf("%d%d%d",&a,&b,&weight);
	Edgelist.push_back(make_pair(weight,make_pair(a,b)));
}
sort(Edgelist.begin(),Edgelist.end());
int mst_cost = 0; initSet(V);
for (int i=0; i < E; ++i){
	pair <int,pair<int,int> > front = EdgeList[i];
	if (!isSameSet(front.second.first,front.second.second)){
		mst_cost += front.first;
		unionSet(front.second.first, front.second.second);
	}
}
//================================================================
/* MILLER RABIN */
#define LIM 32768
int GetInt(int l,int r){
	int x = (rand()%LIM)*LIM + (rand()%LIM);
	return l + x%(r-l+1);
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
	for (int i=0; i<20; ++i){
		a = GetLL(2,n-2);
		x = pmod(a,d,n);
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
//================================================================
/* BELLMAN FORD (?) */
vector <int> dist(V, INF); dist[s] = 0;
for (int i=0; i<V-1; ++i)
	for (int u=0 u<V; ++u)
		for (int j=0; j<(int)AdjList[u].size(); ++j){
			pair <int,int> v = AdjList[u][j];
			dist[v.first] = min(dist[v.first],dist[i]+v.second);
		}
//
bool hasNegativeCycle = false;
for (int u=0; u < V; ++u){
	for (int j=0; j < (int)AdjList[u].size(); ++j){
		pair<int,int> v = Adjlist[u][j];
		if (dist[v.first] > dist[i] + v.second)
			hasNegativeCycle = true;
	}
//================================================================
/* EDMOND KARP | MAXFLOW */
int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;
void augment(int v, int minEdge){
	if (v==s){
		f = minEdge;
		return;
	}
	else if (p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
//inside int main()
mf = 0;
while(1){
	f = 0;
	vector<int> dist(MAX_V, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	p.assign(<MAX_V, -1);
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v=0; v < MAX_V; ++v)
			if (res[u][v] > 0 && dist[v] == INF)
				dist[v] = dist[u] + 1, q.push(v), p[v] = u;
	}
	augment(t,INF);
	if (f == 0) break;
	mf += f;
}
//================================================================
/* KNUTH MORRIS PRATT */
#define MAX_N 100010
char T[MAX_N], P[MAX_N];        		// T = text, P = pattern
int b[MAX_N], n, m;                     // b = back table, n = length of T, m = length of P
void kmpPreprocess () {                 // call this first
        int i = 0, j = -1, b[0] = -1;   // start values
        while (i < m) {         		// preprocess the pattern string P
                while (j >= 0 && P[i] != P[j]) j = b[j];        // if different, reset j using b
                i ++; j ++;                                                                     // if same, advance both pointers
                b[i] = j;                       
        }
}
void kmpSearch () {     		// this is similar as kmpPreprocess but on T
        int i = 0, j = 0;       // start values
        while (i < n) { 		// search through T
                while (j >= 0 && T[i] != P[j]) j = b[j];        // if different, reset j using b
                i ++; j ++;     // if same, advance both pointers
                if (j == m) {   // a match found when j == m
                        printf ("P is found at index %d in T\n", i - j);
                        j = b[j];       // prepare j for the next possible match
                }
        }       
}
//================================================================
/* SUFFIX ARRAY */
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAX_N 100010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
void CountingSort (int k) {
        int i, sum, maxi = max (300, n);
        memset (c, 0, sizeof c);
        for (i = 0; i < n ; i++)        // count frequensi tiap rank
                c[i + k < n ? RA[i + k] : 0] ++;
        for (i = sum = 0; i < maxi; i ++) {
                int t = c[i]; c[i] = sum; sum += t;
        }
        for (i = 0; i < n; i ++)        // shuffle the suffix array if necessary
                tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0] ++] = SA[i];
        for (i = 0; i < n; i ++)        // update the suffix array SA
                SA[i] = tempSA[i];
}
void constructSA () {   // this version can go up to 100000 characters
        int i, k, r;
        for (i = 0; i < n; i ++) RA[i] = T[i] - '.';    //  initial rankings
        for (i = 0; i < n; i ++) SA[i] = i;     // initial SA : {0, 1, 2 ... n-1}
        for (k = 1; k < n; k <<= 1) {   // repeat sorting process log n times
                CountingSort (k);               // actually radix sort : sort based on second items
                CountingSort (0);       // then stable sort based on first items
                tempRA[SA[0]] = r = 0;  // re-rangking, start from rank r = 0
                for (i = 1; i < n; i ++)        // compare adjacent suffixes
                        tempRA[SA[i]] = // if same pair => same rank r; otherwise increase r
                                (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
                for (i = 0; i < n; i ++)        // update rank array RA
                        RA[i] = tempRA[i];
        }
}       
int main () {
        n = (int) strlen (gets (T));
        constructSA ();
        for (int i = 0; i < n; i ++)
                printf ("%2d\t%s\n", SA[i], T + SA[i]);
        ret 0;
}
//================================================================
/* EXTENDED EUCLID */
//solves ax + by = d = gcd(a,b);
void extendedEuclid(int a, int b){
	if (b == 0){
		x = 1; y = 0; d = a;
		return;
	}
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x - (a/b) * y;
	x = x1; y = y1;
}
