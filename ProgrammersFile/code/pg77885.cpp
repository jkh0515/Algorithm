//2개 이하로 다른 비트

#include <string>
#include <vector>
#include <bitset>
using namespace std;

long long cal(string s) {
    for(int i=63;i>=0;i--)
        if(s[i] == '0') {
            s[i] = '1'; s[i+1] = '0';
            break;
        }
    bitset<64> bits(s);
    return bits.to_ullong();
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0;i<numbers.size();i++) {
        bitset<64> bits(numbers[i]);
        string temp = bits.to_string(), t = temp.substr(62, 2);
        if(t == "11") answer.push_back(cal(temp));
        else answer.push_back(numbers[i] + 1);
    }
    return answer;
}
