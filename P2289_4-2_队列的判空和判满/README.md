# P2289 4-2 队列的判空和判满

## 题目描述

设循环队列的存储空间为数组 Q，其最大容量为 N。初始时队列为空，队头指针 front = 0，队尾指针 rear = 0。本题采用 "牺牲一个存储单元" 的方法来区分队空和队满，判定条件如下：

- 队空条件：front == rear；
- 队满条件：(rear + 1) % N == front；
- 当前队列长度：(rear - front + N) % N。

请编写程序，模拟该循环队列的以下三种操作：

- `enqueue x`：若队列已满，则不进行入队操作；否则将元素 x 入队，rear = (rear + 1) % N；
- `dequeue`：若队列为空，则不进行出队操作；否则将队首元素出队，front = (front + 1) % N；
- `query`：查询并输出当前队列中实际存在的元素个数。

## 输入描述

输入第一行包含两个正整数 N 和 M（2 ≤ N, M ≤ 10000），分别表示循环队列的数组容量（包含牺牲的一个单元）和操作次数。

接下来 M 行，每行包含一个操作指令：

- `enqueue x`（x 为 int 范围内的正整数）
- `dequeue`
- `query`

## 输出描述

根据操作指令，输出对应的内容：

- 对于 `enqueue` 操作：若队列已满，输出 `Full`；否则完成入队后，输出新的队尾下标 rear；
- 对于 `dequeue` 操作：若队列已空，输出 `Empty`；否则完成出队后，输出出队元素及新的队头下标 front，用空格隔开；
- 对于 `query` 操作：输出一个整数，表示当前队列中的实际元素个数。

## 样例输入

```
3 7
enqueue 5
enqueue 10
enqueue 15
query
dequeue
dequeue
dequeue
```

## 样例输出

```
1
2
Full
2
5 1
10 2
Empty
```

## 样例输入 2

```
4 5
enqueue 1
dequeue
dequeue
enqueue 2
query
```

## 样例输出 2

```
1
1 1
Empty
2
1
```

## 代码

```c
#include <stdio.h>
#include <string.h>

#define MAXN 10005

int Q[MAXN];
int N;
int front = 0, rear = 0;

int isEmpty(void)
{
    return front == rear;
}

int isFull(void)
{
    return (rear + 1) % N == front;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Full\n");
        return;
    }
    Q[rear] = x;
    rear = (rear + 1) % N;
    printf("%d\n", rear);
}

void dequeue(void)
{
    if (isEmpty())
    {
        printf("Empty\n");
        return;
    }
    int x = Q[front];
    front = (front + 1) % N;
    printf("%d %d\n", x, front);
}

void query(void)
{
    printf("%d\n", (rear - front + N) % N);
}

int main()
{
    int M;
    scanf("%d %d", &N, &M);

    while (M--)
    {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0)
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(op, "dequeue") == 0)
        {
            dequeue();
        }
        else if (strcmp(op, "query") == 0)
        {
            query();
        }
    }
    return 0;
}
```
