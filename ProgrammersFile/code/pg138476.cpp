//귤 고르기

#include <string>
#include <vector>
using namespace std;

int solution(int k, vector<int> tg) {
    int answer = 0, max = 0, sum = 0;
    int arr[10000001] = {0}, arr2[10000001] = {0};
    for(int i=0;i<tg.size();i++)
        arr[tg[i]]++;
    for(int i=0;i<10000001;i++) {
        if(arr[i] != 0) {
            arr2[arr[i]]++;
            if(arr[i] > max) max = arr[i]; 
        }
    }
    for(int i=max;i>0;i--) {
        if(sum >= k) break;
        for(int j=0;j<arr2[i];j++) {
            if(sum >= k) break;
            sum += i;
            answer++;
        }
    }
    return answer;
}
