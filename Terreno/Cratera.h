//
// Created by Utilizador on 25/11/2026.
//

#ifndef TRABALHOPRATICO_CRATERA_H
#define TRABALHOPRATICO_CRATERA_H


#include "Terreno.h"

class Cratera : public Terreno {
public:
    char getTipo() const override;
    bool aceitaMaquina() const override;
    string mostraInfo()override;
};


#endif //TRABALHOPRATICO_CRATERA_H
