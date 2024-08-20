#include <iostream>

int main() {
    int numeros[5]; 
    int soma = 0;  


    std::cout << "Insira 5 numeros:" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cin >> numeros[i]; 
        soma += numeros[i];
    }

    std::cout << "A soma dos numeros e: " << soma << std::endl;

    return 0; 
