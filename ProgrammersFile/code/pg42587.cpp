//프로세스

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> pr, int lc) {
    int max, idx, mul[101] = {0}, temp = -1;
    vector<int> arr;
    for(int i=0;i<pr.size();i++) {
        max = 0;
        idx = temp;
        for(int j=0;j<pr.size();j++) {
            if(idx == pr.size()-1) idx = -1;
            idx++;
            if(mul[idx] == 1) continue;
            if(max < pr[idx]) {
                max = pr[idx];
                temp = idx;
            }
        }
        arr.push_back(temp);
        mul[temp] = 1;
    }
    for(int i=0;i<arr.size();i++)
        if(arr[i] == lc) return i+1;
}
