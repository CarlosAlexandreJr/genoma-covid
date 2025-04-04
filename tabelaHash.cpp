#include "tabelaHash.h"
#include <fstream>

// Inicializa tabela
TabelaHashGenoma::TabelaHashGenoma(int capacidade) {
    tamanho = capacidade;
    dados.resize(tamanho);
}

// Calcula o index na tabela
int TabelaHashGenoma::calcularHash(const string& seq) const {
    int hash = 0;
    // Calculo do Hash
    for (char base : seq) {
        hash = (hash * 31 + base) % tamanho;  // Fórmula simples
    }
    return hash;
}

// Adicionando a sequencia
void TabelaHashGenoma::adicionarSequencia(const string& seq) {
    int indice = calcularHash(seq);
    for (auto& item : dados[indice]) {
        if (item.sequencia == seq) {
            item.cont++;
            return;
        }
    }
    dados[indice].push_back({seq, 1});
}

// Criando o arquivo de resposta
void TabelaHashGenoma::gerarRelatorio(const string& arquivo) const {
    ofstream saida(arquivo);
    if (!saida) {
        throw runtime_error("Erro ao criar arquivo de saída");
    }
    for (const auto& lista : dados) {
        for (const auto& bloco : lista) {
            saida << bloco.sequencia << "\t" << bloco.cont << endl;
        }
    }
}