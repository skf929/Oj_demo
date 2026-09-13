#include <stdio.h>
#define MAXM 100001
int num[MAXM];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        num[x]++;
    }
    for(int i = 1; i <= m; i++){
        printf("%d\n", num[i]);
    }
    return 0;
}
