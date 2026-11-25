//
// Created by Utilizador on 22/11/2026.
//

#ifndef TRABALHOPRATICO_COMANDOCOMPRA_H
#define TRABALHOPRATICO_COMANDOCOMPRA_H
#include "Comandos.h"
class ComandoCompra : public Comandos{

public:

    ComandoCompra();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoCompra();
};


#endif //TRABALHOPRATICO_COMANDOCOMPRA_H
