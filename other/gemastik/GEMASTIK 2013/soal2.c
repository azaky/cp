#include <stdlib.h>
#include <stdio.h>

/* Preorder representation of Binary tree */
typedef struct tNode *node;
typedef struct tNode {
	int info;
	node left;
	node right;
} TreeNode;

#define Info(P) (P).info
#define Left(P) (P).left
#define Right(P) (P).right

#define boolean int
#define true 1
#define false 0

#define Nil NULL
#define null NULL

void BuildTree (TreeNode *T, char *st, int *idx)
{  (*idx)++;
   if (st[*idx]==')')
      (T)=Nil;
   else {
      T = (TreeNode *) malloc (sizeof(TreeNode));
	  Info(*T) = atoi(st[*idx]);
      (*idx)++;                         /* advance */
      BuildTree(&Left(*T),st,idx);
      BuildTree(&Right(*T),st,idx);
   }
   (*idx)++;                           /* advance */
}

int checkHeight(TreeNode T) {
	if (T == null) {
		return 0;
	}
	int leftHeight = checkHeight(Left(T));
	if (leftHeight == -1) {
		return -1;
	}
	int rightHeight = checkHeight(Right(T));
	if (rightHeight == -1) {
		return -1;
	}	
	int heightDiff = leftHeight - rightHeight;
	if (abs(heightDiff) > 1) {
		return -1;
	} else {
		return max(leftHeight, rightHeight) + 1;
	}
}
	
boolean isBalanced(TreeNode T) {
	if (checkHeight(T) == -1) {
		return false;
	} else {
		return true;
	}
}
	
boolean isBST(TreeNode T) {
	if (T == null) return false;
	else 
		if (Left(T) != null) { 
			if (Right(T) != null) {
				if ((Info(Left(T)) < Info(T)) && ((Info(Right(T)) >= Info(T))) return (isBST(Left(T)) && isBST(Right(T)));
				else return false; 
			} else { /* right T null */
				if (Info(Left(T)) < Info(T))  return isBST(Left(T));
				else return false;
			}
		} else { /*Left(T) == null */
			if (Right(T)!=null) {
				if (Info(Right(T)) >= Info(T)) return isBST(Right(T));
				else false;
			} else {
				return true; //one elmt
			}
		}
}
	
int main () {
	char *str; int idx = 0;
	str = (char *) malloc (100 * sizeof(char));
	gets(str);
	TreeNode T;
	BuildTree(&T,str,&idx);
	if (isBalanced(T) && isBST(T)) {
		printf("balanced binary search tree");
	} else if (isBalanced(T) && !isBST(T)) {
		printf("balanced tree, tapi bukan binary search tree");
	} else if (!isBalanced(T) && isBST(T)) {
		printf("balanced tree, tapi binary search tree");
	} else {
		printf("bukan balanced tree dan bukan binary search tree");
	}
	return 0;
}
