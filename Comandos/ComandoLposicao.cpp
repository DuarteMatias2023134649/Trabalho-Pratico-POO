//
// Created by Duarte Matias on 07/11/2026.
//

#include "ComandoLposicao.h"
#include <iostream>
ComandoLposicao::ComandoLposicao(){

}

Fabrica* ComandoLposicao::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim,Ecra *ecra) {

  if (f == nullptr) {
    cout << "A fabrica ainda nao foi criada!\n";
    return f;
  }

  if (val1.length() != 2) {
    cout << "Posicao invalida! Use o formato exato (ex: ce).\n";
    return f;
  }

  if (val1[0] < 'a' || val1[0] > 'z' ||val1[1] < 'a' || val1[1] > 'z') {
    cout << "Posicao invalida!\n";
    return f;
  }

  int x = val1[0] - 'a';
  int y = val1[1] - 'a';

    try {
      if (!val2.empty()) {
        int raio = stoi(val2);
        f->mostraInfoTerreno(x, y, raio);
      }
      else {
        f->mostraInfoTerreno(x, y);
      }
        ecra->mostra();
    }
    catch (const char *e) {
      cout << e << '\n';
    }
    catch (const exception e) {
      cout << "Erro nos valores introduzidos: ";
    }

  return f;
}

ComandoLposicao::~ComandoLposicao(){

}