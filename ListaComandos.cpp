
#include "ListaComandos.h"

bool isNumber(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}


void scriptComandsTXT(Game& jogo, const std::string& arg) {
        std::cout << "Ficheiro a ler: " << arg << "!" << std::endl;
}

void avancaInst(Game& jogo, const std::string& arg) {

    if((isNumber(arg))){
        int num = stoi(arg);
        std::cout << "Vai avancar " << num;
        for (int i = 0; i < num; ++i) {
            jogo.novoTurno();
        }


    }
    else
        std::cout << "Argumentos incorretos";
}

void CompraCaravana(Game& jogo, const std::string& arg) {
    size_t spacePos = arg.find(' ');

    if (arg.empty()) {
        std::cout << "Argumentos invalidos: comprac <Nome cidade> <Tipo>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);

        // Verifica se cada argumento tem exatamente um char
        if (firstArg.size() != 1 || secondArg.size() != 1) {

            std::cout << "Argumentos invalidos: comprac <Nome cidade> <Tipo> " << std::endl;
        } else {
            jogo.compraCaravana(firstArg[0],secondArg[0]);
            std::cout << "Primeiro char: " << firstArg[0] << "\nSegundo char: " << secondArg[0] << std::endl;

        }
    }
}

void ListaPrecos(Game& jogo, const std::string& arg) {
    jogo.MostraCarv();
        if (arg.empty())
          jogo.MostraCarv();

        else
            std::cout << "Argumentos invalidos: precos" << std::endl;

}

void ListaConteudo(Game& jogo, const std::string& arg) {

        if (arg.size() != 1) {
            std::cout << "Argumentos invalidos: cidade <Nome cidade> " << std::endl;
        } else {
            std::cout << "Primeiro char: " << arg[0] << std::endl;
        }
    }

void MostraDetalhesCaravana(Game& jogo, const std::string& arg) {

    if((isNumber(arg))){
        int num = stoi(arg);
        std::cout << "id caravana " << num;
    }
    else
        std::cout << "Argumentos incorretos";

}

void CompraMercadoria(Game& jogo, const std::string& arg) {

    size_t spacePos = arg.find(' ');

    if (arg.empty()) {
        std::cout << "Argumentos invalidos: compra <Numero de toneladas> <ID Caravana>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);
        if((isNumber(firstArg)) && (isNumber(secondArg)) ){
            int numToneladas = stoi(firstArg);
            int idCaravana = stoi(secondArg);
            std::cout << "toneladas: " << numToneladas << "id caravana " << idCaravana;
        } else{
            std::cout << "Argumentos invalidos: compra <Numero de toneladas> <ID Caravana>" << std::endl;
        }
    }
}

void vendeMercadoria(Game& jogo, const std::string& arg) {

    if((isNumber(arg))){
        int num = stoi(arg);
        std::cout << "id caravana " << num;
    }
    else
        std::cout << "Argumentos incorretos";
}

void moveCaravana(Game& jogo, const std::string& arg) {

    size_t spacePos = arg.find(' ');

    if (arg.empty()) {
        std::cout << "Argumentos invalidos: move <ID Caravana> <Direcao>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);
        if((isNumber(firstArg)) && secondArg.size()  == 1 ){
            int idCaravana = stoi(firstArg);
            std::cout << "Caravana com ID: " << idCaravana << "na direcao: " << secondArg;
        } else{
            std::cout << "Argumentos invalidos: move <ID Caravana> <Direcao>" << std::endl;
        }
    }
}

void mostraAllMyCarav(Game& jogo, const std::string& arg) {

    if (arg == "minhasc"){
        jogo.MostraCarv();
    }
    else
        std::cout << "Argumentos incorretos";

}

void AltMoedas(Game& jogo, const std::string& arg) {

    if((isNumber(arg))){
        int num = stoi(arg);
        jogo.setMoedas(num);
    }
    else
        std::cout << "Argumentos incorretos";

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
            {"move", moveCaravana},
            {"moedas", AltMoedas},
            {"minhasc", mostraAllMyCarav},

    };

}

bool ListaComandos::ExecutaComando(Game &J, std::string comando) {

    J.setHouveAlt(false);
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
    }

    return J.isHouveAlt();

}
