#include <algorithm>
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
          jogo.MostraPmerc();
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
        std::cout << "Argumentos invalidos: compra <ID Caravana> <Numero de toneladas>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);
        if((isNumber(firstArg)) && (isNumber(secondArg)) ){
            int idCaravana = stoi(firstArg);
            int numToneladas = stoi(secondArg);
            jogo.compraMercadoria(idCaravana, numToneladas);
            std::cout << "id caravana " << idCaravana << "toneladas: " << numToneladas ;

        } else{
            std::cout << "Argumentos invalidos: compra <ID Caravana> <Numero de toneladas>" << std::endl;
        }
    }
}

void vendeMercadoria(Game& jogo, const std::string& arg) {

    if((isNumber(arg))){
        int num = stoi(arg);
        jogo.vendeMercadoria(num);
        std::cout << "id caravana " << num;
    }
    else
        std::cout << "Argumentos incorretos";
}

void CompraTripulacao(Game& jogo, const std::string& arg) {

    size_t spacePos = arg.find(' ');

    if (arg.empty()) {
        std::cout << "Argumentos invalidos: compra <ID Caravana> <Numero de tripulantes>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);
        if((isNumber(firstArg)) && (isNumber(secondArg)) ){
            int idCaravana = stoi(firstArg);
            int numTripulantes = stoi(secondArg);
            jogo.compraTripulantes(idCaravana, numTripulantes);
            std::cout << "id caravana " << idCaravana << "tripulantes: " << numTripulantes ;

        } else{
            std::cout << "Argumentos invalidos: compra <ID Caravana> <Numero de tripulantes>" << std::endl;
        }
    }
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
            jogo.MoveCaravana(idCaravana,secondArg[0]);
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

void CreateB(Game& jogo, const std::string& arg) {

    size_t spacePos = arg.find(' ');

    if (arg.empty()) {
        std::cout <<  "Argumentos invalidos: barbaro <linha> <coluna>" << std::endl;
    } else {
        std::string firstArg = arg.substr(0, spacePos);
        std::string secondArg = arg.substr(spacePos + 1);
        if ((isNumber(firstArg)) && (isNumber(secondArg))) {

            int L = stoi(firstArg);
            int C = stoi(secondArg);
            jogo.CreateBarber(L,C);

        } else {
            std::cout << "Argumentos invalidos: barbaro <linha> <coluna>" << std::endl;
        }
    }
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
            {"tripul", CompraTripulacao},
            {"vende", vendeMercadoria},
            {"move", moveCaravana},
            {"moedas", AltMoedas},
            {"minhasc", mostraAllMyCarav},
            {"barbaro", CreateB},

    };

}

bool ListaComandos::ExecutaComando(Game &J, std::string comando) {

    J.setHouveAlt(false);
    J.resetLogs();

    std::string com;
    std::string argumentos;
    size_t pos = comando.find(' ');

    com = comando.substr(0, pos);

    argumentos = comando.substr(pos + 1);
    auto it = comandos.find(com);
    if (it != comandos.end()) {
        std::stringstream ss(argumentos);
        it->second(J, argumentos);
    }

    return J.isHouveAlt();

}
