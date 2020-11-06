#include <iostream>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"
#include <list>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 2) {

        cout << "ERROR: Expecting: ./<program_name> <table_size>" << endl;

        return 0;

    }

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

    return 0;
    
}