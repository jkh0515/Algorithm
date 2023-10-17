//숫자 변환하기

#include <cmath>
#include <iostream>
using namespace std;

int arr[1000001];

int dp(int x, int y, int n) {
    if(arr[y] == 1000001) {
        int a = 1000001, b = 10000001, c = 10000001, min = 1000001;
        if(y - n >= x) a = dp(x, y-n, n);
        if(y % 2 == 0 and y / 2 >= x) b = dp(x, y/2, n);
        if(y % 3 == 0 and y / 3 >= x) c = dp(x, y/3, n);
        if(min > a) min = a;
        if(min > b) min = b;
        if(min > c) min = c;
        arr[y] = min+1;
    }
    return arr[y];
}

int solution(int x, int y, int n) {
    int answer = 0;
    fill_n(arr, 1000001, 1000001);   
    arr[x] = 0;
    answer = dp(x, y, n);
    if(answer >= 1000001) answer = -1; 
    return answer;
}
