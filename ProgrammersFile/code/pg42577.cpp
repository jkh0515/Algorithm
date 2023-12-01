//전화번호 목록

#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> pb) {
    int len[21] = {0};
    map<string, int> ma;
    for(int i=0;i<pb.size();i++) {
        len[pb[i].size()]++;
        ma.insert({pb[i], i});
    }
    for(int i=1;i<21;i++) {
        if(len[i] == 0) continue;
        for(int j=0;j<pb.size();j++) {
            if(ma.find(pb[j].substr(0, i)) != ma.end()) {
                if(ma.find(pb[j].substr(0, i))->second != j) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
