#include <iostream>   
#include <fstream>   
#include <sstream>    
#include <map>       
#include <string>     
#include <vector>    
#include <algorithm>  

int main() {
    std::ifstream arquivo_entrada("entrada.txt"); 
    std::ofstream arquivo_saida("estatisticas.txt"); 

    if (!arquivo_entrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    if (!arquivo_saida.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl;
        return 1;
    }

    std::string linha;
    int total_linhas = 0;
    int total_palavras = 0;
    std::map<std::string, int> contagem_palavras;

    while (std::getline(arquivo_entrada, linha)) {
        total_linhas++;
        std::istringstream iss(linha);
        std::string palavra;
        int palavras_na_linha = 0;

        while (iss >> palavra) {
            palavras_na_linha++;
            total_palavras++;
            contagem_palavras[palavra]++;
        }

        std::string palavra_mais_frequente;
        int max_freq = 0;
        for (const auto& p : contagem_palavras) {
            if (p.second > max_freq) {
                max_freq = p.second;
                palavra_mais_frequente = p.first;
            }
        }


        double media_palavras_por_linha = total_linhas > 0 ? static_cast<double>(total_palavras) / total_linhas : 0;


        arquivo_saida << "Número total de linhas: " << total_linhas << std::endl;
        arquivo_saida << "Número total de palavras: " << total_palavras << std::endl;
        arquivo_saida << "Número médio de palavras por linha: " << media_palavras_por_linha << std::endl;
        arquivo_saida << "Palavra mais frequente: " << palavra_mais_frequente << " (ocorrências: " << max_freq << ")" << std::endl;
    }

    arquivo_entrada.close();
    arquivo_saida.close();

    return 0;
}
