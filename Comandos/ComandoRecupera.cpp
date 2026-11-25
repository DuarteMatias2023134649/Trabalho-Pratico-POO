//
// Created by Utilizador on 25/11/2026.
//

#include "ComandoRecupera.h"
ComandoRecupera::ComandoRecupera(){

}

Fabrica* ComandoRecupera::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {

    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }

    return f;
}

ComandoRecupera::~ComandoRecupera(){

}