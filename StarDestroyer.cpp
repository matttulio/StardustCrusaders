//
//  StarDestroyer.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "StarDestroyer.hpp"

stardestroyer::stardestroyer(){
    shipSize = 4;
    
    shipName = "Star Destroyer";
    
    shipCode = 'B';
    
    health = shipSize;
}

stardestroyer::stardestroyer(int dim, string name, char code){
    
    shipSize = dim;
    
    shipName = name;
    
    shipCode = code;
    
    health = shipSize;
    
}

int stardestroyer::getSize() const{
    return shipSize;
}


int stardestroyer::getX() const{
    return theX;
}


int stardestroyer::getY() const{
    return theY;
}


string stardestroyer::getName() const{
    return shipName;
}


char stardestroyer::getCode() const{
    return shipCode;
}


bool stardestroyer::ShipOrientation() const{
    return orientation;
}


bool stardestroyer::ShipDestroyed() const{
    return destroyed;
}


void stardestroyer::setShip(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}


void stardestroyer::printShip(){
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    
    return;
}


void stardestroyer::setHit(){
    
    health--;
    
}

bool stardestroyer::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
        
}
