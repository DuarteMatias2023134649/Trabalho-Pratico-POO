cmake_minimum_required(VERSION 3.30)
project(TrabalhoPratico)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
include_directories(
        Maquinas
        Comandos
        Itens
)
add_executable(TrabalhoPratico
        main.cpp
        Settings.h
        Ecra.cpp Ecra.h
        Engenheiro.cpp Engenheiro.h
        Fabrica.cpp Fabrica.h
        Simulador.cpp Simulador.h
        Terreno/Terreno.cpp  Terreno/Terreno.h
 
        Maquinas/Lancador.cpp Maquinas/Lancador.h
        Maquinas/Maquina.cpp Maquinas/Maquina.h
        Maquinas/Oficina.cpp Maquinas/Oficina.h
        Maquinas/Perfuradora.cpp Maquinas/Perfuradora.h
        Maquinas/Refinaria.cpp Maquinas/Refinaria.h
        Maquinas/Silo.cpp Maquinas/Silo.h
        Maquinas/Transportador.cpp Maquinas/Transportador.h
        
        Comandos/Comandos.cpp Comandos/Comandos.h
        Comandos/ComandoAvanca.cpp Comandos/ComandoAvanca.h
        Comandos/ComandoCarrega.cpp Comandos/ComandoCarrega.h
        Comandos/ComandoContrata.cpp Comandos/ComandoContrata.h
        Comandos/ComandoFabrica.cpp Comandos/ComandoFabrica.h
        Comandos/ComandoFim.cpp Comandos/ComandoFim.h
        Comandos/ComandoLposicao.cpp Comandos/ComandoLposicao.h
        Comandos/ComandoAjuda.cpp Comandos/ComandoAjuda.h
        Comandos/ComandoGrava.cpp Comandos/ComandoGrava.h
  
        Itens/Itens.cpp Itens/Itens.h
        Itens/Agua.cpp Itens/Agua.h
        Itens/Gelo.cpp Itens/Gelo.h
        Itens/KitHabitat.cpp Itens/KitHabitat.h
        Itens/MinerioDeFerro.cpp Itens/MinerioDeFerro.h
        Itens/PlacaDeFerro.cpp Itens/PlacaDeFerro.h
        Itens/SilicioBruto.cpp Itens/SilicioBruto.h
        Itens/SilicioPuro.cpp Itens/SilicioPuro.h
        Comandos/ComandoEstado.cpp
        Comandos/ComandoEstado.h
        Comandos/ComandoCompra.cpp
        Comandos/ComandoCompra.h
        Comandos/ComandoVende.cpp
        Comandos/ComandoVende.h
        Comandos/ComandoRoda.cpp
        Comandos/ComandoRoda.h
        Terreno/Cratera.cpp
        Terreno/Cratera.h
        Terreno/Solo.cpp
        Terreno/Solo.h
        Terreno/Deposito.cpp
        Terreno/Deposito.h
        Comandos/ComandoRecupera.cpp
        Comandos/ComandoRecupera.h
)
