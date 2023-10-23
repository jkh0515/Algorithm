//뒤에 있는 큰 수 찾기

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> nbs) {
    vector<int> answer, temp;
    for(int i=0;i<nbs.size();i++)
        answer.push_back(-1);
    int idx = 0;
    temp.push_back(nbs.size()-1);
    for(int i=nbs.size()-2;i>=0;i--) {
        if(nbs[i] < nbs[temp[idx]]) {
            answer[i] = nbs[temp[idx]];
            temp.push_back(i);
            idx++;
            continue;
        }
        int iidx = idx;
        while(nbs[temp[idx]] <= nbs[i]) {
            if(iidx == 0) {
                temp.clear();
                temp.push_back(i);
                idx = 0;
                break;
            }
            iidx--;
            if(nbs[temp[iidx]] > nbs[i]) {
                answer[i] = nbs[temp[iidx]];
                for(int j=0;j<idx-iidx;j++)
                    temp.pop_back();
                idx -= idx-iidx-1;
                temp.push_back(i);
                break;
            }
        } 
    }
    return answer;
}
