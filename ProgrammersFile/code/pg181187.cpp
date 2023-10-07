//두 원 사이의 정수 쌍

#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long rr1 = pow(r1, 2), rr2 = pow(r2, 2);
    for(long long i=1;i<r1+1;i++)
        answer += floor(sqrt(rr2-pow(i, 2))) + 1 - ceil((sqrt(rr1-pow(i, 2)));
    for(long long i=r1+1;i<=r2;i++)
        answer += floor(sqrt(rr2-pow(i, 2))) + 1;
    answer = answer * 4;
    return answer;
}
