
#include "Interface.h"

Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos(),jogo(&jogo) {}

void Interface::AtualizaMapa(){

    for (int i = 0; i < jogo->getLinhas(); ++i) {
        for (int j = 0; j <jogo->getColunas(); ++j) {
            buffer[i][j]= (*jogo)[i][j];
        }
    }
    buffer.setInfo(jogo->getLogs());

}

void Interface::start() {

    std::string comand;

    do {

        jogo->novoTurno();
        std::getline(std::cin, comand);  // Lê a linha inteira até o enter
        comandos.ExecutaComando(*jogo,comand);
        AtualizaMapa();

        std::cout << buffer;

    } while (comand != "sair");
}