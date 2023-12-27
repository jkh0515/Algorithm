//연속 부분 수열 합의 개수 [ C ]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int elements[], size_t elements_len) {
    int answer = 0, arr[10000001] = {0}, temp;
    for(int i=1;i<=elements_len;i++) {
        for(int j=0;j<elements_len;j++) {
            temp = 0;
            for(int k=0;k<i;k++)
                temp += elements[(j+k)%(elements_len)];
            if(arr[temp]++ == 0) answer++;
        }
    }
    return answer;
}
