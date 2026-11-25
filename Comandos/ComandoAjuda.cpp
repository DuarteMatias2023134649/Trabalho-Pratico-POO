//
// Created by Duarte Matias on 08/11/2026.
//

#include "ComandoAjuda.h"
#include <iostream>

ComandoAjuda::ComandoAjuda() {}

Fabrica* ComandoAjuda::executa(Fabrica *f, const string& val1, const string& val2, const string& val3, bool& sim, Ecra *ecra) {
    cout << "\n====================================================================\n";

    if (val1.empty()) {
        cout << "                    LISTA DE COMANDOS DISPONIVEIS                   \n";
        cout << "====================================================================\n";
        cout << " fabrica <nl> <nc>           - Cria a fabrica com <nl> linhas e <nc> colunas.\n";
        cout << " carrega <nome-do-ficheiro>  - Cria a fabrica a partir de um ficheiro de mapa.\n";
        cout << " avanca [n]                  - Avanca n instantes na simulacao (por defeito 1).\n";
        cout << " compra <tipo> <lc> <dir>    - Compra e coloca uma maquina na posicao <lc>.\n";
        cout << " vende <lc>                  - Vende a maquina na posicao <lc>.\n";
        cout << " roda <lc> <dir>             - Altera a direcao de saida da maquina em <lc>.\n";
        cout << " melhora <lc>                - Melhora a maquina na posicao <lc>.\n";
        cout << " contrata <nome>             - Contrata um engenheiro com o nome indicado.\n";
        cout << " atribui <id> <lc>           - Associa o engenheiro <id> a maquina em <lc>.\n";
        cout << " despede <id>                - Despede o engenheiro <id>.\n";
        cout << " estado                      - Mostra estado da simulacao, maquinas, engenheiros e envios.\n";
        cout << " lposicao <lc> [n]           - Mostra info do terreno/maquina em <lc> (ou raio n).\n";
        cout << " grava <nome>                - Guarda em memoria uma copia da fabrica com <nome>.\n";
        cout << " recupera <nome>             - Recupera a copia da fabrica guardada com <nome>.\n";
        cout << " executa <nome-do-ficheiro>  - Executa comandos lidos de um ficheiro de texto.\n";
        cout << " ajuda [comando]             - Mostra a lista de comandos ou detalhe de um comando.\n";
        cout << " fim                         - Encerra o programa libertando os recursos.\n";
        cout << "====================================================================\n";
    } else if (!val2.empty()) {
        cout << "Erro: Demasiados parametros. Sintaxe: ajuda [comando]\n";
        cout << "====================================================================\n";
    } else {
        if (val1 == "fabrica") {
            cout << "Comando: fabrica <nl> <nc>\n";
            cout << "Parametros: <nl> (linhas, max 26), <nc> (colunas, max 26).\n";
            cout << "Efeito: Cria a fabrica com dimensoes <nl>x<nc> e coloca crateras e depositos aleatoriamente.\n";
            cout << "Falha se: Ja existir fabrica criada, parametros invalidos/fora dos limites ou sem espaco.\n";
            cout << "Exemplo: fabrica 12 20\n";
        } else if (val1 == "carrega") {
            cout << "Comando: carrega <nome-do-ficheiro>\n";
            cout << "Parametros: <nome-do-ficheiro> (ficheiro de texto com o mapa da fabrica).\n";
            cout << "Efeito: Cria a fabrica a partir do mapa especificado no ficheiro.\n";
            cout << "Falha se: Ja existir fabrica criada, o ficheiro nao existir ou nao respeitar o formato.\n";
            cout << "Exemplo: carrega mapal.txt\n";
        } else if (val1 == "avanca") {
            cout << "Comando: avanca [n]\n";
            cout << "Parametros: [n] (opcional, inteiro positivo; por defeito 1).\n";
            cout << "Efeito: Avanca n instantes um a um, acionando maquinas, salarios/ganhos e atualizando o ecra.\n";
            cout << "Falha se: Fabrica ainda nao criada ou n nao for um inteiro positivo.\n";
            cout << "Exemplo: avanca 10\n";
        } else if (val1 == "compra") {
            cout << "Comando: compra <tipo> <lc> <dir>\n";
            cout << "Parametros: <tipo> (p, t, r, o, s, l), <lc> (posicao ex: ce), <dir> (c, b, e, d).\n";
            cout << "Efeito: Compra a maquina indicada e coloca-a em <lc> com direcao de saida <dir>.\n";
            cout << "Falha se: Fabrica nao criada, parametros invalidos, posicao ocupada/cratera ou sem creditos.\n";
            cout << "Exemplo: compra t ce d\n";
        } else if (val1 == "vende") {
            cout << "Comando: vende <lc>\n";
            cout << "Parametros: <lc> (posicao da maquina ex: ce).\n";
            cout << "Efeito: Vende a maquina em <lc>, recebe 50% do custo, liberta engenheiros e perde itens internos.\n";
            cout << "Falha se: Fabrica nao criada, <lc> invalida ou nao existir maquina na posicao.\n";
            cout << "Exemplo: vende ce\n";
        } else if (val1 == "roda") {
            cout << "Comando: roda <lc> <dir>\n";
            cout << "Parametros: <lc> (posicao ex: ce), <dir> (nova direcao: c, b, e, d).\n";
            cout << "Efeito: Altera a direcao de saida da maquina na posicao indicada.\n";
            cout << "Falha se: Fabrica nao criada, parametros invalidos ou nao existir maquina em <lc>.\n";
            cout << "Exemplo: roda ce b\n";
        } else if (val1 == "melhora") {
            cout << "Comando: melhora <lc>\n";
            cout << "Parametros: <lc> (posicao da maquina ex: hi).\n";
            cout << "Efeito: Aplica melhoria na maquina em <lc> pagando o respetivo custo (se aplicavel).\n";
            cout << "Falha se: Fabrica nao criada, <lc> invalida, sem maquina, nao melhoravel ou sem creditos.\n";
            cout << "Exemplo: melhora hi\n";
        } else if (val1 == "contrata") {
            cout << "Comando: contrata <nome>\n";
            cout << "Parametros: <nome> (nome do engenheiro).\n";
            cout << "Efeito: Contrata um engenheiro livre com ID unico automatico e paga o custo inicial.\n";
            cout << "Falha se: Fabrica nao criada, falta o <nome> ou nao ha creditos suficientes.\n";
            cout << "Exemplo: contrata joaquim\n";
        } else if (val1 == "atribui") {
            cout << "Comando: atribui <id> <lc>\n";
            cout << "Parametros: <id> (identificador do engenheiro), <lc> (posicao da maquina ex: hr).\n";
            cout << "Efeito: Associa o engenheiro <id> a maquina em <lc> (removendo associacao anterior se existir).\n";
            cout << "Falha se: Fabrica nao criada, parametros invalidos, engenheiro inexistente ou sem maquina em <lc>.\n";
            cout << "Exemplo: atribui 2 hr\n";
        } else if (val1 == "despede") {
            cout << "Comando: despede <id>\n";
            cout << "Parametros: <id> (identificador do engenheiro).\n";
            cout << "Efeito: Remove o engenheiro da fabrica e deixa de receber salario.\n";
            cout << "Falha se: Fabrica nao criada, <id> invalido ou engenheiro inexistente.\n";
            cout << "Exemplo: despede 2\n";
        } else if (val1 == "estado") {
            cout << "Comando: estado\n";
            cout << "Parametros: Nenhum.\n";
            cout << "Efeito: Lista instante, creditos, maquinas, engenheiros e totais de itens enviados para a Terra.\n";
            cout << "Falha se: Fabrica ainda nao criada.\n";
            cout << "Exemplo: estado\n";
        } else if (val1 == "lposicao") {
            cout << "Comando: lposicao <lc> [n]\n";
            cout << "Parametros: <lc> (posicao ex: df), [n] (opcional, raio do quadrado centrado em <lc>).\n";
            cout << "Efeito: Mostra informacao do terreno e da maquina (itens e estado) em <lc> ou num raio n.\n";
            cout << "Falha se: Fabrica nao criada ou parametros/<lc>/n invalidos.\n";
            cout << "Exemplo: lposicao df 2\n";
        } else if (val1 == "grava") {
            cout << "Comando: grava <nome>\n";
            cout << "Parametros: <nome> (identificador da copia em memoria).\n";
            cout << "Efeito: Guarda em memoria uma copia do estado da fabrica (sem associacoes eng.-maquina).\n";
            cout << "Falha se: Fabrica nao criada ou falta o <nome>.\n";
            cout << "Exemplo: grava antes\n";
        } else if (val1 == "recupera") {
            cout << "Comando: recupera <nome>\n";
            cout << "Parametros: <nome> (identificador da copia previamente gravada).\n";
            cout << "Efeito: Restaura a fabrica para a copia indicada, mantendo engenheiros livres e a copia guardada.\n";
            cout << "Falha se: Nao existir copia gravada com o <nome> indicado ou parametro em falta.\n";
            cout << "Exemplo: recupera antes\n";
        } else if (val1 == "executa") {
            cout << "Comando: executa <nome-do-ficheiro>\n";
            cout << "Parametros: <nome-do-ficheiro> (ficheiro com um comando por linha).\n";
            cout << "Efeito: Le e executa sequencialmente os comandos contidos no ficheiro.\n";
            cout << "Falha se: Ficheiro nao existir ou nao puder ser aberto.\n";
            cout << "Exemplo: executa testel.txt\n";
        } else if (val1 == "ajuda") {
            cout << "Comando: ajuda [comando]\n";
            cout << "Parametros: [comando] (opcional, nome de um comando).\n";
            cout << "Efeito: Lista todos os comandos ou mostra a ajuda detalhada do comando indicado.\n";
            cout << "Falha se: Receber parametros a mais.\n";
            cout << "Exemplo: ajuda compra\n";
        } else if (val1 == "fim") {
            cout << "Comando: fim\n";
            cout << "Parametros: Nenhum.\n";
            cout << "Efeito: Termina a simulacao e liberta todos os recursos alocados.\n";
            cout << "Falha se: Nao se aplica (encerra o programa).\n";
            cout << "Exemplo: fim\n";
        } else {
            cout << "Comando desconhecido: '" << val1 << "'.\n";
            cout << "Escreva 'ajuda' para listar todos os comandos disponiveis.\n";
        }
        cout << "====================================================================\n";
    }

    return f;
}

ComandoAjuda::~ComandoAjuda() {}