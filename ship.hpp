//
//  ship.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#ifndef SHIP_HPP
#define SHIP_HPP

class ship{

public:
    
    ship();
    ship(int dim, string name, char code);
    ship(int dim, string name, char code, int x, int y, bool d, bool o, int h);

    int getSize() const;
    int getX() const;
    int getY() const;
    string getName() const;
    char getCode() const;


    bool ShipOrientation() const;
    bool ShipDestroyed() const;
    bool isSunk();
        
        
    void setShip(int x, int y, bool o);
    void printShip();
    void setHit();

private:
    int shipSize;
    
    int theX, theY;
    
    bool destroyed;
    bool orientation;
    
    int health;
    
    string shipName;
    char shipCode;
};

        
#endif /* SHIP_HPP */
