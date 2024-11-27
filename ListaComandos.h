//
// Created by Utilizador on 11/22/2024.
//

#ifndef TP_POO2425_LISTACOMANDOS_H
#define TP_POO2425_LISTACOMANDOS_H

#include <iostream>
#include <map>
#include <functional>
#include <cmath>
#include <string>
#include "Game.h"


class ListaComandos {

    std::map<std::string, std::function<void(Game&, const std::string&)>> comandos;

public:

    ListaComandos();
    bool ExecutaComando(Game & J, std::string comando);


};


#endif //TP_POO2425_LISTACOMANDOS_H
