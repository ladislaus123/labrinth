#pragma once
#include "constantes.hpp"

void desenhaCenario(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                     int numBlocos, int px, int py);

void exibeStatus(int numero, int orientacao, int movimentos, int rotacoes);
