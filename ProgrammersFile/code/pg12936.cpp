//줄 서는 방법

#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer, narr;
    vector<long> arr;
    arr.push_back(1);
    for(int i=1;i<=n;i++)
        narr.push_back(i);
    for(int i=1;i<n;i++)
        arr.insert(arr.begin(), arr[0]*i);
    int idx = 0;
    while(idx < n) {
        if(k > arr[idx]) {
            int temp = ceil(k/double(arr[idx]));
            for(int i=0;i<n;i++) {
                if(narr[i] == -1) continue;
                if(temp == 1) {
                    answer.push_back(narr[i]);
                    narr[i] = -1;
                    break;
                }
                temp--;
            }
            k %= arr[idx];
            if(k == 0) k = arr[idx];
        }
        else {
            for(int i=0;i<n;i++) {
                if(narr[i] == -1) continue;
                answer.push_back(narr[i]);
                narr[i] = -1;
                break;
            }
        }
        idx++;
    }
    return answer;
}
