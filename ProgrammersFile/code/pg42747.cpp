//H-Index

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cit) {
    int sum = 0, arr[10001] = {0};
    for(int i=0;i<cit.size();i++)
        arr[cit[i]]++;
    if(arr[0] == cit.size()) return 0;
    for(int i=0;i<10001;i++) {
        sum += arr[i];
        if(cit.size()-sum<=i and sum<=i) return i;
    }
}
