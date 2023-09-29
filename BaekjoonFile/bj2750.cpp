//수 정렬1 - 선택 정렬

#include <iostream>
using namespace std;
int arr[10000000];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n-1;i++) {
        int max = arr[i];
        for(int j=i;j<n;j++) {
            if(max > arr[j]) {
                int temp = max;
                max = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = max;
    }
    for(int i=0;i<n;i++) {
        // cout << arr[i] << " ";
        printf("%d\n", arr[i]);
    }
    return 0;
}
