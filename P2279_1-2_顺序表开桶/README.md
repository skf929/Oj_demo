# P2279 1-2 顺序表开桶

## 题目描述

本题考察数组的基本操作与时间复杂度分析。给定 n 个范围在 [1, m] 内的正整数，请统计其中数值 1, 2, ..., m 各出现了多少次。

注意：本题如果使用 c++ 输入输出，需要在主函数中加入

```cpp
cin.tie(nullptr)->sync_with_stdio(false);
```

否则会超时。

## 输入描述

输入第一行包含两个正整数 n (1 ≤ n ≤ 10^7) 和 m (1 ≤ m ≤ 10^5)，分别表示数据的个数和数值的范围上限。

输入第二行包含 n 个范围在 [1, m] 内的正整数，用空格隔开。

## 输出描述

共输出 m 行，其中第 i 行输出数字 i 出现的次数。

## 代码

```c
#include <stdio.h>
#define MAXM 100001
int num[MAXM];
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    int x;
    for(int i = 0;i < n;i++){
        scanf("%d",&x);
        num[x]++;
    }
    for(int i = 1;i <= m;i++){
        printf("%d\n",num[i]);
    }
    return 0;
}
```
