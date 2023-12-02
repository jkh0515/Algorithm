//조이스틱

#include <string>
#include <vector>
using namespace std;

int cal(string name, int idx, int answer) {
    bool tf = 0;
    for(int i=0;i<name.size();i++) {
        if(name[i] != 'A') {
            tf = 1;
            break;
        }
    }
    if(tf == 0) return answer;
    if(name[idx] == 'A') {
        int r = 0, l = 0, rr, ll, ra, la;
        string rname = name, lname = name;
        while(name[idx+r] == 'A' or name[idx-l] == 'A') {
            if(name[idx+r] == 'A') r++;
            if(name[idx-l] == 'A') l++;
            if(idx+r == name.size()) r = -1*idx;
            if(idx-l == -1) l = idx-name.size()+1;
        }
        rname[idx+r] = 'A';
        lname[idx-l] = 'A';
        if(r < 0) rr = r + name.size();
        else rr = r;
        if(l < 0) ll = l + name.size();
        else ll = l;
        if(name[idx+r]-'A' > '['-name[idx+r]) rr += '['-name[idx+r];
        else rr += name[idx+r]-'A';
        if(name[idx-l]-'A' > '['-name[idx-l]) ll += '['-name[idx-l];
        else ll += name[idx-l]-'A';
        ra = cal(rname, idx+r, answer+rr);
        la = cal(lname, idx-l, answer+ll);
        if(ra > la) return la;
        else return ra;
    }
    if(name[idx]-'A' > '['-name[idx]) answer += '['-name[idx];
    else answer += name[idx]-'A';
    name[idx] = 'A';
    return cal(name, idx, answer);
}

int solution(string name) {
    return cal(name, 0, 0);
}
