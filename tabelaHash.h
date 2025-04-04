#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <vector>
#include <string>
#include <list>

using namespace std;

// Classe TabelaHashGenoma
class TabelaHashGenoma {
private:
    // Estrutura para guardar as bases as repeticoes
    struct BlocoContagem {
        string sequencia;
        int cont;
    };
    // Tabela para colisoes
    vector<list<BlocoContagem>> dados;
    int tamanho;

    // Função de posicoes na tabela
    int calcularHash(const string& seq) const;

public:
    // Construtor da Classe
    TabelaHashGenoma(int capacidade = 1000);
    
    // Adiciona a sequencia
    void adicionarSequencia(const string& seq);
    
    // Salva no arquivo
    void gerarRelatorio(const string& arquivo) const;
};

#endif