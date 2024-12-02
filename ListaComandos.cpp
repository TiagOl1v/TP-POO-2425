//
// Created by Utilizador on 11/22/2024.
//

#include "ListaComandos.h"

void scriptComandsTXT(Game& jogo, const std::string& arg) {

        std::cout << "Ficheiro a ler: " << arg << "!" << std::endl;


}

void avancaInst(Game& jogo, const std::string& arg) {

    if((stoi(arg))){
        int num = stoi(arg);
        std::cout << "Vai avancar " << num;
    }
    else
        std::cout << "Argumentos incorretos";
}

void CompraCaravana(Game& jogo, const std::string& arg) {
    size_t spacePos = arg.find(' ');

    if (spacePos == std::string::npos) {
        std::cout << "Argumentos invalidos: comprac <Nome cidade> <Tipo>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);

        // Verifica se cada argumento tem exatamente um char
        if (firstArg.size() != 1 || secondArg.size() != 1) {
            std::cout << "Argumentos invalidos: comprac <Nome cidade> <Tipo> " << std::endl;
        } else {
            std::cout << "Primeiro char: " << firstArg[0] << "\nSegundo char: " << secondArg[0] << std::endl;
        }
    }
}

void ListaPrecos(Game& jogo, const std::string& arg) {

    size_t spacePos = arg.find(' ');

        if (spacePos != std::string::npos) {
        std::cout << "Argumentos invalidos: precos" << std::endl;
        }

}

void ListaConteudo(Game& jogo, const std::string& arg) {
    size_t spacePos = arg.find(' ');

    if (spacePos == std::string::npos) {
        std::cout << "Argumentos invalidos: cidade <Nome cidade>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);

        // Verifica se cada argumento tem exatamente um char
        if (firstArg.size() != 1 || secondArg.size() >= 0) {
            std::cout << "Argumentos invalidos: cidade <Nome cidade> " << std::endl;
        } else {
            std::cout << "Primeiro char: " << firstArg[0] << std::endl;
        }
    }
}
}

void MostraDetalhesCaravana(Game& jogo, const std::string& arg) {


}

void CompraMercadoria(Game& jogo, const std::string& arg) {

}

void vendeMercadoria(Game& jogo, const std::string& arg) {

}

ListaComandos::ListaComandos(){

    comandos = {

            {"exec", scriptComandsTXT},
            {"prox", avancaInst},
            {"comprac", CompraCaravana},
            {"precos", ListaPrecos},
            {"cidade", ListaConteudo},
            {"caravana", MostraDetalhesCaravana},
            {"compra", CompraMercadoria},
            {"vende", vendeMercadoria},

    };

}

bool ListaComandos::ExecutaComando(Game &J, std::string comando) {

    std::string com;
    std::string argumentos;
    size_t pos = comando.find(' ');

    com = comando.substr(0, pos);

    // Extrai os argumentos (parte apos o espaço)
    argumentos = comando.substr(pos + 1);
    auto it = comandos.find(com);
    if (it != comandos.end()) {
        std::stringstream ss(argumentos);
        it->second(J, argumentos);
        return true;
    } else
        return false;


}
