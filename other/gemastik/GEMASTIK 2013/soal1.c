#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void quicksort(int *nbr, int n){
  if(n <= 1)
    return;
  if(n == 2 && nbr[0] <= nbr[1])
    return;
  if(nbr == NULL)
    return;

  int pivot = (int)(n/2.);
  int i;

  for(i = 0; i < n; i++){
    if(nbr[i] > nbr[pivot] && i < pivot){
      int temp = nbr[pivot];
      nbr[pivot] = nbr[i];
      nbr[i] = temp;
    }
    if(nbr[i] < nbr[pivot] && i > pivot){
      int temp = nbr[pivot];
      nbr[pivot] = nbr[i];
      nbr[i] = temp;
    }
  }

  int *left = malloc((pivot + 1)*sizeof(int));
  int *right = malloc((n - pivot - 1)*sizeof(int));

  for(i = 0; i < pivot + 1; i++)
    left[i] = nbr[i];

  for(i = 0; i < n - pivot - 1; i++)
    right[i] = nbr[pivot + 1 + i];

  quicksort(left, pivot+1);
  quicksort(right, n-pivot-1);

  for(i = 0; i < pivot + 1; i++)
    nbr[i] = left[i];

  for(i = 0; i < n - pivot - 1; i++)
    nbr[pivot + 1 + i] = right[i];

  free(left);
  free(right);
}

int is_permutation(char *str1, char *str2){
  
  //cek string kosong
  if (strcmp(str1,"-1") == 0 || strcmp(str2,"-1") == 0) return strcmp(str1,str2) == 0;
  

  int length, i;
  int *stra1, *stra2;

  if(str1 == NULL || str2 == NULL)
    return 0;

  for(i=0;; i++)
    if(str1[i] == '\0')
      break;
  length = i; // number of characters, excluding null character

  for(i=0;; i++)
    if(str2[i] == '\0')
      break;

  // not permutation because of difference in length
  if(length != i)
    return 0;

  // convert to ASCII code arrays
  stra1 = malloc(length*sizeof(int));
  stra2 = malloc(length*sizeof(int));
  
  for(i=0; i<length; i++){
    stra1[i] = (int)str1[i];
    stra2[i] = (int)str2[i];
  }

  // sort ASCII arrays
  quicksort(stra1, length);
  quicksort(stra2, length);

  // compare ASCII codes
  for(i=0; i<length; i++)
    if(stra1[i] != stra2[i])
      return 0;

  // free memory
  free(stra1);
  free(stra2);

  // permutation not excluded neither based on length, nor sorted ASCII codes
  // conclude that strings are permutations of one another
  return 1;
}

int main(){
//  char str1[10] = "abcdefg";
//  char str2[10] = "bacedgf";
  char str1[101], str2[101], s1[101], s2[101];
  gets(str1); strcpy(s1,str1);
  gets(str2); strcpy(s2,str2);
  //upcase!
  int i, l1 = strlen(str1), l2 = strlen(str2);
  for (i = 0; i < l1; i++){
    if ('a' <= str1[i] && str1[i] <= 'z') str1[i] += 'A' - 'a';
    //buang whitespace
    if (isspace(str1[i])){
      str1[i] = str1[--l1];
      str1[l1] = '\0';
      i--;
    }
  }
  for (i = 0; i < l2; i++){
    if ('a' <= str2[i] && str2[i] <+ 'z') str2[i] += 'A' - 'a';
    //buang whitespace
    if (isspace(str2[i])){
      str2[i] = str2[--l2];
      str2[l2] = '\0';
      i--;
    }
  }
  //string kosong
  if (strcmp(str1,"-1") == 0 || strcmp(str2,"-1") == 0){
    if (strcmp(str1,str2) == 0)
      printf("String kosong adalah permutasi dari string kosong");
    else if (strcmp(str1,"-1") == 0)
      printf("String kosong bukan permutasi dari %s",s2);
    else if (strcmp(str2,"-1") == 0)
      printf("%s bukan permutasi dari string kosong",s1);
    else
      printf("dikra jelek");
  }
  else if (is_permutation(str1, str2))
    printf("%s adalah permutasi dari %s", s1, s2);
  else
    printf("%s bukan permutasi dari %s", s1, s2);
  
  puts("");
  
  return 0;
}
