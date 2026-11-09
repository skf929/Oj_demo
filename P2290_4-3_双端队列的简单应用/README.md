# P2290 4-3 双端队列的简单应用

## 题目描述

在操作系统中，CPU 无法同时处理所有进程。时间片轮转（Round Robin）算法是一种常用的抢占式调度算法：系统将所有就绪进程排成一个队列，CPU 每次只给队首进程分配一个微小的时间段（称为时间片）。如果进程在这个时间片内没有执行完，就会被剥夺执行权并重新放回队列的末尾，等待下一次调度。

现有 n 个进程，它们几乎同时在时刻 0 到达就绪队列，并按照输入的顺序依次排入队列中。每个进程 i 都有一个所需的总执行时间 t_i。系统给定的时间片大小为 q。调度规则如下：

- 每次从就绪队列的队首取出一个进程；
- 如果该进程剩余所需的执行时间 ≤ q，则该进程在此轮直接执行完毕，记录它的完成时间；
- 如果该进程剩余所需的执行时间 > q，则该进程在 CPU 上执行完一个时间片 q 之后，将其剩余所需的时间更新，并重新插入到队列的末尾；
- 重复上述步骤，直到队列中的所有进程都执行完毕。

请编写程序，模拟该调度过程，计算并输出每个进程最终的完成时刻。

## 输入描述

输入第一行包含两个正整数 n 和 q（1 ≤ n, q ≤ 100），分别表示进程个数和时间片大小。

输入第二行包含 n 个正整数 t_1, t_2, …, t_n（1 ≤ t_i ≤ 10000），其中 t_i 表示第 i 个进程所需的总执行时间。

## 输出描述

输出一行，包含 n 个整数，依次表示第 1 到第 n 个进程的完成时刻，整数之间用空格隔开。

## 样例输入

```
3 4
10 2 5
```

## 样例输出

```
17 6 15
```

## 样例输入 2

```
2 3
5 2
```

## 样例输出 2

```
7 5
```

## 代码

```c
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
```
