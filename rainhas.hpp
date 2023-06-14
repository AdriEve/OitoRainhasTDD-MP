// Copyright [2023] <Adriele>
#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_
#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/// @file
/// @author Adriele Evellen
/// @version 1.0

/// @brief Verifica se a entrada é solução para o problema das 8 rainhas
class Rainhas {
private:
    /// @brief confere se a entrada é valida 
    /// @param tabuleiro entrada a ser validada
    vector<string> tabuleiro;
public:
    Rainhas(vector<string> tabuleiro) : tabuleiro(tabuleiro) {}
    /// @brief verifica se a entrada está vazia
    /// @return se a entrada é valida
    int solucao();        
};
#endif  // RAINHAS_HPP_
