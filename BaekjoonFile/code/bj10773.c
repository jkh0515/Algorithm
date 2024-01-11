//제로 [ C ]

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, arr[100001] = {0}, idx = 0, answer = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[idx++]);
        if(arr[idx-1] == 0 && idx > 0)
            idx -= 2;
    }
    for(int i=0;i<idx;i++)
        answer += arr[i];
    printf("%d", answer);
    return 0;
}
