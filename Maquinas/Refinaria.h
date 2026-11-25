//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef REFINARIA_H
#define REFINARIA_H

#include "Maquina.h"

class Refinaria : public Maquina{
public:
    Refinaria(char direcaoSaida);
    void atuar() override;
};



#endif //REFINARIA_H
