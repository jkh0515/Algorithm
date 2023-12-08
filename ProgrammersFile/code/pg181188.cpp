//요격 시스템

#include <vector>
#include <algorithm>
using namespace std;

bool cal(vector<int> a, vector<int> b) {
    if(a[1] < b[1]) return a[1] < b[1];
    return b[1] > a[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), cal);
    int size = targets.size(), answer = 0, idx = 0;
    for(int i=0;i<size;i++) {
        while(idx < size and targets[idx][0] < targets[i][1]) idx++;
        answer ++;
        i = idx-1;
    }    
    return answer;
}
