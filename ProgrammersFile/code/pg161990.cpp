//바탕화면 정리

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wp) {
    vector<int> answer;
    int xf=wp.size()+1, xl = 0, yf = wp[0].size()+1, yl = 0;
    for(int i=0;i<wp.size();i++) {
        for(int j=0;j<wp[0].size();j++) {
            if(wp[i][j] == '#'){
                if(i <= xf) xf = i;
                if(i >= xl) xl = i+1;
                if(j <= yf) yf = j;
                if(j >= yl) yl = j+1;
            }
        }
    }
    answer.push_back(xf);
    answer.push_back(yf);
    answer.push_back(xl);
    answer.push_back(yl);
    return answer;
}
