

#ifndef TP_POO2425_CARVCOMERCIO_H
#define TP_POO2425_CARVCOMERCIO_H

#include "Caravana.h"

class CarvComercio : public Caravana{

public:
    CarvComercio(int l, int c);
    bool move(int numCasas) override;
};


#endif //TP_POO2425_CARVCOMERCIO_H
