//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef PERFURADORA_H
#define PERFURADORA_H

#include "Maquina.h"

class Perfuradora : public Maquina{
    public:
    Perfuradora(char direcaoSaida);
    void atuar() override;
};



#endif //PERFURADORA_H
