//의상

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, int> mcl;
    for(int i=0;i<clothes.size();i++) {
        if(mcl.find(clothes[i][1]) == mcl.end())
            mcl.insert({clothes[i][1], 2});
        else mcl.find(clothes[i][1])->second++;
    }
    for(auto itr = mcl.begin();itr!=mcl.end();itr++)
        answer *= itr->second;
    return answer-1;
}
