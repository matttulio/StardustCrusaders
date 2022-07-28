//
//  ship.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <iostream>
#include <string>

#include "ship.hpp"
#include "constants.hpp"

using std::cout;
using std::endl;
using std::string;

ship::ship(){
    
}

ship::ship(int dim, string name, char code){
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
}


ship::ship(int dim, string name, char code, int x, int y, bool o, bool d, int h){ //o = orientazione, d = distruzione, h = health
    
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
    
    theX = x;
    theY = y;
    
    destroyed = false;      //in partenza la nave è integra
    
    orientation = false;    //viene considerato false = orizzonatale, true = verticale
    
    health = dim;
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


void ship::printShip(){
    
    for(int i = 0; i < shipSize; i++){
        
        cout << shipCode << " ";
    }
    
    cout << endl;
    
    return;
}


void ship::setHit(){
    
    health--;
    
}

bool ship::isSunk(){
    
    if(health == 0){ //se non ha salute è affondata
        destroyed = true;
        return true;
    }else
        return false;
        
}
