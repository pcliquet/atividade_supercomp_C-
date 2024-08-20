#include <iostream>

int main() {
    int matriz[3][3];
    int soma = 0;     

    std::cout << "Insira os elementos da matriz 3x3:" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> matriz[i][j]; 
        }
    }


    for(int i = 0; i < 3; i++) {
        soma += matriz[i][i];  
    }

    std::cout << "A soma dos elementos da diagonal principal e: " << soma << std::endl;

    return 0; 
}