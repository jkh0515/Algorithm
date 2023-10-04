//달리기 경주
//수정중 - 미완성

#include <string>
#include <vector>
using namespace std;

typedef struct node {
    string name;
    node* prevNode;
    node* nextNode;
} node;

node* createNode(string name, node* prevNode, node* nextNode) {
    node* newNode = new node;
    newNode->name = name;
    newNode->prevNode = prevNode;
    newNode->nextNode = nextNode;
    return newNode;
}

long hashing(string name) {
    long value = 0;
    for (int i = 0; i < name.length(); i++) {
        value = ((value * 31) * (name[i] - 'a' + 1)) % 50032;
    }
    return value;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    node* ground[50023] = {nullptr};
    node* headNode = new node;
    node* tailNode = new node;
    node* firstNode = new node;
    node* lastNode = new node;
    headNode = createNode("-1", nullptr, firstNode);
    firstNode = createNode(players[0], headNode, lastNode);
    lastNode = createNode(players[players.size()-1], firstNode, tailNode);
    tailNode = createNode("-1", lastNode, nullptr);
    ground[hashing(players[0])] = firstNode;
    ground[hashing(players[players.size()-1])] = lastNode;
    vector<string> answer;
    for(int i=1;i<players.size()-1;i++) {
        node *playerNode;
        playerNode = createNode(players[i], ground[hashing(players[i-1])], ground[hashing(players[i+1])]);
        ground[hashing(players[i])] = playerNode;
    }
    for(int i=0;i<callings.size();i++) {
        if(ground[hashing(callings[i])] != nullptr) {
            node* insertNode;
            node* delNode;
            node* nNode;
            delNode = ground[hashing(callings[i])];
            nNode = delNode->nextNode;
            insertNode = createNode(callings[i], delNode->prevNode->prevNode, delNode->prevNode);
            delNode->prevNode->prevNode->nextNode = insertNode;
            delNode->prevNode->prevNode = insertNode;
            insertNode->nextNode->nextNode = nNode;
            nNode->prevNode = insertNode->nextNode;
            delete delNode;
            ground[hashing(callings[i])] = insertNode;
        }
    }
    node* outNode = headNode;
    for(int i=0;i<players.size()+4;i++) {
        answer.push_back(outNode->name);
        outNode = outNode->nextNode;
    }
    return answer;
}
