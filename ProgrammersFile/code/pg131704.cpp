//택배상자 [ C++ ]

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> temp;
    for(int i=1;i<=order.size();i++) {
        temp.push_back(i);
        while(!temp.empty() and temp.back() == order[answer]) {
            answer++;
            temp.pop_back();
        }
    }
    return answer;
}
