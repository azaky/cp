#include <stdio.h>
int main(){

char blocks[3] = {'A','B','C'};
 char *ptr = &blocks[0];
 char temp;
temp = blocks[0]; printf("4 : %c\n",temp);
 temp = *(blocks + 2); printf("5 : %c\n",temp);
 temp = *(ptr + 1); printf("6 : %c\n",temp);
 temp = *ptr; printf("7 : %c\n",temp);
 ptr = blocks + 1;
 temp = *ptr; printf("8 : %c\n",temp);
 temp = *(ptr + 1); printf("9 : %c\n",temp);
 ptr = blocks;
 temp = *++ptr; printf("10 : %c\n",temp);
 temp = ++*ptr; printf("11 : %c\n",temp);
 temp = *ptr++; printf("12 : %c\n",temp);
 temp = *ptr; printf("13 : %c\n",temp);

return 0;
}
