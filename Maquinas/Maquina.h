//
// Created by Duarte Matias on 17/10/2026.
//

#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>
using namespace std;
#include "../Itens/Itens.h"
class Maquina {
    char tipo;
    char direcaoSaida;
    Itens* item = nullptr;
public:
    Maquina(char tipo,char dir);
    char getTipo() const;
    char getDirecaoSaida() const;
    void setDirecaoSaida(char dir);
    void setItem(Itens* it);
    Itens* getItem() const;
    virtual void atuar()=0;
    virtual ~Maquina();

};



#endif //MAQUINA_H
