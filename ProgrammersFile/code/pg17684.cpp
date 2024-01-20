//[3차] 압축 [ C++ ]

#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    map<string, int> ma;
    vector<int> answer;
    int idx = 27, i, n = -1, t;
    for(i=1;i<=26;i++)
        ma[string(1, (char)(i+64))] = i;
    while(++n < msg.size()) {
        t = 1;
        while(n + t <= msg.size() and ma.find(msg.substr(n, t)) != ma.end()) t++;
        if(n == msg.size() - 1 and t == 1) t = 2;
        if(ma.find(msg.substr(n, t)) == ma.end()) ma[msg.substr(n, t)] = idx++;
        answer.push_back(ma.find(msg.substr(n, t-1))->second);
        if(t > 1) n += t-2;
    }
    return answer;
}
