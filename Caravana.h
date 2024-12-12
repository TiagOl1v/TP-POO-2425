
#ifndef POO_CARAVANA_H
#define POO_CARAVANA_H

#include <iostream>
#include <vector>

class Caravana {

    static std::vector<int> ids;
    int id;

    int LitrosAtual,MaxLitros;
    int tripulantes, MaxTripulantes;
    bool estaNaCidade;
    int posLinha, posColuna;
    int maxMov, movAtual;
    int MaxCarga, cargaAtual;

    int geraID();
public:

    Caravana(int litrosAtual, int maxLitros, int tripulantes, int maxTripulantes, bool estaNaCidade, int posLinha,
             int posColuna, int maxMov, int movAtual, int MaxCarga, int cargaAtual);

    Caravana();
   virtual bool move(int numCasas);
   virtual int getId() const;

    int getPosLinha() const;

    int getPosColuna() const;


};


#endif //POO_CARAVANA_H
