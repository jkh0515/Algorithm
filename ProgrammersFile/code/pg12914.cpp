//멀리 뛰기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[2001] = {0};

int cal(int n) {
    if(arr[n] != -1) return arr[n];
    arr[n] = (cal(n-1) + cal(n-2)) % 1234567;
    return arr[n];
}

long long solution(int n) {
    for(int i=0;i<2001;i++)
        arr[i] = -1;
    arr[1] = 1; arr[2] = 2;
    cal(n);
    return arr[n];
}
