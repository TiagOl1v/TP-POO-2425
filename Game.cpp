//
// Created by Utilizador on 11/16/2024.
//

#include "Game.h"

Game::Game(std::string ficheiro):instantes(0){

    std::map<std::string, std::reference_wrapper<int>> parametros = {
            {"moedas", moedasInic},
            {"instantes_entre_novos_itens", novosItens},
            {"duração_item", PremaneciaItens},
            {"max_itens", MaxItens},
            {"preço_venda_mercadoria", VendaMercadoria},
            {"preço_compra_mercadoria", CompraMercadoria},
            {"preço_caravana", CompraCaravana},
            {"instantes_entre_novos_barbaros", InstSpawnBarb},
            {"duração_barbaros", InstMaxBarbos}
    };

    std::ifstream file(ficheiro);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        throw std::runtime_error("Erro ao abrir o txt dos comandos: " + ficheiro);
    }

    std::string linha;
    file >> linha >> linhas;
    file >> linha >> colunas;
    file.ignore();

    mapaReal = new char*[linhas];
    for (int i = 0; i < linhas; ++i)
        mapaReal[i] = new char[colunas+1];

    for (int i = 0; i < linhas; ++i)
        file.getline(mapaReal[i], colunas + 1);


    while (std::getline(file, linha)) {
        for (auto& param : parametros) {

            if (linha.find(param.first) != std::string::npos) {
                int valor = std::stoi(linha.substr(linha.find(" ") + 1));
                param.second.get() = valor;
                break;
            }

        }
    }

    file.close();

}

int Game::getLinhas() const {
    return linhas;
}

int Game::getColunas() const {
    return colunas;
}


