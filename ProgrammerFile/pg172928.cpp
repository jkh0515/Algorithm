//공원산책

#include <string>
#include <vector>
using namespace std;

vector<int> check(vector<string> park, int *now, char dir, int dis);
vector<int> clearVector();
int discheck(int size, int *nnow);
int obscheck(vector<string> park, int *nnnow, int idx, int dir, int dis);

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int now[2] = {0};
    char dir;
    for(int i=0;i<park.size();i++) {
        for(int j=0;j<park[0].size();j++) {
            if(park[j][i] == 'S') {
                now[1] = i;
                now[0] = j;
                break;
            }
        }
    }
    for(int i=0;i<routes.size();i++) {
        dir = routes[i][0];
        answer = check(park, now, dir, int(routes[i][2])-'0');
    }
    return answer;
}

int discheck(vector<string> park, int *nnow) {
    if(nnow[0] >= 0 and nnow[0] < park[0].size()) {
        if(nnow[1] >= 0 and nnow[1] < park.size()) return 0;
    }
    return 1;
}

int obscheck(vector<string> park, int *nnnow, int idx, int dir, int dis) {
    for(int i=0;i<dis;i++) {
        nnnow[idx] = nnnow[idx] + dir;
        if(park[nnnow[0]][nnnow[1]] == 'X') return 1;
    }
    return 0;
}

vector<int> clearVector(vector<int> a, int one, int two) {
    a.clear();
    a.push_back(one);
    a.push_back(two);
    return a;
}

vector<int> check(vector<string> park, int *now, char dir, int dis) {
    vector<int> returnnow;
    returnnow = clearVector(returnnow, now[0], now[1]);
    int nnow[2] = {now[0], now[1]};
    int nnnow[2] = {now[0], now[1]};
    if(dir == 'N') {
        nnow[0] = now[0] - dis;
        if(discheck(park, nnow)) return returnnow;            
        if(obscheck(park, nnnow, 0, -1, dis)) return returnnow;
        now[0] = now[0] - dis;
        returnnow = clearVector(returnnow, now[0], now[1]);
    }
    else if(dir == 'S') {
        nnow[0] = now[0] + dis;
        int a = discheck(park, nnow);
        if(a) return returnnow; 
        if(obscheck(park, nnnow, 0, 1, dis)) return returnnow;
        now[0] = now[0] + dis;
        returnnow = clearVector(returnnow, now[0], now[1]);
    }
    else if(dir == 'W') {
        nnow[1] = now[1] - dis;
        if(discheck(park, nnow)) return returnnow;
        if(obscheck(park, nnnow, 1, -1, dis)) return returnnow;
        now[1] = now[1] - dis;
        returnnow = clearVector(returnnow, now[0], now[1]);
    }
    else {
        nnow[1] = now[1] + dis;
        if(discheck(park, nnow)) return returnnow;
        if(obscheck(park, nnnow, 1, +1, dis)) return returnnow;
        now[1] = now[1] + dis;
        returnnow = clearVector(returnnow, now[0], now[1]);
    }
    return returnnow;
}
