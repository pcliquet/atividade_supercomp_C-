#include <iostream> // Inclui a biblioteca de entrada e saída

void bubbleSort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[10]; 


    std::cout << "Insira 10 numeros:" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cin >> numeros[i];  
    }
    bubbleSort(numeros, 10);

    std::cout << "Vetor ordenado em ordem crescente:" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
