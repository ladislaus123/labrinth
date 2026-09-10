#pragma once
#include "constantes.hpp"

// carrega o mapa "numero" (1 a NUM_MAPAS) em "destino"
void carregaMapa(int numero, int destino[][TAM]);

// exibe o prompt de escolha de mapa e devolve o numero escolhido (aleatorio se 0)
int escolheMapa();
