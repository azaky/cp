/*
	precomputed the answer using brute force
	bruteforce is in the comment below
	too lazy to think right now, probably will solve large later
*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 1005
#define INF 1000000
#define S 0
#define T m+n+1
using namespace std;
int t,r,c,bom;
int main(){
	scanf("%d",&t);
	for (int tc = 1; tc <= t; ++tc){
		scanf("%d %d %d",&r,&c,&bom);
		printf("Case #%d:\n",tc);
		if (r == 1 && c == 1 && bom == 0){
			puts("c");
		}
		else if (r == 1 && c == 2 && bom == 1){
		puts("c*");
		}
		else if (r == 1 && c == 2 && bom == 0){
		puts("c.");
		}
		else if (r == 1 && c == 3 && bom == 2){
puts("c**");
}
else if (r == 1 && c == 3 && bom == 1){
puts("*.c");
}
else if (r == 1 && c == 3 && bom == 0){
puts("..c");
}
else if (r == 1 && c == 4 && bom == 3){
puts("c***");
}
else if (r == 1 && c == 4 && bom == 2){
puts("**.c");
}
else if (r == 1 && c == 4 && bom == 1){
puts("*..c");
}
else if (r == 1 && c == 4 && bom == 0){
puts("...c");
}
else if (r == 1 && c == 5 && bom == 4){
puts("c****");
}
else if (r == 1 && c == 5 && bom == 3){
puts("***.c");
}
else if (r == 1 && c == 5 && bom == 2){
puts("**..c");
}
else if (r == 1 && c == 5 && bom == 1){
puts("*...c");
}
else if (r == 1 && c == 5 && bom == 0){
puts("....c");
}
else if (r == 2 && c == 1 && bom == 1){
puts("c");
puts("*");
}
else if (r == 2 && c == 1 && bom == 0){
puts(".");
puts("c");
}
else if (r == 2 && c == 2 && bom == 3){
puts("c*");
puts("**");
}
else if (r == 2 && c == 2 && bom == 0){
puts("c.");
puts("..");
}
else if (r == 2 && c == 3 && bom == 5){
puts("c**");
puts("***");
}
else if (r == 2 && c == 3 && bom == 2){
puts("*.c");
puts("*..");
}
else if (r == 2 && c == 3 && bom == 0){
puts("c..");
puts("...");
}
else if (r == 2 && c == 4 && bom == 7){
puts("c***");
puts("****");
}
else if (r == 2 && c == 4 && bom == 4){
puts("**.c");
puts("**..");
}
else if (r == 2 && c == 4 && bom == 2){
puts("*.c.");
puts("*...");
}
else if (r == 2 && c == 4 && bom == 0){
puts("c...");
puts("....");
}
else if (r == 2 && c == 5 && bom == 9){
puts("c****");
puts("*****");
}
else if (r == 2 && c == 5 && bom == 6){
puts("***.c");
puts("***..");
}
else if (r == 2 && c == 5 && bom == 4){
puts("**.c.");
puts("**...");
}
else if (r == 2 && c == 5 && bom == 2){
puts("*.c..");
puts("*....");
}
else if (r == 2 && c == 5 && bom == 0){
puts("c....");
puts(".....");
}
else if (r == 3 && c == 1 && bom == 2){
puts("c");
puts("*");
puts("*");
}
else if (r == 3 && c == 1 && bom == 1){
puts("*");
puts(".");
puts("c");
}
else if (r == 3 && c == 1 && bom == 0){
puts("c");
puts(".");
puts(".");
}
else if (r == 3 && c == 2 && bom == 5){
puts("c*");
puts("**");
puts("**");
}
else if (r == 3 && c == 2 && bom == 2){
puts("**");
puts("..");
puts("c.");
}
else if (r == 3 && c == 2 && bom == 0){
puts("c.");
puts("..");
puts("..");
}
else if (r == 3 && c == 3 && bom == 8){
puts("c**");
puts("***");
puts("***");
}
else if (r == 3 && c == 3 && bom == 5){
puts("***");
puts("*..");
puts("*.c");
}
else if (r == 3 && c == 3 && bom == 3){
puts("***");
puts("...");
puts("c..");
}
else if (r == 3 && c == 3 && bom == 1){
puts("*.c");
puts("...");
puts("...");
}
else if (r == 3 && c == 3 && bom == 0){
puts("c..");
puts("...");
puts("...");
}
else if (r == 3 && c == 4 && bom == 11){
puts("c***");
puts("****");
puts("****");
}
else if (r == 3 && c == 4 && bom == 8){
puts("****");
puts("**..");
puts("**.c");
}
else if (r == 3 && c == 4 && bom == 6){
puts("****");
puts("*...");
puts("*.c.");
}
else if (r == 3 && c == 4 && bom == 4){
puts("****");
puts("....");
puts("c...");
}
else if (r == 3 && c == 4 && bom == 2){
puts("**.c");
puts("....");
puts("....");
}
else if (r == 3 && c == 4 && bom == 3){
puts("*.c.");
puts("*...");
puts("*...");
}
else if (r == 3 && c == 4 && bom == 1){
puts("*.c.");
puts("....");
puts("....");
}
else if (r == 3 && c == 4 && bom == 0){
puts("c...");
puts("....");
puts("....");
}
else if (r == 3 && c == 5 && bom == 14){
puts("c****");
puts("*****");
puts("*****");
}
else if (r == 3 && c == 5 && bom == 11){
puts("*****");
puts("***..");
puts("***.c");
}
else if (r == 3 && c == 5 && bom == 9){
puts("*****");
puts("**...");
puts("**.c.");
}
else if (r == 3 && c == 5 && bom == 7){
puts("*****");
puts("*....");
puts("*.c..");
}
else if (r == 3 && c == 5 && bom == 5){
puts("*****");
puts(".....");
puts("c....");
}
else if (r == 3 && c == 5 && bom == 3){
puts("***.c");
puts(".....");
puts(".....");
}
else if (r == 3 && c == 5 && bom == 6){
puts("**.c.");
puts("**...");
puts("**...");
}
else if (r == 3 && c == 5 && bom == 4){
puts("**.c.");
puts("*....");
puts("*....");
}
else if (r == 3 && c == 5 && bom == 2){
puts("**.c.");
puts(".....");
puts(".....");
}
else if (r == 3 && c == 5 && bom == 1){
puts("*.c..");
puts(".....");
puts(".....");
}
else if (r == 3 && c == 5 && bom == 0){
puts("c....");
puts(".....");
puts(".....");
}
else if (r == 4 && c == 1 && bom == 3){
puts("c");
puts("*");
puts("*");
puts("*");
}
else if (r == 4 && c == 1 && bom == 2){
puts("*");
puts("*");
puts(".");
puts("c");
}
else if (r == 4 && c == 1 && bom == 1){
puts("*");
puts(".");
puts("c");
puts(".");
}
else if (r == 4 && c == 1 && bom == 0){
puts("c");
puts(".");
puts(".");
puts(".");
}

else if (r == 4 && c == 2 && bom == 7){
puts("c*");
puts("**");
puts("**");
puts("**");
}
else if (r == 4 && c == 2 && bom == 4){
puts("**");
puts("**");
puts("..");
puts("c.");
}
else if (r == 4 && c == 2 && bom == 2){
puts("**");
puts("..");
puts("c.");
puts("..");
}
else if (r == 4 && c == 2 && bom == 0){
puts("c.");
puts("..");
puts("..");
puts("..");
}
else if (r == 4 && c == 3 && bom == 11){
puts("c**");
puts("***");
puts("***");
puts("***");
}
else if (r == 4 && c == 3 && bom == 8){
puts("***");
puts("***");
puts("*..");
puts("*.c");
}
else if (r == 4 && c == 3 && bom == 6){
puts("***");
puts("***");
puts("...");
puts("c..");
}
else if (r == 4 && c == 3 && bom == 4){
puts("***");
puts("*..");
puts("..c");
puts("...");
}
else if (r == 4 && c == 3 && bom == 3){
puts("***");
puts("...");
puts("c..");
puts("...");
}
else if (r == 4 && c == 3 && bom == 2){
puts("*.c");
puts("*..");
puts("...");
puts("...");
}
else if (r == 4 && c == 3 && bom == 1){
puts("*.c");
puts("...");
puts("...");
puts("...");
}
else if (r == 4 && c == 3 && bom == 0){
puts("c..");
puts("...");
puts("...");
puts("...");
}
else if (r == 4 && c == 4 && bom == 15){
puts("c***");
puts("****");
puts("****");
puts("****");
}
else if (r == 4 && c == 4 && bom == 12){
puts("****");
puts("****");
puts("**..");
puts("**.c");
}
else if (r == 4 && c == 4 && bom == 10){
puts("****");
puts("****");
puts("*...");
puts("*.c.");
}
else if (r == 4 && c == 4 && bom == 8){
puts("****");
puts("****");
puts("....");
puts("c...");
}
else if (r == 4 && c == 4 && bom == 6){
puts("****");
puts("**..");
puts("...c");
puts("....");
}
else if (r == 4 && c == 4 && bom == 7){
puts("****");
puts("*...");
puts("*.c.");
puts("*...");
}
else if (r == 4 && c == 4 && bom == 5){
puts("****");
puts("*...");
puts("..c.");
puts("....");
}
else if (r == 4 && c == 4 && bom == 4){
puts("****");
puts("....");
puts("c...");
puts("....");
}
else if (r == 4 && c == 4 && bom == 3){
puts("**.c");
puts("*...");
puts("....");
puts("....");
}
else if (r == 4 && c == 4 && bom == 2){
puts("**.c");
puts("....");
puts("....");
puts("....");
}
else if (r == 4 && c == 4 && bom == 1){
puts("*.c.");
puts("....");
puts("....");
puts("....");
}
else if (r == 4 && c == 4 && bom == 0){
puts("c...");
puts("....");
puts("....");
puts("....");
}
else if (r == 4 && c == 5 && bom == 19){
puts("c****");
puts("*****");
puts("*****");
puts("*****");
}
else if (r == 4 && c == 5 && bom == 16){
puts("*****");
puts("*****");
puts("***..");
puts("***.c");
}
else if (r == 4 && c == 5 && bom == 14){
puts("*****");
puts("*****");
puts("**...");
puts("**.c.");
}
else if (r == 4 && c == 5 && bom == 12){
puts("*****");
puts("*****");
puts("*....");
puts("*.c..");
}
else if (r == 4 && c == 5 && bom == 10){
puts("*****");
puts("*****");
puts(".....");
puts("c....");
}
else if (r == 4 && c == 5 && bom == 8){
puts("*****");
puts("***..");
puts("....c");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 11){
puts("*****");
puts("**...");
puts("**.c.");
puts("**...");
}
else if (r == 4 && c == 5 && bom == 9){
puts("*****");
puts("**...");
puts("*..c.");
puts("*....");
}
else if (r == 4 && c == 5 && bom == 7){
puts("*****");
puts("**...");
puts("...c.");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 6){
puts("*****");
puts("*....");
puts("..c..");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 5){
puts("*****");
puts(".....");
puts("c....");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 4){
puts("***.c");
puts("*....");
puts(".....");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 3){
puts("***.c");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 2){
puts("**.c.");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 1){
puts("*.c..");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 4 && c == 5 && bom == 0){
puts("c....");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 1 && bom == 4){
puts("c");
puts("*");
puts("*");
puts("*");
puts("*");
}
else if (r == 5 && c == 1 && bom == 3){
puts("*");
puts("*");
puts("*");
puts(".");
puts("c");
}
else if (r == 5 && c == 1 && bom == 2){
puts("*");
puts("*");
puts(".");
puts("c");
puts(".");
}
else if (r == 5 && c == 1 && bom == 1){
puts("*");
puts(".");
puts("c");
puts(".");
puts(".");
}
else if (r == 5 && c == 1 && bom == 0){
puts("c");
puts(".");
puts(".");
puts(".");
puts(".");
}
else if (r == 5 && c == 2 && bom == 9){
puts("c*");
puts("**");
puts("**");
puts("**");
puts("**");
}
else if (r == 5 && c == 2 && bom == 6){
puts("**");
puts("**");
puts("**");
puts("..");
puts("c.");
}
else if (r == 5 && c == 2 && bom == 4){
puts("**");
puts("**");
puts("..");
puts("c.");
puts("..");
}
else if (r == 5 && c == 2 && bom == 2){
puts("**");
puts("..");
puts("c.");
puts("..");
puts("..");
}
else if (r == 5 && c == 2 && bom == 0){
puts("c.");
puts("..");
puts("..");
puts("..");
puts("..");
}
else if (r == 5 && c == 3 && bom == 14){
puts("c**");
puts("***");
puts("***");
puts("***");
puts("***");
}
else if (r == 5 && c == 3 && bom == 11){
puts("***");
puts("***");
puts("***");
puts("*..");
puts("*.c");
}
else if (r == 5 && c == 3 && bom == 9){
puts("***");
puts("***");
puts("***");
puts("...");
puts("c..");
}
else if (r == 5 && c == 3 && bom == 7){
puts("***");
puts("***");
puts("*..");
puts("..c");
puts("...");
}
else if (r == 5 && c == 3 && bom == 6){
puts("***");
puts("***");
puts("...");
puts("c..");
puts("...");
}
else if (r == 5 && c == 3 && bom == 5){
puts("***");
puts("*..");
puts("*.c");
puts("...");
puts("...");
}
else if (r == 5 && c == 3 && bom == 4){
puts("***");
puts("*..");
puts("..c");
puts("...");
puts("...");
}
else if (r == 5 && c == 3 && bom == 3){
puts("***");
puts("...");
puts("c..");
puts("...");
puts("...");
}
else if (r == 5 && c == 3 && bom == 2){
puts("*.c");
puts("*..");
puts("...");
puts("...");
puts("...");
}
else if (r == 5 && c == 3 && bom == 1){
puts("*.c");
puts("...");
puts("...");
puts("...");
puts("...");
}
else if (r == 5 && c == 3 && bom == 0){
puts("c..");
puts("...");
puts("...");
puts("...");
puts("...");
}
else if (r == 5 && c == 4 && bom == 19){
puts("c***");
puts("****");
puts("****");
puts("****");
puts("****");
}
else if (r == 5 && c == 4 && bom == 16){
puts("****");
puts("****");
puts("****");
puts("**..");
puts("**.c");
}
else if (r == 5 && c == 4 && bom == 14){
puts("****");
puts("****");
puts("****");
puts("*...");
puts("*.c.");
}
else if (r == 5 && c == 4 && bom == 12){
puts("****");
puts("****");
puts("****");
puts("....");
puts("c...");
}
else if (r == 5 && c == 4 && bom == 10){
puts("****");
puts("****");
puts("**..");
puts("...c");
puts("....");
}
else if (r == 5 && c == 4 && bom == 11){
puts("****");
puts("****");
puts("*...");
puts("*.c.");
puts("*...");
}
else if (r == 5 && c == 4 && bom == 9){
puts("****");
puts("****");
puts("*...");
puts("..c.");
puts("....");
}
else if (r == 5 && c == 4 && bom == 8){
puts("****");
puts("****");
puts("....");
puts("c...");
puts("....");
}
else if (r == 5 && c == 4 && bom == 7){
puts("****");
puts("**..");
puts("*..c");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 6){
puts("****");
puts("**..");
puts("...c");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 5){
puts("****");
puts("*...");
puts("..c.");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 4){
puts("****");
puts("....");
puts("c...");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 3){
puts("**.c");
puts("*...");
puts("....");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 2){
puts("**.c");
puts("....");
puts("....");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 1){
puts("*.c.");
puts("....");
puts("....");
puts("....");
puts("....");
}
else if (r == 5 && c == 4 && bom == 0){
puts("c...");
puts("....");
puts("....");
puts("....");
puts("....");
}
else if (r == 5 && c == 5 && bom == 24){
puts("c****");
puts("*****");
puts("*****");
puts("*****");
puts("*****");
}
else if (r == 5 && c == 5 && bom == 21){
puts("*****");
puts("*****");
puts("*****");
puts("***..");
puts("***.c");
}
else if (r == 5 && c == 5 && bom == 19){
puts("*****");
puts("*****");
puts("*****");
puts("**...");
puts("**.c.");
}
else if (r == 5 && c == 5 && bom == 17){
puts("*****");
puts("*****");
puts("*****");
puts("*....");
puts("*.c..");
}
else if (r == 5 && c == 5 && bom == 15){
puts("*****");
puts("*****");
puts("*****");
puts(".....");
puts("c....");
}
else if (r == 5 && c == 5 && bom == 13){
puts("*****");
puts("*****");
puts("***..");
puts("....c");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 16){
puts("*****");
puts("*****");
puts("**...");
puts("**.c.");
puts("**...");
}
else if (r == 5 && c == 5 && bom == 14){
puts("*****");
puts("*****");
puts("**...");
puts("*..c.");
puts("*....");
}
else if (r == 5 && c == 5 && bom == 12){
puts("*****");
puts("*****");
puts("**...");
puts("...c.");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 11){
puts("*****");
puts("*****");
puts("*....");
puts("..c..");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 10){
puts("*****");
puts("*****");
puts(".....");
puts("c....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 9){
puts("*****");
puts("***..");
puts("*...c");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 8){
puts("*****");
puts("***..");
puts("....c");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 7){
puts("*****");
puts("**...");
puts("...c.");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 6){
puts("*****");
puts("*....");
puts("..c..");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 5){
puts("*****");
puts(".....");
puts("c....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 4){
puts("***.c");
puts("*....");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 3){
puts("***.c");
puts(".....");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 2){
puts("**.c.");
puts(".....");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 1){
puts("*.c..");
puts(".....");
puts(".....");
puts(".....");
puts(".....");
}
else if (r == 5 && c == 5 && bom == 0){
puts("c....");
puts(".....");
puts(".....");
puts(".....");
puts(".....");
}
else puts("Impossible");

	}
}

/*
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 6
#define INF 1000000
#define S 0
#define T m+n+1
using namespace std;
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,-1,1,1,-1};
bool vis[MAXN][MAXN];
int kya[MAXN][MAXN];
bool udah[MAXN*MAXN];
int cnt,r,c;
int adj(int row, int col){
	int ret = 0;
	for (int i = 0; i < 8; ++i)
		if (dx[i]+row >= 0 && dx[i] + row < r)
			if (dy[i]+col >= 0 && dy[i] + col < c)
				ret += kya[dx[i]+row][dy[i]+col];
	return ret;
}

void dfs(int row, int col){
//	cout << row <<" "<< col <<" cnt = " << cnt << " "<< vis[row][col] <<  endl;
	cnt++;
	vis[row][col] = 1;
	if(adj(row,col)==0)
	for (int i = 0; i < 8; ++i)
		if (dx[i]+row >= 0 && dx[i] + row < r)
			if (dy[i]+col >= 0 && dy[i] + col < c)
				if (!vis[dx[i]+row][dy[i]+col])
					dfs(dx[i]+row,dy[i]+col);

	
}

void solve (int row,int col,int bom){
	if (col >= c) {
		solve(row+1,0,bom);
		return;
	}
	//cout << row <<" " << col << " ~ " << bom << endl;
	//if (col > 5 || bom > 5) return;
	if (row >= r){
		if (bom +1 >= r*c) return;
		cnt = 0;
		memset(vis,0,sizeof(vis));
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				if (adj(i,j) == 0 && kya[i][j] == 0){
				//	cout << i << " "<< j << endl;
					dfs(i,j); break;
				}
			}
			if (cnt) break;
		}	
		if (!cnt) return;
		//puts("------------");
	//	cout << row <<" " << col << " ~~ " << bom << "cnt = "<< cnt << " " << udah[bom] << endl;
		//	cout << cnt  << "  "<< bom <<" ----- " << r*c << endl;

		if (cnt+bom == r*c){
			if (udah[bom]) return;
		udah[bom] = 1;
			printf("else if (r == %d && c == %d && bom == %d){\n",r,c,bom);
			for (int i = 0; i < r; ++i){
				printf("puts(\"");
				for (int j = 0; j < c; ++j)
					if (kya[i][j]) printf("*");
					else { if (cnt+bom == r*c && adj(i,j)==0) printf("c");
					else printf("."); if(adj(i,j)==0) cnt--;}
				puts("\");");
			}
			puts("}");
		}
		return;
	}
	kya[row][col] = 1;
	solve(row,col+1,bom+1);
	kya[row][col] = 0;
	solve(row,col+1,bom);
}

int main(){
	memset(udah,0,sizeof(udah));
	scanf("%d %d",&r,&c);
	printf("else if (r == %d && c == %d && bom == %d){\n",r,c,r*c-1);
	for (int i = 0; i < r; ++i){
		printf("puts(\"");
		for (int j = 0; j < c; ++j)
			if (i == 0 && j == 0) printf("c");
			else printf("*");
		puts("\");");
	}
	puts("}");
	solve(0,0,0);

}
*/