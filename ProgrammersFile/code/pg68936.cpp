//쿼드압축 후 개수 세기

#include <string>
#include <vector>
using namespace std;

vector<int> answer(2, 0);

int cal(vector<int> arr, int size) {
    if(size == 1) {
        answer[arr[0]]++;
        return 0;
    }
    bool tf = false;
    for(int i=1;i<size*size;i++) {
        if(arr[i] != arr[0]) {
            tf = true;
            break;
        }
    }
    if(tf == false){
        answer[arr[0]]++;
        return 0;
    }
    vector<int> one, two, three, four;
    int size2 = size / 2;
    for(int i=0;i<size2;i++) {
        for(int j=0;j<size2;j++) {
            one.push_back(arr[i*size+j]);
            two.push_back(arr[i*size+j+size2]);
            three.push_back(arr[size*(i+size2)+j]);
            four.push_back(arr[size*(i+size2)+j+size2]);
        }
    }
    cal(one, size2);
    cal(two, size2);
    cal(three, size2);
    cal(four, size2);
    return 0;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> arr2;
    for(int i=0;i<arr.size();i++) {
        for(int j=0;j<arr.size();j++) {
            arr2.push_back(arr[i][j]);
        }
    } 
    cal(arr2, arr[0].size());
    return answer;
}
