//피보나치 수

#include <string>
#include <vector>
using namespace std;

int arr[100001] = {0};

int cal(int n) {
    if(arr[n] != -1) return arr[n];
    arr[n] = (cal(n-1) + cal(n-2)) % 1234567;
    return arr[n];
}

int solution(int n) {
    int answer = 0;
    for(int i=0;i<100001;i++)
        arr[i] = -1;
    arr[0] = 0; arr[1] = 1;
    cal(n);
    return arr[n];
}
