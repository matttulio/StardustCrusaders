//
//  ship.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>

#ifndef SHIP_HPP
#define SHIP_HPP

class ship{

    public:
        ship(int dim, std::string name, char code);
        ship(int dim, std::string name, char code, int x, int y, bool s, bool o);
        ship(const ship &oldShip);
        ship& operator = (const ship &Right);
        ~ship();

        int getSize() const;
        int getX() const;
        int getY() const;
        std::string getName() const;
        char getCode() const;


        bool shipOrientation() const;
        bool shipDestroyed() const;
        
        
        void setPosition(int x, int y, bool o);
        void printShip();
        bool recordHit(int xHit, int yHit);

    private:
        char* shipKind;
        int shipSize;
        int theX, theY;
        bool destroyed;
        bool orientation;
        std::string shipName;
        char shipCode;
};

        
#endif /* SHIP_HPP */
