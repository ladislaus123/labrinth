#include "rotacao.hpp"

void giraDireita(int origem[][TAM], int destino[][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            destino[j][TAM - 1 - i] = origem[i][j];
}

void giraEsquerda(int origem[][TAM], int destino[][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            destino[TAM - 1 - j][i] = origem[i][j];
}

void giraPosicao(int &linha, int &coluna, bool horario) {
    int linhaAntiga = linha;
    int colunaAntiga = coluna;
    if (horario) {
        linha = colunaAntiga;
        coluna = TAM - 1 - linhaAntiga;
    } else {
        linha = TAM - 1 - colunaAntiga;
        coluna = linhaAntiga;
    }
}

int proximaOrientacao(int orientacaoAtual, bool horario) {
    int delta = horario ? 90 : -90;
    return (orientacaoAtual + delta + 360) % 360;
}

void giraCenario(int terreno[][TAM], int &orientacao, bool horario,
                  int &px, int &py, int blocoLinha[], int blocoColuna[], int numBlocos) {
    int girado[TAM][TAM];
    if (horario)
        giraDireita(terreno, girado);
    else
        giraEsquerda(terreno, girado);

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            terreno[i][j] = girado[i][j];

    giraPosicao(px, py, horario);
    for (int k = 0; k < numBlocos; k++)
        giraPosicao(blocoLinha[k], blocoColuna[k], horario);

    orientacao = proximaOrientacao(orientacao, horario);
}
