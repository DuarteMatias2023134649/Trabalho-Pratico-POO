//
// Created by Duarte Matias on 21/10/2026.
//

#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <iostream>
#include "Fabrica.h"
using namespace std;

class Simulador {
  Fabrica* fabrica;
  Fabrica* fabricaGravada;
  Ecra *ecra;
  public:

  Simulador();
  void simular() noexcept;
  Fabrica& getFabrica()const noexcept;
  int getTempo()const noexcept;
  ~Simulador();

};



#endif //SIMULADOR_H
