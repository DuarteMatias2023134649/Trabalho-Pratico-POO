//
// Created by Utilizador on 25/11/2026.
//

#include "Deposito.h"

Deposito::Deposito(char tipo, int quantidade) : tipo(tipo), quantidade(quantidade) {}

char Deposito::getTipo() const { return tipo; }
bool Deposito::aceitaMaquina() const { return true; }
int Deposito::getQuantidade() const { return quantidade; }
void Deposito::setQuantidade(int qtd) { quantidade = qtd; }

string Deposito::mostraInfo() {
    return "Deposito";
}

