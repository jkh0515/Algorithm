//모음사전

#include <string>
using namespace std;

int cal(char a) {
    if(a == 'E') return 1;
    if(a == 'I') return 2;
    if(a == 'O') return 3;
    if(a == 'U') return 4;
    return 0;
}

int solution(string word) {
    int answer = word.size(), arr[5] = {781, 156, 31, 6, 1};
    while(word.size() != 5)
        word += ' ';
    for(int i=4;i>=0;i--)
        answer += cal(word[i])*arr[i];
    return answer;
}
