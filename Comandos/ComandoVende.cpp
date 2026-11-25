//
// Created by Utilizador on 23/11/2026.
//

#include "ComandoVende.h"
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

ComandoVende::ComandoVende(){}

Fabrica* ComandoVende::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {
    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }
    if (val1.empty()) {
        cout << "Erro nos parametros\n";
        return f;
    }
    if (val1.length() != 2) {
        cout << "Posicao invalida! Use o formato exato (ex: ce).\n";
        return f;
    }
    int x = val1[0] - 'a';
    int y = val1[1] - 'a';
    Maquina* m;
    if (f->temMaquina(x,y))
        m = f->getMaquina(x, y);
    else {
        cout << "Nao existe nenhuma maquina nessa posicao!\n";
        return f;
    }

    int custo = 0;
    switch (m->getTipo()) {
        case 'P':
            custo = Settings::perfuradora_custo;
            break;
        case 'T':
            custo = Settings::transportador_custo;
            break;
        case 'R':
            custo = Settings::refinaria_custo;
            break;
        case 'O':
            custo = Settings::oficina_custo;
            break;
        case 'S':
            custo = Settings::silo_custo;
            break;
        case 'L':
            custo = Settings::lancador_custo;
            break;
        default:
            break;
    }
    f->setCreditos(f->getCreditos() + (custo / 2));
    f->setMaquina(x, y, nullptr);
    f->removeMaquina();
    delete m;
    if (ecra != nullptr) {
        f->desenha(*ecra, f->getInstante(), f->getCreditos(), f->getNumEngenheiros());
        ecra->mostra();
    }
    return f;
}
ComandoVende::~ComandoVende(){}