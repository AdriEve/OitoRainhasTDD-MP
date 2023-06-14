// Copyright [2023] <Adriele>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"
#include <fstream>

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
    fstream arquivo("teste_8_rainhas.txt");

    if (arquivo.is_open()) {
        string lin1, lin2, lin3, lin4, lin5, lin6, lin7, lin8;
        getline(arquivo, lin1);
        getline(arquivo, lin2);
        getline(arquivo, lin3);
        getline(arquivo, lin4);
        getline(arquivo, lin5);
        getline(arquivo, lin6);
        getline(arquivo, lin7);
        getline(arquivo, lin8);
        vector<string> tabuleiro = {lin1, lin2, lin3, lin4, lin5, lin6, lin7, lin8};
        Rainhas t9(tabuleiro);
        assert(t9.solucao() == 0);
        arquivo.close();
    }
    
}

TEST_CASE("Teste 10 - multiplos erros") {
    vector<string> tabuleiro = {"01001000", "01000001","10000100", "00001000", "00010100", "00010010", "00000100", "00100000"};
    Rainhas t10(tabuleiro);
    assert(t10.solucao() == 0);
}
