
#include "Interface.h"

Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos(),jogo(&jogo) {}

void Interface::AtualizaMapa(){

    for (int i = 0; i < jogo->getLinhas(); ++i) {
        for (int j = 0; j <jogo->getColunas(); ++j) {
            buffer[i][j]= (*jogo)[i][j];
        }
    }
}

void Interface::start() {

    std::string comand;

    do {
        jogo->novoTurno();
        std::getline(std::cin, comand);  // Lê a linha inteira até o enter
        buffer.setInfo(jogo->getLogs());
        if(comandos.ExecutaComando(*jogo,comand)){
            AtualizaMapa();
            std::cout << buffer;
        }
        else
        std::cout << buffer.getInfo();

    } while (comand != "sair");
}