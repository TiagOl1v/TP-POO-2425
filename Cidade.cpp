#include "Cidade.h"

Cidade::Cidade(char cidade, int posLinha, int posColuna) : cidade(cidade), posLinha(posLinha), posColuna(posColuna) {

        Caravanas.push_back(std::make_unique<CarvComercio>(posLinha,posColuna));
        Caravanas.push_back(std::make_unique<CarvMilitar>(posLinha,posColuna));
        Caravanas.push_back(std::make_unique<CarvSecreta>(posLinha,posColuna));
}

char Cidade::getCidade() const {

    return cidade;
}

bool Cidade::compraCaravana( std::vector<std::unique_ptr<Caravana>>& GameCarv, char tipo,int numberMapa){

    auto it = Caravanas.begin();

    while (it != Caravanas.end()) {

        if (dynamic_cast<CarvComercio*>(it->get()) && tipo == 'C') {

            GameCarv.push_back(std::move(*it));

            GameCarv.back()->setIdNoMapa(numberMapa);

            return true;

        }
        if (dynamic_cast<CarvSecreta*>(it->get()) && tipo == 'S') {

            GameCarv.push_back(std::move(*it));

            GameCarv.back()->setIdNoMapa(numberMapa);

            return true;

        }
        if (dynamic_cast<CarvMilitar*>(it->get()) && tipo == 'M') {

            GameCarv.push_back(std::move(*it));

            GameCarv.back()->setIdNoMapa(numberMapa);

            return true;

        }

            ++it;

    }
    return false;

}

int Cidade::getPosLinha() const {
    return posLinha;
}

int Cidade::getPosColuna() const {
    return posColuna;
}
