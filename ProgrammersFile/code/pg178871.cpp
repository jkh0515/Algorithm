//달리기 경주

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> pl, vector<string> ca) {
    map<string, int> ma;
    vector<string> answer;
    for(int i=0;i<pl.size();i++)
        ma.insert(make_pair(pl[i], i));
    for(int i=0;i<ca.size();i++) {
        int idx = ma.find(ca[i])->second;
        string temp = pl[idx-1];
        ma.find(ca[i])->second--;
        ma.find(temp)->second++;
        pl[idx-1] = pl[idx];
        pl[idx] = temp;
    }
    for(int i=0;i<pl.size();i++)
        answer.push_back(pl[i]);
    return answer;
}
