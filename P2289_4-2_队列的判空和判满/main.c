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
