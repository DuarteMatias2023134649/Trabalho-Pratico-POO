//
// Created by Duarte Matias on 21/10/2026.
//

#include "Simulador.h"
#include "Comandos/Comandos.h"
#include <sstream>
#include <string>

#include "ComandoAvanca.h"
#include "ComandoCarrega.h"
#include "ComandoCompra.h"
#include "ComandoEstado.h"
#include "Comandos/ComandoFim.h"
#include "Comandos/ComandoLposicao.h"
#include "Comandos/ComandoAjuda.h"
#include "Comandos/ComandoGrava.h"
#include "Comandos/ComandoCarrega.h"
#include "ComandoFabrica.h"
#include "ComandoRecupera.h"
#include "ComandoRoda.h"
#include "ComandoVende.h"
#include "Fabrica.h"

Simulador::Simulador(){
    fabrica = nullptr;
    fabricaGravada = nullptr;
    ecra = new Ecra();
    cout << "Simulador"<< endl;
}

void Simulador::simular() noexcept{
    string comando;
    string val1, val2, val3;
    string input;
    bool sim = true;
    Comandos *cmd = nullptr;

    while(sim){
        cout << endl << endl << endl << "Comando: ";

        if (!getline(cin, input))
            break;
        val1 = "";
        val2 = "";
        val3 = "";
        stringstream ss(input);

        if (!(ss >> comando))
            continue;

        ss >> val1;
        ss >> val2;
        ss >> val3;

        if (comando == "fim") {
            cmd = new ComandoFim();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

            delete cmd;

            cmd = nullptr;

            break;

        } else if (comando == "fabrica") {

            cmd = new ComandoFabrica();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        } else if (comando == "avanca") {

            cmd = new ComandoAvanca();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else if (comando == "lposicao") {

            cmd = new ComandoLposicao();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else if (comando == "ajuda") {

            cmd = new ComandoAjuda();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else if (comando == "grava") {

            cmd = new ComandoGrava();

            fabricaGravada = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else if (comando == "recupera") {

            cmd = new ComandoRecupera();

            fabrica = cmd->executa(fabricaGravada, val1, val2, val3, sim, ecra);

        }else if (comando == "carrega") {

            cmd = new ComandoCarrega();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else if (comando == "compra") {

            cmd = new ComandoCompra();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);


        }else if (comando == "vende") {

            cmd = new ComandoVende();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);


        }else if (comando == "roda") {

            cmd = new ComandoRoda();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);


        }else if (comando == "estado") {

            cmd = new ComandoEstado();

            fabrica = cmd->executa(fabrica, val1, val2, val3, sim, ecra);

        }else {
            cout << "Não existe esse comando";
        }
        delete cmd;
        cmd = nullptr;
    }
}



Simulador::~Simulador(){
    if (ecra != nullptr) delete ecra;
    if (fabrica != nullptr) delete fabrica;
}