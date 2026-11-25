//
// Created by Utilizador on 25/11/2026.
//

#include "Cratera.h"
char Cratera::getTipo() const { return '#'; }
bool Cratera::aceitaMaquina() const { return false; }
string Cratera::mostraInfo() {
    return "Cratera";
}