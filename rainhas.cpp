// Copyright [2023] <Adriele>
#include "rainhas.hpp"

void Rainhas::ataques(){
    ofstream arquivo("ataques.txt");
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
    bool funciona=true;
    int cont=0;
    for (auto i : tabuleiro) {
        if (count(i.begin(), i.end(), '1') > 1) {
             for (int j=0; j<8; j++){
                if (i[j]=='1')
                    ataque.push_back((to_string(cont) + "," + to_string(j)));
                }
                funciona= false;
            }
        cont++;
        }
    return funciona;
}

bool Rainhas::checarDiagonalDireita() {
    vector<int> lin, col;
    unordered_set<int> diagonal;
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            char p = tabuleiro[linha][coluna];
            if (p == '1') {
                diagonal.insert(linha - coluna);
                lin.push_back(linha);
                col.push_back(coluna);
            }
        }
    }
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            if (a != b) {
                if (lin[a] - col[a] == lin[b] - col[b]) {
                    ataque.push_back(to_string(lin[b]) + "," +to_string(col[b]));
                }
            }
        }
    }
    return diagonal.size() == tabuleiro.size();
}

bool Rainhas::chcarDiagonalEsquerda() {
    vector<int> lin, col;
    unordered_set<int> diagonal;
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            char p = tabuleiro[linha][coluna];
            if (p == '1') {
                diagonal.insert(linha + coluna);
                lin.push_back(linha);
                col.push_back(coluna);
            }
        }
    }
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            if (a != b) {
                if (lin[a] - col[a] == lin[b] - col[b]) {
                    ataque.push_back(to_string(lin[b]) + "," +to_string(col[b]));
                }
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
