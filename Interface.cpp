
#include "Interface.h"



Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos(),jogo(&jogo) {}


void Interface::DeleUmacopia (std::string arg){

    auto it = bufferMap.find(arg);
    if (it == bufferMap.end()) {
        std::cout << "Copia '" << arg << "' não encontrada.\n";
        return;
    }

    bufferMap.erase(it);
    std::cout << "Copia '" << arg << "' removida com sucesso.\n";


}
void Interface::mostraUmacopia(std::string arg){

    auto it = bufferMap.find(arg);
    if (it == bufferMap.end()) {
        std::cout << "Cópia '" << arg << "' não encontrada.\n";
        return;
    }

    std::cout << "Conteúdo da cópia '" << arg << "':\n" << it->second << "\n";
}

void Interface::MostraAllCop(){

    if (bufferMap.empty()) {
        std::cout << "Não há cópias no mapa.\n";
        return;
    }

    std::cout << "Cópias no mapa:\n";
    for (const auto& pair : bufferMap) {
        std::cout << "- " << pair.first << "\n";
    }

}

void Interface::CriaUmacopia(std::string arg){


    if (bufferMap.find(arg) != bufferMap.end()) {
        std::cout << "Cópia '" << arg << "' já existe.\n";
        return;
    }

    bufferMap.emplace(arg, buffer);
    std::cout << "Cópia '" << arg << "' adicionada com sucesso.\n";
}

bool Interface::InterageMapa(std::string comando){

    bool flag = false;

    std::string cmd;
    std::string argumentos;
    size_t pos = comando.find(' ');

    cmd = comando.substr(0, pos);
    argumentos = comando.substr(pos + 1);
    if(cmd == "loads"){
        mostraUmacopia(argumentos);
        flag = true;
    }else if(cmd == "dels"){
        DeleUmacopia(argumentos);
        flag = true;
    }else if (cmd == "list"){
        MostraAllCop();
        flag = true;
    } else if(cmd == "save"){
        CriaUmacopia(argumentos);
        flag = true;
    }

    return flag;
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
            if(!InterageMapa(comand)){
            buffer.setInfo(jogo->getLogs());
            std::cout << buffer.getInfo();
            }
        }
    } while (comand != "sair");
}