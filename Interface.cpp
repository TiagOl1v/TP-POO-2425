//
// Created by Utilizador on 11/22/2024.
//

#include "Interface.h"


Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos() {}

void Interface::start() {

    std::string comand;

    do {
    std::getline(std::cin, comand);  // Lê a linha inteira até o enter

    comandos.ExecutaComando(*jogo,comand);
    } while (comand != "sair");
}