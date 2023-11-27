//땅따먹기

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int arr[100000][4] = {0}, answer = 0;
    for(int i=0;i<4;i++)
        arr[0][i] = land[0][i];
    for(int i=1;i<land.size();i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++)
                if(j != k and arr[i-1][k] > arr[i][j]) 
                    arr[i][j] = arr[i-1][k];
            arr[i][j] = arr[i][j] + land[i][j];
            if(answer < arr[i][j]) answer = arr[i][j];
        }
    }
    return answer;
}
