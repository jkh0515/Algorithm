//옹알이 (2) [ C ]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0, len = 0, prev = -1;
    char* arr[] = {"ma", "ye", "woo", "aya"}, temp[100];
    for(int i=0;i<babbling_len;i++) {
        bool tf = false;
        if(strlen(babbling[i]) < 2) continue;
        for(int j=0;j<strlen(babbling[i]);j++) {
            temp[len] = babbling[i][j];
            temp[++len] = '\0';
            if(len == 2) {
                for(int k=0;k<2;k++) {
                    if(k == prev) continue;
                    if(strcmp(temp, arr[k]) == 0) {
                        tf = true;
                        len = 0;
                        strcpy(temp, "");
                        prev = k;
                        break;
                    }
                }
                if(len != 0) continue;
            }
            if(len == 3) {
                for(int k=2;k<4;k++) {
                    if(k == prev) continue;
                    if(strcmp(temp, arr[k]) == 0) {
                        tf = true;
                        len = 0;
                        strcpy(temp, "");
                        prev = k;
                        break;
                    }
                }
                if(len != 0) {
                    tf = false;
                    break;
                }
            }
        }
        if(len != 0) tf = false;
        if(tf == true) answer++;
        len = 0;
        prev = -1;
        strcpy(temp, "");
    }
    return answer;
}
