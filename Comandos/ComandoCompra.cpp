//
// Created by Utilizador on 22/11/2026.
//

#include "ComandoCompra.h"

#include "Oficina.h"
#include "Perfuradora.h"
#include "Refinaria.h"
#include "Silo.h"
#include "Transportador.h"
#include "Lancador.h"
#include "../Settings.h"

ComandoCompra::ComandoCompra(){}

Fabrica* ComandoCompra::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {
    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }

    if (val1.empty() || val2.empty() || val3.empty()) {
        cout << "Erro nos parametros\n";
        return f;
    }

    if (val2.length() != 2) {
        cout << "Posicao invalida! Use o formato exato (ex: ce).\n";
        return f;
    }
    char tipo = val1[0];
    int x = val2[0] - 'a';
    int y = val2[1] - 'a';
    char dir = val3[0];

    if (dir != 'c' && dir != 'b' && dir != 'e' && dir != 'd') {
        cout << "Direcao invalida! Use c, b, e ou d.\n";
        return f;
    }

    if (f->getTipoTerreno(x, y) == '#') {
        cout << "Nao e possivel colocar numa cratera!\n";
        return f;
    }

    if (f->temMaquina(x,y)) {
        cout << "A posicao ja se encontra ocupada por outra maquina!\n";
        return f;
    }

    int custo = 0;
    Maquina* maquina = nullptr;

    switch (tipo) {
        case 'p':
            custo = Settings::perfuradora_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Perfuradora(dir);
            break;
        case 't':
            custo = Settings::transportador_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Transportador(dir);
            break;
        case 'r':
            custo = Settings::refinaria_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Refinaria(dir);
            break;
        case 'o':
            custo = Settings::oficina_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Oficina(dir);
            break;
        case 's':
            custo = Settings::silo_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Silo(dir);
            break;
        case 'l':
            custo = Settings::lancador_custo;
            if (f->getCreditos() < custo) {
                cout << "Creditos insuficientes!\n";
                return f;
            }
            maquina = new Lancador(dir);
            break;
        default:
            cout << "Tipo de maquina invalido! Use p, t, r, o, s ou l.\n";
            return f;
    }
    f->setCreditos(f->getCreditos() - custo);
    f->setMaquina(x, y, maquina);
    f->addMaquina();
    if (ecra != nullptr) {
        f->desenha(*ecra, f->getInstante(),f->getCreditos(),f->getNumEngenheiros());
        ecra->mostra();
    }
    return f;
}
ComandoCompra::~ComandoCompra(){}