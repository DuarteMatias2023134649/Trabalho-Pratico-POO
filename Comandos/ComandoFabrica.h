//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef COMANDOFABRICA_H
#define COMANDOFABRICA_H
#include "Comandos.h"
#include "../Fabrica.h"

class ComandoFabrica : public Comandos{

public:

    ComandoFabrica();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra* ecra)override;

    ~ComandoFabrica();
};



#endif //COMANDOFABRICA_H
