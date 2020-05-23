#include <cstdio>
#include <stack>
using namespace std;

int n,car[11111],keluar;
stack <int> road,side;

int succeed(){
	while (!road.empty()) road.pop();
	while (!side.empty()) side.pop();
	for (int i=n; i>0; --i)
		road.push(car[i-1]);
	for (int i=1; i<n; ++i){
		if (!side.empty())
			if (side.top()==i){
				side.pop();
				continue;
			}
		keluar = 0;
		while (!road.empty()){
              
			if (road.top()==i){
				road.pop();
				keluar = 1;
				break;
			}
			else {
				side.push(road.top());
				road.pop();
			}
		}
		if (!keluar) return 0;
	}
	return 1;
}			

int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0; i<n; ++i)
			scanf("%d",&car[i]);
		if (succeed()) printf("yes\n");
			else printf("no\n");
	}
	return 0;
}
