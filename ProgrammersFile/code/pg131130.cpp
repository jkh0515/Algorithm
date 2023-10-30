//혼자 놀기의 달인

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cards) {
    vector<int> open(cards.size(), 0), time;
    int start = 0, size = 0, idx = 0, sum = 0, count[101] = {0};
    while(sum != cards.size()) {
        idx = start;
        size = 0;
        while(open[idx] == 0) {
            open[idx] = 1;
            sum++;
            size++;
            idx = cards[idx]-1;
        }
        start++;
        time.push_back(size);
    }    
    for(int i=0;i<time.size();i++)
        count[time[i]]++;
    sum = 0;
    for(int i=100;i>0;i--) {
        if(count[i] != 0) {
            if(sum == 0) sum = i;
            else return sum * i;
            if(count[i] >= 2) return i*i;
        }
    }
}
