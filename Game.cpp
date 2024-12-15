
#include "Game.h"

bool verificaLetra(char letra){

    char letras_minusculas[] = "abcdefghijklmnopqrstuvwxyz";
    bool flag = false;

    for (int i = 0; letras_minusculas[i] != '\0'; i++) {
        if (letra == letras_minusculas[i]) {
            flag = true;
            break;
        }
    }

    return flag;
}


Game::Game(std::string  & ficheiro):instantes(0){

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
            if(verificaLetra(mapaReal[i][j])){
                cidades.push_back(Cidade(mapaReal[i][j],i,j));
            }

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

    for (int i = 0; i < 10; ++i) {
        maxCarv[i] = false;
    }

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

void Game::novoTurno() {
    logs.str("");       // Remove o conteúdo do buffer
    logs.clear();
}

void Game::compraCaravana(char tipo, char cidade) {
    int number;
    bool flagPodeComprar = false;

    for ( number = 0; number < 10; ++number) {
        if(!maxCarv[number]){
            flagPodeComprar = true;
            break;
        }
    }
    if (flagPodeComprar){
        for (Cidade& city : cidades) { // Usar referência para modificar o objeto original
            if (city.getCidade() == cidade) {
                if (tipo == 'C' || tipo == 'M' || tipo == 'S') {
                    if(city.compraCaravana(CaravanasUser, tipo,number)){
                        logs << "Comprou uma Caravana na cidade:" << cidade << " do tipo: " << tipo << std::endl;
                        maxCarv[number]= true;
                    }
                    else{
                        logs << "[FALHA]A cidade: " << cidade << " nao tem uma Caravana do tipo: " << tipo << std::endl;
                    }

                    break;
                }
            }
        }
    }
}

void Game::MostraCarv(){
    logs << "Possui as seguintes Caravanas: " << std::endl;
    for( const auto & caravana : CaravanasUser ){
        logs << "Caravana -> " << caravana->getIdNoMapa() << std::endl;
    }

}

const std::ostringstream &Game::getLogs() const {
    return logs;
}




