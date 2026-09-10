// Dados dos mapas e escolha de mapa. As matrizes brutas ficam ocultas neste
// arquivo (escopo de arquivo, nao globais do programa) e so sao acessiveis
// por meio de carregaMapa().
#include <iostream>
#include "mapas.hpp"
using namespace std;

static const int mapa1[TAM][TAM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 3, 0, 0, 0, 5, 1},
    {1, 0, 1, 1, 1, 6, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 4, 0, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static const int mapa2[TAM][TAM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 1, 0, 0, 0, 5, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 6, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 4, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static const int mapa3[TAM][TAM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 4, 0, 1, 0, 6, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 3, 1, 0, 7, 0, 1, 0, 4, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 5, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static const int mapa4[TAM][TAM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 4, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 4, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 5, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static const int mapa5[TAM][TAM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 4, 0, 0, 6, 4, 0, 7, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 5, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

//This function loads the map the user chooses into a destination 2d array
void carregaMapa(int numero, int destino[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            switch (numero) {
            case 1: destino[i][j] = mapa1[i][j]; break;
            case 2: destino[i][j] = mapa2[i][j]; break;
            case 3: destino[i][j] = mapa3[i][j]; break;
            case 4: destino[i][j] = mapa4[i][j]; break;
            case 5: destino[i][j] = mapa5[i][j]; break;
            }
        }
    }
}

//This function returns the map the user has chosen
int escolheMapa() {
    int opcao;
    cout << "\nEscolha o mapa: digite um numero de 1 a " << NUM_MAPAS;
    cin >> opcao;

    while (opcao < 0 || opcao > NUM_MAPAS) {
        cout << "Opcao invalida. Digite um numero entre 0 e " << NUM_MAPAS << ": ";
        cin >> opcao;
    }

    return opcao;
}
