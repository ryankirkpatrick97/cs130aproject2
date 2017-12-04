#ifndef MST_H
#define MST_H

#include"edge.h"
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;

class MSTree{

public:
    bool CYCLE = false;
    int COST = 0;
    priority_queue<edge> currentMST;
    priority_queue<edge> bidEdges;
    priority_queue<edge> mandatoryEdges;
    map<int, int> verticies;
    set<int> roots;

    void processInput(string input);
    void inputBid(vector<string> command);
    void inputMandatory(vector<string> command);
    void outputCost();
    void outputComponents();
    void outputCycle();
    void outputList();
    void makeMST();

private:
    vector<string> splitString(string input, char delim);
    void edgeUnion(edge e, bool force);
    int getRoot(int vertex);
};

#endif /* MST_H */
