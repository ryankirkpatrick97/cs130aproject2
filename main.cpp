//This is the main file for calling the trie and placing sentences and reading
//them from the trie.

#include"MSTree.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    MSTree msTree;
    string input;
    getline(cin, input);

    while(input != "END"){
        if(input != "") msTree.processInput(input);
        getline(cin, input);
    }

    return 0;
}
