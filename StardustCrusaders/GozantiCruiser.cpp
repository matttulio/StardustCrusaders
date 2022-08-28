//
//  GozantiCruiser.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "GozantiCruiser.hpp"

gozanticruiser::gozanticruiser(){
    
    shipSize = 3;
    
    shipName = "Gozanti Cruiser";
    
    shipCode = 'C';
    
    health = shipSize;
    
}


int gozanticruiser::getSize() const{
    return shipSize;
}


int gozanticruiser::getX() const{
    return theX;
}


int gozanticruiser::getY() const{
    return theY;
}


string gozanticruiser::getName() const{
    return shipName;
}


char gozanticruiser::getCode() const{
    return shipCode;
}


bool gozanticruiser::ShipOrientation() const{
    return orientation;
}


bool gozanticruiser::ShipDestroyed() const{
    return destroyed;
}


void gozanticruiser::setShip(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}


void gozanticruiser::printShip() const{
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    
    return;
}


void gozanticruiser::setHit(){
    
    health--;
    return;
}

bool gozanticruiser::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
        
}
