//숫자 정사각형 [ C++ ]

#include <iostream>
using namespace std;

int main() {
    int arr[50][50] = {0}, answer = 1;
    int n, m, min, a, b, c, d, i, j, k;
    string str;
    cin >> n >> m;
    min = n;
    if(min > m) min = m;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++)
            arr[j][i] = str[j]-'0';
    }
    for(i=1;i<min;i++) {
        for(j=0;j<m-i;j++) {
            for(k=0;k<n-i;k++) {
                a = arr[j][k];
                b = arr[j][k+i];
                c = arr[j+i][k];
                d = arr[j+i][k+i];
                if(a == b && b == c and c == d)
                    answer = (i+1)*(i+1);
            }
        }
    }
    cout << answer;
    return 0;
}
