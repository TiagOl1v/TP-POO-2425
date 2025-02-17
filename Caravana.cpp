
#include "Caravana.h"
#include <ctime>
#include <algorithm>



Caravana::Caravana(int tripulantes, bool estaNaCidade, int posLinha,
                   int posColuna, int maxMov, int movAtual) :
                                                              tripulantes(tripulantes),
                                                              estaNaCidade(estaNaCidade), posLinha(posLinha),
                                                              posColuna(posColuna), maxMov(maxMov),
                                                              movAtual(movAtual){


}


bool Caravana::move(){

    if(movAtual + 1  < maxMov){
        ++movAtual;
        return true;
    }else
        return false;

}

int Caravana::getTripulacao() const{
    return tripulantes;
}

void Caravana::setTripulacao(int trip) {
    tripulantes += trip;
}


int Caravana::getPosLinha() const {
    return posLinha;
}

int Caravana::getPosColuna() const {
    return posColuna;
}

void Caravana::setIdNoMapa(int idNoMapa) {
    Caravana::idNoMapa = idNoMapa;
}

int Caravana::getIdNoMapa() const {
    return idNoMapa;
}

void Caravana::setPosLinha(int posLinha) {
    Caravana::posLinha = posLinha;
}

void Caravana::setPosColuna(int posColuna) {
    Caravana::posColuna = posColuna;
}

bool Caravana::isEstaNaCidade() const {
    return estaNaCidade;
}

void Caravana::setEstaNaCidade(bool estaNaCidade) {
    Caravana::estaNaCidade = estaNaCidade;
};

void Caravana::resetMoves(){
    movAtual = 0;
}
int Caravana::batalha(){

    int numS = std::rand() % tripulantes;

    return numS;
}

int Caravana::AposCombate(){

    int outroTrip = tripulantes - (int)(tripulantes * 0.50);
    tripulantes = tripulantes - (int)(tripulantes * 0.20);
    return outroTrip;
}

void Caravana::setTripulacao2(int trip) {
    tripulantes = trip;
}