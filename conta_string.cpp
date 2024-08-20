#include <iostream>  
#include <string>  //manipulação de strings

int main() {
    std::string texto; 


    std::cout << "Insira uma string: ";
    std::getline(std::cin, texto);  


    std::cout << "O numero de caracteres na string e: " << texto.length() << std::endl;

    return 0; 
}
