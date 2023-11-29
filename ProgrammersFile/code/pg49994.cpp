//방문 길이

#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0, x = 5, y = 5;
    bool ud[11][11] = {0}, rl[11][11] = {0};
    for(int i=0;i<dirs.size();i++) {
        if(dirs[i] == 'U' and y < 10) {
            if(ud[x][y] == 0) {
                ud[x][y] = 1;
                answer++;
            }
            y++;
        }
        else if(dirs[i] == 'D' and y > 0) {
            if(ud[x][y-1] == 0) {
                ud[x][y-1] = 1;
                answer++;
            }
            y--;
        }
        else if(dirs[i] == 'R' and x < 10) {
            if(rl[x][y] == 0) {
                rl[x][y] = 1;
                answer++;
            }
            x++;
        }
        else if(dirs[i] == 'L' and x > 0){
            if(rl[x-1][y] == 0) {
                rl[x-1][y] = 1;
                answer++;
            }
            x--;
        }
    }
    return answer;
}
