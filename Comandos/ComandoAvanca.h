//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef COMANDOAVANCA_H
#define COMANDOAVANCA_H
#include "Comandos.h"
#include "../Fabrica.h"


class ComandoAvanca : public Comandos{
public:
    ComandoAvanca();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra)override;

    ~ComandoAvanca();

};



#endif //COMANDOAVANCA_H
