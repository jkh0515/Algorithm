//디펜스 게임

#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = k, sum = 0, arr[1000001] = {0}, min = 1000000, max = 0, idx = k;
    if(k >= enemy.size()) return enemy.size();
    for(int i=0;i<k;i++) {
        arr[enemy[i]]++;
        if(min > enemy[i]) min = enemy[i];
        if(max < enemy[i]) max = enemy[i];
    }
    while(enemy.size() != idx) {
        if(enemy[idx] <= min)
            sum += enemy[idx];
        else {
            if(enemy[idx] > max) max = enemy[idx];
            arr[enemy[idx]]++;
            sum += min;
            arr[min]--;
            if(arr[min] == 0) while(arr[min] == 0) min++;
        }
        if(sum > n) break;
        idx++;
        answer++;   
    }
    return answer;
}
