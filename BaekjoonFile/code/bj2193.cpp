//이친수 [ C++ ]

#include <iostream>

int main() {
    int n, i;
    long arr[90] = {1, 1, };
    scanf("%d", &n);
    for(i=2;i<n;i++)
        arr[i] = (arr[i-1] + arr[i-2]);
    printf("%ld", arr[n-1]);
    return 0;
}
