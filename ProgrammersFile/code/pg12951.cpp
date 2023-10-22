//JadenCase 문자열 만들기

#include <string>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "", temp = "";
    istringstream iss(s);
    while(getline(iss, temp, ' ')) {
        if(temp[0] >= 'a' and temp[0] <= 'z') temp[0] -= 32;
        for(int i=1;i<temp.size();i++) {
            if(temp[i] >= 'A' and temp[i] <= 'Z') temp[i] += 32;
        }
        answer += temp + ' ';
    }
    if(s[s.size()-1] != ' ') answer.erase(answer.size()-1, 1);
    return answer;
}
