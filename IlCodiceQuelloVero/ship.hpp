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

#ifndef SHIP_HPP
#define SHIP_HPP

class ship{

public:
    
    virtual int getSize() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual string getName() const = 0;
    virtual char getCode() const = 0;


    virtual bool ShipOrientation() const = 0;
    virtual bool ShipDestroyed() const = 0;
    
    
    virtual void setShip(int x, int y, bool o) = 0;
    virtual void printShip() = 0;
    virtual void setHit() = 0;
    virtual bool isSunk() = 0;

};

        
#endif /* SHIP_HPP */
