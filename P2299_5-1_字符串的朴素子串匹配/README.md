# P2299 5-1 字符串的朴素子串匹配

## 题目描述

串是由零个或多个字符组成的有限序列。求子串在主串中的位置是串的基本操作之一：给定主串 s 和模式串 t，定位函数 `Index(s, t)` 返回子串 t 在主串 s 中首次出现的位置，若 t 不是 s 的子串则返回 0。

简单模式匹配算法（朴素匹配）的思想是：从主串 s 的第一个字符起与模式串 t 的字符逐个比较，若某次比较失配，则将主串指针回溯到本次匹配起点的下一个位置，模式串指针回到串首，重新开始比较；直到匹配成功或主串剩余长度不足为止。

现请你完成代码填空，实现简单模式匹配算法。

## 输入描述

输入两行字符串，第一行为主串 s，第二行为模式串 t。两个串的长度均不超过 100，且仅由小写字母组成。

## 输出描述

输出模式串 t 在主串 s 中首次出现的位置（从 1 开始计数）；若 t 不是 s 的子串，输出 0。

## 样例输入

```
abcabdabc
abd
```

## 样例输出

```
4
```

## 样例输入 2

```
aaaa
aa
```

## 样例输出 2

```
1
```

## 程序填空

```c
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int Index(char s[], char t[]) {
    int i = 0, j = 0;
    int slen = strlen(s), tlen = strlen(t);
    while (i < slen && j < tlen) {
        if (s[i] == t[j]) {
            ________(1)________
            ________(2)________
        }
        else {
            i = ________(3)________;
            j = 0;
        }
    }
    if (________(4)________)
        return i - tlen + 1;
    else
        return 0;
}

int main() {
    char s[MAXSIZE + 1], t[MAXSIZE + 1];
    scanf("%s%s", s, t);
    printf("%d\n", ________(5)________);
    return 0;
}
```

## 代码

```c
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int Index(char s[], char t[]) {
    int i = 0, j = 0;
    int slen = strlen(s), tlen = strlen(t);
    while (i < slen && j < tlen) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            i = i-j+1;
            j = 0;
        }
    }
    if (j == tlen)
        return i - tlen + 1;
    else
        return 0;
}

int main() {
    char s[MAXSIZE + 1], t[MAXSIZE + 1];
    scanf("%s%s", s, t);
    printf("%d\n", Index(s, t));
    return 0;
}
```
