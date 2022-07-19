//
//  constants.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int ship_dim[n_ship] = {5, 4, 3, 1};
const int ship_spaces = 13;
const std::string ship_name[n_ship] = {"Super Star Destroyer", " Star Destroyer", " Gozanti Cruiser", "TIE Fighter"};   //forse fare due array distinti con nomi diversi per le due forza in gioco
const char ship_code[n_ship] = {'A', 'B', 'C', 'D'};

const char unknown = '?';
const char hit = '/';
const char sunk = 'X';
const char miss = '~';




#endif /* constants_hpp */
