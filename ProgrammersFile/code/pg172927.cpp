//광물 캐기

#include <string>
#include <vector>
using namespace std;
int diapks[10] = {0}, ironpks[10] = {0}, stonepks[10] = {0}, asize = 0;

int cal(int di, int ir, int st, int n) {
    int a = 2251, b = 2251, c = 2251, m = 2251;
    if(n + 1 <= asize and (di-1 >= 0 or ir-1 >= 0 or st-1 >= 0)) {
        if(di-1 >= 0) a = cal(di-1, ir, st, n+1) + diapks[n];
        if(ir-1 >= 0) b = cal(di, ir-1, st, n+1) + ironpks[n];
        if(st-1 >= 0) c = cal(di, ir, st-1, n+1) + stonepks[n];
        if(m > a) m = a;
        if(m > b) m = b;
        if(m > c) m = c;
        return m;   
    }
    return 0;
}

int solution(vector<int> pks, vector<string> mnr) {
    int answer = 0;
    asize = mnr.size()/5;
    if(mnr.size() % 5 != 0) asize++;
    for(int i=0;i<mnr.size();i++) {
        int temp = i/5;
        if(mnr[i] == "diamond") {
            ironpks[temp] += 5;  stonepks[temp] += 25;  }
        else if(mnr[i] == "iron") {
            ironpks[temp]++;  stonepks[temp] += 5;  }
        else {
            ironpks[temp] ++;  stonepks[temp] ++;  }
        diapks[temp]++;    
    }
    answer = cal(pks[0], pks[1], pks[2], 0);
    return answer;
}
