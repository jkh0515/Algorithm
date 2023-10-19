//최솟값 만들기

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0, arrA[1001] = {0}, arrB[1001] = {0};
    for(int i=0;i<A.size();i++) {
        arrA[A[i]]++;  arrB[B[i]]++;
    }
    A.clear();  B.clear();
    for(int i=0;i<1001;i++) {
        if(arrA[i] != 0) 
            for(int j=0;j<arrA[i];j++)
                A.push_back(i);
        if(arrB[1000-i] != 0)
            for(int j=0;j<arrB[1000-i];j++)
                B.push_back(1000-i);
    }
    for(int i=0;i<A.size();i++)
        answer += A[i] * B[i];
    return answer;
}
