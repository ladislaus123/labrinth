#include "fisica.hpp"
#include "terreno.hpp"

bool aplicaPassoGravidade(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                           int numBlocos, int px, int py) {
    bool moveu = false;
    for (int k = 0; k < numBlocos; k++) {
        int abaixo = blocoLinha[k] + 1;
        if (!celulaSustentaBloco(terreno, orientacao, blocoLinha, blocoColuna, numBlocos,
                                  px, py, abaixo, blocoColuna[k])) {
            blocoLinha[k] = abaixo;
            moveu = true;
        }
    }
    return moveu;
}

bool  resolveEsmagamento(int terreno[][TAM], int orientacao, int blocoLinha[], int blocoColuna[],
                         int &numBlocos, int px, int py) {
    bool jogadorMorreu = false;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int celula = terreno[i][j];
            if ((celula == 6 || celula == 7) && portaEstaFechada(celula, orientacao)) {
                int idx = indiceBlocoEm(blocoLinha, blocoColuna, numBlocos, i, j);
                if (idx != -1) {
                    // remove o bloco esmagado, compactando o vetor
                    for (int k = idx; k < numBlocos - 1; k++) {
                        blocoLinha[k] = blocoLinha[k + 1];
                        blocoColuna[k] = blocoColuna[k + 1];
                    }
                    numBlocos--;
                }
                if (i == px && j == py)
                    jogadorMorreu = true;
            }
        }
    }
    return jogadorMorreu;
}
