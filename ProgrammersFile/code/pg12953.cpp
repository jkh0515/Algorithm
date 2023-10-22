//N개의 최소공배수

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int prime[100] = {0};
    for(int i=0;i<arr.size();i++) {
        int temp = 2, temp2 = 0;
        while(arr[i] != 1) {
            if(arr[i] % temp == 0) {
                temp2++;
                arr[i] /= temp;
                if(temp2 > prime[temp]) prime[temp] = temp2;
            }
            else {
                temp++;
                temp2 = 0;
            }
        }
    }
    for(int i=2;i<98;i++)
        if(prime[i] != 0)
            for(int j=0;j<prime[i];j++)
                answer *= i;
    return answer;
}
