//숫자 블록

#include <string>
#include <vector>
using namespace std;

int cal(int n) {
    int answer = 1;
    if(n == 1) return 0;
    for(int i=2;i*i<=n;i++) {
        if(i * i == n and answer < i) answer = i;
        else if(n % i == 0) {
            if(answer < n/i and n/i <= 10000000) answer = n/i;
            if(answer < i and i <= 10000000) answer = i;
        }
    }
    return answer;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    int bg = begin, ed = end;
    for(int i=0;i<ed-bg+1;i++)
        answer.push_back(cal(bg+i));
    return answer;
}
