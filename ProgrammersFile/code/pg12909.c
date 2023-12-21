//올바른 괄호 [C]

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {
    int n = 0;
    for(int i=0;i<strlen(s);i++) {
        if(n < 0) return false;
        if(s[i] == '(') n++;
        else n--;
    }
    if(n != 0) return false;
    return true;
}
