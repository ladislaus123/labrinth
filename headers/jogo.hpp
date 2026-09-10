#pragma once
#include "constantes.hpp"

// resultados possiveis ao sair do laco da fase
#define SAIU_MENU 0
#define SAIU_VITORIA 1

// joga a fase "numero", usando o estado (terreno/orientacao/posicoes) por
// referencia para que o menu "Continuar" possa retomar depois; devolve o
// motivo da saida do laco (menu ou vitoria)
int jogaFase(int numero, int terreno[][TAM], int &orientacao, int &px, int &py,
             int blocoLinha[], int blocoColuna[], int &numBlocos,
             int &movimentos, int &rotacoes);
