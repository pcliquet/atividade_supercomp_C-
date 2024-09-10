#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>


struct Item {
    int peso;
    int valor;
};

bool maior_valor(const Item& a, const Item& b){
    return a.valor > b.valor;
}

bool menor_valor(const Item& a, const Item& b){
    return a.peso < b.peso;
}


int mochilaGananciosa(int capacidade, std::vector<Item>& itens, int tipo){
    if(tipo == 1){
        std::sort(itens.begin(), itens.end(), maior_valor);

    }
    else{
        std::sort(itens.begin(), itens.end(), menor_valor);

    }
    int valorTotal = 0;
    int pesoAtual = 0;

    for (const Item& item: itens){
        if(pesoAtual + item.peso <= capacidade){
            valorTotal += item.valor;
            pesoAtual += item.peso;
        }
    }

    return valorTotal;
}




bool lerDadosDoArquivo(const std::string& nomeArquivo, std::vector<Item>& itens, int& capacidade){
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }
    std::string linha;
    std::getline(arquivo, linha);
    std::istringstream iss(linha);
    size_t numItens;
    iss >> numItens >> capacidade;

    itens.resize(numItens);
    for(size_t i = 0; i< numItens; ++i){
        if(std::getline(arquivo, linha)){
            std::istringstream itemStream(linha);
            Item item;
            if(itemStream >> item.peso >> item.valor){
                itens[i] = item;

            }
            
        }

    }



    arquivo.close();
    return true;
}


int main(){
    std::vector<std::string> arquivos = {"in1.txt", "in2.txt", "in3.txt"};
    for(const auto& arquivo : arquivos){
        std::vector<Item> itens;
        int capacidade;
        std:: cerr << "itens: " << arquivo << std::endl;
        if (!lerDadosDoArquivo(arquivo, itens, capacidade)) {
            std::cerr << "Falha ao ler o arquivo: " << arquivo << std::endl;
            continue; // Pular para o próximo arquivo se houver erro
        }        

        int valorMaximo = mochilaGananciosa(capacidade, itens, 0);

        std::cout << "valor maximo: " << valorMaximo << std::endl;


    }


    return 0;
}
