
#ifndef TP_POO2425_BUFFER_H
#define TP_POO2425_BUFFER_H

#include <iostream>
#include "Game.h"

class Buffer {

    int largura=0, altura=0;
    char **mapa = nullptr;
    std::string info;

public:
    Buffer(int a, int l);
    ~Buffer();

    int getLargura() const;

    int getAltura() const;

    char* operator[](int linha);
    const char* operator[](int linha) const;

    void setInfo(const std::ostringstream &info);

    const std::string &getInfo() const;


};

std::ostream &operator<<(std::ostream &os, const Buffer &buf);

#endif //TP_POO2425_BUFFER_H
