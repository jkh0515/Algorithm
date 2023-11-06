//124 나라의 숫자

#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    n -= 1;
    while(n > 2) {
        if(n % 3 == 1) answer = "2" + answer;
        else if(n % 3 == 2) answer = "4" + answer;
        else answer = "1" + answer;
        n = n / 3 - 1;
    }
    if(n == 1) answer = "2" + answer;
    else if(n == 2) answer = "4" + answer;
    else answer = "1" + answer;
    return answer;
}
