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
using std::endl;


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
    orientation = false;
}


ship::ship(int dim, std::string name, char code, int x, int y, bool d, bool o){
    
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
    shipKind = new char [shipSize];
    
    for(int i = 0; i < shipSize; i++){
        shipKind[i] = shipCode;
    }
    
    theX = x;
    theY = y;
    
    destroyed = d;
    
    orientation = o;
}


ship::ship(const ship &oldShip){
    
    shipSize = oldShip.getSize();
    shipName = oldShip.getName();
    shipCode = oldShip.getCode();
    
    shipKind = new char [shipSize];
    
    for(int i = 0; i < shipSize; i++){
        shipKind[i] = shipCode;
    }
    
    theX = oldShip.getX();
    theY = oldShip.getY();
    
    destroyed = oldShip.ShipDestroyed();
    
    orientation = oldShip.ShipOrientation();
    
}


ship& ship::operator=(const ship &right){
    
    if(this != &right){
        
        shipSize = right.getSize();
        shipName = right.getName();
        shipCode = right.getCode();
        
        theX = right.getX();
        theY = right.getY();
        
        destroyed = right.ShipDestroyed();
        
        orientation = right.ShipOrientation();
        
        if(shipSize > 0){
            
            delete [] shipKind;
            shipKind = new char [shipSize];
            
            for(int i = 0; i < shipSize; i++){
                
                shipKind[i] = shipCode;
            }
        }
    }
    
    return *this;
}

ship::~ship(){
    
    if (shipSize > 0)
        delete [] shipKind;
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


bool ship::ShipOrientation() const{
    return orientation;
}


bool ship::ShipDestroyed() const{
    return destroyed;
}


void ship::setPosition(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}

void ship::printShip(){
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipKind << " ";
    }
    
    cout << endl;
    
    return;
}

bool ship::Hit(int xHit, int yHit){
    
    if((xHit != theX || xHit >= theX + shipSize || xHit < theX) || (yHit != theY || yHit >= theY + shipSize || yHit < theY))
        return false;
    else
    {
        if(orientation)
            shipKind[xHit - theX] = hit;
        else
            shipKind[yHit - theY] = hit;
    }
    
    int k = 0;
    
    for(int i = 0; i < shipSize; i++){
        if(shipKind[i] == hit)
            k++;
        if(k == shipSize)
            destroyed = true;
    }
    
    return true;
}

