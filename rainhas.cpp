// Copyright [2023] <Adriele>
#include "rainhas.hpp"

bool Rainhas::checarColuna() {
    for (int num = 0; num < 8; num++) {
        int contaRainhas = 0;
        for (auto i : tabuleiro) {
            if (i[num] == '1') {
                contaRainhas++;
            }
        }
        if (contaRainhas > 1) {
            return false;
        }
    }
    return true;
}


int Rainhas::ChecaTudo() {
    int resultadofinal=0;
    resultadofinal += checarColuna();
    if (resultadofinal== 1) {
         return 1;
    } else {
         return 0;
    }
}

int Rainhas::solucao() {
    if (tabuleiro.empty()) {
        return -1;
    }
    int contaRainhas = 0;
    int contaTamanho = 0;
    for (auto i : tabuleiro) {
        contaRainhas += count(i.begin(), i.end(), '1');
        contaTamanho++;
    }
    if (contaRainhas != 8 || contaTamanho != 8) { // teste 3
        return -1;
    }
    return ChecaTudo();
}
