#include "terreno.hpp"

bool portaEstaFechada(int celula, int orientacao) {
    if (celula == 6) // porta tipo A: solida em 0 e 180
        return (orientacao == 0 || orientacao == 180);
    if (celula == 7) // porta tipo B: solida em 90 e 270
        return (orientacao == 90 || orientacao == 270);
    return false;
}

bool celulaEhPassavel(int celula, int orientacao) {
    switch (celula) {
    case 0:
    case 4:
    case 5:
        return true;
    case 6:
    case 7:
        return !portaEstaFechada(celula, orientacao);
    default: // parede fixa (1)
        return false;
    }
}

int indiceBlocoEm(int blocoLinha[], int blocoColuna[], int numBlocos, int linha, int coluna) {
    for (int k = 0; k < numBlocos; k++)
        if (blocoLinha[k] == linha && blocoColuna[k] == coluna)
            return k;
    return -1;
}

bool celulaSustentaBloco(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                          int numBlocos, int px, int py, int linha, int coluna) {
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
        return true; // borda do mapa
    if (!celulaEhPassavel(terreno[linha][coluna], orientacao))
        return true; // parede ou porta fechada
    if (linha == px && coluna == py)
        return true; // jogador nao e derrubado, mas barra a queda
    if (indiceBlocoEm(blocoLinha, blocoColuna, numBlocos, linha, coluna) != -1)
        return true; // outro bloco ja apoiado ali
    return false;
}

bool jogadorSobreAlavanca(int terreno[][TAM], int px, int py) {
    return terreno[px][py] == 4;
}

bool jogadorVenceu(int terreno[][TAM], int px, int py) {
    return terreno[px][py] == 5;
}
