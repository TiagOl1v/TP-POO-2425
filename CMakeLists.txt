cmake_minimum_required(VERSION 3.24.2)
project(TP_POO2425)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(TP_POO2425
        Buffer.cpp
        Buffer.h
        Cidade.cpp
        Cidade.h
        Game.cpp
        Game.h
        Interface.cpp
        Interface.h
        ListaComandos.cpp
        ListaComandos.h
        Caravana.cpp
        Caravana.h
        main.cpp
        CarvComercio.cpp
        CarvComercio.h
        CarvBarbaros.cpp
        CarvBarbaros.h
        CarvMilitar.cpp
        CarvMilitar.h)
