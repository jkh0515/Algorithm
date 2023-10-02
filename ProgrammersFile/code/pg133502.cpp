//햄버거 만들기

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int size = ingredient.size();
    for(int i=0;i<size;i++) {
        if(ingredient[i] == 1) {
            if(ingredient[i+1] == 2) {
                if(ingredient[i+2] == 3) {
                    if(ingredient[i+3] == 1) {
                        for(int j=0;j<4;j++)
                            ingredient.erase(ingredient.begin()+i);
                        answer = answer + 1;
                        i = i - 4;
                        size = size - 4;
                    }
                }
            }
        }
    }
    return answer;
}
