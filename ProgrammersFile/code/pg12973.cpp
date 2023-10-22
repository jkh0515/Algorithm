//짝지어 제거하기

#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0, idx = 1;
    vector<int> m;
    m.push_back(s[0]);
    for(int i=1;i<s.size();i++) {
        if(m.back() == s[i]) m.pop_back();
        else m.push_back(s[i]);
    }
    if(m.size() == 0) answer = 1;
    return answer;
}
