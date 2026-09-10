#include "fase.hpp"
#include "mapas.hpp"

void extraiEntidades(int mapaBruto[][TAM], int terreno[][TAM], int &px, int &py,
                      int blocoLinha[], int blocoColuna[], int &numBlocos) {
    numBlocos = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (mapaBruto[i][j] == 2) { //set the player position
                px = i;
                py = j;
                terreno[i][j] = 0;
            } else if (mapaBruto[i][j] == 3) { //set the block position
                blocoLinha[numBlocos] = i;
                blocoColuna[numBlocos] = j;
                numBlocos++;
                terreno[i][j] = 0;
            } else {
                terreno[i][j] = mapaBruto[i][j];
            }
        }
    }
}

void inicializaFase(int numero, int terreno[][TAM], int &orientacao, int &px, int &py,
                     int blocoLinha[], int blocoColuna[], int &numBlocos,
                     int &movimentos, int &rotacoes) {
    int mapaBruto[TAM][TAM];
    carregaMapa(numero, mapaBruto); //passes mapaBruto a refrence to load the integers of the chosen map into it
    extraiEntidades(mapaBruto, terreno, px, py, blocoLinha, blocoColuna, numBlocos);
    orientacao = 0;
    movimentos = 0;
    rotacoes = 0;
}
