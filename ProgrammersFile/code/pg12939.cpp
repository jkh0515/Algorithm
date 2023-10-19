//최댓값과 최솟값

#include <string>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    int min, max, idx = 0;
    istringstream iss(s);
    while(getline(iss, answer , ' ')) {
        int temp = stoi(answer);
        if(idx == 0) { min = temp;  max = temp; }
        else {
            if(min > temp) min = temp;
            if(max < temp) max = temp;
        }
        idx++;
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}
