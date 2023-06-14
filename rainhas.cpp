// Copyright [2023] <Adriele>
#include "rainhas.hpp"

void Rainhas::ataques(){
    ofstream arquivo("ataque.txt");
    if(arquivo.is_open()) {
        for(int i=0; i<ataque.size(); i++){
            if(i%2==0)
                arquivo << ataque[i] << "  ";
            else
                arquivo << ataque[i] << endl;
        }
        arquivo.close();
    }
}

bool Rainhas::checarColuna() {
    bool funciona=1;
    string atacando= "";
    for (int num = 0; num < 8; num++) {
        int cont=0;
        int contaRainhas = 0;
        for (auto i : tabuleiro) {
            if (i[num] == '1') {
                if (contaRainhas >= 1)
                    ataque.push_back(atacando);
                atacando = to_string(cont) + "," + to_string(num);
                contaRainhas++;
            }
            cont++;
        }
        if (contaRainhas > 1) {
            ataque.push_back(atacando);
            funciona = false;
        }
        }
        return funciona;
    }

bool Rainhas::checarLinha() {
    for (auto i : tabuleiro) {
        if (count(i.begin(), i.end(), '1') > 1) {
            return false;
        }
    }
    return true;
}

bool Rainhas::checarDiagonalDireita() {
    unordered_set<int> diagonal;
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            char p = tabuleiro[linha][coluna];
            if (p == '1') {
                diagonal.insert(linha - coluna);
            }
        }
    }
    return diagonal.size() == tabuleiro.size();
}

bool Rainhas::chcarDiagonalEsquerda() {
    unordered_set<int> diagonal;
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            char p = tabuleiro[linha][coluna];
            if (p == '1') {
                diagonal.insert(linha + coluna);
            }
        }
    }
    return diagonal.size() == tabuleiro.size();
}

int Rainhas::ChecaTudo() {
    int resultadofinal=0;
    resultadofinal += checarColuna()+ checarLinha() +checarDiagonalDireita();
    if (resultadofinal== 3) {
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
