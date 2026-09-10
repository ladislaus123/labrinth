#pragma once
#include "constantes.hpp"

// informa se a porta representada por "celula" esta fechada na orientacao dada
bool portaEstaFechada(int celula, int orientacao);

// informa se uma celula do terreno pode ser atravessada, considerando a orientacao
bool celulaEhPassavel(int celula, int orientacao);

// procura um bloco em (linha, coluna); devolve o indice dele no vetor ou -1
int indiceBlocoEm(int blocoLinha[], int blocoColuna[], int numBlocos, int linha, int coluna);

// informa se uma determinada celula sustenta um bloco (serve de apoio)
bool celulaSustentaBloco(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                          int numBlocos, int px, int py, int linha, int coluna);

bool jogadorSobreAlavanca(int terreno[][TAM], int px, int py);
bool jogadorVenceu(int terreno[][TAM], int px, int py);
