#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int TC, n, np;
int i, j;
string sline, temp;

char s[10000][20];
map <string, int> hash;
int package[10000];

int idxAns, maxAns;

bool pertamax;

void Update(string &name){
     int idx;
     
     if (hash.count(name) != 0){
        idx = hash[name];
     } else {
        idx = np;
        strcpy(s[np], name.c_str());
        hash[name] = np++;
     }

     if (!pertamax) package[idx]++;
     else pertamax = 0;
     
     return;
}


int main(void){
    scanf("%d", &TC);
    while (TC--){
          scanf("%d\n", &n);
          np = 0;
          memset(package, 0, sizeof(package));
          hash.clear();
          
          for (j = 0; j < n; j++){
              getline(cin, sline);    
              temp = "";
              pertamax = 1;
              for (i = 0; i < sline.length(); i++){
                  if (sline[i] == ' '){
                     if (temp.length() > 0){ 
                         Update(temp);
                                        
                         temp = ""; 
                     }
                  } else {
                     temp += sline[i];       
                  }
              }
              if (temp.length() > 0){
                 Update(temp);
                 
                 temp = ""; 
              }
          }
          
          idxAns = 0;
          for (i = 1; i < np; i++){
              if (package[i] > package[idxAns]){
                 idxAns = i;              
              }
          }
          
          printf("%s\n", s[idxAns]);
    }  
    
    return 0;
}
