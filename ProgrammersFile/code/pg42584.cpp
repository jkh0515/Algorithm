//주식가격

#include <vector>
using namespace std;

vector<int> solution(vector<int> prc) {
    vector<int> answer;
    for(int i=0;i<prc.size();i++) {
        int temp = i, result = 1;
        while(prc[i] <= prc[++temp] and temp < prc.size())
            result++;
        if(result == prc.size() - i) result--;
        answer.push_back(result);
    }
    return answer;
}
