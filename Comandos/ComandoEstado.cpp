//
// Created by Utilizador on 22/11/2026.
//

#include "ComandoEstado.h"

ComandoEstado::ComandoEstado() {}

Fabrica* ComandoEstado::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {
    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }

    if (!val1.empty() || !val2.empty() || !val3.empty()) {
        cout << "Erro nos parametros! Uso: estado\n";
        return f;
    }

    cout << "\n ESTADO DA FABRICA \n";
    cout << "Instante atual: " << f->getInstante() << "\n";
    cout << "Creditos: " << f->getCreditos() << "\n";

    cout << "\n Maquinas ";
    cout << "\nMaquinas: "<< f->getNumMaquinas() <<"\n";
    for (int i = 0; i < f->getLinhas(); ++i) {
        for (int j = 0; j < f->getColunas(); ++j) {
            if (f->temMaquina(i, j)) {
                Maquina* m = f->getMaquina(i, j);
                if (m != nullptr) {
                    cout << "\nMaquina: "<< m->getTipo();
                }
            }
        }
    }



    return f;
}

ComandoEstado::~ComandoEstado() {}