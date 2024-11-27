//
// Created by Utilizador on 11/17/2024.
//

#include "Buffer.h"

Buffer::Buffer(int a, int l):altura(a), largura(l) {

    mapa = new char*[altura];
    for (int i = 0; i < altura; ++i)
        mapa[i] = new char[largura+1];

}

void Buffer::print() const {
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            std::cout << mapa[i][j];
        }
        std::cout << '\n';
    }
}

Buffer::~Buffer() {
    for (int i = 0; i < altura; ++i) {
        delete[] mapa[i];
    }
    delete[] mapa;
}