#include <stdio.h>
#include <queue>
#define MAXN 111111

using namespace std;

int n,k,a[MAXN],prev[MAXN],next[MAXN];
bool restricted[MAXN];
priority_queue <pair<int,int> > q;

int main(){
    scanf("%d %d",&n,&k);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=1; i<n; i++) a[i]=a[i+1]-a[i]; n--;
    //for (int i=1; i<=n; i++) printf("%d\n",a[i]);
    //printf("-------------------------------------------\n");
    //creating linked list
    for (int i=0; i<=n+1; i++){
        prev[i]=i-1; next[i]=i+1;
        }
    //initializing heap
    pair <int,int> temp;
    for (int i=1; i<=n; i++){
        temp.first = -a[i]; temp.second = i;
        q.push(temp);
        }
    //greedy algorithm
    int ans=0,idx;
    restricted[0] = restricted[n+1] = true;
    for (int step=1; step<=k; step++){
        do{
             temp= q.top(); q.pop();
             idx = temp.second;
             } while (restricted[idx]);
        ans = ans-temp.first;
        //insert new element
        if (!restricted[prev[idx]] && !restricted[next[idx]]){
                        a[idx] = a[prev[idx]]+a[next[idx]]-a[idx];
                        temp.first = -a[idx]; temp.second = idx;
                        q.push(temp);
                        }
        else restricted[idx]=true;
        //delete the adjacent element
        //and since we cannot do it in priority_queue, just do it this way
        restricted[prev[idx]]=true;
        restricted[next[idx]]=true;
        //printf("%d | a[%d]=%d a[%d]=%d a[%d]=%d |",ans,prev[idx],a[prev[idx]],idx,a[idx],next[idx],a[next[idx]]);
        //update linked list
        if (prev[idx]>0){prev[idx] = prev[prev[idx]]; next[prev[idx]] = idx;};
        if (next[idx]<n+1){next[idx] = next[next[idx]]; prev[next[idx]] = idx;};
        
        //printf("%d %d %d\n",prev[idx],idx,next[idx]);
        }
    printf("%d\n",ans);
    return 0;
}
	
