//
// Created by Utilizador on 25/11/2026.
//

#ifndef TRABALHOPRATICO_SOLO_H
#define TRABALHOPRATICO_SOLO_H

#include "Terreno.h"

class Solo : public Terreno {
public:
    char getTipo() const override;
    bool aceitaMaquina() const override;
    string mostraInfo()override;

};


#endif //TRABALHOPRATICO_SOLO_H
