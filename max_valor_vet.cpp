#include <iostream> 

int main() {
    int numeros[10];
    int maior;    

    std::cout << "Insira 10 numeros:" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cin >> numeros[i]; 
    }

    maior = numeros[0];

    for(int i = 1; i < 10; i++) {
        if(numeros[i] > maior) {
            maior = numeros[i]; 
        }
    }


    std::cout << "O maior numero e: " << maior << std::endl;

    return 0; 
}
