//
// Created by Duarte Matias on 21/10/2026.
//

#include "ComandoFabrica.h"

#include <iostream>
#include <ostream>

ComandoFabrica::ComandoFabrica(){

}

Fabrica* ComandoFabrica::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra){
    if (f != nullptr) {
        cout << "Ja foi criada a fabrica";
        return f;
    }else {
        try {
            int linhas = stoi(val1);
            int colunas = stoi(val2);

            if ((linhas <= Settings::fabrica_max_linhas && colunas <= Settings::fabrica_max_colunas) &&
                (linhas >= 10 && colunas >= 10)) {

                f = new Fabrica(linhas, colunas);
                if (f != nullptr) {
                    f->desenha(*ecra, 0, 1000, 0);
                }
                ecra->mostra();
                return f;
                } else {
                    cout << "Tamanho inválido.\n";
                }
        }
        catch (exception e) {

            cout << "Erro nos argumentos\n";
        }
    }
      return nullptr;
}

ComandoFabrica::~ComandoFabrica(){

}