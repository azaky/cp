#include <cstdio>
#include <queue>
using namespace std;

int tc,n,pos,level,t,print;
queue < pair<int,int> > q,c;
pair <int,int> now;

int main(){
	scanf("%d",&tc);
	while (tc--){
		scanf("%d%d",&n,&pos);
		while (!q.empty()) q.pop();
		for (int i=0; i<n; ++i){
			scanf("%d",&level);
			q.push(make_pair(level,i));
		}
		t = 0;
		while (1){
			now = q.front(); q.pop();
			c = q;
			print = 1;
			while (!c.empty()){
				if (c.front().first>now.first){
					print = 0;
					break;
				}
				c.pop();
			}
			if (!print) q.push(now);
				else {
					++t;
					if (now.second==pos) break;
				}
		}
		printf("%d\n",t);
	}
	return 0;
}
