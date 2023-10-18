//영어 끝말잇기

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> wds) {
    vector<int> answer;
    map<string, int> m;
    bool tf = false;
    m.insert({wds[0], 0});
    for(int i=1;i<wds.size();i++) {
        if(wds[i-1][wds[i-1].size()-1] != wds[i][0]) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            tf = true;
            break;
        } 
        if(m.find(wds[i]) == m.end()) m.insert({wds[i], i});
        else {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            tf = true;
            break;
        }
    }
    if(tf == false) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
