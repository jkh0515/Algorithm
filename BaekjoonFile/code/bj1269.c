//대칭 차집합 [ C ]

#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b, temp;
    bool arr[100000001] = {0};
    scanf("%d %d", &a, &b);
    int answer = a + b;
    for(int i=0;i<a;i++) {
        scanf("%d", &temp);
        arr[temp] = 1;
    }
    for(int i=0;i<b;i++) {
        scanf("%d", &temp);
        if(arr[temp] == 1) {
            arr[temp] = 0;
            answer -= 2;
        }
        else arr[temp] = 1;
    }
    printf("%d", answer);
    return 0;
}
