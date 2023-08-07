//벌집

#include <iostream>
using namespace std;

int cal(int n) {
    int result = 0;
    for(int i=1;i<=n;i++) {
        result += i;
    }
    return 1+result*6;
}

int main() {
    // std::cout << cal(3);
    int n;
    cin >> n;
    int ans = 0;
    while(n != 1) {
        if(n > cal(ans)) {
            // cout << cal(ans) << endl;
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
