//
// Created by Utilizador on 23/11/2026.
//

#ifndef TRABALHOPRATICO_COMANDOVENDE_H
#define TRABALHOPRATICO_COMANDOVENDE_H
#include "Comandos.h"

class ComandoVende :public Comandos{

    public:

    ComandoVende();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoVende();

};


#endif //TRABALHOPRATICO_COMANDOVENDE_H
