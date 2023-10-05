//크기가 작은 부분문자열

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<t.size()-p.size()+1;i++) {
        unsigned long long temp = 0;
        for(int j=0;j<p.size();j++)
            temp = temp + pow(10, p.size()-1-j) * (t[i+j]-'0'); 
        if(temp <= stoll(p))
            answer ++;
    }
    return answer;
}
