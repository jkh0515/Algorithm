//N개의 최소공배수 [ C ]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len) {
    int answer = 1, num[100] = {0}, temp;
    for(int i=0;i<arr_len;i++) {
        for(int j=2;j<=arr[i];j++) {
            temp = 0;
            while(arr[i] % j == 0) {
                temp++;
                arr[i] /= j;
            }
            if(num[j] < temp) num[j] = temp;
        }
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<num[i];j++)
            answer *= i;
    return answer;
}
