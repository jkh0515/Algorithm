//두 큐 합 같게 만들기 [ C++ ]

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, start = 0, end = queue1.size()-1;
    long sum = 0, goal, now = 0;
    for(int i=0;i<queue2.size();i++) {
        queue1.push_back(queue2[i]);
        sum += queue1[i] + queue2[i];
        now += queue1[i];
    }
    if(sum % 2 != 0) return -1;
    goal = sum / 2;
    if(now == goal) return answer;
    while(end < queue1.size()) {
        if(now > goal) {
            now -= queue1[start++];
            answer++;
        }
        if(now < goal) {
            now += queue1[++end];
            answer++;
        }
        if(now == goal) break;
    }
    if(end >= queue1.size()) return -1;
    return answer;
}
