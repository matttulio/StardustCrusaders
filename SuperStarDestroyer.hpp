//
//  SuperStarDestroyer.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#ifndef SuperStarDestroyer_hpp
#define SuperStarDestroyer_hpp

#include "ship.hpp"

class superstardestroyer: public ship{
    
public:
    superstardestroyer();
    superstardestroyer(int dim, string name, char code);  
    superstardestroyer(int dim, string name, char code, int x, int y, bool d, bool o);


private:
    int shipSize;

    int theX, theY;

    bool destroyed;
    bool orientation;

    string shipName;
    char shipCode;
    
};

#endif /* SuperStarDestroyer_hpp */
