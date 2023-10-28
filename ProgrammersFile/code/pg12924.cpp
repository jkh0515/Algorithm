//숫자의 표현

#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=n;i>0;i--) {
        int sum = 0, tempi = i;
        for(int j=0;j<i;j++){
            sum += tempi;
            if(sum == n) {
                answer++;
                break;
            }
            if(sum > n) break;
            tempi--;
        }
    }
    return answer;
}
