//
// Created by Utilizador on 25/11/2026.
//

#ifndef TRABALHOPRATICO_COMANDORECUPERA_H
#define TRABALHOPRATICO_COMANDORECUPERA_H

#include "Comandos.h"

class ComandoRecupera : public Comandos{

public:
    ComandoRecupera();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoRecupera();
};


#endif //TRABALHOPRATICO_COMANDORECUPERA_H
