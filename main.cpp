#include <iostream>
#include "ship.hpp"
#include "grid.hpp"
#include "Game.hpp"
using namespace std;

int main(){
    
    
    game match;
    
    match.PrintMenu();
        
    match.SetGameMode();
        
    match.WhoStarts();
    
    match.Play();
    
    match.PrintWinnerScreen();
    

}
