//수 정렬3 - 카운팅 정렬

#include <iostream>
using namespace std;
int arr[10000];

int main() {
    int n, temp;
    // cin >> n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        // cin >> temp;
        scanf("%d", &temp);
        arr[temp-1] += 1;
    }
    for(int i=0;i<10000;i++) {
        // if(arr[i] == 0) {
            // continue;
        // }
        for(int j=0;j<arr[i];j++) {
            printf("%d\n", i+1);
        }
    }
    return 0;
}