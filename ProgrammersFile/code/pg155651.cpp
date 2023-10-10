//호텔 대실

#include <string>
#include <vector>
using namespace std;

int mcal(vector<vector<string>> bt, int one, int two) {
    int fint = stoi(bt[one][two].substr(0, 2));
    int sint = stoi(bt[one][two].substr(3, 2));
    return fint * 60 + sint;
}

int solution(vector<vector<string>> bt) {
    int answer = 0;
    int time[1441] = {0};
    for(int i=0;i<bt.size();i++) {
        int start = mcal(bt, i, 0), finish = mcal(bt, i, 1);
        if(finish > 1430) finish = finish - 10;
        for(int j=start;j<finish+10;j++) {
            time[j]++;
            if(time[j]>=answer) answer = time[j];
        }
    }
    return answer;
}
