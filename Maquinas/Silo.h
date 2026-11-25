//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef SILO_H
#define SILO_H

#include "Maquina.h"

class Silo : public Maquina{
    Itens** itens = nullptr;
    int numItens = 0;
public:
    Silo(char direcaoSaida);
    Silo(const Silo &novo);
    Silo& operator=(const Silo& outro);
    bool recebeItem(Itens* it);
    Itens* getItem(int y) const;
    void atuar() override;
    ~Silo();


};



#endif //SILO_H
