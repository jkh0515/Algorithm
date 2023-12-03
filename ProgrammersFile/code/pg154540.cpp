//무인도 여행

#include <string>
#include <vector>
using namespace std;

int idx, w, h, m;
vector<int> arr, arr2;

int check(int i, int a) {
    if((i < 0 or i >= m or arr[i] == 0) and a == 3) return -1;
    if(i < 0 or i >= m) return 0;
    if(a == 1) arr[i];
    if(a == 2) return arr2[i];
    if(a == 3) {
        if(arr2[i] != 0) return -1;
        return i;
    }
}

int cal(int i, int a = 0) {
    if(i < 0 or i >= m) return 0;
    if(check(i-1, 2) != 0) arr2[i] = check(i-1, 2);
    else if(check(i+1, 2) != 0) arr2[i] = check(i+1, 2);
    else if(check(i-w, 2) != 0) arr2[i] = check(i-w, 2);
    else if(check(i+w, 2) != 0) arr2[i] = check(i+w, 2);
    else if(arr2[i] == 0) arr2[i]= ++idx;
    cal(check(i-1, 3));
    cal(check(i+1, 3));
    cal(check(i-w, 3));
    cal(check(i+w, 3));
    return 0;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int sum[10001] = {0}, ct[100001] = {0};
    w = maps[0].size() + 1;
    h = maps.size();
    m = w * h;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w-1;j++) {
            if(maps[i][j] == 'X')
                arr.push_back(0);
            else arr.push_back(int(maps[i][j])-48);
            arr2.push_back(0);
        }
        arr.push_back(0);
        arr2.push_back(0);
    }
    for(int i=0;i<=m;i++)
        if(arr2[i] == 0 and arr[i] != 0) cal(i, 1);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(arr2[i*w+j] != 0)
                sum[arr2[i*w+j]] += arr[i*w+j];
    for(int i=1;i<=idx;i++) {
        if(sum[i] == 0) continue;
        ct[sum[i]]++;
    }
    for(int i=0;i<100001;i++) {
        if(ct[i] == 0) continue;
        for(int j=0;j<ct[i];j++)
            answer.push_back(i);
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}
