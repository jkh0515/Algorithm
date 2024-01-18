//K진수에서 소수 개수 구하기 [ C++ ]

#include <vector>
#include <algorithm>
using namespace std;

vector<long> cal(int n, int k) {
    string temp = "";
    vector<long> answer;
    while(n != 0) {
        while(n % k != 0) {
            temp += to_string(n % k);
            n /= k;
            if(n <= k) {
                temp += to_string(n % k);
                break;
            }
        }
        if(temp.size() > 0) {
            reverse(temp.begin(), temp.end());
            if (stol(temp) > 1) answer.push_back(stol(temp));
            temp = "";
        }
        n /= k;
    }
    return answer;
}

int solution(int n, int k) {
    int answer = 0, tf;
    vector<long> vt = cal(n, k);
    for(int i=0;i<vt.size();i++) {
        if(vt[i] == 2) {
            answer++;
            continue;
        }
        tf = 0;
        for(long j=2;j*j<=vt[i];j++) {
            if(vt[i] % j == 0) {
                tf = 1;
                break;
            }
        }
        if(tf == 0) answer++;
    }
    return answer;
}
