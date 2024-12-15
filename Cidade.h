
#ifndef TP_POO2425_CIDADE_H
#define TP_POO2425_CIDADE_H

#include "CarvBarbaros.h"
#include "CarvComercio.h"
#include "CarvMilitar.h"
#include <vector>
#include <memory>

class Cidade {

    char cidade;//char que identifica a cidade
    std::vector<std::unique_ptr<Caravana>> Caravanas;
    int posLinha, posColuna;

public:
    Cidade(char cidade, int posLinha, int posColuna);

    char getCidade() const;
    bool compraCaravana( std::vector<std::unique_ptr<Caravana>> & GameCarv, char tipo, int numberMapa);
};


#endif //TP_POO2425_CIDADE_H
