//소수 찾기

#include <string>
#include <vector>
using namespace std;

vector<int> vt;

int cal(int* arr, int idx, int size, int n) {
    if(n > 1) {
        bool tf = 0;
        for(int i=0;i<vt.size();i++) {
            if(vt[i] == n) {
                tf = 1;
                break;
            }
        }
        if(tf == 0) vt.push_back(n);
    }
    if(idx == size) return 0;
    for(int i=1;i<11;i++) {
        if(arr[i] != 0) {
            int tarr[11];
            for(int i=0;i<11;i++)
                tarr[i] = arr[i];
            string stn = to_string(n);
            if(i == 10) stn += "0";
            else stn += to_string(i);
            tarr[i]--;
            cal(tarr, idx+1, size, stoi(stn));
        }
    }
    return 0;
}

int solution(string nbs) {
    int answer = 0, arr[11] = {0};
    for(int i=0;i<nbs.size();i++) {
        if(nbs[i] == '0') arr[10]++;
        else arr[nbs[i]-'0']++;
    }
    cal(arr, 0, nbs.size(), 0);
    for(int i=0;i<vt.size();i++) {
        bool tf = 0;
        for(int j=2;j<vt[i];j++) {
            if(vt[i] % j == 0) {
                tf = 1;
                break;
            }
        }
        if(tf == 0) answer++;
    }
    return answer;
}
