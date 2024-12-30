#include "CarvSecreta.h"

CarvSecreta::CarvSecreta(int l, int c): Caravana(40,true,l,c,100,0), LitrosAtual(0),
                                          MaxLitros(100) , MaxCarga(40), cargaAtual(0){

}

int CarvSecreta::getMaxCarga() const {
    return MaxCarga;
}

int CarvSecreta::getcargaAtual() const {
    return cargaAtual;
}

void CarvSecreta::setcargaAtual(int carga) {
    cargaAtual += carga;
}

void CarvSecreta::zeracargaAtual() {
    cargaAtual = 0;
}


int CarvSecreta::batalha() {
    int numS = std::rand() % this->getTripulacao();
    numS = numS * 2;
    return numS;
}