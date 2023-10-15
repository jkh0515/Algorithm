//롤케이크 자르기

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> tp) {
    int answer = 0, nb = 0;
    int tpn[10001] = {0};
    int front[1000001] = {0};
    int back[1000001] = {0};
    for(int i=0;i<tp.size()-1;i++) {
        if(tpn[tp[i]] == 0) nb++;
        front[i] = nb;
        tpn[tp[i]]++;
    }
    nb = 0;
    for(int i=0;i<tp.size();i++)
        tpn[tp[i]] = 0;
    for(int i=0;i<tp.size();i++) {
        if(tpn[tp[tp.size()-1-i]] == 0) nb++;
        back[i] = nb;
        tpn[tp[tp.size()-1-i]]++;
    }
    for(int i=0;i<tp.size()-1;i++)
        if(front[i] == back[tp.size()-i-2])
            answer++;
    return answer;
}
