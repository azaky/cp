#include<stdio.h>
#include<algorithm>
 
typedef struct data{
        int card;
        struct data *next;
        }data;
        
typedef struct Queue{
        data *first;
        data *last;
        }queue;
 
void push(queue* l,int p){
        data *temp=new data;
        temp->card=p;
        temp->next=NULL;
        if(l->first==NULL){
                l->first = l->last=temp;
                return;
        }
        l->last->next=temp;
        l->last=temp;
}
 
void pop(queue* l){
        if(l->last==NULL && l->first==NULL)return;
        data *temp=l->first;
        l->first=l->first->next;
        free(temp);
}
 
int top(queue *l){
        if(l->first!=NULL)return l->first->card;
}
 
int main(){
        while(1){
                queue q;
                q.first=q.last=NULL;
                int banyak;
                scanf("%d",&banyak);
                if(banyak==0) break;
                for(int i=1;i<=banyak;i++) push(&q,i);   
                
                printf("Discarded cards:");
                for(int i=2;i<=banyak;i++){
                        printf(" %d",top(&q));
						pop(&q);
                        push(&q,top(&q)); 
						pop(&q);
                        if(q.first->next!=NULL)printf(",");
                }
        printf("\nRemaining card: %d\n",top(&q));
        }       
return 0;
}
