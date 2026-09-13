# 二维数组对称判断

## 题目要求

判断一个 4×4 的整型二维数组是否关于主对角线对称。

即对任意下标 i、j，都满足 `a[i][j] == a[j][i]`。

- 对称：输出 `对称`
- 不对称：输出 `不对称`

## 代码

```c
#include <stdio.h>

int main()
{
    int a[4][4]={1,2,3,4,
                 2,2,5,6,
                 3,5,3,7,
                 8,6,7,4};

    int i,j,found=0;

    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(a[i][j]!=a[j][i])
            {
                found=1;
                break;
            }
        }

        if(found)
            break;
    }

    if(found)
        printf("不对称\n");
    else
        printf("对称\n");

    getchar();
    getchar();
}
```
