//
// Created by Duarte Matias on 21/10/2026.
//

#include "ComandoFim.h"

ComandoFim::ComandoFim(){

}

Fabrica* ComandoFim::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra){
    cout << "Fim do Jogo";
    if (sim)
        sim = false;
    return f;
}

ComandoFim::~ComandoFim(){

}
