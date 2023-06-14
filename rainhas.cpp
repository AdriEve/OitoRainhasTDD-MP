// Copyright [2023] <Adriele>
#include "rainhas.hpp"

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
    return +1;
}
