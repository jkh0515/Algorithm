//교점에 별 만들기

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<long long> arr;
    long long llmax = 9223372036854775807;
    long long xmin = llmax, xmax = -1*xmin, ymin = xmin, ymax = xmax;
    for(int i=0;i<line.size();i++) {
        for(int j=i+1;j<line.size();j++) {
            long long temp = (long)line[i][0]*line[j][1] - (long)line[i][1]*line[j][0];
            if(temp != 0) {
                long long x = ((long)line[i][1]*line[j][2] - (long)line[i][2]*line[j][1]), y = ((long)line[i][2]*line[j][0] - (long)line[i][0]*line[j][2]);
                if(x % temp == 0 and y % temp == 0) {
                    arr.push_back(x/temp);
                    arr.push_back(y/temp);
                    if(xmin > x/temp) xmin = x/temp;
                    if(xmax < x/temp) xmax = x/temp;
                    if(ymin > y/temp) ymin = y/temp;
                    if(ymax < y/temp) ymax = y/temp;
                }
            }
        }
    }
    for(long long i=ymin;i<=ymax;i++) {
        string temp = ".";
        for(long long j=xmin;j<xmax;j++)
            temp += ".";
        answer.push_back(temp);
    }
    for(int i=0;i<arr.size();i++)
        answer[ymax - arr[i+1]][arr[i++] - xmin] = '*';
    return answer;
}
