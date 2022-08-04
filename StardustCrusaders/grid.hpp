//
//  grid.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>

#include "SuperStarDestroyer.hpp"
#include "StarDestroyer.hpp"
#include "GozantiCruiser.hpp"
#include "TIEFighter.hpp"

#include "constants.hpp"
#include "Game.hpp"
#include "ship.hpp"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class grid{

public:
    grid();
    grid(int d_grid, int n_ships, bool player_mode);

    void printInfo();
    void printPlayerGrid();
    void setGrid(bool player_mode);
    void printOpponentGrid();
    
    void CountDown (int count) const;
    
    bool getPmode() const;
    bool isShotBy(grid board);//grid indica il tipo e board il nome
    
    bool hittable() const;

    
private:
    int dim_grid;
    bool p_mode;
    vector< vector<char> > theGrid; //usiamo la struttura vector così da potere decidere in seguito la dimensione della nostra matrice, se avessi usato un semplice array avrei dovuto definirla a priori dal codice e non avrei potuto deciderla una volta avviato il programma
    vector<char> row; //riempiamo prima le righe e poi usiamo push_back per metterle dentro la matrice, dopo di che si gestisce come un semplice array
    
    int n_ships;
    
    vector<ship*> shipVec;
    
    superstardestroyer ssd;
    stardestroyer sd;
    gozanticruiser gc;
    TIEfighter tf;
    
    
    /*
    int *r = new int(0);
    int *orientation = new int(0);
    bool *already_hit = new bool(false);
    int *Try_z = new int(0);
    bool *direction_hit = new bool(true); //se vero allora spara verso destra/verso il basso (+), se false allora spara verso sinistra/verso alto (-)
    
    int *old_shots = new int [10];
    int *theX = new int;
    int *theY = new int;
    int *theK = new int;
*/
    int *orientation;
    //bool *already_hit = new bool(false);

};
#endif // GRIGLIA_H_INCLUDED /* grid_hpp */
