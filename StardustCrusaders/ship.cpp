//
//  ship.cpp
//  StardustCrusaders
//
//  Created by Matteo Gallo on 29/08/22.
//

#include "ship.hpp"



int ship::getSize() const{
    return shipSize;
}


int ship::getX() const{
    return theX;
}


int ship::getY() const{
    return theY;
}


string ship::getName() const{
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


void ship::setShip(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}


void ship::printShip() const{
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    
    return;
}


void ship::setHit(){
    
    health--;
    return;
    
}

bool ship::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
}
