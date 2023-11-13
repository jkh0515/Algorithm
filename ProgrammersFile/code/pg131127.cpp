//할인 행사

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, sum = 0, now = 0;
    map<string, int> ma;
    for(int i=0;i<want.size();i++) {
        sum += number[i];
        ma.insert({want[i], number[i]});
    }
    for(int i=0;i<discount.size();i++) {
        if(ma.find(discount[i]) != ma.end()) {
            ma.find(discount[i])->second--;
            if(ma.find(discount[i])->second >= 0) now++;
        }
        if(now == sum) answer++;
        if(i >= 9) {
            if(ma.find(discount[i-9]) != ma.end()) {
                ma.find(discount[i-9])->second++;
                if(ma.find(discount[i-9])->second > 0) now--;
            }
        }
    }
    return answer;
}
