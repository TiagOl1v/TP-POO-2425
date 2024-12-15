
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