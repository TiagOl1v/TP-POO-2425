#include "Cidade.h"

Cidade::Cidade(char cidade, int posLinha, int posColuna) : cidade(cidade), posLinha(posLinha), posColuna(posColuna) {


    std::cout << "LOG: cidade criada: " << cidade << " linha:" << posLinha << "coluna:" << posColuna;
        Caravanas.push_back(std::make_unique<CarvComercio>(posLinha,posColuna));


}

char Cidade::getCidade() const {

    return cidade;
}

std::string Cidade::compraCaravana( std::vector<std::unique_ptr<Caravana>>& GameCarv, char tipo){

    auto it = Caravanas.begin();

    while (it != Caravanas.end()) {

        if (dynamic_cast<CarvComercio*>(it->get()) && tipo == 'C') {

            GameCarv.push_back(std::move(*it));

            it = Caravanas.erase(it);

            return "yes";

        }
            ++it;

    }

}