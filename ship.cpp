//
//  ship.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <iostream>

#include "ship.hpp"
#include "constants.hpp"

using std::cout;


ship::ship(int dim, std::string name, char code){
    
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
    shipKind = new char [shipSize];
    
    for(int i = 0; i < shipSize; i++){
        shipKind[i] = shipCode;
    }
    
    theX = 0;
    theY = 0;
    
    destroyed = false;
}

ship::ship(int dim, std::string name, char code, int x, int y, bool s, bool o){
    
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
    
    
}

int ship::getSize() const{
    return shipSize;
}

int ship::getX() const{
    return theX;
}

int ship::getY() const{
    return theY;
}

std::string ship::getName() const{
    return shipName;
}

char ship::getCode() const{
    return shipCode;
}

