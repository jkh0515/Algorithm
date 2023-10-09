//혼자서 하는 틱택토

#include <vector>
using namespace std;

int cal(vector<string> bd, char ox) {
    bool tf3 = false;
    for(int i=0;i<3;i++) {
        bool tf1 = false, tf2 = false;
        for(int j=0;j<3;j++){
            if(bd[j][i] != ox) tf2 = true;
            if(bd[i][j] != ox) tf1 = true; 
        }
        if(bd[i][i] != ox) tf3 = true;
        if(tf2 == false or tf1 == false) return 0;
    }
    if(tf3 == false) return 0;
    if(bd[0][2] == ox and bd[1][1] == ox and bd[2][0] == ox) return 0;
    return 1;
}

int solution(vector<string> bd) {
    int o = 0, x = 0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(bd[i][j] == 'O') o++;
            else if(bd[i][j] == 'X') x++;
        }
    }
    if(x>o or o-x > 1) return 0;
    if(x == o and cal(bd, 'O') == 0) return 0;
    if(x < o and cal(bd, 'X') == 0) return 0;
    return 1;
}
