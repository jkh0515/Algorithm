//기능개발

#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> prg, vector<int> spd) {
    vector<int> answer, idx, dif;
    dif.push_back(ceil((float)(100-prg[0])/spd[0]));
    int max = dif[0];
    for(int i=1;i<prg.size();i++) {
        dif.push_back(ceil((float)(100-prg[i])/spd[i]));
        if(max < dif[i]) {
            max = dif[i];
            idx.push_back(i);
        }
    }
    idx.push_back(prg.size());
    answer.push_back(idx[0]);
    for(int i=1;i<idx.size();i++)
        answer.push_back(idx[i] - idx[i-1]);
    return answer;
}
