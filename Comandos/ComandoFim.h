//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef COMANDOFIM_H
#define COMANDOFIM_H
#include "Comandos.h"
#include <iostream>
using namespace std;

class ComandoFim : public Comandos{

  public:
    ComandoFim();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra)override;

    ~ComandoFim();

};

#endif //COMANDOFIM_H
