// Copyright [2023] <Adriele>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Teste 1 -tabuleiro vazio") {
    Rainhas t1({});
    assert(t1.solucao() == -1);
}

TEST_CASE("Teste 2 -sem damas") {
    vector<string> tabuleiro = {"00000000", "00000000","00000000","00000000","00000000","00000000","00000000","00000000"};
    Rainhas t2(tabuleiro);
    assert(t2.solucao() == -1);
}

TEST_CASE("Teste 3 -Tamanho errado") {
    vector<string> tabuleiro = {"00101000", "01000000","00000010","01000000","00000010","10000000","000000100"};
    Rainhas t3(tabuleiro);
    assert(t3.solucao() == -1);
}

TEST_CASE("Teste 4 -damas na mesma coluna") {
    vector<string> tabuleiro = {"10000000", "10000000","00100000", "01000000","00000001", "00000010","01000000", "00001000"};
    Rainhas t4(tabuleiro);
    assert(t4.solucao() == 0);
}

TEST_CASE("Teste 5 -damas na mesma linha") {
    vector<string> tabuleiro = {"10000001", "00000000", "01000000", "00000100","00100000", "00000010","00010000", "00000001"};
    Rainhas t5(tabuleiro);
    assert(t5.solucao() == 0);
}

TEST_CASE("Teste 6 - Duas damas diagonal direita") {
    vector<string> tabuleiros = {"10000000", "00000001", "01000000", "00001000", "00010000", "00000010", "00000100", "00100000"};
    Rainhas t6(tabuleiros);
    assert(t6.solucao() == 0);
}

TEST_CASE("Teste 7 -Caso correto") {
    vector<string> tabuleiro = {"00010000", "00000100", "00000001", "01000000", "00000010", "10000000", "00100000", "00001000"};
    Rainhas t7(tabuleiro);
    assert(t7.solucao() == 1);
}// passou nos testes

TEST_CASE("Teste 8 - Duas damas diagonal esquerda") {
    vector<string> tabuleiro = {"01000000", "00000001","10000000", "00001000", "00010000", "00000010", "00000100", "00100000"};
    Rainhas t8(tabuleiro);
    assert(t8.solucao() == 0);
}

TEST_CASE("Teste 9 - Usando arquivo") {
    ifstream arquivo("teste_8_rainhas.txt");

    if (arquivo.is_open()) {
        string linha;
        string lin1, lin2, lin3, lin4, lin5, lin6, lin7, lin8;
        while (getline(arquivo, linha)) {
            lin1 << linha;
            lin2 << linha;
            lin3 << linha;
            lin4 << linha;
            lin5 << linha;
            lin6 << linha;
            lin7 << linha;
            lin8 << linha;

        }

        arquivo.close();
    }
    vector<string> tabuleiro = {"lin1", "lin2","lin3", "lin4", "lin5", "lin6", "lin7", "lin8"};
    Rainhas t8(tabuleiro);
    assert(t8.solucao() == 0);
}
