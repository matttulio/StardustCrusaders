#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

const char unknown = '?';
const char hit = '/';
const char sunk = 'X';
const char miss = '~';

int main(){
/*
    int grid_dim = 20;
    char choose = 'p';

char theGrid[grid_dim][grid_dim];

for(int i = 0; i < grid_dim; i++)
    {
        for(int j = 0; j < grid_dim; j++){
            theGrid[i][j] = '~' ;
        }
    }
	cout << "Legenda simboli:" << endl;
        cout << "/ = colpito,  ~ = mancato/acqua,  X = affondato,  ? = ignoto\n";
	cout << "A = Super Star Destroyer,  B = Star Destroyer,  C = Gozanti Cruiser,  D = TIE Fighter";
        cout << endl;
cout << "LA TUA FLOTTA:" << endl;

        cout << "   0|1|2|3|4|5|6|7|8|9\n";
        for (int i=0; i < grid_dim; i ++)
        {
            for(int j=0; j < grid_dim; j++)
            {
                if(j==0)
                {
                    cout << i << "  ";
                }
            cout << theGrid[i][j] ;
            if(j != grid_dim)
            {
                cout << "|";
            }
            }
    cout << endl;

    }
    cout << endl;
cout << "LA FLOTTA DEL NEMICO:" << endl;
cout << "   0|1|2|3|4|5|6|7|8|9\n";
        for (int i = 0; i < grid_dim; i ++){
              
        for(int j = 0; j < grid_dim; j++)
        {
            if(j == 0)
            {
                cout << i << "  ";
            }

            if(theGrid[i][j] != sunk || theGrid[i][j] != miss || theGrid[i][j] != hit)
                cout << unknown;
            else
                cout << theGrid[i][j];

            if(j != grid_dim)
            {
                cout << "|";
            }
        }

    cout << endl;

        }
    */
    cout << "\033[1;35mbold red text\033[0m\n";
    
    cout <<"  \033[1;35m_________  __                      .___               __    _________                                   .___\033[0m\n";
    cout <<" \033[1;35m/   _____/_/  |_ _____  _______   __| _/__ __  _______/  |_  \\_   ___ \\_______  __ __  ___________     __| _/ ____ _______  ______\033[0m\n";
    cout <<" \033[1;35m\\_____  \\ \\   __\\\\__  \\ \\_  __ \\ / __ ||  |  \\/  ___/\\   __\\ /    \\  \\/\\_  __ \\|  |  \\/  ___/\\__  \\   / __ |_/ __ \\\\_  __ \\/  ___/\033[0m\n";
    cout <<" \033[1;35m/        \\ |  |   / __ \\_|  | \\// /_/ ||  |  /\\___ \\  |  |   \\     \\____|  | \\/|  |  /\\___ \\  / __ \\_/ /_/ |\\  ___/ |  | \\/\\___ \\ \033[0m\n";
    cout <<"\033[1;35m/_______  / |__|  (____  /|__|   \\____ ||____//____  > |__|    \\______  /|__|   |____//____  >(____  /\\____ | \\___  >|__|  /____  >\033[0m\n";
    cout <<"        \033[1;35m\\/             \\/             \\/           \\/                 \\/                   \\/      \\/      \\/     \\/            \\/\033[0m\n";
    
    std::cout << "\n";
    std::cout << "                                                                                       \033[1;35mcreated by Barletta Valentina & Gallo Matteo\033[0m" << endl;
    
    cin.ignore();
    
    system("clear");
    
    std::cout <<"  \033[1;35m_________  __                      .___               __    _________                                   .___\033[0m\n";
    std::cout <<" \033[1;35m/   _____/_/  |_ _____  _______   __| _/__ __  _______/  |_  \\_   ___ \\_______  __ __  ___________     __| _/ ____ _______  ______\033[0m\n";
    std::cout <<" \033[1;35m\\_____  \\ \\   __\\\\__  \\ \\_  __ \\ / __ ||  |  \\/  ___/\\   __\\ /    \\  \\/\\_  __ \\|  |  \\/  ___/\\__  \\   / __ |_/ __ \\\\_  __ \\/  ___/\033[0m\n";
    std::cout <<" \033[1;35m/        \\ |  |   / __ \\_|  | \\// /_/ ||  |  /\\___ \\  |  |   \\     \\____|  | \\/|  |  /\\___ \\  / __ \\_/ /_/ |\\  ___/ |  | \\/\\___ \\ \033[0m\n";
    std::cout <<"\033[1;35m/_______  / |__|  (____  /|__|   \\____ ||____//____  > |__|    \\______  /|__|   |____//____  >(____  /\\____ | \\___  >|__|  /____  >\033[0m\n";
    std::cout <<"        \033[1;35m\\/             \\/             \\/           \\/                 \\/                   \\/      \\/      \\/     \\/            \\/\033[0m\n";
    
    std::cout << "\n";
    std::cout << "                                                                                       \033[1;35mcreated by Barletta Valentina & Gallo Matteo\033[0m" << std::endl;
}
    /*
    std::cout << "Ormai da tempo..."; //scrivere qualcosa di lore, qualcosa che giustifichi la battaglia del gioco, meglio se novità assoluta
    
    std::cout << "Digitare y per giocare oppure n per uscire: ";
    std::cin >> choose;
    std::cout << choose << endl;
    
        while(choose != 'n' && choose != 'y'){
            std::cout << "ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA y o n. REINSERIRE IL VALORE DESIDERATO: ";
            std::cin >> choose;
    }
    
    if(choose == 'n'){
        exit(0);
    }else{
        system("clear");
        cout << "caazzo";
    }
    
    bool mode;
    
    std::cout << "Selezionare la modalità di gioco:\n";
    std::cout << "Per giocare contro il computer digitare 1\n";
    std::cout << "Per giocare contro un'altra persona digitare 2\n";
    std::cin >> mode;
    
    cout << mode << endl;
    mode = 5;
    
    mode = true;
    
    cout << mode << endl;
    
    sleep(5);
    
    cout << "cama" << endl;
    
    sleep(2);
    
    system("clear");
    vector< vector<char> > theGrid;
    vector<char> p;
    p.push_back('a');
    p.push_back('b');
    p.push_back('c');
    p.push_back('d');
    theGrid.push_back(p);
    p[0] = 'd';
    p[1] = 'c';
    p[2] = 'b';
    p[3] = 'a';
    theGrid.push_back(p);
    
    cout << theGrid[0][0] << " " << theGrid[0][1] << " " << theGrid[0][2] << " " << theGrid[1][3] << endl;
    cout << theGrid[1][0] << " " << theGrid[1][1] << " " << theGrid[1][2] << " " << theGrid[1][3] << endl;*/
    /*srand(time(NULL));
    
 for(int i = 0; i < 10; i++){
     cout << rand() % 2 << " ";
 }
    
  
    int *i = new int(1);
    int *k = new int [10];
    
    if(&k [0] == &k [1])
        cout << "occhei";
        
    k [1] = *i;
    k [0] = *i;
    cout << k[*i];
    cout << *i;
    
    switch(k [*i]){
        case 1:
            cout <<"Maronn";
            break;
        case 2:
            cout << "Napoli";
            break;
        case 0:
            cout << "Svezia";
            break;
    }
    cout << endl;

    int dim_grid = 50;
    
    char theGrid [dim_grid][dim_grid];
    
    for(int i = 0; i < dim_grid; i++){
        for(int j = 0; j < dim_grid; j++){
            theGrid[i][j] = '~';   //miss e acqua hanno lo stesso simbolo
        }
    }
    
    theGrid[5][3] = 'X';
    
    cout << "      ";
    
    for(int i = 0; i < dim_grid; i ++){
        cout << i;
        if(i < dim_grid - (dim_grid - 10)){
            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << " ";
            }
        }
        cout << "|";
    }
    
    cout << endl;
    
    for(int i = 0; i < dim_grid; i ++){
        cout << "   ";
        for(int j = 0; j < dim_grid; j++){
            if(j == 0){
                cout << i;
                if(i < dim_grid - (dim_grid - 10)){
                    for(int k = 0; k < log10(dim_grid) - 1; k++){
                        cout << " ";
                    }
                }
                cout << "|";
            }
            cout << theGrid[i][j];
            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
}

    
    int i = 5;
    bool c = false;
    while(!c && i % 2 != 0){
        cout << "Arg" << endl;
        i++;
        if(i == 7)
            c = true;
    }
    */
    
