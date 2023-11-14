//문자열 압축

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int min = s.size(), n, now;
    for(int i=1;i<s.size()/2+1;i++) {
        string pev = s.substr(0, i);
        n = 1;
        now = s.size();
        for(int j=i;j<s.size();j++) {
            string temp = s.substr(j, i);
            if(pev == temp) {
                n++;
                now -= i;
            }
            else {
                if(n > 1) now += to_string(n).size();
                n = 1;
                pev = temp;
            }
            j += i - 1;
        }
        if(s.size() % i == 0 and n > 1) now += to_string(n).size();
        if(min > now) min = now;
    }
    return min;
}
