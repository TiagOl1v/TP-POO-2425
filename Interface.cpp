
#include "Interface.h"



Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos(),jogo(&jogo) {}

void Interface::InterageMapa(std::string comando){

};

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

        std::getline(std::cin, comand);  // Lê a linha inteira até o enter

        if(comandos.ExecutaComando(*jogo,comand)){
            buffer.setInfo(jogo->getLogs());
            AtualizaMapa();
            std::cout << buffer;
        }
        else{
            InterageMapa(comand);
            buffer.setInfo(jogo->getLogs());
            std::cout << buffer.getInfo();
        }
    } while (comand != "sair");
}