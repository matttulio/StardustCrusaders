#include "Game.hpp"

int main(){
    
    
    game match;
    
    match.PrintMenu();
        
    match.SetGameMode();
        
    
    match.WhoStarts();
    cout << "Main 14";
    match.Play();
    
    match.PrintWinnerScreen();
    

}
