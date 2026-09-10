#pragma once
#include "constantes.hpp"

void giraDireita(int origem[][TAM], int destino[][TAM]);
void giraEsquerda(int origem[][TAM], int destino[][TAM]);

// aplica a mesma transformacao geometrica da rotacao sobre uma unica posicao
void giraPosicao(int &linha, int &coluna, bool horario);

int proximaOrientacao(int orientacaoAtual, bool horario);

// gira o terreno inteiro e reposiciona jogador e blocos da mesma forma
void giraCenario(int terreno[][TAM], int &orientacao, bool horario,
                  int &px, int &py, int blocoLinha[], int blocoColuna[], int numBlocos);
