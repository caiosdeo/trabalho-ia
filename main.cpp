#include <iostream>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"
#include "uninformed_methods/uninformed.h"
#include "informed_methods/informed.h"
#include <list>
#include <iterator>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 2) {

        cout << "ERROR: Expecting: ./<program_name> <table_size>" << endl;

        return 0;

    }

    // Criando tabuleiro com o tamanho passado no argumento
    Table* root = new Table(atoi(argv[1]));
    cout << "RAIZ: ";
    printTable(root->getTokens(), root->getSize());
    cout << endl;

    // Pegando nó final
    Table* final = bfs(root);

    // Printando solução
    stack<int>* solution = getSolution(final);
    printStack(solution);

    // Imprimindo os tokens do nó final
    cout << "FINAL: ";
    printTable(final->getTokens(), final->getSize());
    cout << endl; 

    cout << "SIZE OF TABLE: " << sizeof(final) << endl;

    // unsigned int tokens[5][9] = {
    //     {1,2,1,1,3,2,2,2,1},
    //     {1,2,2,1,3,1,2,2,1},
    //     {1,1,1,3,1,2,2,2,2},
    //     {1,2,2,2,3,2,1,1,1},
    //     {1,2,1,2,3,1,2,2,1},
    // }; 

    // for (int i = 0; i < 5; i++){

    //     for(int j = 0; j < 9; j++)
    //         cout << tokens[i][j];
    //     // cout << endl;
    //     cout << " H = " << " " << getBiggestGroupHeuristic(tokens[i], 9) << endl;
    // }
    // return 0;
    
}