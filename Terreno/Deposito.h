//
// Created by Utilizador on 25/11/2026.
//

#ifndef TRABALHOPRATICO_DEPOSITO_H
#define TRABALHOPRATICO_DEPOSITO_H


#include "Terreno.h"

class Deposito : public Terreno {
    char tipo;
    int quantidade;
public:
    Deposito(char tipo, int quantidade);
    char getTipo() const override;
    bool aceitaMaquina() const override;
    int getQuantidade() const override;
    void setQuantidade(int qtd);
    string mostraInfo()override;
};


#endif //TRABALHOPRATICO_DEPOSITO_H
