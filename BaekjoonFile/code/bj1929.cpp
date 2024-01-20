//소수 구하기 [ C++ ]

#include <iostream>
using namespace std;

int main() {
    int n, m, tf;
    cin >> n >> m;
    for(int i=n;i<=m;i++) {
        if(i < 2) continue;
        tf = 0;
        for(int j=2;j*j<=i;j++) {
            if(i % j == 0) {
                tf = 1;
                break;
            }
        }
        if(tf == 0) printf("%d\n", i);
    }
    return 0;
}
