
#ifndef TP_POO2425_CARVMILITAR_H
#define TP_POO2425_CARVMILITAR_H

#include "Caravana.h"
class CarvMilitar : public Caravana {

    int idNoMapa;
    int LitrosAtual,MaxLitros;
    int MaxCarga, cargaAtual;

public:
    CarvMilitar(int l, int c);
    int getMaxCarga() const;
    int getcargaAtual() const;
    void setcargaAtual(int carga);
    void zeracargaAtual();
};

#endif //TP_POO2425_CARVMILITAR_H
