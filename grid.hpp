//
//  grid.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED

#include <string>
#include <vector>
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
    grid(game m, bool player_mode);

    void printInfo();
    void printPlayerGrid();
    void setGrid(bool player_mode);
    void printOpponentGrid();
    bool isShotBy(grid board);//grid indica il tipo e board il nome



private:
    int dim_grid;
    bool p_mode;
    vector< vector<char> > theGrid; //usiamo la struttura vector così da potere decidere in seguito la dimensione della nostra matrice, se avessi usato un semplice array avrei dovuto definirla a priori dal codice e non avrei potuto deciderla una volta avviato il programma
    vector<char> row;   //riempiamo prima le righe e poi usiamo push_back per metterle dentro la matrice, dopo di che si gestisce come un semplice array
    int n_ships;
    vector<ship> shipVec;
    
    int *r = new int(0);
    int *orientation = new int(0);
    bool *already_hit = new bool(false);
    int *Try_z = new int(0);


};
#endif // GRIGLIA_H_INCLUDED /* grid_hpp */
