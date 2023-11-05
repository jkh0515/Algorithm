//카펫

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int idx = 1 , ylw = 0, yll = 0;
    while(ylw + yll + 2 != brown / 2) {
        if(yellow % idx == 0) {
            ylw = yellow / idx;
            yll = idx;
        }
        idx++;
    }
    answer.push_back(ylw + 2);
    answer.push_back(yll + 2);
    return answer;
}
