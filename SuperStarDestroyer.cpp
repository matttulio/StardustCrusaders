//
//  SuperStarDestroyer.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "SuperStarDestroyer.hpp"

superstardestroyer::superstardestroyer(){
    
}

superstardestroyer::superstardestroyer(int dim, string name, char code):ship(dim, name, code){
    
    shipSize = 5;
    
    shipName = "Super Star Destroyer";
    
    shipCode = 'A';
    
}
