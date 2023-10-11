//연속된 부분 수열의 합

#include <vector>
using namespace std;

vector<int> solution(vector<int> sq, int k) {
    vector<int> answer;
    int sum = 0, start = 0, idx = 0;
    int minsize = 1000000000, minstart = 1000000000;
    while(sq[idx] <= k and idx <= sq.size()) {
        sum += sq[idx];
        if(sum > k) {
            while(sum > k) {
                sum -= sq[start];
                start++;
            }
        }
        if(sum == k) {
            if(minsize > idx - start + 1) {
                minsize = idx - start + 1;
                minstart = start;
            }
        }
        idx++;            
    }
    answer.push_back(minstart);
    answer.push_back(minstart + minsize - 1);
    return answer;
}
