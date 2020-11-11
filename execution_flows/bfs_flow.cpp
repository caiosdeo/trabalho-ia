#include <iostream>
#include "bfs_flow.h"
#include "../auxiliar_functions/aux.h"
#include "../uninformed_methods/uninformed.h"

using namespace std;

void bfsFlow(int size){

    // Creating root
    Table* root = new Table(size);
    cout << "RAIZ: ";
    printTable(root->getTokens(), root->getSize());
    cout << endl;

    // Picking last node
    Table* final = bfs(root);

    // Printing solution
    stack<int>* solution = getSolution(final);
    printStack(solution);

    // Printing solution table
    cout << "FINAL: ";
    printTable(final->getTokens(), final->getSize());
    cout << endl;

}