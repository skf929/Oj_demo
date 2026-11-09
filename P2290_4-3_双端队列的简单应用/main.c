#include<stdio.h>
#define MAXSIZE 10005
typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *Q){
	Q->front = Q->rear = 0;
}

int IsEmpty(SqQueue *Q){
	return Q->front == Q->rear;
}

int EnQueue(SqQueue *Q,int x){
	if((Q->rear+1)%MAXSIZE == Q->front){
		return 0;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return 1;
}

int DeQueue(SqQueue *Q,int *x){
	if(IsEmpty(Q)){
		return 0;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return 1;
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int t[MAXSIZE],ans[MAXSIZE];
	SqQueue Q;
	
	InitQueue(&Q);
	
	for(int i = 0;i < n;i++){
		scanf("%d",&t[i]);
		EnQueue(&Q,i);
	}

	long long time = 0;
	
	while(!IsEmpty(&Q)){
		int id;
		DeQueue(&Q,&id);
		
		if(t[id] <= q){
			time += t[id];
			ans[id] = time;
		}else{
			time += q;
			t[id] -= q;
			EnQueue(&Q,id);
		}
	}
	for(int i = 0;i < n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
