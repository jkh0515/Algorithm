//수식 최대화

#include <string>
#include <vector>
using namespace std;

vector<long> p, m, x;

vector<long> cal(vector<long> num, int tp) {
    vector<long> pmx;
    if(tp == 1) pmx = p;
    else if(tp == 2) pmx = m;
    else pmx = x;
    for(int i=0;i<pmx.size();i++) {
        int idx = pmx[i], idx2 = pmx[i]+1;
        while(num[idx] == -3) idx--;
        while(num[idx2] == -3) idx2++;
        if(tp == 1) num[idx] += num[idx2];
        else if(tp == 2) num[idx] -= num[idx2];
        else num[idx] *= num[idx2];
        num[idx2] = -3;
    }
    return num;
}

long long solution(string exp) {
    long long max = 0, idx = 0;
    vector<long> num, temp;
    for(int i=0;i<exp.size();i++) {
        string str = "";
        while(exp[i] >= '0') str += exp[i++];
        num.push_back(stoi(str));
        if(exp[i] == '+') p.push_back(idx++);
        else if(exp[i] == '-') m.push_back(idx++);
        else if(exp[i] == '*') x.push_back(idx++);
    }
    for(int i=1;i<4;i++) {
        for(int j=1;j<4;j++) {
        if(j == i) continue;
            for(int k=1;k<4;k++) {
                if(k == i or k == j) continue;
                temp = cal(num, i);
                temp = cal(temp, j);
                temp = cal(temp, k);
                if(temp[0] < 0) temp[0] *= -1;
                if(temp[0]>max) max = temp[0];
            }
        }
    }
    return max;
}
