#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

typedef struct data{
	
	int l_mobil;
	struct data* next;
	
}data;

typedef struct list{
	data *first, *last;
}list;

int empty(list l){
	return (l.first == NULL);
}

data* front(list l){
	return l.first;
}

void pop(list *l){
	l->first = l->first->next;
}

void push(list *l, int l_mobil){
	data *temp = (data*)malloc(sizeof(data));
	temp->l_mobil = l_mobil;
	temp->next = NULL;
	if (empty(*l)){
		l->first = temp;
		l->last = temp;
	}
	else {
		l->last->next = temp;
		l->last = temp;
	}
}

void print(list l){
	puts("PRINTING LIST ...");
	data *temp;
	temp = l.first;
	while (temp != NULL){
		printf("%d\n",temp->l_mobil);
		temp = temp->next;
	}
	puts("END OF PRINTING LIST ...");
}

int main(){
	int c, tc; scanf("%d",&c);
	for (tc = 1; tc <= c; tc++){
		int l, m;
		scanf("%d%d",&l,&m);
		
		list left, right;
		left.first = left.last = right.first = right.last = NULL;
		
		int i;
		for (i = 1; i <= m; ++i){
			int l_mobil;
			char posisi[10];
			scanf("%d%s",&l_mobil,posisi);
			if (!strcmp(posisi,"left")) push(&left,l_mobil);
			if (!strcmp(posisi,"right")) push(&right,l_mobil);
		}
		
		int Moveleft = 0, Moveright = 0;
		
		for(; !empty(left); ++Moveleft){
			//print(left);
			int space = 100*l;
			while (!empty(left)){
				if (space >= front(left)->l_mobil){
					space -= front(left)->l_mobil;
					pop(&left);
				}
				else break;
			}
		}
		for(; !empty(right); ++Moveright){
			int space = 100*l;
			while (!empty(right)){
				if (space >= front(right)->l_mobil){
					space -= front(right)->l_mobil;
					pop(&right);
				}
				else break;
			}
		}
		printf("%d\n",2*Moveleft-1 > 2*Moveright ? 2*Moveleft-1 : 2*Moveright);
	}
	return 0;
}
