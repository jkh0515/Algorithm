//시소 짝꿍

#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct node {
    int n = 0;
    int db = 0;
    bool ss[4001] = {false};
    vector<int> vt;
} node;

long long solution(vector<int> wt) {
    long long answer = 0;
    int asize = wt.size();
    int arr[4001][1000] = {0};
    int iarr[4001] = {0};
    node* narr[4001];
    for(int i=0;i<4001;i++) {
        node* nNode = new node;
        narr[i] = nNode;
    }
    for(int i=0;i<wt.size();i++) {
        narr[wt[i]]->n++;
        if(narr[wt[i]]->n > 1) {
            wt.erase(wt.begin() + i);
            i--;
        }
    }
    for(int i=0;i<wt.size();i++) {
        for(int j=2;j<5;j++) {
            int wtj = wt[i] * j;
            arr[wtj][iarr[wtj]] = wt[i];
            if(iarr[wtj] > 0) {
                for(int k=0;k<iarr[wtj];k++) {
                    if(narr[arr[wtj][k]]->ss[wt[i]] == false) {
                        narr[arr[wtj][k]]->ss[wt[i]] = true;
                        narr[arr[wtj][k]]->db++;
                        narr[arr[wtj][k]]->vt.push_back(wt[i]);
                    }
                }
            }
            iarr[wtj]++;
        }
    }
    for(int i=0;i<4001;i++) {
        if(narr[i]->n > 0)
            if(narr[i]-> n > 1) 
                answer += long(narr[i]->n) * (narr[i]->n - 1) / 2;
        if(narr[i]->db > 0)
            for(int j=0;j<narr[i]->db;j++)
                answer += long(narr[narr[i]->vt[j]]->n) * narr[i]->n; 
    }
    return answer;
}
