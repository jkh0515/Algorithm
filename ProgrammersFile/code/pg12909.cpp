//올바른 괄호

#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int n = 0;
    bool answer = true;
    for(int i=0;i<s.size();i++) {
        if(n < 0) break;
        if(s[i] == ')') n--;
        else n++;
    }
    if(n != 0) answer = false;
    return answer;
}
