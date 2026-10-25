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
