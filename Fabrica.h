//
// Created by Duarte Matias on 17/10/2026.
//

#ifndef FABRICA_H
#define FABRICA_H

#include "Terreno/Terreno.h"
#include "Ecra.h"
#include "Settings.h"

class Fabrica {
    int tempo;
    int creditos;
    int nEngenheiros;
    int nMaquinas;
    int nLinhas, nColunas;
    Terreno*** terreno;
    void criaGrelha();
public:
    ~Fabrica();
    void desenha(Ecra &ecra, int instante, int creditos, int numEngenheiros)const;
    int getLinhas()const{return nLinhas;}
    int getColunas()const{return nColunas;}
    void mostraInfoTerreno(int lin, int col) const;
    void mostraInfoTerreno(int lin, int col,int raio)const;
    void mostraInfoTerrenoRaio(int lin, int col,int raio) const;
    void avancaInstante();
    char getTipoTerreno(int x, int y)const{return terreno[x][y]->getTipo();}
    bool temMaquina(int x, int y)const{return terreno[x][y]->temMaquina();}
    void setTipoTerreno(int x, int y, char tipo, int quantidade = 0);
    void setMaquina(int x, int y,Maquina* m){terreno[x][y]->setMaquina(m);}
    Maquina* getMaquina(int x, int y) const { return terreno[x][y]->getMaquina(); }
    int getInstante()const{return tempo;}
    int getCreditos()const{return creditos;}
    void setCreditos(int c){creditos = c;}
    int getNumEngenheiros()const{return nEngenheiros;}
    int getNumMaquinas()const{return nMaquinas;}
    void addMaquina(){nMaquinas++;}
    void removeMaquina(){nMaquinas--;}
    Fabrica(int l,int col);
    Fabrica(int lin,int col,bool aut);
    Fabrica(const Fabrica &novo);
    Fabrica& operator=(const Fabrica& outro);
};



#endif //FABRICA_H
