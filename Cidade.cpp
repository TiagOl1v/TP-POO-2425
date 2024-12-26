#include "Cidade.h"

Cidade::Cidade(char cidade, int posLinha, int posColuna) : cidade(cidade), posLinha(posLinha), posColuna(posColuna) {

    std::cout << "LOG: cidade criada: " << cidade << " linha:" << posLinha << "coluna:" << posColuna << std::endl;
        Caravanas.push_back(std::make_unique<CarvComercio>(posLinha,posColuna));

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
