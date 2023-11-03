//이진 변환 반복하기

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int tten(vector<int> two) {
    int ten = 0;
    for(int i=0;i<two.size();i++)
        ten += two[i] * pow(2, i);
    return ten;
}

vector<int> ttwo(int ten) {
    vector<int> two;
    if(ten == 0) {
        two.push_back(0);
        return two;
    }
    while(ten != 1) {
        two.push_back(ten % 2);
        ten /= 2;
    }
    two.push_back(1);
    return two;
}

int cal(vector<int> two) {
    int result = 0;
    for(int i=0;i<two.size();i++)
        if(two[i] == 0)
            result++;
    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0), two;
    for(int i=0;i<s.size();i++)
        two.push_back(s[i]-48);
    while(two.size() != 1) {
        answer[0]++;
        answer[1] += cal(two);
        two = ttwo(two.size() - cal(two));
    }
    return answer;
}
