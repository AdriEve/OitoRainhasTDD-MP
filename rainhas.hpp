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
    /// @brief verifica se a entrada está vazia e verifica a quantidade de rainhas no tabuleiro
    /// @return se a entrada é valida
    int solucao();
    /// @brief função que irá chamar as outras funçoes para checar colunas linhas e diagonais
    /// @return resultado das funçoes juntas
    int ChecaTudo();
    /// @brief verifica se há mais de uma rainha em cada coluna
    /// @return retorna 1 se houver mais de uma rainha na coluna ou 0 se nao tiver
    bool checarColuna();      
};
#endif  // RAINHAS_HPP_
