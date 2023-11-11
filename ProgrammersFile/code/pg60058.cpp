//괄호 변환

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string cal(string p) {
    if(p == "") return "";
    int temp = 0, tf = 0, idx = 0, temp2 = 0;
    for(int i=0;i<p.size();i++) {
        if(p[i] == '(') temp++;
        else temp--;
        if(temp == 0 and i != 0 and idx == 0) idx = i;
        if(temp < 0) tf = 1;
    }
    if(tf == 0) return p;
    string u = p.substr(0,idx+1), v = p.substr(idx+1, p.size()-idx-1);
    for(int i=0;i<u.size();i++) {
        if(u[i] == '(') temp2++;
        else temp2--;
        if(temp2 < 0) tf = 0;
    }
    if(tf == 1) return u + cal(v);
    string result = "(" + cal(v) + ")";
    for(int i=1;i<u.size()-1;i++) {
        if(u[i] == '(') result += ")";
        else result += "(";
    }
    return result;
}

string solution(string p) {
    return cal(p);
}
