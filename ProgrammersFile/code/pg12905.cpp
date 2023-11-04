//가장 큰 정사각형 찾기

#include <vector>
using namespace std;

int solution(vector<vector<int>> bd) {
    int answer = 0, a = -1;
    for(int i=1;i<bd[0].size();i++) {
        for(int j=bd.size()-2;j>=0;j--) {
            if(bd[j][i] != 0) {
                a = bd[j][i];
                if(bd[j][i-1] != 0) {
                    a = bd[j][i-1];
                    if(bd[j+1][i-1] != 0) {
                        if(bd[j+1][i-1] < a) a = bd[j+1][i-1];
                        if(bd[j+1][i] != 0) {
                            if(bd[j+1][i] < a) a = bd[j+1][i];
                            if(answer <= a + 1) answer = a + 1;
                            bd[j][i] = a+1;
                        }
                    }
                }
            }
        }
    }
    if(a == 1 and answer == 0) return 1;
    if(a == -1) {
        for(int i=0;i<bd.size();i++)
            for(int j=0;j<bd[0].size();j++)
                if(bd[i][j] == 1) return 1;
    }
    return answer * answer;
}
