

#ifndef TP_POO2425_INTERFACE_H
#define TP_POO2425_INTERFACE_H

#include "ListaComandos.h"
#include "Buffer.h"
#include <vector>

class Interface {

    Game *jogo;
    Buffer buffer;
    ListaComandos comandos;

    std::map<std::string, Buffer> bufferMap;

    void AtualizaMapa();

    void DeleUmacopia (std::string arg);
    void mostraUmacopia(std::string arg);
    void MostraAllCop();
    void CriaUmacopia(std::string arg);

    bool InterageMapa(std::string comando);
public:

    Interface(Game & jogo);
    void start();
};



#endif //TP_POO2425_INTERFACE_H
