//
//  grid.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>

#include "SuperStarDestroyer.hpp"
#include "StarDestroyer.hpp"
#include "GozantiCruiser.hpp"
#include "TIEFighter.hpp"

#include "constants.hpp"

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
    
    bool getPmode() const;
    bool isShotBy(grid board);//grid indica il tipo e board il nome
    
    bool hittable() const;
    
    void recordGrid(int d_grid, int num_ships, bool player_mode);

    void countTheShots(int& num_hit, int& num_miss);


    
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
    
    
    int *orientation;

};
#endif // GRIGLIA_H_INCLUDED /* grid_hpp */


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

//bool *already_hit = new bool(false);
