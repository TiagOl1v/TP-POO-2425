
#include "Buffer.h"

Buffer::Buffer(int a, int l):altura(a), largura(l) {

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

Buffer::Buffer(const Buffer& other) : largura(other.largura), altura(other.altura), info(other.info) {
    mapa = new char*[altura];
    for (int i = 0; i < altura; ++i) {
        mapa[i] = new char[largura + 1];
        std::copy(other.mapa[i], other.mapa[i] + largura + 1, mapa[i]);
    }
}

Buffer& Buffer::operator=(const Buffer& other) {
    if (this == &other) return *this; // Evita auto-atribuição

    // Libera os recursos existentes
    for (int i = 0; i < altura; ++i) {
        delete[] mapa[i];
    }
    delete[] mapa;

    // Copia os valores do outro Buffer
    largura = other.largura;
    altura = other.altura;
    info = other.info;

    mapa = new char*[altura];
    for (int i = 0; i < altura; ++i) {
        mapa[i] = new char[largura + 1];
        std::copy(other.mapa[i], other.mapa[i] + largura + 1, mapa[i]);
    }

    return *this;
}

Buffer::~Buffer() {
    for (int i = 0; i < altura; ++i) {
        delete[] mapa[i];
    }
    delete[] mapa;
}

int Buffer::getLargura() const {
    return largura;
}

int Buffer::getAltura() const {
    return altura;
}

void Buffer::setInfo(const std::ostringstream &info) {
    Buffer::info = info.str();
}

const std::string &Buffer::getInfo() const {
    return info;
}


std::ostream &operator<<(std::ostream &os, const Buffer &buf){

    for (int i = 0; i < buf.getAltura(); ++i) {
        for (int j = 0; j < buf.getLargura(); ++j) {
            os << buf[i][j];
        }
        os << std::endl;
    }

    os << "OUTPUT COMANDO\n" << buf.getInfo();

    return os;
}