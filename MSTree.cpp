
#include"MSTree.h"
#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

    void MSTree::processInput(string input){
        vector<string> vectInput;
        vectInput = splitString(input, ' ');
        string command = vectInput[0];
        if(command == "BID"){
            inputBid(vectInput);
        }else if(command == "MANDATORY"){
            inputMandatory(vectInput);
        }else if(command == "COST?"){
            outputCost();
        }else if(command == "COMPONENTS?"){
            outputComponents();
        }else if(command == "CYCLE?"){
            outputCycle();
        }else if(command == "LIST?"){
            outputList();
        }else{
            cout << "Invalid command" << endl;
        }
    }

    void MSTree::inputBid(vector<string> command){
        int from = stoi(command[1]);
        int to = stoi(command[2]);
        int weight = stoi(command[3]);
        edge e(from, to, weight);
        bidEdges.push(e);
    }

    void MSTree::inputMandatory(vector<string> command){
        int from = stoi(command[1]);
        int to = stoi(command[2]);
        int weight = stoi(command[3]);
        edge e(from, to, weight);
        mandatoryEdges.push(e);
    }

    void MSTree::outputCost(){
        makeMST();
        cout << COST << endl;
    }
    void MSTree::outputComponents(){
        cout << roots.size() << endl;
    }

    void MSTree::outputCycle(){
        if (CYCLE) cout << "YES" << endl;
        else       cout << "NO"  << endl;
    }
    void MSTree::outputList(){
        makeMST();
        priority_queue<edge> copy = currentMST;
        while(!copy.empty()){
            edge e = copy.top();
            copy.pop();
            if(e.from > e.to){
                e.swap();
            }
            cout << "(" + to_string(e.from) + "," + to_string(e.to) + ") " ;
        }
        cout << endl;
    }

    void MSTree::makeMST(){
        //Add mandatory edges to graph
        while(!mandatoryEdges.empty()){
            edge e = mandatoryEdges.top();
            mandatoryEdges.pop();
            edgeUnion(e, true);
        }

        //Add valid bid edges to graph
        while(!bidEdges.empty()){
            edge e = bidEdges.top();
            bidEdges.pop();
            edgeUnion(e, false);
        }
    }


    //Private Methods
    vector<string> MSTree::splitString(string input, char delim){
        vector<string> vectInput;
        stringstream ss(input);
        string word;
        while( getline(ss, word, delim) ){
            vectInput.push_back(word);
        }

        return vectInput;
    }

    void MSTree::edgeUnion(edge e, bool force){
        //if from or to not in verticies, add with value -1
        if( ! verticies.count(e.from)){
            verticies.insert(pair<int, int>(e.from, -1));
        }
        if( ! verticies.count(e.to)){
            verticies.insert(pair<int, int>(e.to, -1));
        }

        //follow from and to to root
        int fromRoot = getRoot(e.from);
        int toRoot = getRoot(e.to);
        roots.insert(fromRoot);
        roots.insert(toRoot);
        //Check needed and possibly add
        if(fromRoot != toRoot || force){
            if(force && fromRoot == toRoot){
                CYCLE = true;
            }
            verticies.erase(fromRoot);
            roots.erase(fromRoot);
            verticies.insert(pair<int,int>(fromRoot, toRoot));
            currentMST.push(e);
            COST += e.weight;
        }
    }

    int MSTree::getRoot(int vertex){
        int nextVertex;
        nextVertex = verticies.find(vertex)->second;
        if(nextVertex != -1){
            vertex = getRoot(nextVertex);
        }
        return vertex;
    }
