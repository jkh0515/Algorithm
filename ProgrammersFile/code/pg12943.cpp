//콜라스 추측

#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    int answer = 0, i = 0;
    long num2 = long(num);
    for(i=0;i<500;i++) {
        if(num2 == 1) 
            break;
        else if(num2%2 == 0)
            num2 = num2 / 2;
        else
            num2 = num2 * 3 + 1;
    }
    answer = i;
    if(answer == 500)
        answer = -1;
    return answer;
}
