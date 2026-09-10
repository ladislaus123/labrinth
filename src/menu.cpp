#include <iostream>
#include <cstdlib>
#include "menu.hpp"
#include "terminal.hpp"
using namespace std;


//This function displays the menu and returns the option the user selects 1-4
int exibeMenu(bool temPartidaEmAndamento) {
    (void)system("clear");
    cout << "================== LABIRINTO GIRATORIO ==================\n";
    cout << "1 - Novo jogo\n";
    if (temPartidaEmAndamento)
        cout << " 2 - Continuar\n"; 
    cout << "3 - Instrucoes\n";
    cout << "4 - Fim\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;
    return opcao;
}

void exibeSobre() {
    (void)system("clear");
    cout << "================ SOBRE ================\n";
    cout << "Labirinto Giratorio\n";
    cout << "Equipe: (preencha com os nomes da equipe)\n";
    cout << "Setembro/2026 - Algoritmos e Programacao II - Prof. (preencha)\n\n";
    cout << "Regras:\n";
    cout << " - Atravesse o labirinto ate a saida (S).\n";
    cout << " - Blocos soltos (O) caem com a gravidade ao girar o cenario.\n";
    cout << " - Portas tipo A (=/:) sao solidas em 0 e 180 graus.\n";
    cout << " - Portas tipo B (|/;) sao solidas em 90 e 270 graus.\n";
    cout << " - Uma porta que fecha sobre um bloco o esmaga; sobre o jogador, perde a fase.\n\n";
    cout << "Teclas:\n";
    cout << " W A S D - mover o jogador\n";
    cout << " Q       - girar o cenario para a esquerda (sobre a alavanca)\n";
    cout << " E       - girar o cenario para a direita (sobre a alavanca)\n";
    cout << " R       - reiniciar a fase\n";
    cout << " ESC     - voltar ao menu\n\n";
    cout << "Pressione qualquer tecla para voltar...\n";
    getch();
}
