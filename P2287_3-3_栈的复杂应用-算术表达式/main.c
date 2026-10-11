#include <stdio.h>

#define MAXSIZE 1005

int num[MAXSIZE];
int ntop = 0;           // 操作数栈，ntop == 0 为空
char op[MAXSIZE];
int otop = 0;           // 运算符栈，otop == 0 为空

// 优先级：乘 2，加减 1，左括号 0（遇到 ( 时不会被先算）
int priority(char c) {
    if (c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;           // '('
}

// 弹出一个运算符和两个操作数，计算后把结果压回操作数栈
void calc() {
    char c = op[--otop];
    int b = num[--ntop];    // 后弹出的是右操作数
    int a = num[--ntop];    // 先弹出的是...注意这里 a 是左操作数
    int r;
    if (c == '+') r = a + b;
    else if (c == '-') r = a - b;
    else r = a * b;
    num[ntop++] = r;
}

int main() {
    char s[MAXSIZE];
    int i, len;
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num[ntop++] = c - '0';
        }
        else if (c == '(') {
            op[otop++] = c;
        }
        else if (c == ')') {
            while (op[otop - 1] != '(') {
                calc();
            }
            otop--;                         // 弹出 '('
        }
        else {                              // + - *
            while (otop > 0 && priority(op[otop - 1]) >= priority(c)) {
                calc();
            }
            op[otop++] = c;
        }
    }

    while (otop > 0) {
        calc();
    }

    printf("%d\n", num[0]);
    return 0;
}
