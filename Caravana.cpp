
#include "Caravana.h"
#include <ctime>
#include <algorithm>


int Caravana::geraID(){

    static std::vector<int> ids;
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int newID;
    bool flag;

    do {

        newID = std::rand() % 9999;

        // ID unico?
        flag= std::find(ids.begin(), ids.end(), newID) == ids.end();

    } while (!flag);

    // Adiciona o ID ao vetor
    ids.push_back(newID);

    return newID;
}

Caravana::Caravana(int litrosAtual, int maxLitros, int tripulantes,
                   int maxTripulantes, bool estaNaCidade, int posLinha,
                   int posColuna, int maxMov, int movAtual, int MaxCarga, int cargaAtual) : LitrosAtual(litrosAtual), MaxLitros(maxLitros),
                                                              tripulantes(tripulantes), MaxTripulantes(maxTripulantes),
                                                              estaNaCidade(estaNaCidade), posLinha(posLinha),
                                                              posColuna(posColuna), maxMov(maxMov),
                                                              movAtual(movAtual), MaxCarga(MaxCarga),
                                                              cargaAtual(cargaAtual){

   id = geraID();

}


bool Caravana::move(int numCasas){

    return true;
}

int Caravana::getId() const {
    return id;
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
};