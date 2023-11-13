//예상 대진표

#include <cmath>
using namespace std;

int cal(int n, int a, int b) {
    if(a > b) return cal(n, b, a);
    if(b - a == 1 and a % 2 != 0) return n + 1;
    return cal(n+1, ceil(a/2.0), ceil(b/2.0));
}

int solution(int n, int a, int b){
    return cal(0, a, b);
}
