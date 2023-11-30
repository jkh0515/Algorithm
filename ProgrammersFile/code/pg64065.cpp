//튜플

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    int temp = 0, now = 0;
    vector<int> answer, arr;
    string a = "";
    bool ct[100001] = {0};
    map<int, int> ma;
    for(int i=1;i<s.size()-1;i++) {
        if(s[i] == '{') {
            temp = 1;
            now = 0;
        }
        else if(temp == 1 and s[i] == ',') {
            arr.push_back(stoi(a));
            now++;
            a = "";
        } 
        else if(s[i] == '}') {
            arr.push_back(stoi(a));
            ma.insert({++now, arr.size()-now});
            now = 0;
            temp = 0;
            a = "";
        }
        else if (s[i] != ',')
            a += s[i];
    }
    
    for(int i=1;i<=ma.size();i++) {
        for(int j=0;j<i;j++) {
            if(ct[arr[ma.find(i)->second+j]] != 1) {
                answer.push_back(arr[ma.find(i)->second+j]);
                ct[arr[ma.find(i)->second+j]] = 1;
            }
        }
    }
    return answer;
}
