# P2282 2-1 单链表的基本操作

## 题目描述

线性表的链式存储结构的特点是用一组物理存储地址不连续的存储单元存储线性表的数据元素，每个结点除存储数据元素外，还必须存储指向其后继结点的指针。为了方便操作，单链表常带一个 "头结点"，其指针域指向表中第一个结点。

现给定一个带头结点的单链表（结点按输入顺序尾插建立），请你完成代码填空，实现单链表的建立、删除指定位置结点和遍历输出这一组基本操作。

## 输入描述

输入第一行包含一个正整数 n (1 ≤ n ≤ 100)，表示单链表中结点的个数。

输入第二行包含 n 个整数，表示各结点的数据元素，用空格隔开，按顺序依次尾插到链表尾部。

输入第三行包含一个整数 j，表示删除链表中第 j 个结点（1 ≤ j ≤ n）。

## 输出描述

输出一行，包含删除后链表中的所有元素，元素之间用一个空格隔开。

## 样例输入

```
5
10 20 30 40 50
3
```

## 样例输出

```
10 20 40 50
```

## 样例输入 2

```
3
1 2 3
1
```

## 样例输出 2

```
2 3
```

## 代码

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList;

int main()
{
    LinkList L, p, q;
    int n, i, j;

    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;

    scanf("%d", &n);

    p = L;

    for (i = 0; i < n; i++) {
        q = (LinkList)malloc(sizeof(Node));
        scanf("%d", &q->data);

        p->next = q;
        q->next = NULL;

        p = q;
    }

    scanf("%d", &j);

    p = L;

    for (i = 1; i < j; i++)
        p = p->next;

    q = p->next;

    p->next = q->next;

    free(q);

    p = L->next;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");

    return 0;
}
```
