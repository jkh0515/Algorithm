//N-Queen

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int answer = 0;

void cal(vector<int> queen, int n) {
    if(queen.size() == n) answer++;
    for(int i=0;i<n;i++) {
        bool tf = false;
        for(int j=0;j<queen.size();j++) {
            if(queen.size() - (j) == abs(queen[j] - i)) tf = true; 
            else if(queen[j] == i) tf = true; 
            if(tf == true) break;
        }
        if(tf == true) continue;
        vector<int> tqueen = queen;
        tqueen.push_back(i);
        cal(tqueen, n);
    }
} 

int solution(int n) {
    vector<int> queen;
    cal(queen, n);
    return answer;
}
