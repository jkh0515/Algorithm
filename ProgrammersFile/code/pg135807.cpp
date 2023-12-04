//숫자 카드 나누기

#include <string>
#include <vector>
using namespace std;

int cal(vector<int> arrA, vector<int> arrB) {
    int min = 0, tf = 0, idx = 0;
    vector<int> avt, avt2;
    for(int i=1;i<arrA.size();i++)
        if(arrA[min] > arrA[i]) min = i;
    for(int i=2;i<=arrA[min];i++)
        if(arrA[min] % i == 0)
            avt.push_back(i);
    for(int i=0;i<arrA.size();i++) {
        if(i == min) continue;
        for(int j=avt.size();j>0;j--) {
            if(avt[j-1] != -1 and arrA[i] % avt[j-1] != 0) {
                idx++;
                avt[j-1] = -1;
                if(idx == avt.size()) break;
            }
        }
        if(idx == avt.size()) break;
    }
    for(int i=0;i<avt.size();i++)
        if(avt[i] != -1)
            avt2.push_back(avt[i]);
    if(avt2.size() == 0) return 0;
    for(int i=avt2.size();i>0;i--) {
        tf = avt2[i-1];
        for(int j=0;j<arrB.size();j++) {
            if(arrB[j] % tf == 0) {
                tf = 0;
                break;
            }
        }
        if(tf == avt2[i-1])
            break;
    }
    return tf;
}

int solution(vector<int> arrA, vector<int> arrB) {
    int a = cal(arrA, arrB), b = cal(arrB, arrA);
    if(a > b) return a;
    return b;
}
