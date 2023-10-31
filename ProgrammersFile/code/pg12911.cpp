//다음 큰 숫자

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
    while(ten != 1) {
        two.push_back(ten % 2);
        ten /= 2;
    }
    two.push_back(1);
    return two;
}

int cal(vector<int> two) {
    int n = 0;
    for(int i=0;i<two.size();i++)
        if(two[i] == 1) n++;
    return n;
}

vector<int> tplus(vector<int> two) {
    if(two[two.size()-1] == 1) two.push_back(0);
    int i = 0; 
    two[i]++;
    while(two[i] > 1) {
        two[i] -= 2;
        two[++i]++;
    }
    if(two[two.size()-1] == 0) two.pop_back();
    return two;
}

int solution(int n) {
    int answer = 0;
    vector<int> two = ttwo(n), twot = tplus(two);
    while(cal(two) != cal(twot))
        twot = tplus(twot);
    answer = tten(twot);
    return answer;
}
