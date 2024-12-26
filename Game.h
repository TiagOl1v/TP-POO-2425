
#ifndef TP_POO2425_GAME_H
#define TP_POO2425_GAME_H


#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <sstream>
#include <Cidade.h>

class Game {

    int instantes;
    int carvAtuais;
    int nCitys; // numero de cidades
    bool HouveAlt; //detectar se o mapa mudou

    //----------------- variaveis txt -----------------
    int moedas; //numero inicial de moedas
    int novosItens; // intantes a que sao colucados itens
    int MaxItens; // max de itens
    int PremaneciaItens; //maximo que o item vai permanecer
    int InstMaxBarbos;  // maximo que os barbaros duram
    int InstSpawnBarb; //intantes ate spawnar novos barbaros
    int VendaMercadoria;
    int CompraMercadoria;
    int CompraCaravana;

    int linhas,colunas;
    char **mapaReal;

    std::ostringstream logs;
    std::vector<Cidade> cidades;
    std::vector<std::unique_ptr<Caravana>> CaravanasUser;
    std::map<int, bool> maxCarv;
    std::vector<CarvBarbaros> BarbarosC;

    void AtualizaQuemEstaNaCidade();
    void VerfCombate();
    void Combate();
    bool Movimenta(Caravana *caravana, char direcao);
    bool Movimenta(std::unique_ptr<Caravana>& caravana, char direcao);

public:

    Game(std::string & ficheiro);
    int getLinhas() const;
    int getColunas() const;

    void setMoedas(int moedas);

    void novoTurno();


    void compraCaravana(char tipo, char cidade);
    char* operator[](int row);
    const char* operator[](int row) const;
    void MostraCarv();
    void MoveCaravana(int id, char direcao);
    const std::ostringstream &getLogs() const;


    void setHouveAlt(bool houveAlt);
    bool isHouveAlt() const;
    void resetLogs();
    void CreateBarber(int l, int c);
    void compraMercadoria(int Merc, int id);

    void MostraPmerc();
    
    ~Game();


};


#endif //TP_POO2425_GAME_H
