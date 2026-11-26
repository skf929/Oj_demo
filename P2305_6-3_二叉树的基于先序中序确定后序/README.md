# P2305 6-3 二叉树的基于先序中序确定后序

## 题目描述

一棵二叉树的先序遍历序列和中序遍历序列可以唯一确定这棵二叉树：先序序列的第一个结点是根结点，在中序序列中找到该根结点后，其左侧是左子树的中序序列、右侧是右子树的中序序列，再根据左右子树的结点个数在先序序列中划分出左右子树的先序序列，递归进行即可还原整棵二叉树。

这一性质是二叉树部分的常考考点（考研选择题常给出先序与中序序列，要求建树后计算后序或层次遍历的结果）。

现给定一棵二叉树（结点值互不相同）的先序遍历序列和中序遍历序列，请你构造出这棵二叉树，并输出它的后序遍历序列。

## 输入描述

输入第一行包含一个正整数 `n`（`1 ≤ n ≤ 10^5`），表示二叉树的结点个数。

输入第二行包含 `n` 个整数，为二叉树的先序遍历序列，用空格隔开。

输入第三行包含 `n` 个整数，为二叉树的中序遍历序列，用空格隔开。

输入保证先序和中序序列对应同一棵二叉树，且结点值为 `1` 到 `n` 的整数、互不相同。

## 输出描述

输出一行，为二叉树的后序遍历序列，结点值之间用一个空格隔开。

## 样例输入 1

```text
7
1 2 4 5 3 6 7
4 2 5 1 6 3 7
```

## 样例输出 1

```text
4 5 2 6 7 3 1
```

## 样例输入 2

```text
3
1 2 3
2 1 3
```

## 样例输出 2

```text
2 3 1
```

## 代码

```cpp
#include<iostream>
#include<vector>
using namespace std;

vector<int> pre, pos;

void postTraversal(int preL, int inL, int inR)
{
    if(inL > inR)
        return;

    int root = pre[preL];
    int k = pos[root];

    int leftSize = k - inL;

    postTraversal(preL + 1, inL, k - 1);

    postTraversal(preL + leftSize + 1, k + 1, inR);

    cout << root << " ";
}

int main()
{
    int n;
    cin >> n;

    pre.resize(n);
    vector<int> in(n);
    pos.resize(n + 1);

    for(int i = 0; i < n; i++)
        cin >> pre[i];

    for(int i = 0; i < n; i++)
    {
        cin >> in[i];
        pos[in[i]] = i;
    }

    postTraversal(0, 0, n - 1);

    cout << endl;

    return 0;
}
```
