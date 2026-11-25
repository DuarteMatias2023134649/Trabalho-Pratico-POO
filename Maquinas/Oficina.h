//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef OFICINA_H
#define OFICINA_H

#include "Maquina.h"

class Oficina : public Maquina{
public:
    Oficina(char direcaoSaida);
    void atuar() override;
};



#endif //OFICINA_H
