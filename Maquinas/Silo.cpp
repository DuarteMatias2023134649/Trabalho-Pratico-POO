//
// Created by Duarte Matias on 21/10/2026.
//

#include "Silo.h"
#include "../Settings.h"

Silo::Silo(char direcaoSaida): Maquina('S', direcaoSaida) {

}

Silo::Silo(const Silo &novo): Maquina(novo) {

}

Silo& Silo::operator=(const Silo& outro) {
    if (this != &outro) {
        for (int i = 0; i < numItens; i++)
            delete itens[i];
        delete[] itens;
        itens = nullptr;
        numItens = 0;

        if (outro.numItens > 0) {
            itens = new Itens*[outro.numItens];
            for (int i = 0; i < outro.numItens; i++)
                recebeItem(outro.getItem(i));
            numItens = outro.numItens;
        }
    }
    return *this;
}
Itens* Silo::getItem(int y) const {
    if (itens == nullptr || y < 0 || y >= numItens) {
        return nullptr;
    }
    return itens[y];
}

bool Silo::recebeItem(Itens* it) {

    if (it == nullptr) {
        return false;
    }

    Itens** novo = new Itens*[numItens + 1];

    for (int i = 0; i < numItens; i++) {
        novo[i] = itens[i];
    }
    novo[numItens] = it;

    delete[] itens;
    itens = novo;
    numItens++;
    return true;

}
void Silo::atuar() {
    if (numItens <= 0 || itens == nullptr) {
        return;
    }

    int prob = Settings::silo_prob_perda;
    if (prob > 0 && (rand() % 100) < prob) {
        delete itens[0];

        if (numItens == 1) {
            delete[] itens;
            itens = nullptr;
            numItens = 0;
        } else {
            Itens** novo = new Itens*[numItens - 1];
            for (int i = 1; i < numItens; i++) {
                novo[i - 1] = itens[i];
            }
            delete[] itens;
            itens = novo;
            numItens--;
        }
    }
}
Silo::~Silo() {
    for (int i = 0; i < numItens; i++) {
        delete itens[i];
    }
    delete[] itens;
}
