//
// Created by Duarte Matias on 21/10/2026.
//

#include "ComandoAvanca.h"

ComandoAvanca::ComandoAvanca(){

}

Fabrica* ComandoAvanca::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra) {
    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }
    int passos = 1;
    if (!val1.empty()) {
        try{
            passos = stoi(val1);
            if (passos <= 0)
                passos = 1;
        }catch (exception e) {
            cout<< "Erro nos atributos";
            return f;
        };

    }
    for (int i = 0; i < passos; ++i) {
        f->avancaInstante();
    }
    f->desenha(*ecra, f->getInstante(), f->getCreditos(), f->getNumEngenheiros());
    ecra->mostra();
    return f;
}

ComandoAvanca::~ComandoAvanca(){

}