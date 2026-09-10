#pragma once
#include "constantes.hpp"

// separa o mapa bruto em terreno (paredes, portas, alavanca, saida) e
// entidades moveis (jogador e blocos)
void extraiEntidades(int mapaBruto[][TAM], int terreno[][TAM], int &px, int &py,
                      int blocoLinha[], int blocoColuna[], int &numBlocos);

// carrega o mapa "numero" e ja separa em terreno + entidades, zerando os contadores
void inicializaFase(int numero, int terreno[][TAM], int &orientacao, int &px, int &py,
                     int blocoLinha[], int blocoColuna[], int &numBlocos,
                     int &movimentos, int &rotacoes);
