//거리두기 확인하기

#include <string>
#include <vector>
using namespace std;

vector<string> place;

bool cal(int y, int x, int a, int b) {
    if(a < 0) return true;
    if(a >= 0 and a != 2 and place[y][x] == 'P') return false;
    bool up = true, down = true, right = true, left = true;
    if(x > 0 and place[y][x-1] != 'X' and b != 2) left = cal(y, x-1, a-1, 1);
    if(x < 4 and place[y][x+1] != 'X' and b != 1) right = cal(y, x+1, a-1, 2);
    if(y > 0 and place[y-1][x] != 'X' and b != 4) down = cal(y-1, x, a-1, 3);
    if(y < 4 and place[y+1][x] != 'X' and b != 3) up = cal(y+1, x, a-1, 4);
    if(up == true and down == true and right == true and left == true) return true;
    else return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++) {
        place.clear();
        for(int j=0;j<5;j++)
            place.push_back(places[i][j]);
        bool tf = true;
        for(int j=0;j<5;j++) {
            if(tf == false) break;
            for(int k=0;k<5;k++) {
                if(tf == false) break;
                if(place[j][k] == 'P') 
                    tf = cal(j, k, 2, 0);
            }
        }
        answer.push_back(tf);
    }
    return answer;
}
