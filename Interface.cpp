
#include "Interface.h"



Interface::Interface(Game & jogo): buffer(jogo.getLinhas(),jogo.getColunas()),comandos(),jogo(&jogo) {}


void Interface::DeleUmacopia (std::string arg){

}
void Interface::mostraUmacopia(std::string arg){

}
void Interface::MostraAllCop(){

}
void Interface::CriaUmacopia(std::string arg){

}

bool Interface::InterageMapa(std::string comando){

    bool flag = false;

    std::string cmd;
    std::string argumentos;
    size_t pos = comando.find(' ');

    cmd = comando.substr(0, pos);

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