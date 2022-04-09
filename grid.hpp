//
//  grid.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <string>
#include <vector>
#include "constants.hPP"
#include "ship.hpp"

class grid{

public:
    grid();
    grid(const grid &oldGrid);
    grid& operator=(const grid &right);
    ~grid();

    void printPlayerGrid();
    void printOpponentGrid();
    bool setShip(int shipNum, int x, int y, bool o);
    bool shot(int x, int y);



private:
   char theGrid[grid_dim][grid_dim];
   std::vector<ship> shipVec;


};
#endif // GRIGLIA_H_INCLUDED /* grid_hpp */
