//연속 부분 수열 합의 개수

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> em) {
    int answer = 0;
    int sum[1000001] = {0};
    for(int i=1;i<=em.size();i++) {
        for(int j=0;j<em.size();j++) {
            int temp = 0;
            int idx = j;
            for(int k=0;k<i;k++) {
                if(idx >= em.size()) idx = 0;
                temp += em[idx++];
            }
            sum[temp]++;
        }
    }
    for(int i=0;i<1000001;i++)
        if(sum[i] != 0) answer++;
    return answer;
}
