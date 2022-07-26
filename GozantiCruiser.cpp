//
//  GozantiCruiser.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "GozantiCruiser.hpp"

gozanticruiser::gozanticruiser(){
    
}

gozanticruiser::gozanticruiser(int dim, string name, char code):ship(dim, name, code){
    
    shipSize = 3;
    
    shipName = "Gozanti Cruiser";
    
    shipCode = 'C';
    
}
