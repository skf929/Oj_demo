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
