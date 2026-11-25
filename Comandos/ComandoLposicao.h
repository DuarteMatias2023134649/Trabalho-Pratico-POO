//
// Created by Duarte Matias on 07/11/2026.
//

#ifndef COMANDOLPOSICAO_H
#define COMANDOLPOSICAO_H

#include "Comandos.h"
#include "../Fabrica.h"

class ComandoLposicao: public Comandos {

public:

    ComandoLposicao();

    Fabrica* executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra)override;

    ~ComandoLposicao();

};




#endif //COMANDOLPOSICAO_H
