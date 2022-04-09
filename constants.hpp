//
//  constants.hpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <string>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int n_ship = 4;
const int ship_dim[n_ship] = {5, 4, 3, 1};
const int ship_spaces = 13;
const std::string ship_name[n_ship] = {"Super Star Destroyer", " Star Destroyer", " Gozanti Cruiser", "TIE Fighter"};
const char ship_code[n_ship] = {'A', 'B', 'C', 'D'};

const char water = '~';
const char hit = 'X';
const char miss = 'O';


const int grid_dim = 10;


#endif /* constants_hpp */
