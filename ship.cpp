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


/*ship::ship(int dim, string name, char code){
    
    shipSize = dim;
    shipName = name;
    shipCode = code;

}*/


/*ship::ship(int dim, std::string name, char code, int x, int y, bool o, bool d){ //o = orientazione, d = distruzione
    
    shipSize = dim;
    shipName = name;
    shipCode = code;
    
    
    theX = x;
    theY = y;
    
    destroyed = false;      //in partenza la nave è integra
    
    orientation = false;    //viene considerato false = orizzonatale, true = verticale
}*/





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
        
        cout << shipCode << " ";
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
    }
    
        if(k == shipSize)
            destroyed = true;
    
    cout << "_";
    
    return true;
}

