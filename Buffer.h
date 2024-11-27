//
// Created by Utilizador on 11/17/2024.
//

#ifndef TP_POO2425_BUFFER_H
#define TP_POO2425_BUFFER_H

#include <iostream>
#include "Game.h"

class Buffer {

    int largura=0, altura=0;
    char **mapa = nullptr;

public:
    Buffer(int a, int l);
    ~Buffer();
    void print()const;
};


#endif //TP_POO2425_BUFFER_H
