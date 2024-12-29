#include "CarvMilitar.h"

CarvMilitar::CarvMilitar(int l, int c): Caravana(40,true,l,c,3,0), LitrosAtual(0),
                                        MaxLitros(400) , MaxCarga(5), cargaAtual(0){
}
int CarvMilitar::getMaxCarga() const {
    return MaxCarga;
}

int CarvMilitar::getcargaAtual() const {
    return cargaAtual;
}

void CarvMilitar::setcargaAtual(int carga) {
    cargaAtual += carga;
}

void CarvMilitar::zeracargaAtual() {
    cargaAtual = 0;
}




