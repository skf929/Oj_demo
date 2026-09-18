# 排队插入删除

## 题目描述

食堂里正在举办买卤肉饭抽奖的活动，因为奖品是精美手办，所以吸引了大量的二次元，排起了长队。

这个队伍有一个奇特之处，进入队伍的方式不是从队伍的尾部进入，而是用一个变量 i 表示进入队伍的位置。如果 i 处进入了一个新的学生，那么从 1 到 i−1 的排队学生不变，而原本在 i 位及其后方的学生需要向后挪动一位，空出的第 i 位由新来的学生占据。同理，如果第 i 位的学生离开，后方的学生会全部向前挪动一位。

一共有三种操作：

- 变量 i 加一，指令格式为：`1`。
- 在 i 位置加入一名学生，指令格式为：`2 x`，x 是进入队伍的学生编号，保证不重复。
- 在 i 位置离开一名学生，指令格式为：`3`。

队伍位置编号从 1 开始，初始 i 的值为 1，一共给出 n (1 ≤ n ≤ 100000) 个操作，全部操作完成之后，依次输出队伍里的学生编号。输入会保证操作总是合法的，i 保证不会大于当前队伍里学生数 + 1，且不会在没有学生的位置出现学生离开的操作。

## 输入描述

第一行输入正整数 n，表示操作次数。

接下来的 n 行每行为一个操作指令。

## 输出描述

输出一行，为队伍里从前到后的学生编号，用空格隔开。

## 样例输入

```
10
2 1
2 2
3
2 3
2 4
1
3
3
2 5
1
```

## 样例输出

```
4 5
```

## 代码

```c
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct Node {
    int data;           // 学生编号
    struct Node *next;  // 指向下一个节点
};

int main() {
    int n;
    scanf("%d", &n);

    // 哨兵节点（不存学生）
    struct Node dummy;
    dummy.next = NULL;

    // i = 1
    // pre 指向第 i 个位置的前一个节点
    struct Node *pre = &dummy;

    int i = 1;

    // 处理 n 次操作
    for (int k = 0; k < n; k++) {

        int op;
        scanf("%d", &op);

        // 操作 1：i 加一
        if (op == 1) {
            i++;

            // 当前第 i 个位置的前一个节点
            // 向后移动一个节点
            pre = pre->next;
        }

        // 操作 2：在第 i 个位置插入学生 x
        else if (op == 2) {
            int x;
            scanf("%d", &x);

            // 创建新节点
            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            // 存储学生编号
            newNode->data = x;

            // 新节点指向原来的第 i 个节点
            newNode->next = pre->next;

            // 前一个节点指向新节点
            pre->next = newNode;
        }

        // 操作 3：删除第 i 个学生
        else if (op == 3) {

            // 找到第 i 个节点
            struct Node *del = pre->next;

            // 跳过这个节点
            pre->next = del->next;

            // 释放被删除节点的内存
            free(del);
        }
    }

    // 输出整个链表
    struct Node *p = dummy.next;

    int first = 1;

    while (p != NULL) {
        if (!first) {
            printf(" ");
        }

        printf("%d", p->data);

        first = 0;
        p = p->next;
    }

    printf("\n");

    // 释放剩余节点
    p = dummy.next;

    while (p != NULL) {
        struct Node *temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}
```
