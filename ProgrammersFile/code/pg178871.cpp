//달리기 경주
//수정중222 - 미완성

#include <string>
#include <vector>
using namespace std;

typedef struct node {
    string name;
    int now;
    int nowIdx;
    int pIdx;
    int nIdx;
} node;

int hsh(string name) {
    int value = 0;
    for(int i=0;i<name.size();i++) {
        value = (value * 29 + name[i]) % 50032;
    }
    return value;
}

node* createNode(string name, int now, int nowIdx, int pIdx, int nIdx) {
    node* newNode = new node;
    newNode->name = name;
    newNode->now = now;
    newNode->nowIdx = nowIdx;
    newNode->pIdx = pIdx;
    newNode->nIdx = nIdx;
    return newNode;
}

vector<string> solution(vector<string> pl, vector<string> ca) {
    vector<string> answer;
    int size = pl.size();
    node* g[50034] = {nullptr};
    node* hNode = createNode("-1", -1, 50032, -1, hsh(pl[0]));
    node* lNode = createNode("-1", -1, 50033, hsh(pl[size-1]), -1);
    node* fNode = createNode(pl[0], 0, hsh(pl[0]), 50032, hsh(pl[1]));
    node* tNode = createNode(pl[size-1], size-1, hsh(pl[size-1]), hsh(pl[size-2]), -1);
    g[50032] = hNode;
    g[50033] = lNode;
    g[hsh(pl[0])] = fNode;
    g[hsh(pl[size-1])] = tNode;
    for(int i=1;i<size-1;i++) {
        node* pNode = createNode(pl[i], i, hsh(pl[i]), hsh(pl[i-1]), hsh(pl[i+1]));
        g[hsh(pl[i])] = pNode;
    }
    for(int i=0;i<ca.size();i++) {
        node* curNode = g[hsh(ca[i])];
        g[g[curNode->pIdx]->pIdx]->nIdx = hsh(ca[i]);
        g[curNode->pIdx]->nIdx = curNode->nIdx;
        int temp = g[curNode->pIdx]->pIdx;
        g[curNode->nIdx]->pIdx = curNode->pIdx;
        g[curNode->pIdx]->pIdx = hsh(ca[i]);
        curNode->nIdx = curNode->pIdx;
        curNode->pIdx = temp;
    }
    node* tempNode = g[hNode->nIdx];
    for(int i=0;i<size;i++) {
        answer.push_back(tempNode->name);
        tempNode = g[tempNode->nIdx];
    }
    return answer;
}