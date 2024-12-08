

#ifndef TP_POO2425_INTERFACE_H
#define TP_POO2425_INTERFACE_H

#include "ListaComandos.h"
#include "Buffer.h"

class Interface {

    Game *jogo;
    Buffer buffer;
    ListaComandos comandos;
    void AtualizaMapa();
public:

    Interface(Game & jogo);
    void start();

};


#endif //TP_POO2425_INTERFACE_H
