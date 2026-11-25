//
// Created by Duarte Matias on 08/11/2026.
//

#ifndef COMANDOGRAVA_H
#define COMANDOGRAVA_H
#include "Comandos.h"


class ComandoGrava : public Comandos {
  public:
    ComandoGrava();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) override;

    ~ComandoGrava();
};



#endif //COMANDOGRAVA_H
