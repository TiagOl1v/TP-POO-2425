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

    // Ler linhas e colunas
    std::string linha;
    std::getline(file, linha);
    linhas = std::stoi(linha.substr(linha.find(" ") + 1));

    std::getline(file, linha);
    colunas = std::stoi(linha.substr(linha.find(" ") + 1));

    // Inicializar o mapa
    mapaReal = new char*[linhas];
    for (int i = 0; i < linhas; ++i)
        mapaReal[i] = new char[colunas + 1]; // +1 para '\0'

    // Ler o mapa
    for (int i = 0; i < linhas; ++i) {
        std::getline(file, linha);

        for (int j = 0; j < colunas; ++j) {
            mapaReal[i][j] = linha[j];
        }
        mapaReal[i][colunas] = '\0'; // Garantir que está null-terminated
    }

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

char* Game::operator[](int row) {
    return mapaReal[row];
}

const char* Game::operator[](int row) const {
    return mapaReal[row];
}

Game::~Game() {
    // Libera a memória alocada
    for (int i = 0; i < linhas; ++i) {
        delete[] mapaReal[i];
    }
    delete[] mapaReal;
}

int Game::getLinhas() const {
    return linhas;
}

int Game::getColunas() const {
    return colunas;
}

void Game::print() const {

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << mapaReal[i][j] << ' ';
        }
        std::cout << '\n';
    }

}
