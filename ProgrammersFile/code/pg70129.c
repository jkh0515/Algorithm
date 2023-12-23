//이진 변환 반복하기 [ C ]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int translate(int n, int answer, int type) {
    int tn = 0, tnow = 0;
    while(n != 1) {
        if(n % 2 == 1) tn++;
        n /= 2;
        tnow++;
    }
    if(type == 0) answer += 1;
    if(type == 1) answer += tnow-tn;
    if(tn == 0 && tnow == 0) return answer;
    return translate(tn+1, answer, type);
}

int* solution(const char* s) {
    int* answer = (int*)malloc(sizeof(int) * 2), n = 0, size = strlen(s);
    for(int i=0;i<size;i++)
        if(s[i] == '1') n++;
    answer[0] = translate(n, 0, 0);
    answer[1] = translate(n, size-n, 1);
    return answer;
}
