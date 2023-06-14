// Copyright [2023] <Adriele>
#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_
#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

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
    vector<string> ataque;
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
    /// @brief verifica se há mais de uma rainha em cada linha
    /// @return retorna 1 se houver mais de uma rainha na linha ou 0 se nao tiver    
    bool checarLinha();
    /// @brief verifica se há mais de uma rainha em cada diagonal direitas
    /// @return retorna 1 se houver mais de uma rainha na diagonal ou 0 se nao tiver   
    bool checarDiagonalDireita();
    /// @brief verifica se há mais de uma rainha em cada diagonal esquerdas
    /// @return retorna 1 se houver mais de uma rainha na diagonal ou 0 se nao tiver 
    bool chcarDiagonalEsquerda();
    void ataques();

};
#endif  // RAINHAS_HPP_
