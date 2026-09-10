#pragma once
#include "constantes.hpp"

// desce cada bloco em 1 linha, se a celula abaixo dele estiver livre;
// devolve true se algum bloco se moveu nesse passo (usado para animar a queda)
bool aplicaPassoGravidade(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                           int numBlocos, int px, int py);

// resolve o esmagamento causado por portas que se fecharam sobre um bloco ou o
// jogador; devolve true se o jogador morreu
bool resolveEsmagamento(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                         int &numBlocos, int px, int py);
