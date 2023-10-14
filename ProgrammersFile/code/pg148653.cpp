//마법의 엘리베이터

#include <string>
#include <vector>
using namespace std;

int solution(int st) {
    int answer = 0;
    string str = to_string(st);
    for(int i=str.size()-1;i>=0;i--) {
        int stri = (int)str[i] - '0';
            if(stri > 5) {
                answer += 10 - stri;
                if(i == 0) answer ++;
                else str[i-1] = (int)str[i-1] + 1;
            }
            else if(stri == 5) {
                if((int)str[i-1] - '0' > 4) {
                    if(i == 0) answer ++;                    
                    else str[i-1] = (int)str[i-1] + 1;
                }
                answer += 5;
            }
            else answer += stri;
        }
    return answer;
}
