//콜라 문제

#include <string>
#include <vector>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a) {
        answer = answer + b;
        n = n - a + b;
    }
    return answer;
}
