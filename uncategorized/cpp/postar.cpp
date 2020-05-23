#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int a[55][55],n,rd,cd,bebek,c,m,m1,l1,r1,l,r,ans,x;
char g[55][55];
bool mati[55][55],yey;
void flood(int row,int col)
{
    
     if (g[row][col] == 'K') c++;
      
     mati[row][col] =1;
  if (row > 0)
   {
          if (!mati[row-1][col]) flood(row-1,col);
          if (col >0)
           if (!mati[row-1][col-1]) flood(row-1,col-1);
          }     
 if (col >0)
 {
         if (!mati[row][col-1]) flood(row,col-1);
         if (row < n-1)
          if (!mati[row+1][col-1]) flood(row+1,col-1);
         }
 if (row < n-1){
  if (!mati[row+1][col]) flood(row+1,col);
  if (col <n-1)
    if (!mati[row+1][col+1]) flood(row+1,col+1);
  }
 if (col < n-1){
    if (!mati[row][col+1]) flood(row,col+1);
    if (row>0)
      if (!mati[row-1][col+1]) flood(row-1,col+1);
    }
}
  
int main()
{
 scanf("%d",&n); gets(g[0]);
 for (int i = 0; i < n; i++) 
   gets(g[i]);
 rd = 0; cd = 0; bebek = 0;
 for (int i = 0; i < n; i++) 
   for (int j = 0; j < n; j++)
     if (g[i][j] == 'P'){
                 rd = i; cd = j;
                 }
     else if (g[i][j] == 'K') bebek++;
   //  cout << "heng" << endl;
 for (int i =0; i < n; i++)
  for (int j = 0; j < n; j++)
    scanf("%d",&a[i][j]);
     
 x = a[rd][cd];
 r = 1000000;
 l = 0; ans  = 1000000;
 while (l <= r)
   {
       m = (l+r)/2;
       l1 = 0; r1 = 1000000;
       yey = 0;
        while (l1<=r1)
         {
           m1 = (l1+r1)/2;
           memset(mati,0,sizeof(mati));
           for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
               if (a[i][j] > x+m1 || a[i][j] < x-m) mati[i][j] = 1;
               
               c = 0; flood(rd,cd);
           if (c >= bebek) {
                          if (m1+m < ans) ans = m1+m;
                          r1 = m1-1;
                          yey = 1;
                         } else l1 = m1+1;
           
        //   cout << l1 << " " << r1 << "   " << l << " " << r << " " << c<< endl; 
         }
        if (yey) r = m-1;
        else l = m+1;
       }  
      cout << ans << endl;
    //  system("pause"); 
}
