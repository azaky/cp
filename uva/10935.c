#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
	
	int card;
	struct data *next, *prev;
	
}data;

typedef struct list{
	data *first, *last;
}list;

void init(list *l, int n){
	int i;
	for (i=1; i <= n; i++){
		data *temp = (data*)malloc(sizeof(data));
		temp->card = i;
		if (i == 1){
			temp->next = temp->prev = temp;
			l->first = l->last = temp;
		}
		else {
			l->last->next = temp;
			l->first->prev = temp;
			temp->next = l->first;
			temp->prev = l->last;
			l->last = temp;
		}
	}
}

int main(){
	int n;
	while (scanf("%d",&n) == 1){
		if (n == 0) return 0;
		list kartu;
		init(&kartu,n);
		
		printf("Discarded cards:");
		data *temp = kartu.first;
		while (temp->next != temp){
			//keluarin kartu temp
			if (temp == kartu.first) printf(" %d",temp->card); else printf(", %d",temp->card);
			//buang temp
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			//pindahin kartu teratas
			temp = temp->next;
			temp = temp->next;
		}
		printf("\nRemaining card: %d\n",temp->card);
	}
}
