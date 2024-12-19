
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


bool Game::MovimentaAll(Caravana *caravana, char direcao){

    int newPosL, newPosC;

    if (direcao == 'D' && (mapaReal[caravana->getPosLinha()][caravana->getPosColuna() + 1] == '.')){
            caravana->setPosColuna(caravana->getPosColuna() + 1);
            newPosL = caravana->getPosLinha();
            newPosC = caravana->getPosColuna();
        }

    else if (direcao == 'E' && (mapaReal[caravana->getPosLinha()][caravana->getPosColuna() - 1] == '.')){
        caravana->setPosColuna(caravana->getPosColuna() - 1);
        newPosL = caravana->getPosLinha();
        newPosC = caravana->getPosColuna();
        }
    else if (direcao == 'B' && (mapaReal[caravana->getPosLinha() - 1][caravana->getPosColuna()] == '.')){
        caravana->setPosColuna(caravana->getPosLinha() - 1);
        newPosL = caravana->getPosLinha();
        newPosC = caravana->getPosColuna();
        }
    else if (direcao == 'C' && (mapaReal[caravana->getPosLinha() + 1][caravana->getPosColuna()] == '.'))
        if (caravana->move()) {
            caravana->setPosColuna(caravana->getPosLinha() + 1);
            newPosL = caravana->getPosLinha();
            newPosC = caravana->getPosColuna();
        }

    if (!caravana->isEstaNaCidade()) {
        mapaReal[newPosL][newPosC] = '.';
    }
    if(caravana->getIdNoMapa() != 99)  {
    mapaReal[newPosL][newPosC] = static_cast<char>(caravana->getIdNoMapa() + '0');
    logs << "Caravana do Utilizador id -> " << caravana->getIdNoMapa() << std::endl;
        return true;
    }else{
        mapaReal[newPosL][newPosC] = '!';
        logs << "Caravana Barbara movida!!!!" << std::endl;
        return true;
    }

}


void Game::Combate(){



}

void Game::VerfCombate(){

    for (CarvBarbaros & Bab : BarbarosC ){
        for(auto & carvUser : CaravanasUser){
            if( (Bab.getPosColuna() == (carvUser->getPosColuna() + 1 )) || Bab.getPosColuna() == (carvUser->getPosColuna() - 1 ) ){
                if ((Bab.getPosLinha() == (carvUser->getPosLinha() + 1 )) || Bab.getPosLinha() == (carvUser->getPosLinha() - 1 )){

                }
            } else if ( ( (Bab.getPosLinha() == (carvUser->getPosLinha() + 1 )) || Bab.getPosLinha() == (carvUser->getPosLinha() - 1 ) )  && (Bab.getPosColuna() == (carvUser->getPosColuna()) )){

            }
        }
    }

}

Game::Game(std::string  & ficheiro):instantes(0){

    std::map<std::string, std::reference_wrapper<int>> parametros = {
            {"moedas", moedas},
            {"instantes_entre_novos_itens", novosItens},
            {"duração_item", PremaneciaItens},
            {"max_itens", MaxItens},
            {"preço_venda_mercadoria", VendaMercadoria},
            {"preço_compra_mercadoria", CompraMercadoria},
            {"preço_caravana", CompraCaravana},
            {"instantes_entre_novos_barbaros", InstSpawnBarb},
            {"duração_barbaros", InstMaxBarbos}
    };
    std::cout << InstSpawnBarb;
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
    instantes++;

    if(!HouveAlt){
    logs.str("");       //limpar logs
    logs.clear();
    HouveAlt = true;
    }

    if(instantes % InstSpawnBarb == 0){
        int nLinha;
        int nColuna;
       do {

        nLinha = std::rand() % linhas;
        nColuna = std::rand() % colunas;

        } while (mapaReal[nLinha][nColuna] != '.');
        BarbarosC.emplace_back(CarvBarbaros(false,nLinha,nColuna));
    }//criar uma cav barbaro

    return;

}

void Game::compraCaravana(char tipo, char cidade) {
    int number;
    bool flagPodeComprar = false;

    if(moedas < CompraCaravana){
        logs << "[FALHA]Nao tem dinheiro suficiente " << std::endl;
        return;
    }

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

void Game::setMoedas(int moedas) {
    Game::moedas = moedas;
}



void Game::MoveCaravana(int id, char direcao) {

    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == id) {
            if(caravana->move()){
                
            }else
                logs << "A caravana não possui mais movimentos neste turno";
        }
    }
}

void Game::setHouveAlt(bool houveAlt) {
    HouveAlt = houveAlt;
}

bool Game::isHouveAlt() const {
    return HouveAlt;
}
