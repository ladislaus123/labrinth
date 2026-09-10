#pragma once
#include "constantes.hpp"

// move o jogador uma celula na direcao indicada pela tecla, se possivel
void moveJogador(int terreno[][TAM], int &px, int &py, int orientacao, char tecla,
                  int blocoLinha[], int blocoColuna[], int numBlocos, int &movimentos);
