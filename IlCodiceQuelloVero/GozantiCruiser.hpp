//
//  GozantiCruiser.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#ifndef GozantiCruiser_hpp
#define GozantiCruiser_hpp

#include "ship.hpp"

class gozanticruiser: public ship{
    
public:
    
    gozanticruiser();
    gozanticruiser(int dim, string name, char code);
    gozanticruiser(int dim, string name, char code, int x, int y, bool d, bool o);

    virtual int getSize() const;
    virtual int getX() const;
    virtual int getY() const;
    virtual string getName() const;
    virtual char getCode() const;


    virtual bool ShipOrientation() const;
    virtual bool ShipDestroyed() const;
    
    
    virtual void setShip(int x, int y, bool o);
    virtual void printShip();
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

#endif /* GozantiCruiser_hpp */
