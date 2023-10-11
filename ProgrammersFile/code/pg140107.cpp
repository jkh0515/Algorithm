//점 찍기

#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0, dd = pow(d, 2);
    for(int x=0;x<=d;x++) {
        long long xx = long(pow(x, 2));
        long long y = sqrt(dd - xx);
        answer += y / k + 1;
        x += k - 1;
    }
    return answer;
}
