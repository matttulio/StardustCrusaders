//
//  TIEFighter.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "TIEFighter.hpp"

TIEfighter::TIEfighter(){
    
}

TIEfighter::TIEfighter(int dim, string name, char code){
    
    shipSize = 1;
    
    shipName = "TIEfighter";
    
    shipCode = 'D';
    
    health = shipSize;
    
}

int TIEfighter::getSize() const{
    return shipSize;
}


int TIEfighter::getX() const{
    return theX;
}


int TIEfighter::getY() const{
    return theY;
}


string TIEfighter::getName() const{
    return shipName;
}


char TIEfighter::getCode() const{
    return shipCode;
}


bool TIEfighter::ShipOrientation() const{
    return orientation;
}


bool TIEfighter::ShipDestroyed() const{
    return destroyed;
}


void TIEfighter::setShip(int x, int y, bool o){
    
    theX = x;
    theY = y;
    
    orientation = o;
    
    return;
}


void TIEfighter::printShip(){
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    cout << endl;
    
    return;
}


void TIEfighter::setHit(){
    
    health--;
    
}

bool TIEfighter::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
        
}
