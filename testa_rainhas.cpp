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