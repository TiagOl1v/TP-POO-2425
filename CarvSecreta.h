#ifndef TP_POO2425_CARVSECRETA_H
#define TP_POO2425_CARVSECRETA_H
#include "Caravana.h"

class CarvSecreta : public Caravana{

    int LitrosAtual,MaxLitros;
    int MaxCarga, cargaAtual;
    int maxTripulantes;


public:
    CarvSecreta(int l, int c);

    int batalha() override;

};


#endif //TP_POO2425_CARVSECRETA_H
