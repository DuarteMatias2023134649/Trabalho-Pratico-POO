//
// Created by Duarte Matias on 17/10/2026.
//

#include "Fabrica.h"
#include <cstdlib>
#include <ctime>
#include "Terreno/Solo.h"
#include "Terreno/Cratera.h"
#include "Terreno/Deposito.h"

static Terreno* criaTerreno(char tipo, int quantidade) {
    switch (tipo) {
        case '#': return new Cratera();
        case '%':
        case '$':
        case '~': return new Deposito(tipo, quantidade);
        default:  return new Solo();
    }
}

bool colocaTipos(char tipo,int lin, int col, int quantidade,Terreno*** t) {

    int colocados = 0;
    while (colocados < quantidade) {
        int r = rand() % lin;
        int c = rand() % col;
        if (t[r][c]->getTipo() == '.') {
            int qtdInicial = 0;
            if (tipo == '%' || tipo == '$' || tipo == '~') {
                qtdInicial = Settings::deposito_quantidade_min +
                             (rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));
            }
            delete t[r][c];
            t[r][c] = criaTerreno(tipo, qtdInicial);
            colocados++;
        }
    }
    return colocados == quantidade;
}

void Fabrica::criaGrelha() {
    terreno = new Terreno**[nLinhas];
    for (int i = 0; i < nLinhas; i++) {
        terreno[i] = new Terreno*[nColunas];
        for (int j = 0; j < nColunas; j++) {
            terreno[i][j] = new Solo();
        }
    }
}

Fabrica::Fabrica(int lin,int col){

    nLinhas = lin;
    nColunas = col;
    criaGrelha();
    creditos = Settings::fabrica_creditos_iniciais;
    nEngenheiros = 0;
    nMaquinas = 0;
    tempo = 0;
    bool a;
    a = colocaTipos('#',lin,col, Settings::fabrica_num_crateras, terreno);
    a = a * colocaTipos('%',lin,col, Settings::fabrica_num_depositos_ferro, terreno);
    a = a * colocaTipos('$',lin,col, Settings::fabrica_num_depositos_silicio, terreno);
    a = a * colocaTipos('~',lin,col,Settings::fabrica_num_depositos_gelo, terreno);
    if (a == true) {
        cout << "Foram Colocados todos";
    }else {
        cout << "Não foi possivel colocar todos";
    }
}
Fabrica::Fabrica(int lin,int col, bool aut){

    nLinhas = lin;
    nColunas = col;
    criaGrelha();
    creditos = Settings::fabrica_creditos_iniciais;
    nEngenheiros = 0;
    nMaquinas = 0;
    tempo = 0;
}

Fabrica::Fabrica(const Fabrica &novo) {
    *this = novo;
}
Fabrica& Fabrica::operator=(const Fabrica& outro) {

    if (this != &outro) {
        if (terreno != nullptr) {
            for (int i = 0; i < nLinhas; i++) {
                if (terreno[i] != nullptr) {
                    for (int j = 0; j < nColunas; j++) {
                        delete terreno[i][j];
                    }
                    delete[] terreno[i];
                }
            }
            delete[] terreno;
            terreno = nullptr;
        }
    }
    tempo = outro.tempo;
    creditos = outro.creditos;
    nEngenheiros = outro.nEngenheiros;
    nMaquinas = outro.nMaquinas;
    nLinhas = outro.nLinhas;
    nColunas = outro.nColunas;

    if (nLinhas > 0 && nColunas > 0 && outro.terreno != nullptr) {
        terreno = new Terreno**[nLinhas];
        for (int i = 0; i < nLinhas; i++) {
            terreno[i] = new Terreno*[nColunas];
            for (int j = 0; j < nColunas; j++) {
                if (outro.terreno[i][j] != nullptr) {
                    char tipo = outro.terreno[i][j]->getTipo();
                    int qtd = outro.terreno[i][j]->getQuantidade();
                    terreno[i][j] = criaTerreno(tipo, qtd);
                } else {
                    terreno[i][j] = nullptr;
                }
            }
        }
    }
    return *this;
}

void Fabrica::setTipoTerreno(int x, int y, char tipo, int quantidade) {
    if (terreno == nullptr || x < 0 || x >= nLinhas || y < 0 || y >= nColunas) {
        return;
    }
    delete terreno[x][y];
    terreno[x][y] = criaTerreno(tipo, quantidade);
}

void Fabrica::desenha(Ecra &ecra, int instante, int creditos, int numEngenheiros) const {

    ecra.limparEcra();

    int origemLinha = 2;
    int origemColuna = 2;

    ecra.desenharMoldura(origemLinha - 1, origemColuna - 1, nColunas + 5, nLinhas + 3);

    string reguaColunas = "";
    for (int j = 0; j < nColunas; ++j) {
        reguaColunas += (char)('A' + j);
    }
    ecra.escreverEcra(reguaColunas, origemLinha, origemColuna + 2);

    for (int i = 0; i < nLinhas; ++i) {
        string letraLinha(1, (char)('A' + i));
        ecra.escreverEcra(letraLinha, origemLinha + 1 + i, origemColuna);

        for (int j = 0; j < nColunas; ++j) {
            char simbolo = terreno[i][j]->getTipo();
            if (temMaquina(i, j)) {
                const Maquina* m = getMaquina(i, j);
                if (m != nullptr) {
                    if (m->getTipo() == 'T') {
                        char dir = m->getDirecaoSaida();
                        if (dir == 'c') simbolo = '^';
                        else if (dir == 'b') simbolo = 'v';
                        else if (dir == 'e') simbolo = '<';
                        else if (dir == 'd') simbolo = '>';
                        else simbolo = 'T';
                    } else {
                        simbolo = m->getTipo();
                    }
                }
            }
            string s(1, simbolo);
            ecra.escreverEcra(s, origemLinha + 1 + i, origemColuna + 2 + j);
        }
    }

    int painelColuna = origemColuna + nColunas + 6;

    ecra.desenharMoldura(origemLinha - 1, painelColuna - 2, 30, nLinhas + 3);

    ecra.escreverEcra("Instante: " + to_string(instante), origemLinha, painelColuna);
    ecra.escreverEcra("Creditos: " + to_string(creditos), origemLinha + 1, painelColuna);
    ecra.escreverEcra("Maquinas: " + to_string(nMaquinas), origemLinha + 2, painelColuna);
    ecra.escreverEcra("Engenheiros: " + to_string(numEngenheiros), origemLinha + 3, painelColuna);
    ecra.escreverEcra("No ultimo instante:", origemLinha + 5, painelColuna);

}


void Fabrica::mostraInfoTerreno(int lin, int col)const {

    if (lin < 0 || lin >= nLinhas || col < 0 || col >= nColunas) {
        throw("Fora dos Limites da fabrica");
    }

    cout << "Posicao " << (char)('a' + lin) << (char)('a' + col) << ": " << terreno[lin][col]->mostraInfo();

}

void Fabrica::mostraInfoTerreno(int lin, int col,int raio)const {

    for (int i = lin - raio; i <= lin + raio; ++i) {
        for (int j = col - raio; j <= col + raio; ++j) {
            if (i >= 0 && i < nLinhas && j >= 0 && j < nColunas) {
                mostraInfoTerreno(i, j);
            }
        }
    }
}

void Fabrica::avancaInstante() {
    tempo++;
    for (int i = 0; i < nLinhas; ++i) {
        for (int j = 0; j < nColunas; ++j) {
            Maquina* m = terreno[i][j]->getMaquina();
            if (m != nullptr)
                m->atuar();
        }
    }
}

Fabrica::~Fabrica(){
    if (terreno != nullptr) {
        for (int i = 0; i < nLinhas; i++) {
            for (int j = 0; j < nColunas; j++) {
                delete terreno[i][j];
            }
            delete[] terreno[i];
        }
        delete[] terreno;
        terreno = nullptr;
    }
}