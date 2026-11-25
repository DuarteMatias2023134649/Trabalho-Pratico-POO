//
// Created by Duarte Matias on 17/10/2026.
//

#include "Maquina.h"
Maquina::Maquina(char tipo,char dir): tipo(tipo), direcaoSaida(dir){}

char Maquina::getTipo() const {
    return tipo;
}

char Maquina::getDirecaoSaida() const {
    return direcaoSaida;
}

void Maquina::setDirecaoSaida(char dir) {
    direcaoSaida = dir;
}

void Maquina::setItem(Itens* it) {
    item = it;
}

Itens* Maquina::getItem() const {
    return item;
}
Maquina::~Maquina() {
    delete item;
    item = nullptr;
}