//둘만의 암호

#include <string>
#include <vector>
using namespace std;

string solution(string s, string skip, int index) {
    for(int i=0;i<s.length();i++) {
        for(int j=0;j<index;j++) {
            s[i] = s[i] + 1;
            if(s[i] == 123) {
                s[i] = 97;
            }
            for(int k=0;k<skip.length();k++) {
                for(int l=0;l<skip.length();l++) {
                    if(s[i] == skip[l]) {
                        s[i] = s[i] + 1;
                        if(s[i] == 123) {
                            s[i] = 97;
                        }
                    }
                }
            }
        }
    }
    return s;
}
