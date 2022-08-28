//
//  StarDestroyer.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#ifndef StarDestroyer_hpp
#define StarDestroyer_hpp

#include "ship.hpp"

class stardestroyer: public ship{
    
public:
    
    stardestroyer();

     virtual int getSize() const;
     virtual int getX() const;
     virtual int getY() const;
     virtual string getName() const;
     virtual char getCode() const;


     virtual bool ShipOrientation() const;
     virtual bool ShipDestroyed() const;
     
    
     virtual void setShip(int x, int y, bool o);
     virtual void printShip() const;
     virtual void setHit();
     virtual bool isSunk();

private:
    int shipSize;

    int theX, theY;

    bool destroyed;
    bool orientation;

    string shipName;
    char shipCode;
    
    int health;
    
};

#endif /* StarDestroyer_hpp */
