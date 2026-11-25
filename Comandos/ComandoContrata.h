//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef COMANDOCONTRATA_H
#define COMANDOCONTRATA_H
#include "Comandos.h"

class ComandoContrata : public Comandos {

    public:
    ComandoContrata();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoContrata();

};

#endif //COMANDOCONTRATA_H
