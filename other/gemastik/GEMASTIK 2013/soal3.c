#include <stdio.h>

int n_solns;

void Try(int ist[22][22], int pos, int nampung, int mv[], int mv_no) {
   int i, j;

   if (pos == nampung) {
      n_solns++;
      for (i=0; i<mv_no-1; i++) {
	 printf("%d ", mv[i]);
      } printf("%d\n",mv[mv_no-1]);
      return;
   }

   for (i=0; i<22; i++) {
      if (ist[pos][i]) {
	 for (j=0; j<mv_no; j++) {
	    if (mv[j] == i) break;
	 }
	 if (j == mv_no) {
	    mv[mv_no] = i;
	    Try(ist, i, nampung, mv, mv_no+1);
	 }
      }
   }
}


int main(void) {
   int nampung;
   int x, y;
   int ist[22][22];
   int mv[22], n_m;
   int cas = 1;

   while (1) {

      for (x=0; x<22; x++)
	 for (y=0; y<22; y++)
	    ist[x][y] = 0;

      if(scanf("%d %d", &x, &y)!=2)break;
      while (x && y) {
	 ist[x][y] = 1; ist[y][x] = 1;
	 scanf("%d %d", &x, &y);
      }
      scanf("%d",&nampung);

      printf("KASUS NO. %d:\n", cas++);
      mv[0] = 1;
      n_solns = 0;
      Try(ist, 1, nampung, mv, 1);
      printf("Ada %d rute dari posko ke titik %d.\n",
	     n_solns, nampung);
   }

   return 0;
}

      
