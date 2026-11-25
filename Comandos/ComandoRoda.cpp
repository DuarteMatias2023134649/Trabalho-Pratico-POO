//
// Created by Utilizador on 23/11/2026.
//

#include "ComandoRoda.h"

ComandoRoda::ComandoRoda(){

}

Fabrica* ComandoRoda::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {
    if (f == nullptr) {
        cout << "A fabrica ainda nao foi criada!\n";
        return f;
    }
    if (val1.empty() || val2.empty()) {
        cout << "Erro nos parametros\n";
        return f;
    }
    if (val1.length() != 2) {
        cout << "Posicao invalida! Use o formato exato (ex: ce).\n";
        return f;
    }
    char dir = val2[0];

    if (dir != 'c' && dir != 'b' && dir != 'e' && dir != 'd') {
        cout << "Direcao invalida! Use c, b, e ou d.\n";
        return f;
    }
    int x = val1[0] - 'a';
    int y = val1[1] - 'a';
    Maquina* m = nullptr;
    if (f->temMaquina(x,y))
        m = f->getMaquina(x, y);
    else {
        cout << "Nao existe nenhuma maquina nessa posicao!\n";
        return f;
    }
    m->setDirecaoSaida(dir);
    if (ecra != nullptr) {
        f->desenha(*ecra, f->getInstante(), f->getCreditos(), f->getNumEngenheiros());
        ecra->mostra();
    }
    return f;
}

ComandoRoda::~ComandoRoda(){

}