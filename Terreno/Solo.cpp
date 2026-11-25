//
// Created by Utilizador on 25/11/2026.
//

#include "Solo.h"

char Solo::getTipo() const { return '.'; }
bool Solo::aceitaMaquina() const { return true; }

string Solo::mostraInfo() {
    return "Solo";
}
