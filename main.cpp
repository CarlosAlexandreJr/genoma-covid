#include "tabelaHash.h"
#include <iostream>
#include <fstream>
#include <cctype>

const int TAM_BLOCO = 6;
const int TAM_LINHA = 60; 
const int BLOCOS_LINHA = TAM_LINHA / TAM_BLOCO;

// Verifica se um bloco tem apenas os caracteres das bases do genoma
bool validarBloco(const string& bloco) {
    if (bloco.length() != TAM_BLOCO) return false;
    for (char base : bloco) {
        base = toupper(base);
        if (base != 'A' && base != 'T' && base != 'C' && base != 'G') {
            return false;
        }
    }
    return true;
}

// Processando o arquivo do genoma
void processarArquivo(const string& entrada, const string& saida) {
    ifstream genoma(entrada);
    if (!genoma) {
        throw runtime_error("O arquivo não foi encontrado");
    }
    // Criando uma nova tabela
    TabelaHashGenoma tabela;
    string linha;

    while (getline(genoma, linha)) {
        if (linha.length() < TAM_LINHA) continue;
        for (int i = 0; i < BLOCOS_LINHA; i++) {
            int inicio = i * TAM_BLOCO;
            string bloco = linha.substr(inicio, TAM_BLOCO);
            // Verificando se as linhas sao validas e colocando as letras em maiusculo
            if (validarBloco(bloco)) {
                for (char& base : bloco) {
                    base = toupper(base);
                }
                // Adicionando na tabela
                tabela.adicionarSequencia(bloco);
            }
        }
    }
    // Salvando o resultado
    tabela.gerarRelatorio(saida);
}

int main() {
    try {
        processarArquivo("genoma.txt", "bases_genoma_coronavirus.txt");
    } catch (const exception& e) {
        return 1;
    }
    return 0;
}