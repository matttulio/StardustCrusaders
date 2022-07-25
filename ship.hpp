//
//  ship.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#ifndef SHIP_HPP
#define SHIP_HPP

class ship{

    public:
        ship();
        //ship(int dim, string name, char code);  //quando le costruisco la prima volta saranno così, quando le carico sulla board avranno le caratteristiche di cui sotto
        //ship(int dim, string name, char code, int x, int y, bool d, bool o);

        int getSize() const;
        int getX() const;
        int getY() const;
        string getName() const;
        char getCode() const;


        bool ShipOrientation() const;
        bool ShipDestroyed() const;
        
        
        void setShip(int x, int y, bool o);
        void printShip();
        void setHit(int xHit, int yHit);

    private:
        int shipSize;
    
        int theX, theY;
    
        bool destroyed;
        bool orientation;
    
        string shipName;
        char shipCode;
};

        
#endif /* SHIP_HPP */
