# P2286 3-2 栈的应用：进制转换

## 题目描述

给定一个十进制正整数 N 和目标进制 b (2 ≤ b ≤ 16)，请编写程序利用栈的基本操作，将 N 转换成对应的 b 进制数并输出。可以遵照以下算法步骤：

1. 初始化一个空栈；
2. 当 N 大于 0 时，计算 N 除以 b 的余数，并将该余数压入栈中；
3. 更新 N 为 N 除以 b 的商；
4. 重复步骤 2 和 3，直到 N 变为 0；
5. 依次弹出栈中的所有元素并输出，即得到对应的 b 进制数。

当 b > 10 时，10 ~ 15 分别用大写字母 A ~ F 表示。

## 输入描述

输入一行，包含两个整数 N 和 b (1 ≤ N ≤ 10^9, 2 ≤ b ≤ 16)，分别表示十进制正整数和目标进制。

## 输出描述

输出一行，表示 N 转换后的 b 进制数。

## 样例输入

```
1348 8
```

## 样例输出

```
2504
```

## 样例输入 2

```
255 16
```

## 样例输出 2

```
FF
```

## 代码

```c
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
```
