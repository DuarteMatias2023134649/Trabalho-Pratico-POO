//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef COMANDOCARREGA_H
#define COMANDOCARREGA_H
#include "Comandos.h"


class ComandoCarrega : public Comandos {

public:
    ComandoCarrega();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoCarrega();
};



#endif //COMANDOCARREGA_H
