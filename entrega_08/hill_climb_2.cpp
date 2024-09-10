#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;
int calcularValor(const vector<int>& valores, const vector<int>& combinacao) {
    int valorTotal = 0;
    for (size_t i = 0; i < combinacao.size(); ++i) {
        if (combinacao[i] == 1) {
            valorTotal += valores[i];
        }
    }
    return valorTotal;
}

// Função para verificar o peso total de uma combinação
int calcularPeso(const vector<int>& pesos, const vector<int>& combinacao) {
    int pesoTotal = 0;
    for (size_t i = 0; i < combinacao.size(); ++i) {
        if (combinacao[i] == 1) {
            pesoTotal += pesos[i];
        }
    }
    return pesoTotal;
}

// Função para gerar uma solução inicial aleatória
vector<int> gerarSolucaoInicial(int N) {
    vector<int> solucao(N);
    for (int i = 0; i < N; ++i) {
        solucao[i] = rand() % 2; // 0 ou 1
    }
    return solucao;
}

// Função para gerar vizinhos (alternar bits)
vector<vector<int>> gerarVizinhos(const vector<int>& solucao) {
    vector<vector<int>> vizinhos;
    vector<int> temp = solucao;
    for (size_t i = 0; i < solucao.size(); ++i) {
        temp[i] = 1 - temp[i]; // Inverte o bit
        vizinhos.push_back(temp);
        temp[i] = 1 - temp[i]; // Restaura o bit
    }
    return vizinhos;
}

void hillClimbing(int capacidade, const vector<int>& pesos, const vector<int>& valores) {
    int N = pesos.size();
    vector<int> solucaoAtual = gerarSolucaoInicial(N);
    
    while (true) {
        vector<vector<int>> vizinhos = gerarVizinhos(solucaoAtual);
        vector<int> melhorVizinho;
        int valorMelhor = 0;

        bool encontrouMelhor = false;
        for (const auto& vizinho : vizinhos) {
            int pesoTotal = calcularPeso(pesos, vizinho);
            int valorTotal = calcularValor(valores, vizinho);
            
            if (pesoTotal <= capacidade && valorTotal > valorMelhor) {
                valorMelhor = valorTotal;
                melhorVizinho = vizinho;
                encontrouMelhor = true;
            }
        }

        if (encontrouMelhor) {
            solucaoAtual = melhorVizinho;
        } else {
            break;
        }
    }

    int valorFinal = calcularValor(valores, solucaoAtual);
    cout << "Valor máximo: " << valorFinal << endl;
    cout << "Itens selecionados: ";
    for (int i = 0; i < N; ++i) {
        if (solucaoAtual[i] == 1) {
            cout << i + 1 << " "; // Itens são numerados a partir de 1
        }
    }
    cout << endl;
}

void processarEntradaHC(const std::string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    int N, W;
    arquivo >> N >> W;  
    vector<int> pesos(N);
    vector<int> valores(W);

    cout << "vector pesos: " << N << endl;
    cout << "vector prices: " << W << endl;
   
    for (int i = 0; i < N; ++i) {
        arquivo >> pesos[i] >> valores[i];
       // cout << "pesos: " << pesos[i]<< endl;
        //cout <<"valores: "<< valores[i]<<endl;
    }

    arquivo.close();

    auto inicio = chrono::high_resolution_clock::now();
    hillClimbing(W, pesos, valores); 
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Arquivo: " << nomeArquivo << endl;
    cout << "Tempo de execução: " << duracao.count() << " segundos" << endl;
    cout << "-----------------------------" << endl;
}



int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    vector<string> arquivos = {"in1.txt","in2.txt","in3.txt"};


    for (const auto& arquivo : arquivos) {
        processarEntradaHC(arquivo);
    }

    return 0;
}
