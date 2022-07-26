//
//  TIEFighter.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#include "TIEFighter.hpp"

TIEfighter::TIEfighter(){
    
}

TIEfighter::TIEfighter(int dim, string name, char code):ship(dim, name, code){
    
    shipSize = 1;
    
    shipName = "TIEfighter";
    
    shipCode = 'D';
    
}
