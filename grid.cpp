//
//  grid.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>

#include "grid.hpp"
#include "Game.hpp"
#include "ship.hpp"
#include "SuperStarDestroyer.hpp"
#include "StarDestroyer.hpp"
#include "GozantiCruiser.hpp"
#include "TIEFighter.hpp"

using std::cout;
using std::endl;

grid::grid(int d_grid, int num_ships, bool player_mode){

    dim_grid = d_grid;
    n_ships = num_ships;
    
    p_mode = player_mode;

    for(int i = 0; i < dim_grid; i++)
    {
        for(int j = 0; j < dim_grid; j++){
            theGrid[i][j] = miss;   //miss e acqua hanno lo stesso simbolo
        }
    }

    //in un eventuale espansione si potrebbe mantenere uno scheletro di navi e con l'aumentare della dimensione della board si possono moltiplicare con un ciclo che crea un vettore del tipo di nave per un numero di volte pari al numero di navi inserito/4, se si vuole diminuire la dimensione della board mettere una condizione che gira sulla densità di navi e quando si supera una certa soglia inzia a togliere le navi più grosse

    superstardestroyer ssd;
    stardestroyer sd;
    gozanticruiser gc;
    TIEfighter tf;

    shipVec = {ssd, sd, gc, tf}; //ma qui prende davvero le navi?
    
}




void grid::printInfo(){
    cout << "Legenda simboli:" << endl;
    cout << "/ = colpito,  ~ = mancato/acqua,  X = affondato,  ? = ignoto\n";
    cout << "A = Super Star Destroyer,  B = Star Destroyer,  C = Gozanti Cruiser,  D = TIE Fighter";
    cout << endl;
}

void grid::printPlayerGrid(){

    cout << "LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia

    cout << "   0|1|2|3|4|5|6|7|8|9\n";     //cambiare con qualcosa che itera sulla dimensione
    for (int i = 0; i < dim_grid; i ++)
        {
            for(int j = 0; j < dim_grid; j++)
                {
                    if(j == 0)
                        {
                            cout << i << "  ";
                        }
                    cout << theGrid[i][j] ;
                    if(j != dim_grid)
                        {
                            cout << "|";
                        }
                }
        cout << endl;
    }
    cout << endl;
}


void grid::printOpponentGrid(){

    cout << "LA FLOTTA DEL NEMICO:" << endl;

    cout << "   0|1|2|3|4|5|6|7|8|9\n";
    for (int i = 0; i < dim_grid; i ++){
    for(int j = 0; j < dim_grid; j++)
        {
            if(j == 0)
        {
            cout << i << "  ";
            }

            if(theGrid[i][j] != sunk || theGrid[i][j] != miss || theGrid[i][j] != hit)
                cout << unknown;
            else
                cout << theGrid[i][j];

            if(i != dim_grid)
            {
                cout << "|";
            }
        }
    cout << endl;
    }


}

void grid::setGrid(bool player_mode){ //la griglia è gia piena di acqua, come dice il costruttore, numero di navi e dimensione griglia sono  note dal costruttore.


    int x = 0, y = 0;   //posizione cartesiana dell'estremità sinistra/alta della nave
    bool condition = true;  //condizione che verrà utile in seguito, da lasciare fuori dagli if
    bool orientation;   //orientazione della nave


    if(player_mode){   //se il giocatore che sta settando è umano

        for(int i = 0; i < shipVec.size(); i++){

            cout << "Posizionare la nave " << shipVec[i].getName() << " dove si desidera." << endl;  //prende l'i-esima nave e ricava il nome
            cout << "\n\n";
            cout << shipVec[i].getName() << "   ";
            shipVec[i].printShip(); //stampa l'i-esima nave, volendo si potrebbe fare l'overloading dell'operatore << così possiamo ficcarla nel cout (se rimane tempo)
            cout << "    ha una dimensione di " << shipVec[i].getSize() << endl;    //prendiamo l'i-esima dimensione
            cout << "\n\n";

            printPlayerGrid();

            cout << "\n\n";

            cout << "Scegliere se la nave deve essere posizionata con un'orientazione verticale, digitando v, od orizzontale digitando o: ";

            char temp;  //variabile temporanea per leggere char in input

            cin >> temp;

            cout << endl;

            while(temp != 'v' && temp != 'o'){
                cout << "ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA 'v' od 'o'. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> temp;
                cout << endl;
            }

            int n = 0;
            vector<int> vec_n;  //numero di spazi disponibili in una determinata riga/colonna


            //TUTTO IL PROCESSO DI CONTROLLO È OTTIMIZZABILE

            if(temp == 'o'){
                orientation = true; //true = orizzontale
                cout << "Hai selezionato orizzontale" << endl;
                sleep(2);
                system("clear");

                cout << shipVec[i].getName() << "   ";
                shipVec[i].printShip();
                cout << "    ha una dimensione di " << shipVec[i].getSize() << endl;
                cout << "\n\n";

                printPlayerGrid();

                cout << "\n\n";


                cout << "Scegliere la riga in cui si vuole inserire l'estremità sinistra della nave ";
                cin >> x;
                cout << endl;


                for(int j = 0; j < dim_grid; j++){  //DA FINIRE DI CONTROLLARE DA QUI!!!!!!!!!!!!!!!!!
                    if(theGrid[x][y + j] == miss)   //contiamo quanti spazi consecutivi separati da navi ci sono
                        n++;
                    if(theGrid[x][y + j] != miss || y + j == 9){
                        vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                        n = 0;
                    }
                }

                while(x > dim_grid || x < 0 || *max_element(vec_n.begin(), vec_n.end()) <= shipVec[i].getSize()){   //affinché la riga sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero massimo di spazi consecutivi sia almeno lo stesso numero degli spazi occupabili dalla nave
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> x;
                    cout << endl;

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //potremmo trovare un modo migliore per fare questo controllo, non mi piace che rifcciamo questo ciclo
                        if(theGrid[x][y + j] == miss)   //contiamo quanti spazi consecutivi separati da navi ci sono
                            n++;
                        if(theGrid[x][y + j] != miss || y + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                            n = 0;
                        }
                    }

                }

                cout << "Scegliere la colonna in cui si vuole inserire l'estremità sinistra della nave ";
                cin >> y;
                cout << endl;


                for(int j = 0; j < shipVec[i].getSize(); j++){
                    if(theGrid[x][y + j] != miss)   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta
                        condition = false;
                }

                while(y < 0 || y + shipVec[i].getSize() - 1 >= dim_grid  || !condition){ //la selezione deve stare dentro la board e siccome la nave la piazziamo dall'estremità sinistra inn poi dobbiamo anche controllare che l'estremità destra della nave sarà ancora dentro la board, e che ino
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> y;
                    cout << endl;

                    condition = true;

                    for(int j = 0; j < shipVec[i].getSize(); j++){
                        if(theGrid[x][y + j] != miss)   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta
                            condition = false;
                    }
                }


                shipVec[i].setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i].getSize(); j++){  //finiti i controlli piazziamo la nave
                    theGrid[x][y + j] = shipVec[i].getCode();
                }

                cout << "Hai posizionato la nave con successo" << endl;

                cout << "\n\n";

                printPlayerGrid();

                sleep(3);
                system("clear");


            }else{
                //caso in cui la nave ha orientazione verticale

                orientation = false;
                cout << "Hai selezionato verticale" << endl;
                sleep(2);
                system("clear");

                cout << shipVec[i].getName() << "   ";
                shipVec[i].printShip();
                cout << "    ha una dimensione di " << shipVec[i].getSize() << endl;
                cout << "\n\n";

                printPlayerGrid();

                cout << "\n\n";


                cout << "Scegliere la colonna in cui si vuole inserire l'estremità alta della nave ";
                cin >> y;
                cout << endl;

                for(int j = 0; j < dim_grid; j++){  //ricordo che di default x = 0 e y = 0
                    if(theGrid[x + j][y] == miss)   //contiamo quanti spazi consecutivi separati da navi ci sono
                        n++;
                    if(theGrid[x + j][y] != miss || x + j == 9){
                        vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                        n = 0;
                    }
                }

                while(y > dim_grid || y < 0 || *max_element(vec_n.begin(), vec_n.end()) <= shipVec[i].getSize()){   //affinché la colonna sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero di spazi consecutivi sia almeno lo stesso numero degli spazi occupati dalla nave
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> y;
                    cout << endl;

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //ricordo che di default x = 0 e y = 0
                        if(theGrid[x + j][y] == miss)   //contiamo quanti spazi consecutivi separati da navi ci sono
                            n++;
                        if(theGrid[x + j][y] != miss || x + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                            n = 0;
                        }
                    }
                }

                cout << "Scegliere la riga in cui si vuole inserire l'estremità alta della nave ";
                cin >> x;
                cout << endl;

                for(int j = 0; j < shipVec[i].getSize(); j++){
                    if(theGrid[x + j][y] != miss)   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta in alternativa dal pezzo precedente di codice si può lasciare al giocatora la possibilità di scegliere soltanto le posizioni possibili
                    condition = false;
                }

                while(x < 0 || x + shipVec[i].getSize() - 1 >= dim_grid  || !condition){
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> x;
                    cout << endl;

                    condition = true;

                    for(int j = 0; j < shipVec[i].getSize(); j++){
                        if(theGrid[x + j][y] != miss)   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta
                            condition = false;
                    }

                }
                
                shipVec[i].setShip(x, y, orientation);

                for(int j = 0; j < shipVec[i].getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x + j][y] = shipVec[i].getCode();
                }

                cout << "Hai posizionato la nave con successo" << endl;

                cout << "\n\n";

                printPlayerGrid();

                sleep(3);
                system("clear");
            }
        }

        cout << "La tua flotta è in posizione comandante!" << endl;

        cout << "\n\n\n";

        printPlayerGrid();

        system("clear");

    }else{  //se il giocatore che sta settando la board è CPU

        for(int i = 0; i < shipVec.size(); i++){

            srand((unsigned int) time(NULL));

            if(rand() % 2 == 0)
                orientation = true; //orizzontale
            else
                orientation = false;

            x = rand() % 10;
            y = rand() % 10;

            if(orientation){
                for(int j = 0; j < shipVec[i].getSize(); j++){
                    if(theGrid[x][y + j] != miss)
                        condition = false;
                }

                while(theGrid[x][y] != miss || !condition){
                    x = rand() % 10;
                    y = rand() % 10;

                    for(int j = 0; j < shipVec[i].getSize(); j++){
                        if(theGrid[x][y + j] != miss)
                            condition = false;
                    }
                }
                
                shipVec[i].setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i].getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x][y + j] = shipVec[i].getCode();
                }
                
            }else{
                for(int j = 0; j < shipVec[i].getSize(); j++){
                    if(theGrid[x + j][y] != miss)
                        condition = false;
                }

                while(theGrid[x][y] != miss || !condition){
                    x = rand() % 10;
                    y = rand() % 10;

                    for(int j = 0; j < shipVec[i].getSize(); j++){
                        if(theGrid[x + j][y] != miss)
                            condition = false;
                    }
                }
                
                shipVec[i].setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i].getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x + j][y] = shipVec[i].getCode();
                }
                
            }
            sleep(1);
        }
    }
}




// è la funzione che viene richiamata in Game

bool grid::isShotBy(grid board){
    
    int x, y;
    if(p_mode){
    //cout << "Passare il computer al comandante " << player1_name;
    //cout << endl;
        cout << "Premere ENTER per iniziare l'attacco ";
        cin.ignore();

        printInfo(); //Andrà bene scrivere p1 e p2? Non credo. In game gli stiamo dicendo di strae in p1.shot(p2) e quindi qua va modificato in qualche modo
        cout << "\n\n\n" ;
        board.printPlayerGrid();
        cout << "\n\n\n" ;
        printOpponentGrid();
        cout << "\n\n\n";

        cout << "Dove vuoi sparare? Inserisci le coordinate digitando prima il numero della riga e poi della colonna: ";
        cin >> x;
        cout << ", ";
        cin >> y;

        while (x < 0 || x > dim_grid || y < 0 || y > dim_grid || theGrid [x][y] == sunk || theGrid [x][y] == hit || theGrid [x][y] == miss){
            cout << "ERRORE, INSERIRE DELLE COORDINATE VALIDE: ";
            cin >> x;
            cout << ", ";
            cin >> y;
            cout << endl;
        }


    //Controlli sui tre scenari


        if (theGrid[x][y] == water){
        theGrid[x][y] = miss;
            if(p_mode){
                cout << "MANCATO!";
                cout <<  "Non hai più colpi a disposizione. Passa il computer al tuo avversario ";
                system("clear");
            }
            
            return false;

        }else{
            if (theGrid[x+1][y] == theGrid[x][y] || theGrid[x-1][y] == theGrid[x][y] || theGrid[x][y+1] == theGrid[x][y] || theGrid[x][y-1] == theGrid[x][y]){
                cout << "COLPITO! Hai un altro colpo a disposizione " << endl;
                cout << "Inserisci le nuove coordinate ";
                theGrid [x][y] = hit;

            }else{

                switch(theGrid[x][y]){
                case 'A':

                    cout << "La nave" << shipVec[0].getName() << "è stata COLPITA ED AFFONDATA!" << endl;
                    if (shipVec[0].ShipOrientation() == true){ //true = orizzontale
                        for(int i = 0; i < shipVec[0].getSize(); i++){
                            theGrid[shipVec[0].getX()][shipVec[0].getY() + i] = sunk;
                        }
                    }else{
                        for(int i = 0; i < shipVec[0].getSize(); i++){
                            theGrid[shipVec[0].getX() + i][shipVec[0].getY()] = sunk;
                        }
                    }


                    break;

                case 'B':
                    cout << "La nave" << shipVec[1].getName() << "è stata COLPITA ED AFFONDATA!" << endl;
                    if (shipVec[1].ShipOrientation() == true){ //true = orizzontale
                        for(int i = 0; i < shipVec[1].getSize(); i++){
                            theGrid[shipVec[1].getX()][shipVec[1].getY() + i] = sunk;
                        }
                    }else{
                        for(int i = 0; i < shipVec[1].getSize(); i++){
                            theGrid[shipVec[1].getX() + i][shipVec[1].getY()] = sunk;
                        }

                    }

                    break;

                case 'C':
                    cout << "La nave" << shipVec[2].getName() << "è stata COLPITA ED AFFONDATA!" << endl;
                    if (shipVec[2].ShipOrientation() == true){ //true = orizzontale
                        for(int i = 0; i < shipVec[2].getSize(); i++){
                            theGrid[shipVec[2].getX()][shipVec[2].getY() + i] = sunk;
                        }
                    }else{
                        for(int i = 0; i < shipVec[2].getSize(); i++){
                            theGrid[shipVec[2].getX() + i][shipVec[2].getY()] = sunk;
                        }

                    }

                    break;

                case 'D':
                    cout << "La nave" << shipVec[3].getName() << "è stata COLPITA ED AFFONDATA!" << endl;
                    if (shipVec[3].ShipOrientation() == true){ //true = orizzontale
                        for(int i = 0; i < shipVec[3].getSize(); i++){
                            theGrid[shipVec[3].getX()][shipVec[3].getY() + i] = sunk;
                        }
                    }else{
                        for(int i = 0; i < shipVec[3].getSize(); i++){
                            theGrid[shipVec[3].getX() + i][shipVec[3].getY()] = sunk;
                        }

                    }

                    break;
            }

            cout << "Hai un altro colpo a disposizione. Inserisci le nuove coordinate";

            }
        }

            return true;
        }
        
    }else{  //se il giocatore è CPU

        // Vorrei che tutte le scritte si cancellassero. Va bene usare system("clear")?

        int *old_shots = new int [10];
        int plus_minus [] = {-1, 1};
        int *x = new int;
        int *y = new int;
        int *k = new int;

        if(!*already_hit){

            srand((unsigned int) time(NULL));

            cout << "Il tuo avversario sta pianificando il suo attacco, attendere..." << endl;

            *x = rand() % 10;
            *y = rand() % 10;

        }else{

            if(*orientation == 0){   //se non è ancora stata guessata un'orientazione
                *k = 2; //variabile di supporto per capire a che punto siamo nel guess

                srand((unsigned int) time(NULL));
                *orientation = rand() % 2 + 1;
            }
            

            if(*orientation == 1 && *k == 2 && *Try_z < 2){ //orientazione verticale

                while(theGrid[*x][*y] == miss || theGrid[*x][*y] == hit || theGrid[*x][*y] == sunk){    //fin tanto che non trova qualcosa da colpire randomizza un +-1 rispetto alla posizione del colpo precedente

                    srand((unsigned int) time(NULL));
                    int g = rand() % 2;

                    *x = old_shots[*r] + plus_minus[g];
                    *y = old_shots[*r + 1];
                }

                *k = *k - 1;

            }else if(*orientation == 1 && *k == 1 && *Try_z < 2){    //se il colpo con k = 2 abbiamo mancato

                while(theGrid[*x][*y] == miss || theGrid[*x][*y] == hit || theGrid[*x][*y] == sunk){

                    srand((unsigned int) time(NULL));
                    int g = rand () % 2;

                    *x = old_shots[*r] + plus_minus[g];
                    *y = old_shots[*r + 1];
                }

                *k = *k - 1;
            }

    
            if(*orientation == 2 && *k == 2 && *Try_z < 2){ //orientazione orizzontale

                while(theGrid[*x][*y] == miss || theGrid[*x][*y] == hit || theGrid[*x][*y] == sunk){

                    srand((unsigned int) time(NULL));
                    int g = rand () % 2;

                    *x = old_shots[*r];
                    *y = old_shots[*r + 1] + plus_minus[g];
                }

                *k = *k - 1;

            }else if(*orientation == 1 && *k == 1 && *Try_z < 2){

                while(theGrid[*x][*y] == miss || theGrid[*x][*y] == hit || theGrid[*x][*y] == sunk){

                    srand((unsigned int) time(NULL));
                    int g = rand () % 2;

                    *x = old_shots[*r];
                    *y = old_shots[*r + 1] + plus_minus[g];
                }

                *k = *k - 1;
            }
        }
        
        int temp;
        
        if(old_shots[0] == old_shots [2] && *Try_z == 2){ //se le prime due entrate pari del vettore sono uguali significa che la nave ha le x uguali e quindi è orizzontale
            *orientation = 2;
            if(old_shots[1] > old_shots [3]){   //cosi abbiamo nell'ultima entrata l'ascissa maggiore, diventa utile nel while dopo
                temp = old_shots [3];
                old_shots [3] = old_shots[1];
                old_shots[1] = temp;
            }
                
            *k = 0;
        }
        
        if(old_shots[1] == old_shots [3] && *Try_z == 2){ //se le prime due entrate pari del vettore sono uguali significa che la nave ha le y uguali e quindi è verticale
            *orientation = 1;
            if(old_shots[0] > old_shots [2]){ //cosi abbiamo nell'ultima entrata l'ordine maggiore, diventa utile nel while dopo
                temp = old_shots [2];
                old_shots [2] = old_shots[0];
                old_shots[0] = temp;
            }
            *k = 0;
        }
        
        while(*already_hit && *Try_z >= 2 && *k == 0){
            
            if(old_shots[*r - 2] != *x || old_shots[*r - 1] != *y)  //se ha mancato ma non ancora affondato allora cambia direzione del colpo
                *direction_hit = false;
            
            if(*orientation == 2 && *direction_hit){  //orizzontale
                *x = old_shots[*r - 2];
                *y = old_shots[*r - 1] + 1;
                
            }else if(*orientation == 2 && !*direction_hit){
                *x = old_shots[*r - 2];
                *y = old_shots[*r - 1] - 1;
            }
            
            if(*orientation == 1 && *direction_hit){    //verticale
                *x = old_shots[*r - 2] + 1;
                *y = old_shots[*r - 1];
                
            }else if(*orientation == 1 && !*direction_hit)
                *x = old_shots[*r - 2] - 1;
                *y = old_shots[*r - 1];
        }
        
        
        

        if(theGrid[*x][*y] == miss)
            return false;

        else{
        
            *already_hit = true;
        
            old_shots [*r] = *x;
            old_shots [*r + 1] = *y;
        
            *r = *r + 2;
        
            *Try_z = *Try_z + 1;
            
            return true;
        
        
            switch(theGrid[*x][*y]){
                case 'A':
                    shipVec[0].setHit();
                    theGrid[*x][*y] = hit;
                    if(shipVec[0].isSunk()){    //bisogna aggiungere una caratteristica della nave che è il numero di pezzi colpiti, poi si controlla se i pezzi colpiti == dim_ship, se vero allora è sunk
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        delete[] old_shots;
                    }
                    break;
            
                case 'B':
                    shipVec[1].setHit();
                    theGrid[*x][*y] = hit;
                    if(shipVec[1].isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        delete[] old_shots;
                    }
                    break;
            
                case 'C':
                    shipVec[2].setHit();
                    theGrid[*x][*y] = hit;
                    if(shipVec[2].isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        delete[] old_shots;
                    }
                    break;
            
                case 'D':
                    shipVec[3].setHit();
                    theGrid[*x][*y] = hit;
                    if(shipVec[3].isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        delete[] old_shots;
                    }
                    break;
            }
        
        
        }
        
    }
}
