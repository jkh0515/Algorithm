//괄호 회전하기

#include <string>
#include <vector>
using namespace std;

int cal(string s) {
    int arr[3] = {0};
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') arr[0]++;
        else if(s[i] == ')') {
            if(arr[0] > 0 and s[i-1] != '{' and s[i-1] != '[') arr[0]--;
            else return 0;
        }
        else if(s[i] == '{') arr[1]++;
        else if(s[i] == '}') {
            if(arr[1] > 0 and s[i-1] != '(' and s[i-1] != '[') arr[1]--;
            else return 0;
        }
        else if(s[i] == '[') arr[2]++;
        else if(s[i] == ']') {
            if(arr[2] > 0 and s[i-1] != '{' and s[i-1] != '(') arr[2]--;
            else return 0;
        }
    }
    for(int i=0;i<3;i++)
        if(arr[i] != 0) return 0;
    return 1;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++) {
        string temp;
        temp = s.substr(i, s.size()-i);
        temp += s.substr(0, i);
        answer += cal(temp);
    }
    return answer;
}
