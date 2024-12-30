
#include "Game.h"
#include <cstdlib>
#include <ctime>

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

bool Game::Movimenta(Caravana *caravana, char direcao) {

    int newPosL, newPosC;
    bool moveu = false;

    newPosL = caravana->getPosLinha();
    newPosC = caravana->getPosColuna();

    if (direcao == 'D'){
        ++newPosC;

        if(newPosC == colunas)
            newPosC = 0;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosColuna(newPosC);
                moveu = true;
            }
        }
    }else if (direcao == 'E'){
        --newPosC;

        if(newPosC == -1)
            newPosC = colunas - 1;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosColuna(newPosC);
                moveu = true;
            }
        }
    } else if (direcao == 'B'){
        ++newPosL;

        if(newPosL == linhas)
            newPosL = 0;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosLinha(newPosL);
                moveu = true;
            }
        }
    } else if (direcao == 'C'){
        --newPosL;

        if(newPosL == -1)
            newPosL = linhas - 1;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosLinha(newPosL);
                moveu = true;
            }
        }
    }

    if (moveu) {

        mapaReal[newPosL][newPosC] = '!';
        logs << "Caravana Barabara foi movida cuidado! " << std::endl;

    }
    return moveu;
}


bool Game::Movimenta(std::unique_ptr<Caravana>& caravana, char direcao){

    int newPosL, newPosC;
    bool moveu = false;

    newPosL = caravana->getPosLinha();
    newPosC = caravana->getPosColuna();

    if (direcao == 'D'){
        ++newPosC;

        if(newPosC == colunas)
            newPosC = 0;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosColuna(newPosC);
                moveu = true;
            }
        }
    }else if (direcao == 'E'){
        --newPosC;

        if(newPosC == - 1)
            newPosC = colunas - 1;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosColuna(newPosC);
                moveu = true;
            }
        }
    } else if (direcao == 'B'){
        ++newPosL;

        if(newPosL == linhas)
            newPosL = 0;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosLinha(newPosL);
                moveu = true;
            }
        }
    } else if (direcao == 'C'){
        --newPosL;

        if(newPosL == -1)
            newPosL = linhas - 1;

        if((mapaReal[newPosL][newPosC] == '.') || verificaLetra(mapaReal[newPosL][newPosC]) ) {
            if (caravana->move()) {

                if (!caravana->isEstaNaCidade())
                    mapaReal[caravana->getPosLinha()][caravana->getPosColuna()] = '.';

                caravana->setPosLinha(newPosL);
                moveu = true;
            }
        }
    }

    if (moveu) {
        AtualizaQuemEstaNaCidade();
        if(!caravana->isEstaNaCidade())
        mapaReal[newPosL][newPosC] = static_cast<char>(caravana->getIdNoMapa() + '0');

        logs << "Caravana do Utilizador id -> " << caravana->getIdNoMapa() << " foi movida" << std::endl;

    }
    return moveu;

}

void Game::AtualizaQuemEstaNaCidade(){

    for (auto &caravana: CaravanasUser) {
        for (const Cidade &cidade : cidades) {
            if( (caravana->getPosLinha() == cidade.getPosLinha())  && (caravana->getPosColuna() == cidade.getPosColuna())){
                    caravana->setEstaNaCidade(true);
                    break;
            }
            else {
                caravana->setEstaNaCidade(false);
            }
        }
    }

    for (CarvBarbaros &caravana: BarbarosC) {
        for (const Cidade &cidade : cidades) {
            if( (caravana.getPosLinha() == cidade.getPosLinha())  && caravana.getPosColuna() == cidade.getPosColuna()) {
                caravana.setEstaNaCidade(true);
                break;
            }
            else
                caravana.setEstaNaCidade(false);
        }
    }

}



void Game::VerfCombate(){
    bool removeBarbaro = false;
    int numSorteioUser,numSorteioBarbaro;

    for (auto Bab = BarbarosC.begin(); Bab != BarbarosC.end(); ) {
        bool removeBarbaro = false;
        for(auto & carvUser : CaravanasUser){
            if( (Bab->getPosColuna() == (carvUser->getPosColuna() + 1 )) || Bab->getPosColuna() == (carvUser->getPosColuna() - 1 ) || Bab->getPosColuna() == (carvUser->getPosColuna())){
                if ((Bab->getPosLinha() == (carvUser->getPosLinha() + 1 )) || Bab->getPosLinha() == (carvUser->getPosLinha() - 1 ) || (Bab->getPosLinha() == (carvUser->getPosLinha() ))){
                        if(!carvUser->isEstaNaCidade() && !Bab->isEstaNaCidade()){
                            logs << "BATALHA!!! entre a caravana do user id -> " << carvUser->getIdNoMapa() << "e caravana barbara"<< std::endl;
                             numSorteioBarbaro = Bab->batalha() ;
                             numSorteioUser = carvUser->batalha() ;
                            logs << "Numero Sorteado pela carv user: " <<numSorteioUser << " numero sorteado pela carv barbara: "<< numSorteioBarbaro << std::endl;
                            if ( numSorteioUser < numSorteioBarbaro)
                            {
                                int tripulacaoRetirada =  carvUser->getTripulacao() - Bab->AposCombate();
                                if(tripulacaoRetirada <= 0) {

                                    std::vector<std::unique_ptr<Caravana>> temp;
                                    for (auto& aux : CaravanasUser) {
                                        if (aux->getIdNoMapa() != carvUser->getIdNoMapa()) {
                                            temp.push_back(std::move(aux));
                                        }
                                    }
                                    maxCarv[carvUser->getIdNoMapa()] = false;
                                    mapaReal[carvUser->getPosLinha()][carvUser->getPosColuna()] = '.';
                                    logs << "Caravana do user foi eleminada com id -> " << carvUser->getIdNoMapa() << std::endl;

                                    CaravanasUser = std::move(temp);
                                    break;
                                }
                                else{
                                     carvUser->setTripulacao2(tripulacaoRetirada);
                                    logs << "Foram retirados tripulantes carv user: " << tripulacaoRetirada <<std::endl;
                                }
                            }else if(numSorteioUser > numSorteioBarbaro){
                                int RetiradaR = Bab->getTripulacao() - carvUser->AposCombate();
                                if(RetiradaR <= 0){
                                    logs << "Caravana bárbara foi eliminada." << std::endl;
                                    removeBarbaro = true;
                                    mapaReal[Bab->getPosLinha()][Bab->getPosColuna()] = '.';
                                    logs << "Foram retirados pela carv Bab: " << RetiradaR <<std::endl;
                                    break;
                                }else{
                                    Bab->setTripulacao2(RetiradaR);
                                    logs << "Foram tripulantes  pela carv Bab: " << RetiradaR <<std::endl;
                                }


                            }else
                                logs << "Deu empate!! " << std::endl;

                        }
                }
            }
        }
        if (removeBarbaro) {
            Bab = BarbarosC.erase(Bab);
        } else {
            ++Bab;
        }
    }


}

Game::Game(std::string  & ficheiro):instantes(0){
    std::srand(std::time(0));
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

    std::ifstream file(ficheiro);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        throw std::runtime_error("Erro ao abrir o txt dos comandos: " + ficheiro);
    }

    // Ler linhas e colunas
    std::string linha;
    std::getline(file, linha);
    linhas = std::stoi(linha.substr(linha.find(' ') + 1));

    std::getline(file, linha);
    colunas = std::stoi(linha.substr(linha.find(' ') + 1));

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
                cidades.emplace_back(mapaReal[i][j],i,j);
            }
            else if(mapaReal[i][j] != '.' && mapaReal[i][j] != '+'){
                mapaReal[i][j]= '.';
            }


        }
        mapaReal[i][colunas] = '\0';
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

void Game::MostraDcaravana(int id) {

    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == id) {

            if (auto comercio = dynamic_cast<CarvComercio *>(caravana.get())) {
                logs << "Caravana comercio:\n" << "id: " << comercio->isEstaNaCidade() << "\nTripulantes: " << comercio->getTripulacao() << "\nPos: " << comercio->getPosLinha() << " , " << comercio->getPosColuna();
            } else if (auto militar = dynamic_cast<CarvMilitar *>(caravana.get())) {
                logs << "Caravana militar:\n" << "id: " << militar->isEstaNaCidade() << "\nTripulantes: " << militar->getTripulacao() << "\nPos: " << militar->getPosLinha() << " , " << militar->getPosColuna();
            } else if (auto surpresa = dynamic_cast<CarvSecreta *>(caravana.get())) {
                logs << "Caravana surpresa:\n" << "id: " << surpresa->isEstaNaCidade() << "\nTripulantes: " << surpresa->getTripulacao() << "\nPos: " << surpresa->getPosLinha() << " , " << surpresa->getPosColuna();


            }

        }
    }
}
char* Game::operator[](int row) {
    return mapaReal[row];
}

const char* Game::operator[](int row) const {
    return mapaReal[row];
}

void Game::resetLogs() {
    logs.str("");       //limpar logs
    logs.clear();
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
        resetLogs();
        HouveAlt= true;
    }

    AtualizaQuemEstaNaCidade();
    VerfCombate();

    if(instantes % InstSpawnBarb == 0){
        int nLinha;
        int nColuna;

       do {

        nLinha = std::rand() % linhas;
        nColuna = std::rand() % colunas;

        } while (mapaReal[nLinha][nColuna] != '.');
        BarbarosC.emplace_back(false,nLinha,nColuna);
        BarbarosC.back().setIdNoMapa(99);
        mapaReal[nLinha][nColuna] = '!';
        logs << "Spawn Caravana Barbara " << std::endl;
    }//criar uma cav barbaro

    for (CarvBarbaros& barbaro : BarbarosC) {

        int chance = std::rand() % 4;

        if (chance == 0) {
            Movimenta(&barbaro,'D');
        } else if (chance == 1) {
            Movimenta(&barbaro,'E');
        } else if (chance == 2) {
            Movimenta(&barbaro,'B');
        } else if (chance == 3) {
            Movimenta(&barbaro,'C');
        }
    }

    for (auto & caravana : CaravanasUser)
        caravana->resetMoves();


    AtualizaQuemEstaNaCidade();

    return;

}

void Game::compraCaravana(char tipo, char cidade) {
    int number;
    bool flagPodeComprar = false;

    if(moedas < CompraCaravana){
        logs << "[FALHA]Nao tem dinheiro suficiente " << std::endl;
        return;
    }
    std::cout << "antes: " << moedas << std::endl;
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
                        logs << "[Sucesso] Comprou uma Caravana na cidade:" << cidade << " do tipo: " << tipo << std::endl;
                        maxCarv[number]= true;
                        std::cout << "Conta: " << moedas << " - " << CompraCaravana << std::endl;
                        moedas = moedas - CompraCaravana;
                        std::cout << "Dinheiro: " << moedas << std::endl;
                    }
                    else{
                        logs << "[FALHA]A cidade: " << cidade << " nao tem uma Caravana do tipo: " << tipo << std::endl;
                    }

                    break;
                }
            }
        }
    }
    else
        logs << "[FALHA]Max de caravanas em posse antigido" << std::endl;
}

void Game::MostraCarv(){
    logs << "Possui as seguintes Caravanas: " << std::endl;
    for( const auto & caravana : CaravanasUser ){
        logs << "Caravana IDgit -> " << caravana->getIdNoMapa() << std::endl;
    }
}

void Game::MostraPmerc(){
    logs << "Preco de compra mercadoria: " << CompraMercadoria << std::endl;
    logs << "Preco de venda mercadoria: " << VendaMercadoria << std::endl;

}

const std::ostringstream &Game::getLogs() const {
    return logs;
}

void Game::setMoedas(int moedas) {
    Game::moedas = moedas;
}

void Game::MoveCaravana(int id, char direcao) {

    bool ex=false;

    AtualizaQuemEstaNaCidade();
    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == id) {
            if(caravana->move()){
                Movimenta(caravana,direcao);
                ex = true;
            }else {
                logs << "[FALHA] A caravana nao tem mais movimentos neste turno" << std::endl;
                ex = true;
            }
        }
    }
    if(!ex)
    logs << "[FALHA] A caravana com esse id nao foi encontrada" << std::endl;
}

void Game::CreateBarber(int l, int c){

    if(mapaReal[l][c] == '.'){
        BarbarosC.emplace_back(false,l,c);
        BarbarosC.back().setIdNoMapa(99);
        mapaReal[l][c] = '!';
        logs << "[Sucesso]Spawn de uma Caravana de barbaros" << std::endl;
    }
    else
        logs << "[FALHA] Nao foi realizado o spawn Caravana de barbaros" << std::endl;
}

void Game::compraMercadoria(int idCarv, int toneladas) {
    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == idCarv) {
            if (!caravana->isEstaNaCidade()) {
                logs << "[FALHA] Precisa estar na cidade para comprar mercadoria" << std::endl;
                return;
            }

            if (moedas < CompraMercadoria * toneladas) {
                logs << "[FALHA] Nao tem dinheiro suficiente " << std::endl;
                return;
            }

            if (auto comercio = dynamic_cast<CarvComercio *>(caravana.get())) {
                if (toneladas > comercio->getMaxCarga()) {
                    logs << "[FALHA] A carga maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                comercio->setcargaAtual(toneladas);
            } else if (auto militar = dynamic_cast<CarvMilitar *>(caravana.get())) {
                if (toneladas > militar->getMaxCarga()) {
                    logs << "[FALHA] A carga maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                militar->setcargaAtual(toneladas);
            } else if (auto secreta = dynamic_cast<CarvSecreta *>(caravana.get())) {
                if (toneladas > secreta->getMaxCarga()) {
                    logs << "[FALHA] A carga maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                secreta->setcargaAtual(toneladas);
            }

            moedas -= CompraMercadoria * toneladas;
            logs << "[SUCESSO] Mercadoria comprada com sucesso!" << std::endl;
            return;
        }
    }

    // nenhuma caravana encontrada
    logs << "[FALHA] A caravana com esse id nao foi encontrada" << std::endl;
}

void Game::vendeMercadoria(int idCarv) {
    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == idCarv) {
            if (!caravana->isEstaNaCidade()) {
                logs << "[FALHA] Precisa estar na cidade para vender mercadoria" << std::endl;
                return;
            }

            if (auto comercio = dynamic_cast<CarvComercio *>(caravana.get())) {
                moedas += VendaMercadoria * comercio->getcargaAtual();
                comercio->zeracargaAtual();
            } else if (auto militar = dynamic_cast<CarvMilitar *>(caravana.get())) {
                moedas += VendaMercadoria * militar->getcargaAtual();
                militar->zeracargaAtual();
            } else if (auto secreta = dynamic_cast<CarvSecreta *>(caravana.get())) {
                moedas += VendaMercadoria * secreta->getcargaAtual();
                secreta->zeracargaAtual();
            }
        }
        logs << "[SUCESSO] Mercadorias vendidas com sucesso!" << std::endl;
        return;
    }

    logs << "[FALHA] A caravana com esse id nao foi encontrada" << std::endl;
}

void Game::compraTripulantes(int idCarv, int tripulantes) {
    for (auto &caravana: CaravanasUser) {
        if (caravana->getIdNoMapa() == idCarv) {
            if (!caravana->isEstaNaCidade()) {
                logs << "[FALHA] Precisa estar na cidade para comprar tripulacao" << std::endl;
                return;
            }

            if (dynamic_cast<CarvComercio *>(caravana.get())) {
                if (tripulantes + caravana->getTripulacao() > 30) {
                    logs << "[FALHA] A tripulacao maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                caravana->setTripulacao(tripulantes);
            } else if (dynamic_cast<CarvMilitar *>(caravana.get())) {
                if (tripulantes + caravana->getTripulacao() > 40) {
                    logs << "[FALHA] A carga maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                caravana->setTripulacao(tripulantes);
            } else if (dynamic_cast<CarvSecreta *>(caravana.get())) {
                if (tripulantes + caravana->getTripulacao() > 40) {
                    logs << "[FALHA] A carga maxima da caravana ja foi excedida! " << std::endl;
                    return;
                }
                caravana->setTripulacao(tripulantes);
            }

            moedas -= tripulantes; //1 moeda cada tripulante comprado
            logs << "[SUCESSO] Tripulacao comprada com sucesso!" << std::endl;
            return;
        }
    }

    // nenhuma caravana encontrada
    logs << "[FALHA] A caravana com esse id nao foi encontrada" << std::endl;
}

void Game::setHouveAlt(bool houveAlt) {
    HouveAlt = houveAlt;
}

bool Game::isHouveAlt() const {
    return HouveAlt;
}
