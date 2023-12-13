//[3차] n 진수 게임

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char ncal(int n) {
    if(n >= 10) return char(55+n);
    else return char(48 + n);
}

string trans(int n, int m) {
    string answer = "";
    while(m >= n) {
        answer += ncal(m%n);
        m /= n;
    }
    answer += ncal(m);
    reverse(answer.begin(), answer.end());
    return answer;
}

string solution(int n, int t, int m, int p) {
    string answer = "", str = "";
    int idx = 0;
    while(str.size() <= t*m)
        str += trans(n, idx++);
    for(int i=0;i<t;i++)
        answer += str[i*m+p-1];
    return answer;
}
