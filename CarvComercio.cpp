
#include "CarvComercio.h"

CarvComercio::CarvComercio(int l, int c): Caravana(20,20,true,l,c,2,0), LitrosAtual(0),
                                            MaxLitros(200) , MaxCarga(40), cargaAtual(0){

}

bool CarvComercio::move(int numCasas){

    return true;
}