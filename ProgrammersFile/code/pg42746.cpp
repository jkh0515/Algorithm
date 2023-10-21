//가장 큰 수

#include <string>
#include <vector>
using namespace std;

string solution(vector<int> n) {
    vector<int> m;
    int arr[1001] = {0};
    string answer = "";
    int size = 1, start = 0;
    for(int i=0;i<n.size();i++)  
        arr[n[i]]++;
    m.push_back(0);
    for(int i=0;i<1001;i++) {
        if(arr[i] == 0) continue;
        for(int j=0;j<size;j++) {
            if(stoi(to_string(m[j]) + to_string(i)) <= stoi(to_string(i) + to_string(m[j]))) {
                for(int k=0;k<arr[i];k++)  
                    m.insert(m.begin()+j, i);
                size += arr[i];
                break;
            }
            if(j == size-1) {
                m.push_back(i);
                size++;
                break;
            }
        }
    }
    if(m.front() == 0) return "0";
    for(int i=0;i<size-1;i++)  
        answer += to_string(m[i]);
    return answer;
}
