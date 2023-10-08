//광물 캐기
//수정중 - 미완

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int tired(vector<string> mnl, int idx) {
    int result = 0;
    for(int i=idx*5;i<idx*5+5;i++) {
        if(i >= mnl.size()) break;
        if(mnl[i] == "diamond") result += 3;
        else if(mnl[i] == "iron") result += 2;
        else result ++;
    }
    return result;
}

int cal(vector<string> mnl, int idx, int pk) {
    int sum = 0;
    if(pk == 0) {
        for(int i=idx*5;i<idx*5+5;i++) {
            if(i >= mnl.size()) return sum;
            sum ++;
        }
    }
    else if(pk == 1) {
        for(int i=idx*5;i<idx*5+5;i++) {
            if(i >= mnl.size()) return sum;
            if(mnl[i] == "diamond") sum += 5;
            else sum ++;
        }
    }
    else {
        for(int i=idx*5;i<idx*5+5;i++) {
            if(i >= mnl.size()) return sum;
            if(mnl[i] == "diamond") sum += 25;
            else if(mnl[i] == "iron") sum += 5;
            else sum ++;
        }
    }
    return sum;
}

int solution(vector<int> picks, vector<string> mnl) {
    int ntired[10], nidx = 0, answer = 0;
    int rank[10] = {-1}, rpick[10] = {-1};
    int npicks = picks[0] + picks[1] + picks[2];
    int nsize = mnl.size()/5 + 1;
    if(mnl.size() == 50) nsize = 10;
    
    for(int i=0;i<nsize;i++) {
        if(npicks <= i) {
            nsize = npicks;
            break;
        }
        ntired[nidx] = tired(mnl, i);
        nidx ++;
    }
    
    for(int i=0;i<nidx;i++) {
        int max = 0, maxidx = 0;
        for(int j=0;j<nidx;j++) {
            bool tf = false;
            for(int k=0;k<i+1;k++)
                if(j == rank[k]) tf = true;
            if(tf == true) continue;
            if(max < ntired[j]) {
                max = ntired[j];
                maxidx = j;
            }
        }
        rank[i] = maxidx;
    }
    
    int tempidx = 0;
    cout << nidx << endl;
    for(int i=0;i<nidx;i++) {
        for(int j=0;j<picks[tempidx];j++) {
            rpick[rank[i]] = tempidx;
            i++;
            if(i >= nidx) break;
        }
        i--;
        tempidx ++;
    }
    
    for(int i=0;i<nidx;i++)
        answer += cal(mnl, i, rpick[i]);
    
    if(mnl.size() % 5 != 0 and nidx != 1) {
        int result1 = 0, result2 = 0, temppick = 0;
        bool ch = false;
        for(int i=nidx-2;i>=0;i--) {
            if(rpick[i] == 0 and picks[0] != 0) {
                temppick = i;
                rpick[i] = rpick[nidx-1];
                rpick[nidx-1] = 0;
                ch = true;
                break;
            }
        }
        for(int i=0;i<nidx;i++)
            result1 += cal(mnl, i, rpick[i]);
        if(ch == true) {
            rpick[nidx-1] = rpick[temppick];
            rpick[temppick] = 0;
        }
        for(int i=nidx-2;i>=0;i--) {
            if(rpick[i] == 1 and picks[1] != 0) {
                rpick[i] = rpick[nidx-1];
                rpick[nidx-1] = 1;
                break;
            }
        }
        for(int i=0;i<nidx;i++)
            result2 += cal(mnl, i, rpick[i]);
        if(result1 < answer and result2 > result1) return result1;
        if(result2 < answer and result2 < result1) return result2;
    }
    return answer;
}
