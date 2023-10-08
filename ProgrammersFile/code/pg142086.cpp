//가장 가까운 같은 글자

#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> result;
    for(int i=s.size()-1;i>=0;i--) {
        bool d = false;
        for(int j=1;j<s.size();j++) {
            if(j > i) continue;
            if(s[i] == s[i-j]) {
                result.push_back(j);
                d = true;
                break;
            }
        }
        if(d == false)
            result.push_back(-1);
    }
    for(int i=s.size()-1;i>=0;i--)
        answer.push_back(result[i]);
    return answer;
}
