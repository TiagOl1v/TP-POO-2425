
#ifndef POO_CARAVANA_H
#define POO_CARAVANA_H


class Caravana {

    static int id;

    int LitrosAtual,MaxLitros;
    int tripulantes, MaxTripulantes;
    bool estaNaCidade;
    int posLinha, posColuna;
    int maxMov, movAtual;
    int MaxCarga, cargaAtual;

public:

    Caravana(int litrosAtual, int maxLitros, int tripulantes, int maxTripulantes, bool estaNaCidade, int posLinha,
             int posColuna, int maxMov, int movAtual, int MaxCarga, int cargaAtual);


};


#endif //POO_CARAVANA_H
