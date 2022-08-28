//
//  grid.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

#include <unistd.h>
#include <cstdlib>
#include <math.h>

#include "SuperStarDestroyer.hpp"
#include "StarDestroyer.hpp"
#include "GozantiCruiser.hpp"
#include "TIEFighter.hpp"

#include "ship.hpp"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class grid{

public:
    
    void recordGrid(int d_grid, int num_ships, bool player_mode, string op_name);

    void printInfo();
    void printPlayerGrid();
    void setGrid(bool player_mode);
    void printOpponentGrid();
    
    void CountDown (int count) const;
    
    bool getPmode() const;
    bool isShotBy(grid board);//grid indica il tipo e board il nome
    
    bool hittable() const;
    
    void countTheShots(int& num_hit, int& num_miss);

    
private:
    int dim_grid;
    bool p_mode;
    
    int color;
    
    string opponent;
    
    vector< vector<char> > theGrid; //usiamo la struttura vector così da potere decidere in seguito la dimensione della nostra matrice, se avessi usato un semplice array avrei dovuto definirla a priori dal codice e non avrei potuto deciderla una volta avviato il programma
    
    vector<char> row; //riempiamo prima le righe e poi usiamo push_back per metterle dentro la matrice, dopo di che si gestisce come un semplice array
    
    int n_ships;
    
    vector<ship*> shipVec;
    
    superstardestroyer ssd;
    stardestroyer sd;
    gozanticruiser gc;
    TIEfighter tf;
    
    
    char unknown;
    char hit;
    char sunk;
    char water;
    char miss;
    
    int *orientation;

};
#endif // GRIGLIA_H_INCLUDED /* grid_hpp */
