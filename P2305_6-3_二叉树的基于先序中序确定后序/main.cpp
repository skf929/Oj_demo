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
