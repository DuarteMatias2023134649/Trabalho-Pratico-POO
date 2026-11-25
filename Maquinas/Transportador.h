//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef TRANSPORTADOR_H
#define TRANSPORTADOR_H

#include "Maquina.h"

class Transportador: public Maquina {
public:
    Transportador(char direcaoSaida);
    void atuar() override;
};



#endif //TRANSPORTADOR_H
