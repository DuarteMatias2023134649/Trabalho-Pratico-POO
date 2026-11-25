//
// Created by Duarte Matias on 21/10/2026.
//

#include "ComandoCarrega.h"
#include <fstream>
ComandoCarrega::ComandoCarrega() {

}

Fabrica* ComandoCarrega::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {

    if (val1.empty()) {
        cout << "Erro: Deve indicar o nome do ficheiro (ex: grava jogo.txt)\n";
        return f;
    }
    ifstream file(val1);

    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro\n";
        return f;
    }

    int lin,col;

    if (!(file >> lin >> col))
        throw "Erro na leitura do ficheiro";

    if ((lin <= Settings::fabrica_max_linhas && col <= Settings::fabrica_max_colunas) &&
        (lin >= 10 && col >= 10)) {
        delete f;
        f = new Fabrica(lin, col,false);
        char tipo;
        Terreno* terreno;
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                if (!(file >> tipo)) {
                    cout << "Erro: Ficheiro incompleto na linha " << i << ", coluna " << j << "\n";
                    return f;
                }
                f->setTipoTerreno(i,j,tipo);
            }
        }
            if (ecra != nullptr) {
                f->desenha(*ecra, 0, Settings::fabrica_creditos_iniciais, 0);
                ecra->mostra();
            }
        } else {
            cout << "Tamanho inválido.\n";
            return f;
        }
    return f;
}

ComandoCarrega::~ComandoCarrega() {

}