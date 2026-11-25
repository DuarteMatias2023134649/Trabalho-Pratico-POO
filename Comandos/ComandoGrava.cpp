//
// Created by Duarte Matias on 08/11/2026.
//

#include "ComandoGrava.h"
#include <fstream>
ComandoGrava::ComandoGrava(){

}

Fabrica* ComandoGrava::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {

    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }

  return f;
}

ComandoGrava::~ComandoGrava(){

}