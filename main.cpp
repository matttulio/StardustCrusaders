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
    
    if(match.GetMode())
        match.PlayPvP();
    else
        match.PlayPvCPU();
    
    match.PrintWinnerScreen();
    

}
