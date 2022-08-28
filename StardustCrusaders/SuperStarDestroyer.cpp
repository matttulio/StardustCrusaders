//
//  SuperStarDestroyer.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "SuperStarDestroyer.hpp"

superstardestroyer::superstardestroyer(){
    shipSize = 5;
    
    shipName = "Super Star Destroyer";
    
    shipCode = 'A';
    
    health = shipSize;
}

int superstardestroyer::getSize() const{
    return shipSize;
}


int superstardestroyer::getX() const{
    return theX;
}


int superstardestroyer::getY() const{
    return theY;
}


string superstardestroyer::getName() const{
    return shipName;
}


char superstardestroyer::getCode() const{
    return shipCode;
}


bool superstardestroyer::ShipOrientation() const{
    return orientation;
}


bool superstardestroyer::ShipDestroyed() const{
    return destroyed;
}


void superstardestroyer::setShip(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}


void superstardestroyer::printShip() const{
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    
    return;
}


void superstardestroyer::setHit(){
    
    health--;
    return;
    
}

bool superstardestroyer::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
}
