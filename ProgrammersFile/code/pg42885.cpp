//구명보트

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, arr[241] = {0}, num = people.size();
    vector<int> sp;
    for(int i=0;i<people.size();i++)
        arr[people[i]]++;
    for(int i=0;i<limit;i++) {
        if(arr[i] == 0) continue;
        for(int j=0;j<arr[i];j++)
            sp.push_back(i);
    }
    int max = sp.size()-1, min = 0;
    while(1) {
        if(not(max <= min or sp[max] + sp[min] > limit)) {
            min++;
            num--;
        }
        num--;
        max--;
        answer++;
        if(num == 0) break;
    }
    return answer;
}
