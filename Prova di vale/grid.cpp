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

grid::grid(game m){

    dim_grid = m.GetDimGrid();
    n_ships = m.GetNumShips();

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
    nextMoveCPU = {board[x+1][y], board[x-1][y], board[x][y+1], board[x][y-1]}; //mi serve per chiedere al computer di fare la prossima mossa
}

/*grid::grid(const grid &oldGrid)
{
    for (int i=0; i<grid_dim; i++)
        for (int j=0; j<grid_dim; j++)
            theGrid[i][j]=oldGrid.theGrid[i][j];
    shipVec = oldGrid.shipVec;
}*/


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
            }
            sleep(1);
        }
    }
}


/*bool grid::setShip(ship ship, int x, int y){


    for(int i = 0; i < ship.getSize(); i++){

        if(shipVec[i].ShipOrientation()){

                if( x + i >= grid_dim || y >= grid_dim || theGrid[x + i][y] != miss)
                    return false;
                    }
        else{
                if( x >= grid_dim || y + i >= grid_dim || theGrid[x][y + i] != miss)
                    return false;

            }

    }

    for(int i = 0; i < ship.getSize(); i++){
            if(ship.ShipOrientation())
                theGrid[x + i][y] = ship.getCode();
            else
                theGrid[x][y + i] = ship.getCode();
    }

    return true;
}*/


// è la funzione che viene richiamata in Game

bool grid::shot(grid board){

    int score_k = 0; //per i punti vittoria
    int nextMove_z = 0;


    /*if(player_mode){
            for(int i = 0; i < n_ship; i++){
                if(shipVec[i].Hit(x, y)){
                theGrid[x][y] = hit;
                }
                else{
                theGrid[x][y] = miss;
                }
            }
    }else{
        for(int i = 0; i < n_ship; i++){
                if(shipVec[i].Hit(x, y)){
                theGrid[x][y] = hit;
                }
                else{
                theGrid[x][y] = miss;
                }
            }
    }

    if(theGrid[x][y] == hit)
        cout << "Hai colpito la nave! Hai un altro colpo a disposizione. Digita le nuove coordinate ";
        return true;
    else
        return false;*/


        if(player1_mode){
        //cout << "Passare il computer al comandante " << player1_name;
        //cout << endl;
        cout << "Premere ENTER per iniziare l'attacco ";
        cin.ignore();

        p1.printInfo(); //Andrà bene scrivere p1 e p2? Non credo. In game gli stiamo dicendo di strae in p1.shot(p2) e quindi qua va modificato in qualche modo
        cout << "\n\n\n" ;
        p1.printPlayerGrid();
        cout << "\n\n\n" ;
        p2.printOpponentGrid();
        cout << "\n\n\n";

        cout << "Dove vuoi sparare? Inserisci le coordinate digitando prima il numero della riga e poi della colonna: " << cin << x << cout << ", " << cin << y;

        while (x < 0 || x > dim_grid || y < 0 || y > dim_grid || board [x][y] != sunk || board [x][y] != hit){
            cout << "ERRORE, INSERIRE DELLE COORDINATE VALIDE: ";
            cin << x << cout << ", " << cin << y;
            cout << endl;
        }


    }else{

        srand((unsigned int) time(NULL));

        if(nextMove_z = 0){

        cout << "Il tuo avversario sta pianificando il suo attacco, attendere..." << endl;
        x = rand() % 10;
        y = rand() % 10;

        }else{
            board pos[x][y] = rand() % nextMoveCPU.size(); //Cerco di randomizzare la scelta
            board [x][y] = nextMoveCPU[random];

        }


        /*int random = rand() % v.size();
        int sel_elem = v[random];*/
    }

    /*if(player2_mode){
        cout << "Passare il computer al comandante " << player2_name;
        cout << endl;
        cout << "Premere invio per iniziare l'attacco ";
        cin.ignore();

        p2.printInfo();
        cout << "\n\n\n" ;
        p2.printPlayerGrid();
        cout << "\n\n\n" ;
        p1.printOpponentGrid();
        cout << "\n\n\n";

        cout << "Dove vuoi sparare? Inserisci le coordinate digitando prima il numero della riga e poi della colonna: " << cin << x << ", " << cin << y;

    }else{

        srand((unsigned int) time(NULL));

        cout << "Il tuo avversario sta pianificando il suo attacco, attendere..." << endl;
        x = rand() % 10;
        y = rand() % 10;
    }*/




    //Controlli sui tre scenari


    if (board[x][y] == water){
        board[x][y] = miss;
            if(player_mode){
                cout << "MANCATO!"
                cout <<  "Non hai più colpi a disposizione. Passa il computer al tuo avversario ";
                system("clear");
            }else{ //qui non metto nulla su z? tanto la bool mi restituisce false
                cout << "Il tuo avversario non ha colpito nessuna delle tue navi"
                system("clear");
            }

        return false;

    }else{
        if(board[x+1][y] == board[x][y] || board[x-1][y] == board[x][y] || board[x][y+1] == board[x][y] || board[x][y-1] == board[x][y]){
            board[x][y] = hit;
            score_k++;
                if(player_mode){
                    cout << "Hai COLPITO la nave! Hai un altro colpo a disposizione. ";
                    system("clear");
                }else{
                    nextMove_z++; //Va bene??
                    cout << "Il tuo avversario ha colpito in posizione " << x << cout << ", " << y << endl;
                    cout << "Preparati al suo prossimo attacco ";
                    system("clear");
                }

        }else{
            board[x][y] = sunk;
            score_k++;
                if(player_mode){
                    cout << "La nave e' stata COLPITA ed AFFONDATA! Hai un altro colpo a disposizione. ";
                    system("clear");
                }else {
                    nextMove_z = 0; //Lo metto qua?
                    cout << "Il tuo avversario ha AFFONDATO una tua nave. Stai all'erta! Sta per attaccare di nuovo... ";
                    system("clear");
                }
        }
        return true;
        }

        // Vorrei che tutte le scritte si cancellassero. Va bene usare system("clear")?

    if(score_k == )











}
