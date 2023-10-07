//덧칠하기

#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> st) {
    int answer = 0;
    int stidx = 0;
    for(int i=1;i<=n;i++) {
        if(i == st[stidx]) {
            answer ++;
            i = i + m - 1;
            while(i<=n and i>=st[stidx] and stidx<st.size())
                stidx ++;
        }
    }
    return answer;
}
