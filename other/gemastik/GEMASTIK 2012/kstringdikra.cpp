#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<utility>
using namespace std;

#define MAXN 500005

int n, nk, i, len;
char s[MAXN];
int cnt[26];

bool found;

int path[26][26];

int ans[MAXN];

void work(int pos, int now){
    if (found)
       return; 
       
    int j;
     
    if (now == len){
       if (nk == 1){
          for (j = 0; j < now; j++){
              printf("%c", (char)(ans[j]+'A'));
          }       
          printf("\n");
          found = 1;
       } else {
          nk--;       
       }
       
       return;
    }
    
    for (j = 0; j < 26; j++){
        if (path[pos][j] > 0){
           path[pos][j]--;
           ans[now] = j;
           
           work(j,now+1);
           
           path[pos][j]++;
        }
    }
}

int main(void){
    scanf("%s %d", s, &nk);
    
    len = strlen(s);
    n = len;
    
    memset(path, 0, sizeof(path));
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < len; i++){
        path[s[i]-'A'][s[(i+1)%len]-'A']++;     
        cnt[s[i]-'A']++;
    }
    
    for (i = 0; i < 26; i++){
        if (cnt[i] == len){
           printf("%s\n", s);
           return 0;           
        }    
    }
    
    i = 0;
    while (nk > cnt[i]){
        nk -= cnt[i];
        i++;
    }
    
    found = 0;
    
    ans[0] = i;
    work(i,1);
    
    return 0;
}
