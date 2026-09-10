#include <iostream>
#include "gameloop.hpp"
#include "constantes.hpp"
#include "mapas.hpp"
#include "fase.hpp"
#include "menu.hpp"
#include "jogo.hpp"
#include "terminal.hpp"
using namespace std;

void executaLoopPrincipal() {
    int terreno[TAM][TAM];
    int orientacao = 0;
    int px = 0, py = 0;
    int blocoLinha[MAX_BLOCOS];
    int blocoColuna[MAX_BLOCOS];
    int numBlocos = 0;
    int movimentos = 0;
    int rotacoes = 0;
    int numeroMapaAtual = 0;
    bool temPartidaEmAndamento = false;

    bool rodando = true;
    while (rodando) {
        int opcao = exibeMenu(temPartidaEmAndamento); //returns the option the user selects as an Int

        switch (opcao) {
        case 1: { // Novo jogo
            numeroMapaAtual = escolheMapa(); //returns the int of the map the user chooses
            inicializaFase(numeroMapaAtual, terreno, orientacao, px, py, blocoLinha, blocoColuna,
                            numBlocos, movimentos, rotacoes);
            int resultado = jogaFase(numeroMapaAtual, terreno, orientacao, px, py, blocoLinha,
                                      blocoColuna, numBlocos, movimentos, rotacoes);
            temPartidaEmAndamento = (resultado != SAIU_VITORIA);
            break;
        }
        case 2: // Continuar
            if (temPartidaEmAndamento) {
                int resultado = jogaFase(numeroMapaAtual, terreno, orientacao, px, py, blocoLinha,
                                          blocoColuna, numBlocos, movimentos, rotacoes);
                temPartidaEmAndamento = (resultado != SAIU_VITORIA);
            }
            break;
        case 3: // Instrucoes
            exibeSobre();
            break;
        case 4: // Fim
            rodando = false;
            break;
        default:
            cout << "Opcao invalida.\n";
        }
    }
}
