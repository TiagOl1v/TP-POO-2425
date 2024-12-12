#include "Interface.h"
#include <string>
int main() {

    std::string  fichTXT, opcao;

    std::cout << "Insira um dos seguintes comandos:\nconfig <nomeFicheiro>\nsair\n" << std::endl;
    std::getline(std::cin,opcao );
    size_t espaco = opcao.find(' ');

    std::string primeira = opcao.substr(0, espaco);
    fichTXT = opcao.substr(espaco + 1);

    if(primeira == "sair")
        return 1;
    else if (primeira == "config")
        try {

            Game game(fichTXT);
            Interface interface(game);
            interface.start();

        }catch (const std::runtime_error& e) {
         std::cerr << "Exceção: " << e.what() << std::endl;
    }

    return 0;
}
