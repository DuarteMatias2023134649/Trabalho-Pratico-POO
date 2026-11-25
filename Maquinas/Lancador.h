//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef LANCADOR_H
#define LANCADOR_H

#include "Maquina.h"

class Lancador: public Maquina {
public:
    Lancador(char direcaoSaida);
    void atuar() override;
};



#endif //LANÇADOR_H
