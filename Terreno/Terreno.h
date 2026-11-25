//
// Created by Duarte Matias on 17/10/2026.
//

#ifndef TERRENO_H
#define TERRENO_H

#include "../Maquinas/Maquina.h"

class Terreno {
  Maquina* maquina;
public:
  Terreno();
  Terreno& operator=(const Terreno&);
  virtual ~Terreno();
  virtual string mostraInfo() = 0;
  virtual char getTipo() const = 0;
  virtual bool aceitaMaquina() const = 0;
  virtual int getQuantidade() const { return 0; }
  bool temMaquina() const;
  Maquina* getMaquina() const;
  void setMaquina(Maquina* m);
  Maquina* retiraMaquina();
};



#endif //TERRENO_H
