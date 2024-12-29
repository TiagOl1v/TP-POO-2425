
#include "CarvComercio.h"

CarvComercio::CarvComercio(int l, int c): Caravana(20,true,l,c,10,0), LitrosAtual(0),
                                            MaxLitros(200) , MaxCarga(40), cargaAtual(0){

}

int CarvComercio::getMaxCarga() const {
    return MaxCarga;
}

int CarvComercio::getcargaAtual() const {
    return cargaAtual;
}

void CarvComercio::setcargaAtual(int carga) {
    cargaAtual += carga;
}

void CarvComercio::zeracargaAtual() {
    cargaAtual = 0;
}

