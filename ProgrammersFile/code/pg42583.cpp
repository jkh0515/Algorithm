//다리를 지나는 트럭

#include <string>
#include <vector>
using namespace std;

int solution(int brlg, int wt, vector<int> trwt) {
    int answer = 0, timer = 0, nowwt = 0, size = trwt.size();
    vector<int> br, brar, nowbr, trar;
    while(trar.size() != size) {
        if(nowbr.size() > 0) {
            if(nowbr[0] == brlg) {
                nowwt -= br[0];
                trar.push_back(0);
                if(trar.size() == size) break;
                nowbr.erase(nowbr.begin());
                br.erase(br.begin());
            }
        }
        if(trwt.size() > 0) {
            if(nowwt + trwt[0] <= wt) {
                nowwt += trwt[0];
                nowbr.push_back(0);
                br.push_back(trwt[0]);
                trwt.erase(trwt.begin());
            }
        }
        for(int i=0;i<nowbr.size();i++)
            nowbr[i]++;
        timer++;
    }
    return timer+1;
}
