#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>


using namespace std;


int mochila(int W, const vector<int>& pesos, const vector<int>& valores, int n) {
  
    if (n == 0 || W == 0) {
        return 0;
    }

    if (pesos[n-1] > W) {
        return mochila(W, pesos, valores, n-1);
    } 
    return max(mochila(W, pesos, valores, n-1),
               valores[n-1] + mochila(W - pesos[n-1], pesos, valores, n-1));
}


void processarEntrada(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    int N, W;
    arquivo >> N >> W;

    vector<int> pesos(N);
    vector<int> valores(N);

    for (int i = 0; i < N; ++i) {
        arquivo >> pesos[i] >> valores[i];
    }

    arquivo.close();

    auto inicio = chrono::high_resolution_clock::now();
    int maxValor = mochila(W, pesos, valores, N);
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Arquivo: " << nomeArquivo << endl;
    cout << "Valor maximo: " << maxValor << endl;
    cout << "Tempo de execucao: " << duracao.count() << " segundos" << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    vector<string> arquivos = {"in1.txt", "in2.txt", "in3.txt", "in4.txt"};
    for (const auto& arquivo : arquivos) {
        processarEntrada(arquivo);
    }
    return 0;
}