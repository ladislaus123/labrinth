#include "jogador.hpp"
#include "terreno.hpp"

void moveJogador(int terreno[][TAM], int &px, int &py, int orientacao, char tecla,
                  int blocoLinha[], int blocoColuna[], int numBlocos, int &movimentos) {
    int novoPx = px;
    int novoPy = py;

    switch (tecla) {
    case 'w': case 'W': novoPx = px - 1; break;
    case 's': case 'S': novoPx = px + 1; break;
    case 'a': case 'A': novoPy = py - 1; break;
    case 'd': case 'D': novoPy = py + 1; break;
    default: return; // tecla nao e de movimento
    }

    if (novoPx < 0 || novoPx >= TAM || novoPy < 0 || novoPy >= TAM)
        return;
    if (!celulaEhPassavel(terreno[novoPx][novoPy], orientacao))
        return;
    if (indiceBlocoEm(blocoLinha, blocoColuna, numBlocos, novoPx, novoPy) != -1)
        return; // blocos tambem bloqueiam o jogador

    px = novoPx;
    py = novoPy;
    movimentos++;
}
