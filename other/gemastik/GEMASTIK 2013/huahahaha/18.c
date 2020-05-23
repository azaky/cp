#include <stdlib.h>
#include <stdio.h>

 void replace(char *str){
 if(str == NULL) return;
 int length, i, j;
 char *backup;
 for(i=0;;i++)
 if(str[i] == '\0') break;
 length = i;
 backup = malloc(length*sizeof(char));
 for(i=0; i<length-i; i++)
 backup[i] = str[i];
 for(i=0, j=0; j<length-1; i++){
 if((int)backup[i] != 32)
 str[j] = backup[i];
 else{
 str[j] = '%';
 str[j+1] = '2';
 str[j+2] = '0';
 j += 2;
 }
 j++;
 }
 free(backup);
 }
