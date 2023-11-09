//멀쩡한 사각형

#include <vector>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    vector<int> cy;
    double a, temp = 0;
    int i = 1, big = h;
    if((double)w / h < 1) a = (double)w / h;
    else { 
        a = (double)h / w; 
        big = w; 
    }
    while(a*i != (int)(a*i)) {
        if((int)(a*i) == (int)temp) cy.push_back(1);
        else cy.push_back(2);
        temp = a*i++;
    }
    cy.push_back(1);
    for(int i=0;i<big;i++)
        answer -= cy[i%cy.size()];
    return answer;
}
