//전력망을 둘로 나누기

#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

map<int, vector<int>> ma;

int cal(int idx, int now, int size, int prev = -1) {
    auto node = ma.find(idx);
    auto nodevt = node->second;
    if(nodevt.size() <= 1) return 1;
    int n, sum, min = 101;
    for(n=0;n<nodevt.size();n++) if(nodevt[n] > idx) break;
    if(now != 0) n = nodevt.size()-1;
    for(int i=n;i<nodevt.size();i++) {
        sum = 1;
        for(int j=0;j<nodevt.size();j++) {
            if((now == 0 and j == i) or prev == nodevt[j]) continue;
            sum += cal(nodevt[j], now+1, size, idx);
        }
        if(min > sum) min = sum;
    }
    return min;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101, size = n;
    sort(wires.begin(), wires.end());
    for(int i=0;i<wires.size();i++) {
        vector<int> temp;
        if(ma.find(wires[i][0]) == ma.end())
            ma.insert({wires[i][0], temp});
        if(ma.find(wires[i][1]) == ma.end())
            ma.insert({wires[i][1], temp});
        ma.find(wires[i][0])->second.push_back(wires[i][1]);
        ma.find(wires[i][1])->second.push_back(wires[i][0]);
    }
    for(int i=1;i<n;i++) {
        int temp = cal(i, 0, size);
        if(answer > abs(size-temp*2)) answer = abs(size-temp*2);
    }
    return answer;
}
