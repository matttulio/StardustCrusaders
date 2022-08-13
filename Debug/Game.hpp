//
//  Play.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 13/07/22.
//https://open.spotify.com/album/2rwQ71x5mXHX162ce5ypy7?si=4DNuO8pORHe-t8S72H_l3Q

#ifndef Game_HPP
#define Game_HPP

#include <stdio.h>
#include <string>
#include "ship.hpp"
#include "grid.hpp"


class game{
    
public:
    
    game();
    
    game(bool m, bool s, int n, int d, string name1, string name2, bool p1, bool p2); //l'oggetto game si porta le caratterische generali dietro, quindi modalità, stato del match, numero di navi e dimensione della griglia
    
    void PrintMenu();   //conterrà un print con dentro titolo del gioco, autori e gioca/esci, se gioca allora esce dalla funzione ed entra in SetGameMode
    
    void PrintInstructions();
    
    void SetGameMode(); //nel nostro caso assegnerà dei valori a variabili come la dimensione della grid, il numero di navi e se cpu vs p o pvp, dopo di che si passa a whostart
    
    bool GetStatus() const;   //restituisce lo stato della partita, se la partita è in corso = true
    
    bool GetMode() const;
    
    int GetNumShips() const;
    
    int GetDimGrid() const;
    
    void WhoStarts();    //randomizza un numero, se pari inizia p1 se dispari inizia p2
    
    int GetWhoStarts() const;
    
    bool GetP1Mode() const;
    
    bool GetP2Mode() const;
    
    //BISOGNA DECIDERE SE RAGGRUPPARE IN UN'UNICA FUNZIONE  LE DUE SEGUENTI, PER ORA MI SEMBRA PIÙ COMODO COSÌ
    void Play(); //racchiude tutte le funzioni necessarie per giocare intera partita, esce quando il while che gira sulle navi distrutte raggiunge il numero dato dal setgamemode
    
    void PlayPvCPU();   //lo stesso ma con la CPU
    
    void Shoot();   //contiene cin che prende coordinate e le passa alla funzione di grid
    
    void PrintWinnerScreen();   //stampa una schermata con sopra il nome del vincitore e dei complimenti, magari mettere possibilità di rigiocare con cin che setta un bool che permette di stare dentro un while grosso nel main
    
    grid p1;
    grid p2;

    account A1;
    account A2;

private:
    bool mode;
    bool status;
    
    int n_ships;
    int dim_grid;
    
    int whostart;
    
    string player1_name;
    string player2_name;
    
    bool player1_mode;
    bool player2_mode;
    
    bool who_won;
    
    vector<string> random_name;
    
    int n_hit; //numero di hit e sunk
    int n_miss; //numero di miss
    
    
};


#endif /* Game_hpp */
