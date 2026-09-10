#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "jogo.hpp"
#include "terminal.hpp"
#include "terreno.hpp"
#include "jogador.hpp"
#include "rotacao.hpp"
#include "fisica.hpp"
#include "desenho.hpp"
#include "fase.hpp"
using namespace std;

int jogaFase(int numero, int terreno[][TAM], int &orientacao, int &px, int &py,
             int blocoLinha[], int blocoColuna[], int &numBlocos,
             int &movimentos, int &rotacoes) {
    DeactivateCursor();
    (void)system("clear");

    while (true) {
        desenhaCenario(terreno, orientacao, blocoLinha, blocoColuna, numBlocos, px, py);
        exibeStatus(numero, orientacao, movimentos, rotacoes);

        if (jogadorVenceu(terreno, px, py)) {
            cout << "\nVoce venceu! Pressione qualquer tecla para voltar ao menu...\n";
            getch();
            ReactivateCursor();
            return SAIU_VITORIA;
        }

        char tecla = getch(); //get the user input

        if (tecla == 27) { // ESC
            ReactivateCursor();
            return SAIU_MENU;
        }

        if (tecla == 'r' || tecla == 'R') {
            inicializaFase(numero, terreno, orientacao, px, py, blocoLinha, blocoColuna,
                            numBlocos, movimentos, rotacoes);
        } else if ((tecla == 'q' || tecla == 'Q' || tecla == 'e' || tecla == 'E') &&
                   jogadorSobreAlavanca(terreno, px, py)) {
            bool horario = (tecla == 'e' || tecla == 'E');
            giraCenario(terreno, orientacao, horario, px, py, blocoLinha, blocoColuna, numBlocos);
            rotacoes++;

            bool jogadorMorreu = resolveEsmagamento(terreno, orientacao, blocoLinha, blocoColuna,
                                                      numBlocos, px, py);

            while (aplicaPassoGravidade(terreno, orientacao, blocoLinha, blocoColuna, numBlocos, px, py)) {
                SetCursorPos(0, 0);
                desenhaCenario(terreno, orientacao, blocoLinha, blocoColuna, numBlocos, px, py);
                exibeStatus(numero, orientacao, movimentos, rotacoes);
                usleep(120000); // pausa curta entre cada linha de queda, para dar pra ver o bloco cair
            }

            jogadorMorreu = resolveEsmagamento(terreno, orientacao, blocoLinha, blocoColuna,
                                                      numBlocos, px, py);

            if (jogadorMorreu) {
                SetCursorPos(0, 0);
                desenhaCenario(terreno, orientacao, blocoLinha, blocoColuna, numBlocos, px, py);
                cout << "\nUma porta fechou sobre voce! Fase perdida. Reiniciando...\n";
                cout << "Pressione qualquer tecla para continuar...\n";
                getch();
                inicializaFase(numero, terreno, orientacao, px, py, blocoLinha, blocoColuna,
                                numBlocos, movimentos, rotacoes);
            }
        } else {
            moveJogador(terreno, px, py, orientacao, tecla, blocoLinha, blocoColuna, numBlocos,
                        movimentos);
        }

        SetCursorPos(0, 0);
    }
}
