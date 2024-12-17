
#ifndef POO_CARAVANA_H
#define POO_CARAVANA_H

#include <iostream>
#include <vector>

class Caravana {


    int id;
    int idNoMapa;

    int tripulantes;
    bool estaNaCidade;
    int posLinha, posColuna;
    int maxMov, movAtual;


    int geraID();

public:

    Caravana(int tripulantes, bool estaNaCidade, int posLinha,
             int posColuna, int maxMov, int movAtual);


   virtual bool move(int numCasas);
   virtual int getId() const;

    int getPosLinha() const;
    int getPosColuna() const;

    void setIdNoMapa(int idNoMapa);
    virtual int getIdNoMapa() const;
};


#endif //POO_CARAVANA_H
