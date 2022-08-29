//
//  ship.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::atoi;

#ifndef SHIP_HPP
#define SHIP_HPP

class ship{

public:
    
    int getSize() const;
    int getX() const;
    int getY() const;
    string getName() const;
    char getCode() const;


    bool ShipOrientation() const;
    bool ShipDestroyed() const;
    
    
    void setShip(int x, int y, bool o);
    void printShip() const;
    void setHit();
    bool isSunk();
    
protected:
    int shipSize;

    int theX, theY;

    bool destroyed;
    bool orientation;

    string shipName;
    char shipCode;
    
    int health;

};

        
#endif /* SHIP_HPP */
