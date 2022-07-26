//
//  StarDestroyer.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "StarDestroyer.hpp"

stardestroyer::stardestroyer(){
    
}

stardestroyer::stardestroyer(int dim, string name, char code):ship(dim, name, code){
    
    shipSize = 4;
    
    shipName = "Star Destroyer";
    
    shipCode = 'B';
    
}
