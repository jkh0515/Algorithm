//큰 수 만들기 [ C++ ]

#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int max = 0;
    for(int i=number.size()-k-1;i>=0;i--) {
        for(int j=max;j<number.size()-i;j++) {
            if(number[max] < number[j]) max = j;
            if(number[max] == 9) break;
        }
        answer += number[max++];
    }
    return answer;
}
