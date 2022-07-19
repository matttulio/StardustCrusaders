//
//  StarDestroyer.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#ifndef StarDestroyer_hpp
#define StarDestroyer_hpp

#include <stdio.h>
#include "ship.hpp"

class stardestroyer: public ship{
    
public:
    
    stardestroyer();
    //superstardestroyer(int dim, string name, char code, int x, int y, bool d, bool o);

    int getSize() const;
    int getX() const;
    int getY() const;
    string getName() const;
    char getCode() const;


    bool ShipOrientation() const;
    bool ShipDestroyed() const;
    
    
    void setPosition(int x, int y, bool o);
    void printShip();
    bool Hit(int xHit, int yHit);

private:
    int shipSize;

    int theX, theY;

    bool destroyed;
    bool orientation;

    string shipName;
    char shipCode;
    
};

#endif /* StarDestroyer_hpp */
