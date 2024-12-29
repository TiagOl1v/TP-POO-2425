
#ifndef POO_CARAVANA_H
#define POO_CARAVANA_H

#include <iostream>
#include <vector>

class Caravana {


    int idNoMapa;

    int tripulantes;
    bool estaNaCidade;
    int posLinha, posColuna;
    int maxMov, movAtual;


public:

    Caravana(int tripulantes, bool estaNaCidade, int posLinha,
             int posColuna, int maxMov, int movAtual);


   virtual bool move();
    virtual int batalha();
    virtual int AposCombate();
    int getTripulacao() const;
    void setTripulacao(int trip);
    int getPosLinha() const;
    int getPosColuna() const;

    void setIdNoMapa(int idNoMapa);
    virtual int getIdNoMapa() const;

    void setPosLinha(int posLinha);

    void resetMoves();

    bool isEstaNaCidade() const;

    void setEstaNaCidade(bool estaNaCidade);

    void setPosColuna(int posColuna);

    void setTripulacao2(int trip);
};


#endif //POO_CARAVANA_H
