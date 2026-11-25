//
// Created by Duarte Matias on 08/11/2026.
//

#ifndef COMANDOAJUDA_H
#define COMANDOAJUDA_H
#include "Comandos.h"
#include "../Fabrica.h"


class ComandoAjuda : public Comandos{
public:
    ComandoAjuda();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra)override;

    ~ComandoAjuda();

};




#endif //COMANDOAJUDA_H
