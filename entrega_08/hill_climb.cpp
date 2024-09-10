#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>

struct Item {
    int peso;
    int valor;
};

// Função para calcular o valor total de uma solução
int calcularValor(const std::vector<Item>& itens, const std::vector<char>& solucao) {
    int valorTotal = 0;
    for (size_t i = 0; i < itens.size(); ++i) {
        if (solucao[i]) {
            valorTotal += itens[i].valor;
        }
    }
    return valorTotal;
}

// Função para calcular o peso total de uma solução
int calcularPeso(const std::vector<Item>& itens, const std::vector<char>& solucao) {
    int pesoTotal = 0;
    for (size_t i = 0; i < itens.size(); ++i) {
        if (solucao[i]) {
            pesoTotal += itens[i].peso;
        }
    }
    return pesoTotal;
}

// Função para o algoritmo Mochila Cheia
std::vector<char> mochilaCheia(const std::vector<Item>& itens, int capacidade) {
    std::vector<char> solucao(itens.size(), 0);
    for (size_t i = 0; i < itens.size(); ++i) {
        if (calcularPeso(itens, solucao) + itens[i].peso <= capacidade) {
            solucao[i] = 1;
        }
    }
    return solucao;
}

// Função para gerar uma solução inicial válida (respeitando a capacidade)
std::vector<char> gerarSolucaoInicialValida(const std::vector<Item>& itens, int capacidade) {
    std::vector<char> solucao(itens.size(), 0);
    int pesoAtual = 0;

    // Gerar a seed baseada no tempo atual
    auto agora = std::chrono::high_resolution_clock::now();
    auto duration = agora.time_since_epoch();
    unsigned seed = duration.count();  // Gera a seed baseada no tempo
    std::mt19937 gen(seed);  // Usa a seed gerada
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < itens.size(); ++i) {
        // Tentar adicionar o item somente se não ultrapassar a capacidade
        if (dis(gen) && (pesoAtual + itens[i].peso <= capacidade)) {
            solucao[i] = 1;
            pesoAtual += itens[i].peso;
        }
    }

    return solucao;
}

// Função para gerar vizinhos
std::vector<std::vector<char>> gerarVizinhos(const std::vector<char>& solucao) {
    std::vector<std::vector<char>> vizinhos;
    for (size_t i = 0; i < solucao.size(); ++i) {
        std::vector<char> vizinho = solucao;
        vizinho[i] = !vizinho[i];  // Inverter o bit para gerar o vizinho
        vizinhos.push_back(vizinho);
    }
    return vizinhos;
}

// Função para o algoritmo Hill Climbing
std::vector<char> hillClimbing(const std::vector<Item>& itens, int capacidade) {
    size_t tamanho = itens.size();
    std::vector<char> solucaoAtual = gerarSolucaoInicialValida(itens, capacidade);

    while (true) {
        std::vector<std::vector<char>> vizinhos = gerarVizinhos(solucaoAtual);
        std::vector<char> melhorVizinho = solucaoAtual;
        int valorMelhor = calcularValor(itens, solucaoAtual);

        for (const auto& vizinho : vizinhos) {
            int pesoVizinho = calcularPeso(itens, vizinho);
            int valorVizinho = calcularValor(itens, vizinho);

            // Considerar apenas vizinhos que respeitem a capacidade e sejam melhores
            if (pesoVizinho <= capacidade && valorVizinho > valorMelhor) {
                melhorVizinho = vizinho;
                valorMelhor = valorVizinho;
            }
        }

        if (melhorVizinho == solucaoAtual) {
            break;  // Parar se nenhum vizinho for melhor
        }

        solucaoAtual = melhorVizinho;  // Atualizar para o melhor vizinho
    }

    return solucaoAtual;
}

// Função para ler os dados do arquivo
bool lerDadosDoArquivo(const std::string& nomeArquivo, std::vector<Item>& itens, int& capacidade) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    std::string linha;
    std::getline(arquivo, linha);
    std::istringstream iss(linha);
    size_t numItens;
    iss >> numItens >> capacidade;

    itens.resize(numItens);
    for (size_t i = 0; i < numItens; ++i) {
        if (std::getline(arquivo, linha)) {
            std::istringstream itemStream(linha);
            Item item;
            if (itemStream >> item.peso >> item.valor) {
                itens[i] = item;
            }
        }
    }

    arquivo.close();
    return true;
}

int main() {
    std::vector<std::string> arquivos = {"in1.txt", "in2.txt", "in3.txt"};
    for (const auto& arquivo : arquivos) {
        std::vector<Item> itens;
        int capacidade;
        
        if (!lerDadosDoArquivo(arquivo, itens, capacidade)) {
            std::cerr << "Falha ao ler o arquivo: " << arquivo << std::endl;
            continue; // Pular para o próximo arquivo se houver erro
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        
        auto resultadoMochilaCheia = mochilaCheia(itens, capacidade);
        auto resultadoHillClimbing = hillClimbing(itens, capacidade);
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempo = end - start;
        
        std::cout << "Resultados para o arquivo " << arquivo << ":\n";
        std::cout << "Tempo de execução: " << tempo.count() << " segundos\n";
        std::cout << "Peso máximo permitido: " << capacidade << "\n";
        
        // Avaliar e imprimir a qualidade das soluções
        std::cout << "Mochila Cheia Valor Total: " << calcularValor(itens, resultadoMochilaCheia) << "\n";
        std::cout << "Mochila Cheia Peso Total: " << calcularPeso(itens, resultadoMochilaCheia) << "\n";
        std::cout << "Hill Climbing Valor Total: " << calcularValor(itens, resultadoHillClimbing) << "\n";
        std::cout << "Hill Climbing Peso Total: " << calcularPeso(itens, resultadoHillClimbing) << "\n";
    }

    return 0;
}
