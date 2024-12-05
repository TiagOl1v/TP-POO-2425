//
// Created by Utilizador on 11/17/2024.
//

#include "Buffer.h"

Buffer::Buffer(int a, int l):altura(a), largura(l) {

    std::cout << altura;

    mapa = new char*[altura];
    for (int i = 0; i < altura; ++i)
        mapa[i] = new char[largura+1];
}

char* Buffer::operator[](int linha) {
    return mapa[linha];
}

const char* Buffer::operator[](int linha) const {

    return mapa[linha];
}

Buffer::~Buffer() {
    for (int i = 0; i < altura; ++i) {
        delete[] mapa[i];
    }
    delete[] mapa;
}