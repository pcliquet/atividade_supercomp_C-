#include <iostream> 

int main() {
    double num1, num2; 
    char operacao;

    std::cout << "Insira o primeiro numero: ";
    std::cin >> num1;
    
    std::cout << "Insira o segundo numero: ";
    std::cin >> num2;
    

    std::cout << "Escolha a operacao (+, -, *, /): ";
    std::cin >> operacao;
    

    switch (operacao) {
        case '+':
            std::cout << "Resultado: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Resultado: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Resultado: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Resultado: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Erro: Divisao por zero nao e permitida!" << std::endl;
            }
            break;
        default:
            std::cout << "Operacao invalida!" << std::endl;
            break;
    }
    
    return 0;
}
