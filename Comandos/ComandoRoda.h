//
// Created by Utilizador on 23/11/2026.
//

#ifndef TRABALHOPRATICO_COMANDORODA_H
#define TRABALHOPRATICO_COMANDORODA_H
#include "Comandos.h"


class ComandoRoda : public Comandos{
    public:
    ComandoRoda();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoRoda();
};


#endif //TRABALHOPRATICO_COMANDORODA_H
