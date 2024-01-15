//삼각 달팽이 [ C++ ]

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int a = 0, b = 1, c, tb, d = 3, state = -1, idx = 1;
    while(++state < n) {
        if(state % 3 == 0) {
            tb = 0;
            for(int i=state;i<n;i++) {
                answer.insert(answer.begin()+a+tb, idx++);
                tb += b;
            }
            c = a+tb-b;
            a += 4 * (state / 3 + 1);
        }
        else if(state % 3 == 1) {
            for(int i=c+1;i<=n-state+c;i++)
                answer.insert(answer.begin()+i, idx++);
        }
        else {
            for(int i=n-state-1;i>=0;i--)
                answer.insert(answer.begin()+d+b*i-1, idx++);
            b += 2;
            d += b * 2;
        }
    }
    return answer;
}
