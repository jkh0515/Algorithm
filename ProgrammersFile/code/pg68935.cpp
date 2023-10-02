//3진법 뒤집기

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> third;
    while(1) {
        if(n < 3) {
            third.push_back(n);
            break;
        }
        third.push_back(n % 3);
        n = n / 3;
    }
    int idx = third.size()-1;
    for(int i=0;i<=third.size();i++) {
        answer = answer + third[idx] * pow(3, i);
        idx--;
    }
    return answer;
}
