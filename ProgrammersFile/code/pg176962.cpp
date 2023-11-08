//과제 진행하기 - 미완

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<int> ingT;
    map<int, int> will, ing;
    int tl[101441] = {0};
    for(int i=0;i<101441;i++) tl[i] = -1;
    for(int i=0;i<plans.size();i++) {
        int time = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 2));
        will.insert({i, stoi(plans[i][2])});
        tl[time] = i;
    }
    for(int i=0;i<1441;i++) {
        if(tl[i] == -1) continue;
        int temp = tl[i];
        while(tl[++i] == -1) {
            will.find(temp)->second--;
            if(will.find(temp)->second <= 1) {
                answer.push_back(plans[temp][0]);
                while(ing.size() != 0) {
                    if(answer.size() + ing.size() != will.size() and tl[i+1] != -1) break;
                    ing.find(ingT[0])->second--;
                    if(ing.find(ingT[0])->second <= 1) {
                        answer.push_back(plans[ing.find(ingT[0])->first][0]);
                        ing.erase(ing.find(ingT[0]));
                        ingT.erase(ingT.begin());
                    }
                    i++;
                }
                break;
            }
        }
        if(will.find(temp)->second > 1) {
            ing.insert({temp, will.find(temp)->second});
            ingT.insert(ingT.begin(), temp);
        }
        i--;
    }
    return answer;
}
