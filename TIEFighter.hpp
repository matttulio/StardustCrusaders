//
//  TIEFighter.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 12/07/22.
//

#ifndef TIEFighter_hpp
#define TIEFighter_hpp

#include "ship.hpp"

class TIEfighter: public ship{
    
public:
    
    TIEfighter();
    TIEfighter(int dim, string name, char code);
    TIEfighter(int dim, string name, char code, int x, int y, bool d, bool o);

    int getSize() const;
    int getX() const;
    int getY() const;
    string getName() const;
    char getCode() const;


    bool ShipOrientation() const;
    bool ShipDestroyed() const;
    
    
    void setShip(int x, int y, bool o);
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

#endif /* TIEFighter_hpp */
