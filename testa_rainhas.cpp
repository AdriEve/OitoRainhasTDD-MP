// Copyright [2023] <Adriele>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Teste 1 -tabuleiro vazio") {
    Rainhas t1({});
    assert(t1.solucao() == -1);
}

TEST_CASE("Teste 2 -sem damas") {
    std::vector<std::string> board = {"00000000", "00000000","00000000","00000000","00000000","00000000","00000000","00000000"};
    Queens t2(board);
    assert(t2.solve() == -1);
}