//
// Created by Duarte Matias on 17/10/2026.
//

#ifndef COMANDOS_H
#define COMANDOS_H
#include "../Fabrica.h"
class Comandos {

    public:

    Comandos();

    virtual Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) = 0;

    virtual ~Comandos();
};



#endif //COMANDOS_H
