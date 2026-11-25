//
// Created by Utilizador on 22/11/2026.
//

#ifndef TRABALHOPRATICO_COMANDOESTADO_H
#define TRABALHOPRATICO_COMANDOESTADO_H
#include "Comandos.h"

class ComandoEstado : public Comandos {
public:
    ComandoEstado();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoEstado();
};


#endif //TRABALHOPRATICO_COMANDOESTADO_H
