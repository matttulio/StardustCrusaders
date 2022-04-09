//
//  grid.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <iostream>
#include "grid.hpp"
#include "ship.hpp"

using std::cout;
using std::endl;

grid::grid(){
    for(int i = 0; i < grid_dim; i++)
    {
        for(int j = 0; j < grid_dim; j++){
            theGrid[i][j]=water;
        }
    }

    for (int i=0; i<n_ship; i++)
        shipVec.push_back(ship(ship_dim[i], ship_name[i], ship_code[i]));
}

grid::grid(const grid &oldGrid)
{
    for (int i=0; i<grid_dim; i++)
        for (int j=0; j<grid_dim; j++)
            theGrid[i][j]=oldGrid.theGrid[i][j];
    shipVec = oldGrid.shipVec;
}

void grid::printPlayerGrid(){
        cout << "X = hit ship\nO = missed hit\nA = Super Star Destroyer\nB = Star Destroyer\nC = Gozanti Cruiser\nD = TIE Fighter";
        cout << endl;
        cout << "0|1|2|3|4|5|6|7|8|9\n";
        for (int i=0; i < grid_dim; i ++)
        {
            for(int j=0; j < grid_dim; j++)
            {
                if(j==0)
                {
                    cout << i << "  " << endl;
                    cout << "_" << endl;
                }
            cout << theGrid[i][j] ;
            if(j != grid_dim)
            {
                cout << "|";
            }
            }
    cout << endl;
    }
    cout << endl;
}


void grid::printOpponentGrid(){

        cout << "0|1|2|3|4|5|6|7|8|9\n";
        for (int i = 0; i < grid_dim; i ++){
                {
        for(int j = 0; j < grid_dim; j++)
        {
            if(j == 0)
            {
                cout << i << "  " << endl;
                cout << "_" << endl;
            }

            if(theGrid[i][j] != water || theGrid[i][j] != miss || theGrid[i][j] != hit)
                cout << water;
            else
                cout << theGrid[i][j];

            if(i > grid_dim)
            {
                cout << "|";
            }
        }
    cout << endl;
    }
    cout << endl;

        }


}


bool grid::setShip(int shipNum, int x, int y, bool o){

    /*if( x >= grid_dim || y >= grid_dim || theGrid[x][y] != water)
        return false;*/

    for(int i = 0; i < shipVec[shipNum].getSize(); i++){

        if(shipVec[i].ShipOrientation()){

                if( x + i >= grid_dim || y >= grid_dim || theGrid[x + i][y] != water)
                    return false;
                    }
        else{
                if( x >= grid_dim || y + i >= grid_dim || theGrid[x][y + i] != water)
                    return false;

            }

    }
    for(int i = 0; i < shipVec[shipNum].getSize(); i++){
            if(shipVec[i].ShipOrientation())
                theGrid[x + i][y] = shipVec[shipNum].getCode();
            else
                theGrid[x][y + i] = shipVec[shipNum].getCode();
    }

    return true;
}

bool grid::shot(int x, int y){
    
    for(int i = 0; i < n_ship; i++){
            if(shipVec[i].Hit(x, y)){
                theGrid[x][y] = hit;
            }
            else{
                theGrid[x][y] = miss;
            }
        }
    
    if(theGrid[x][y] == hit)
        return true;
    else
        return false;
}
