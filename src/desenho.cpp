#include <iostream>
#include "desenho.hpp"
#include "terreno.hpp"
using namespace std;

void desenhaCenario(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                     int numBlocos, int px, int py) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == px && j == py) {
                cout << '@';
                continue;
            }
            if (indiceBlocoEm(blocoLinha, blocoColuna, numBlocos, i, j) != -1) {
                cout << 'O';
                continue;
            }
            switch (terreno[i][j]) {
            case 0: cout << ' '; break;
            case 1: cout << '#'; break;
            case 4: cout << 'A'; break;
            case 5: cout << 'S'; break;
            case 6: cout << (portaEstaFechada(6, orientacao) ? '=' : ':'); break;
            case 7: cout << (portaEstaFechada(7, orientacao) ? '|' : ';'); break;
            default: cout << ' ';
            }
        }
        cout << '\n';
    }
}

void exibeStatus(int numero, int orientacao, int movimentos, int rotacoes) {
    cout << "Mapa " << numero
         << " | Orientacao: " << orientacao << " graus"
         << " | Movimentos: " << movimentos
         << " | Rotacoes: " << rotacoes << "\n";
    cout << "WASD move | Q/E gira (sobre a alavanca) | R reinicia | ESC volta ao menu\n";
}
