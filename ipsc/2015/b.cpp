#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 10005
int n,val;
int cnt1[MAXN], cnt2[MAXN], st[MAXN];
vector<int> nilai;
vector<pair<string,int> > v[4];
map<string,int> hehe;
map<int,vector<int> > m2;
map<int,vector<pair<int,int> > >  m;
char s[25], a[25],b[25],c[25];
int cur;
 
int main() {
	for (int kya = 0; kya < 3; ++kya){
		scanf("%d",&n);
		v[kya].clear();
		for (int i = 0; i < n; ++i){
			scanf("%s %d",s,&val);
			hehe[s] = val;
			v[kya].pb(mp(s,val));
		}
	}
	m.clear();
	for (int i = 0; i < v[0].size(); ++i){
		for (int j = 0; j < v[1].size(); ++j){
			val = v[0][i].se + v[1][j].se;
 
			m[val].pb(mp(i,j));
		}
	}
	nilai.clear();
	for (int i = 0; i < v[2].size(); ++i){
		val = v[2][i].se;
		m2[val].pb(i);
		if (m2[val].size() == 1) nilai.pb(val);
	}
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	memset(st,0,sizeof(st));
	scanf("%d",&n);
	for (int q = 0; q < n; ++q){
		scanf("%s %s %s",a,b,c);
		val = hehe[a] + hehe[b] + hehe[c] + 1;
 
		for (int i = st[val]; i < nilai.size(); ++i){
			cur =  nilai[i];
			if (cur > val) continue;
			if (cnt2[val] >= m[val-cur].size()){
				cnt2[val] = 0;
				cnt1[val]++;
			}
			//cout << i << " " << cur << "  " << val-cur << "   "<< cnt1[val] << " "<< cnt2[val] << "  "<< m2[cur].size() << " "<< m[val-cur].size() << endl;
			if (cnt1[val] < m2[cur].size() && cnt2[val] < m[val-cur].size()){
				int idxm2 = cnt1[val];
				int idxm = cnt2[val];
				cnt2[val]++;
				cout << v[0][m[val-cur][idxm].fi].fi << " " << v[1][m[val-cur][idxm].se].fi << " "<< v[2][m2[cur][idxm2]].fi << endl;
				break;
			}
			else{
				cnt1[val]=cnt2[val]=0;
				st[val]++;
			}
		}
 
	}
	return 0;
}