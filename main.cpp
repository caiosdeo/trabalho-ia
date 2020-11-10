#include <iostream>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"
#include "uninformed_methods/uninformed.h"
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
    Table* final = backtracking(root);

    // Printando solução
    stack<int>* solution = getSolution(final);
    printStack(solution);

    // Imprimindo os tokens do nó final
    cout << "FINAL: ";
    printTable(final->getTokens(), final->getSize());
    cout << endl;



    /*

    // Criando tabuleiro com o tamanho passado no argumento
    Table* tabuleiro = new Table(atoi(argv[1]));
    cout << "PAI: " << tabuleiro->getHashValue() << endl;
    printTable(tabuleiro->getTokens(), tabuleiro->getSize());

    // Aplicaveis do tabuleiro
    list<int>* aplicaveis = findApplicableRules(tabuleiro);
    // Filhos Tabuleiro
    cout << "Regras Possiveis Pai: \n";
    for(list<int>::iterator it = aplicaveis->begin(); it != aplicaveis->end(); ++it){
        cout << "Regra " << *it << " ";
        Table* filho = givesLight(tabuleiro, *it);
        printTable(filho->getTokens(), filho->getSize());
    }
    cout << endl;

    // Gerando o com a regra -2
    Table* filho = givesLight(tabuleiro, -2);
    cout << "FILHO: " << filho->getHashValue() << endl;
    printTable(filho->getTokens(), filho->getSize());
    list<int>* aplicaveisF = findApplicableRules(filho);
    // Filhos do filho (-2)
    cout << "Regras Possiveis Filho: \n";
    for(list<int>::iterator it = aplicaveisF->begin(); it != aplicaveisF->end(); ++it){
        cout << "Regra " << *it << " ";
        Table* neto = givesLight(filho, *it);
        printTable(neto->getTokens(), neto->getSize());
    }
    cout << endl;

        // Gerando o com a regra 1
    Table* neto = givesLight(filho, 1);
    cout << "NETO: " << neto->getHashValue() << endl;
    printTable(neto->getTokens(), neto->getSize());
    list<int>* aplicaveisN = findApplicableRules(neto);
    // Filhos do filho (1)
    cout << "Regras Possiveis Neto: \n";
    for(list<int>::iterator it = aplicaveisN->begin(); it != aplicaveisN->end(); ++it){
        cout << "Regra " << *it << " ";
        Table* bisneto = givesLight(neto, *it);
        printTable(bisneto->getTokens(), bisneto->getSize());
    }
    cout << endl;

    */

    // unsigned int tokens[5][5] = {
    //     {1,2,2,1,0},
    //     {1,2,2,0,1},
    //     {1,2,0,2,1},
    //     {1,0,2,1,2},
    //     {0,2,1,1,2}
    // };

    // for (int i = 0; i < 5; i++){

    //     for(int j = 0; j < 5; j++)
    //         cout << tokens[i][j];

    //     cout << " solução " << " " << checkSolution(tokens[i], 5) << endl;
    // }
    return 0;
    
}