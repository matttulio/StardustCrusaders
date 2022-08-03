#include "Game.hpp"

int main(){
    
    
    game match;
    
    match.PrintMenu();
        
    match.SetGameMode();
        
    
    match.WhoStarts();
    
    match.Play();
    
    match.PrintWinnerScreen();
    

}
