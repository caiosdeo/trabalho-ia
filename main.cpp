#include <iostream>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"

using namespace std;

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 2) {

        cout << "ERROR: Expecting: ./<program_name> <table_size>" << endl;

        return 0;

    }

    // Criando tabuleiro com o tamanho passado no argumento
    Table* tabuleiro = new Table(atoi(argv[1]));
    printTable(tabuleiro->getTokens(), tabuleiro->getSize());
    Table* filho = givesLight(tabuleiro,-1);
    printTable(filho->getTokens(), filho->getSize());
    Table* neto = givesLight(filho,3);
    printTable(neto->getTokens(), neto->getSize());

    return 0;
    
}
