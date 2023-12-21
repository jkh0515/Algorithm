//귤 고르기 [ C ]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cal(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int arr[10000001] = {0}, max = 0;
    for(int i=0;i<tangerine_len;i++) {
        if(max < tangerine[i]) max = tangerine[i];
        arr[tangerine[i]]++;
    }
    qsort(arr, max+1, sizeof(int), cal);
    for(int i=0;i<=max;i++) {
        k -= arr[i];
        if(k <= 0) return i+1;
    }
}
