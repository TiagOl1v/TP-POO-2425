

#ifndef TP_POO2425_CARVCOMERCIO_H
#define TP_POO2425_CARVCOMERCIO_H

#include "Caravana.h"

class CarvComercio : public Caravana{

    int LitrosAtual,MaxLitros;
    int MaxCarga, cargaAtual;
    int maxTripulantes;


public:
    CarvComercio(int l, int c);
    int getMaxCarga() const;
    int getcargaAtual() const;
    void setcargaAtual(int carga);
    void zeracargaAtual();

};


#endif //TP_POO2425_CARVCOMERCIO_H
