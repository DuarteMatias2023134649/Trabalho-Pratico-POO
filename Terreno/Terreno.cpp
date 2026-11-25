//
// Created by Duarte Matias on 17/10/2026.
//

#include "Terreno.h"

Terreno::Terreno() : maquina(nullptr) {}

Terreno::~Terreno() {
    delete maquina;
    maquina = nullptr;
}
bool Terreno::temMaquina() const { return maquina != nullptr; }
Maquina* Terreno::getMaquina() const { return maquina; }
void Terreno::setMaquina(Maquina* m) { maquina = m; }

Terreno& Terreno::operator=(const Terreno& outro) {
    if (this != &outro) {
        delete maquina;
        maquina = nullptr;
    }
    return *this;
}

Maquina* Terreno::retiraMaquina() {
    Maquina* m = maquina;
    maquina = nullptr;
    return m;
}