//
// Created by Duarte Matias on 17/10/2026.
//

#ifndef ECRA_H
#define ECRA_H
#include "Settings.h"
#include <iostream>
using namespace std;

class Ecra {

  char buffer[Settings::ecra_max_linhas][Settings::ecra_max_colunas];

  public:

  Ecra();
  bool limparEcra()noexcept;
  bool posicionarCursor(int linha, int coluna)noexcept;
  bool escreverEcra(const string palavra, int linha, int coluna)noexcept;
  bool desenharMoldura(int linha, int coluna, int largura, int altura)noexcept;
  bool mostra()const noexcept;
  ~Ecra();

};



#endif //ECRA_H
