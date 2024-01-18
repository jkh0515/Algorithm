//스킬트리 [ C++ ]

#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size(), arr[26] = {0}, now, i, j;
    for(i=0;i<skill.size();i++)
        arr[skill[i]-65] = i+1;
    for(i=0;i<skill_trees.size();i++) {
        now = 1;
        for(j=0;j<skill_trees[i].size();j++) {
            if(arr[skill_trees[i][j]-65] == 0) continue;
            else if(arr[skill_trees[i][j]-65] == now) now++;
            else {
                answer--;
                break;
            }
        }
    }
    return answer;
}
