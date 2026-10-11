#include <stdio.h>
#define MAXSIZE 64

int stack[MAXSIZE];
int top = 0;

void push(int c) {
    stack[top++] = c;
}

int pop() {
    top--;
    return stack[top];
}

int main() {
    int N, b;
    int remainder;
    scanf("%d %d", &N, &b);

    while (N > 0) {
        remainder = N % b;
        push(remainder);
        N = N / b;
    }

    while (top != 0) {
        int d = pop();
        if (d < 10)
            printf("%d", d);
        else
            printf("%c", 'A' + d - 10);
    }
    printf("\n");
    return 0;
}
