//
//  grid.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//


#include "grid.hpp"
#include "Game.hpp"
#include "ship.hpp"
#include "SuperStarDestroyer.hpp"
#include "StarDestroyer.hpp"
#include "GozantiCruiser.hpp"
#include "TIEFighter.hpp"


grid::grid(){
    
}

grid::grid(int d_grid, int num_ships, bool player_mode){

    dim_grid = d_grid;
    n_ships = num_ships;
    
    p_mode = player_mode;
    
    vector<char> row;
    
    for(int i = 0; i < dim_grid; i++){
        row.push_back(water);
    }

    for(int j = 0; j < dim_grid; j++){
        theGrid.push_back(row);
    }


    //in un eventuale espansione si potrebbe mantenere uno scheletro di navi e con l'aumentare della dimensione della board si possono moltiplicare con un ciclo che crea un vettore del tipo di nave per un numero di volte pari al numero di navi inserito/4, se si vuole diminuire la dimensione della board mettere una condizione che gira sulla densità di navi e quando si supera una certa soglia inzia a togliere le navi più grosse

    /*superstardestroyer ssd;
    stardestroyer sd;
    gozanticruiser gc;
    TIEfighter tf;*/
    
    //cout << ssd.getName() << " " << ssd.getSize() <<  " " << ssd.getCode() << endl;

    shipVec.push_back(&ssd);
    shipVec.push_back(&sd);
    shipVec.push_back(&gc);
    shipVec.push_back(&tf);
    
    //cout << shipVec.size() << endl;
    
    //cout << shipVec[3]->getName() << " " << shipVec[3]->getSize() <<  " " << shipVec[3]->getCode() << endl;
    
}




void grid::printInfo(){
    cout << "Legenda simboli:" << endl;
    cout << "/ = colpito,  ~ = mancato/acqua,  X = affondato,  ? = ignoto\n";
    cout << "A = Super Star Destroyer,  B = Star Destroyer,  C = Gozanti Cruiser,  D = TIE Fighter";
    cout << endl;
    cout << "\n\n\n";
    
    cout << "Le navi che hai affondato sono:\n";
    for(int i = 0; i < shipVec.size(); i++){
        if(shipVec[i]->isSunk()){
            cout << shipVec[i]->getName() << " ";
            shipVec[i]->printShip();
            cout << " di dimensione " << shipVec[i]->getSize() << "\n";
        }
    }
        
        cout << "\n\n";
        
    cout << "Le navi che devi ancora affondare sono:\n";
    for(int i = 0; i < shipVec.size(); i++){
        if(!shipVec[i]->isSunk()){
            cout << shipVec[i]->getName() << " ";
            shipVec[i]->printShip();
            cout << " di dimensione " << shipVec[i]->getSize() << "\n";
        }
    }
    
}

void grid::printPlayerGrid(){

    cout << "LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia

    cout << "     ";
    
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
    cout << endl;
}


void grid::printOpponentGrid(){

    cout << "LA FLOTTA DEL NEMICO:" << endl;
    
    cout << "     ";

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
    
    for (int i = 0; i < dim_grid; i ++){
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
            if(theGrid[i][j] == sunk || theGrid[i][j] == miss || theGrid[i][j] == hit)
                cout << theGrid[i][j];
            else
                cout << unknown;

            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
}

void grid::setGrid(bool player_mode){ //la griglia è gia piena di acqua, come dice il costruttore, numero di navi e dimensione griglia sono  note dal costruttore.


    int x, y;   //posizione cartesiana dell'estremità sinistra/alta della nave
    bool condition;  //condizione che verrà utile in seguito, da lasciare fuori dagli if
    bool orientation;   //orientazione della nave


    if(player_mode){   //se il giocatore che sta settando è umano
        
        cin.ignore();

        for(int i = 0; i < shipVec.size(); i++){
            
            x = 0;
            y = 0;
            condition = true;

            cout << "Posizionare la nave " << shipVec[i]->getName() << " dove si desidera." << endl;  //prende l'i-esima nave e ricava il nome
            cout << "\n\n";
            cout << shipVec[i]->getName() << "   ";
            shipVec[i]->printShip(); //stampa l'i-esima nave, volendo si potrebbe fare l'overloading dell'operatore << così possiamo ficcarla nel cout (se rimane tempo)
            cout << "    ha una dimensione di " << shipVec[i]->getSize() << endl;    //prendiamo l'i-esima dimensione
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
            bool cond = false;
            vector<int> vec_n;  //numero di spazi disponibili in una determinata riga/colonna
            
            int max_v;


            //TUTTO IL PROCESSO DI CONTROLLO È OTTIMIZZABILE

            if(temp == 'o'){
                orientation = true; //true = orizzontale
                
                system("clear");
                cout << "Hai selezionato orizzontale" << endl;
                cout << "\n";
                cout << shipVec[i]->getName() << "   ";
                shipVec[i]->printShip();
                cout << "    ha una dimensione di " << shipVec[i]->getSize() << endl;
                cout << "\n\n";

                printPlayerGrid();

                cout << "\n\n";


                cout << "Scegliere la riga in cui si vuole inserire l'estremità sinistra della nave ";
                cin >> x;
                cout << endl;
                
                


                while(!cond){
                
                    while(x > dim_grid - 1 || x < 0){   //affinché la riga sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero massimo di spazi consecutivi sia almeno lo stesso numero degli spazi occupabili dalla nave
                        cout << "ERRORE!!! Inserire un numero valido: ";
                        cin >> x;
                        cout << endl;
                    }

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //potremmo trovare un modo migliore per fare questo controllo, non mi piace che rifcciamo questo ciclo
                        cout << "j = " << j << " ";
                        if(theGrid[x][y + j] == water){
                            n++;
                            cout << "n = " << n << " ";
                        }   //contiamo quanti spazi consecutivi separati da navi ci sono
                            
                        if(theGrid[x][y + j] != water || y + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                            cout << "vec = " << vec_n [0] << " ";
                            n = 0;
                        }
                    }
                    
                    max_v = vec_n [0];
                    
                    if(vec_n.size() > 1){
                        for(int j = 0; j < vec_n.size() - 1; j++){
                            if(vec_n [j] < vec_n [j + 1])
                                max_v = vec_n [j + 1];
                        }
                    }
                    
                    cout << "max  = " << max_v << " ";

                    if(max_v >= shipVec[i]->getSize())
                        cond = true;
                    else
                        x = 10;
                    
                }

                cout << "Scegliere la colonna in cui si vuole inserire l'estremità sinistra della nave ";
                cin >> y;
                cout << endl;


                
                if(y + shipVec[i]->getSize() - 1 >= dim_grid || x < 0)
                    condition = false;
                else{
                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        if(theGrid[x][y + j] != water){   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta
                            condition = false;
                            break;
                        }
                    }
                }

                while(!condition){ //la selezione deve stare dentro la board e siccome la nave la piazziamo dall'estremità sinistra inn poi dobbiamo anche controllare che l'estremità destra della nave sarà ancora dentro la board, e che ino
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> y;
                    cout << endl;

                    condition = true;

                    if(y + shipVec[i]->getSize() - 1 >= dim_grid || x < 0)
                        condition = false;
                    else{
                        for(int j = 0; j < shipVec[i]->getSize(); j++){
                            if(theGrid[x][y + j] != water){   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta
                                condition = false;
                                break;
                            }
                        }
                    }
                }


                shipVec[i]->setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){  //finiti i controlli piazziamo la nave
                    theGrid[x][y + j] = shipVec[i]->getCode();
                }

                cout << "Hai posizionato la nave con successo" << endl;

                cout << "\n\n";

                printPlayerGrid();

                system("clear");


            }else if(temp == 'v'){
                //caso in cui la nave ha orientazione verticale

                orientation = false;
                system("clear");

                cout << "Hai selezionato verticale" << endl;
                cout << "\n";
                cout << shipVec[i]->getName() << "   ";
                shipVec[i]->printShip();
                cout << "    ha una dimensione di " << shipVec[i]->getSize() << endl;
                cout << "\n\n";

                printPlayerGrid();

                cout << "\n\n";


                cout << "Scegliere la colonna in cui si vuole inserire l'estremità alta della nave ";
                cin >> y;
                cout << endl;

                
                
                while(!cond){

                    while(y > dim_grid - 1 || y < 0){   //affinché la colonna sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero di spazi consecutivi sia almeno lo stesso numero degli spazi occupati dalla nave
                        cout << "ERRORE!!! Inserire un numero valido: ";
                        cin >> y;
                        cout << endl;
                    }

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //ricordo che di default x = 0 e y = 0
                        cout << "j = " << j << " ";
                        if(theGrid[x + j][y] == water){   //contiamo quanti spazi consecutivi separati da navi ci sono
                            n++;
                            cout << "n = " << n << " ";
                        }
                        if(theGrid[x + j][y] != water || x + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
                            cout << "vec = " << vec_n [0] << " ";
                            n = 0;
                        }
                    }
                    
                    max_v = vec_n [0];
                    
                    if(vec_n.size() > 1){
                        for(int j = 0; j < vec_n.size() - 1; j++){
                            if(vec_n [j] < vec_n [j + 1])
                                max_v = vec_n [j + 1];
                        }
                    }
                    
                    cout << "max  = " << max_v << " ";

                    if(max_v >= shipVec[i]->getSize())
                        cond = true;
                    else
                        y = 10;
                }

                cout << "Scegliere la riga in cui si vuole inserire l'estremità alta della nave ";
                cin >> x;
                cout << endl;

                
                if(x + shipVec[i]->getSize() - 1 >= dim_grid || x < 0)
                    condition = false;
                else{
                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        if(theGrid[x + j][y] != water){   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta in alternativa dal pezzo precedente di codice si può lasciare al giocatora la possibilità di scegliere soltanto le posizioni possibili
                            condition = false;
                            break;
                        }
                    }
                }
                

                while(!condition){
                    cout << "ERRORE!!! Inserire un numero valido: ";
                    cin >> x;
                    cout << endl;

                    condition = true;

                    if(x + shipVec[i]->getSize() - 1 >= dim_grid || x < 0)
                        condition = false;
                    else{
                        for(int j = 0; j < shipVec[i]->getSize(); j++){
                            if(theGrid[x + j][y] != water){   //quando esce dal ciclo se ha incontrato almeno un pezzo che non è acqua la condizione non è più soddisfatta in alternativa dal pezzo precedente di codice si può lasciare al giocatora la possibilità di scegliere soltanto le posizioni possibili
                                condition = false;
                                break;
                            }
                        }
                    }

                }
                
                shipVec[i]->setShip(x, y, orientation);

                for(int j = 0; j < shipVec[i]->getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x + j][y] = shipVec[i]->getCode();
                }
                

                cout << "Hai posizionato la nave con successo" << endl;

                cout << "\n\n";

                printPlayerGrid();

                system("clear");
            }
        }

        cout << "La tua flotta è in posizione comandante!" << endl;

        cout << "\n\n\n";

        printPlayerGrid();

        system("clear");

    }else{  //se il giocatore che sta settando la board è CPU
        
        cout << "AAAAA " << ssd.getName();

        for(int i = 0; i < shipVec.size(); i++){
            
            x = 0;
            y = 0;
            condition = true;
            
            srand((unsigned int) time(NULL));

            if(rand() % 2 == 0)
                orientation = true; //orizzontale
            else
                orientation = false;
            
            x = rand() % 10;
            y = rand() % 10;
            cout << shipVec.size();
            cout << "AAAAA " << shipVec[i]->getName();

            if(orientation){    //orientazione orizzontale
                
                x = rand() % 10;
                y = rand() % (11 - shipVec[i]->getSize());
                
                cout << " x = " << x << " y = " << y << endl;
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){
                    if(theGrid[x][y + j] != water)
                        cout << "check y = " << y + j << endl;
                        condition = false;
                }

                while(theGrid[x][y] != water && !condition){
                    x = rand() % 10;
                    y = rand() % (11 - shipVec[i]->getSize());
                    
                    cout << " x = " << x << " y = " << y << endl;

                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        if(theGrid[x][y + j] != water){
                            condition = false;
                            cout << "check y = " << y + j << endl;
                        }
                        else
                            condition = true;
                    }
                }
                
                shipVec[i]->setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x][y + j] = shipVec[i]->getCode();
                }
                
            }else{  //orientazione verticale
                
                x = rand() % (11 - shipVec[i]->getSize());
                y = rand() % 10;
                
                cout << " x = " << x << " y = " << y << endl;
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){
                    cout << "SetGrid 431 ";
                    if(theGrid[x + j][y] != water){
                        condition = false;
                        cout << "check x = " << x + j << endl;
                    }
                }

                while(theGrid[x][y] != water || !condition){
                    cout << "SetGrid 437 ";
                    x = rand() % (11 - shipVec[i]->getSize());
                    y = rand() % 10;
                    
                    cout << " x = " << x << " y = " << y << endl;

                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        cout << "SetGrid 442 ";
                        if(theGrid[x + j][y] != water){
                            condition = false;
                            cout << "check x = " << x + j << endl;
                        }
                        else
                            condition = true;
                    }
                }
                
                shipVec[i]->setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){  //finiti i controlli stampiamo
                    cout << "Bazzecole";
                    theGrid[x + j][y] = shipVec[i]->getCode();
                }
                
            }
            sleep(1);
        }
        
        printPlayerGrid();
        sleep(1);
    }
    
}


bool grid::getPmode() const{
    return p_mode;
}




// è la funzione che viene richiamata in Game

bool grid::isShotBy(grid board){

    int x, y, k;
    if(board.getPmode()){
    //cout << "Passare il computer al comandante " << player1_name;
    //cout << endl;
        cout << "Premere ENTER per iniziare l'attacco " << endl;
        cin.ignore();
        cin.ignore();
        system("clear");

        printInfo(); //Andrà bene scrivere p1 e p2? Non credo. In game gli stiamo dicendo di strae in p1.shot(p2) e quindi qua va modificato in qualche modo
        cout << "\n\n\n" ;
        board.printPlayerGrid();
        cout << "\n\n\n" ;
        printOpponentGrid();
        cout << "\n\n\n";

        cout << "Dove vuoi sparare? Inserisci le coordinate digitando prima il numero della riga e poi della colonna: " << endl;
        cout << "Riga: ";
        cin >> x;
        cout << "Colonna: ";
        cin >> y;

        while (x < 0 || x > dim_grid - 1 || y < 0 || y > dim_grid - 1 || theGrid [x][y] == sunk || theGrid [x][y] == hit || theGrid [x][y] == miss){
            cout << "ERRORE, INSERIRE DELLE COORDINATE VALIDE: ";
            cout << "Riga: ";
            cin >> x;
            cout << "Colonna: ";
            cin >> y;
            cout << endl;
        }


    //Controlli sui tre scenari


        if (theGrid[x][y] == water){

            theGrid[x][y] = miss;
            cout << "MANCATO!";
            cout <<  "Non hai più colpi a disposizione. Premi invio e passa il computer al tuo avversario.";
            cin.ignore();
            cin.ignore();
            system("clear");

            return false;

        }else{

            switch(theGrid[x][y]){
            case 'A':
                shipVec[0]->setHit();
                theGrid [x][y] = hit;
                cout << "COLPITO! Hai un altro colpo a disposizione " << endl;



                if(shipVec[0]->isSunk()){
                    cout << "La nave " << shipVec[0]->getName() << " è stata COLPITA ED AFFONDATA!" << endl;
                    if (shipVec[0]->ShipOrientation() == true){ //true = orizzontale
                        for(int i = 0; i < shipVec[0]->getSize(); i++){
                            theGrid[shipVec[0]->getX()][shipVec[0]->getY() + i] = sunk;
                        }
                    }else{
                        for(int i = 0; i < shipVec[0]->getSize(); i++){
                            theGrid[shipVec[0]->getX() + i][shipVec[0]->getY()] = sunk;
                        }
                    }
                }


                break;

            case 'B':

                    shipVec[1]->setHit();
                    theGrid [x][y] = hit;
                    cout << "COLPITO! Hai un altro colpo a disposizione" << endl;



                    if(shipVec[1]->isSunk()){
                        cout << "La nave " << shipVec[1]->getName() << " è stata COLPITA ED AFFONDATA!" << endl;
                        if (shipVec[1]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[1]->getSize(); i++){
                            theGrid[shipVec[1]->getX()][shipVec[1]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[1]->getSize(); i++){
                            theGrid[shipVec[1]->getX() + i][shipVec[1]->getY()] = sunk;
                            }

                        }
                    }

                    break;

            case 'C':

                    shipVec[2]->setHit();
                    theGrid [x][y] = hit;
                    cout << "COLPITO! Hai un altro colpo a disposizione" << endl;

                    if(shipVec[2]->isSunk()){
                        cout << "La nave " << shipVec[2]->getName() << " è stata COLPITA ED AFFONDATA!" << endl;
                        if (shipVec[2]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[2]->getSize(); i++){
                            theGrid[shipVec[2]->getX()][shipVec[2]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[2]->getSize(); i++){
                                theGrid[shipVec[2]->getX() + i][shipVec[2]->getY()] = sunk;
                            }
                        }
                    }

                    break;

            case 'D':
                    
                    shipVec[3]->setHit();
                    theGrid [x][y] = hit;
                    cout << "COLPITO! Hai un altro colpo a disposizione" << endl;

                    if(shipVec[3]->isSunk()){
                        cout << "La nave " << shipVec[3]->getName() << " è stata COLPITA ED AFFONDATA!" << endl;
                        if (shipVec[3]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[3]->getSize(); i++){
                                theGrid[shipVec[3]->getX()][shipVec[3]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[3]->getSize(); i++){
                                theGrid[shipVec[3]->getX() + i][shipVec[3]->getY()] = sunk;
                            }
                        }
                    }
                    
                    break;
            }
            
            k = 0;
            for(int i = 0; i < shipVec.size(); i++){
                if(shipVec[i]->isSunk())
                    k++;
            }
            
            if(k == shipVec.size())
                return false;
                    
            }

            return true;
            
        
    }else{  //se il giocatore è CPU
        
        

        // Vorrei che tutte le scritte si cancellassero. Va bene usare system("clear")?
        
        //int plus_minus [] = {-1, 1};

        if(!*already_hit){
            
            cout << "isShotBy 747" << endl;

            srand((unsigned int) time(NULL));

            cout << "Il tuo avversario sta pianificando il suo attacco, attendere..." << endl;

            *theX = rand() % 10;
            *theY = rand() % 10;
            
            while(theGrid[*theX][*theY] == miss || theGrid[*theX][*theY] == hit || theGrid[*theX][*theY] == sunk){
                srand((unsigned int) time(NULL));
                
                *theX = rand() % 10;
                *theY = rand() % 10;
            }
            
            cout << "isShotBy 760" << endl;
            
            cout << " hit x = " << *theX << " y = " << *theY << endl;

        }else{
            
            int i = 0;  //x di hit
            int j = 0;  //y di hit
            
            while(theGrid[i][j] != hit){    //andiamo a cercare il primo hit in un una ricerca riga per riga
                j = 0;
                while(theGrid[i][j] != hit){
                    j++;
                    if(j == dim_grid - 1)
                        break;
                }
                i++;
            }
            
            cout << "hit è in i = " << i << " j = " << j << endl;
            
            
            //riempiamo side
            
            if(i == 0)
                vec_side [2] = 1;
            
            if(j == 0)
                vec_side [0] = 1;
            
            if(i == dim_grid - 1)
                vec_side [3] = 1;
            
            if(j == dim_grid - 1)
                vec_side [1] = 1;
            
            
            if(i == 0 && j == 0){   //bordo in (0, 0)
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                    
            }else if(i == 0 && j == dim_grid - 1){  //bordo in (0, 9)
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }else if(i == dim_grid - 1 && j == 0){  //bordo in (9, 0)
                
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
            }else if(i == dim_grid - 1 && j == dim_grid - 1){   //bordo in (9, 9)
                
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }else if(i == 0 && j != 0 && j != dim_grid - 1){    //lato alto
                
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }else if(i == dim_grid - 1 && j != 0 && j != dim_grid - 1){    //lato basso
                
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }else if(j == 0 && i != 0 && i != dim_grid - 1){    //lato sinistro
                
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
            
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
            }else if(j == dim_grid - 1 && i != 0 && i != dim_grid - 1){    //lato destro
                
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
            
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }else{  //in mezzo alla board
                
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
            
                if(theGrid[i - 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }
            
            
            
            /*caso 1
                0|1|2|...
              0|/|?|
              1|?|.|
             */
            int sum_side = 0;
            int sum_around = 0;
            int sum_hit = 0;
            
            for(int k = 0; k < 4; k++){
                
                sum_side = sum_side + vec_side [k];
                
                sum_around = sum_around + vec_around [k];
                
                sum_hit = sum_hit + vec_hit [k];
            }
            
            
            
            if(sum_side == 2){  //siamo negli spigoli
                
                if(sum_around == 0){    //nessuno dei caratteri adiacenti ad hit è miss/sunk
                    
                    if(sum_hit == 0){   //nessuno dei caratteru adiacenti ad hit è hit
                        
                        /*caso 1
                         
                            0|1|2|...
                          0|/|?|
                          1|?|.|
                         
                         */
                        
                        if(vec_side [0] == 1 && vec_side [2] == 1){
                            
                            srand((unsigned int) time(NULL));
                            
                            *orientation = rand() % 2 + 1;
                            
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY + 1;
                            else    //verticale
                                *theX = *theX + 1;
                        }
                            
                        /*caso 2
                            |8|9|
                            |?|/|0
                            |.|?|1
                         
                        */
                            
                        if(vec_side [0] == 1 && vec_side [3] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY - 1;
                            else    //verticale
                                *theX = *theX + 1;
                            
                        }
                        
                        /*caso 3
                          
                         8|?|.|
                         9|/|?|
                          |0|1|2|...
                         
                         */
                        
                        if(vec_side [1] == 1 && vec_side [2] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY + 1;
                            else    //verticale
                                *theX = *theX - 1;
                            
                        }
                        
                        /*caso 4
                          
                         |.|?|8
                         |?|/|9
                         |8|9|
                         
                         */
                        
                        if(vec_side [1] == 1 && vec_side [3] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY - 1;
                            else    //verticale
                                *theX = *theX - 1;
                            
                        }
                        
                    }else if(sum_hit == 1){
                        
                        
                        /*caso 5
                         
                            0|1|2|...
                          0|/|/|
                          1|?|.|
                         
                         */
                        
                        if(vec_side [0] == 1 && vec_side [2] == 1 && vec_hit [3] == 1){
                            
                            int k = 0;
                            
                            while(theGrid[i][j + k] == hit){
                                k++;
                            }
                            
                            if(theGrid[i][j + k] != miss || theGrid[i][j + k] != sunk){
                                *theY = *theY + k;
                                goto end;
                            }
                            
                            srand((unsigned int) time(NULL));
                            
                            *orientation = rand() % 2 + 1;
                            
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY + 1;
                            else    //verticale
                                *theX = *theX + 1;
                        }
                            
                        /*caso 2
                            |8|9|
                            |?|/|0
                            |.|?|1
                         
                        */
                            
                        if(vec_side [0] == 1 && vec_side [3] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY - 1;
                            else    //verticale
                                *theX = *theX + 1;
                            
                        }
                        
                        /*caso 3
                          
                         8|?|.|
                         9|/|?|
                          |0|1|2|...
                         
                         */
                        
                        if(vec_side [1] == 1 && vec_side [2] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY + 1;
                            else    //verticale
                                *theX = *theX - 1;
                            
                        }
                        
                        /*caso 4
                          
                         |.|?|8
                         |?|/|9
                         |8|9|
                         
                         */
                        
                        if(vec_side [1] == 1 && vec_side [3] == 1){
                                
                            srand((unsigned int) time(NULL));
                                
                            *orientation = rand() % 2 + 1;
                                
                            if(*orientation == 1)   //orizzontale
                                *theY = *theY - 1;
                            else    //verticale
                                *theX = *theX - 1;
                            
                        }
                        
                    }
                    
                }
                
            }
            
            
            
            
            /*
            cout << "isShotBy 766" << endl;

            if(*orientation == 0){   //se non è ancora stata guessata un'orientazione
                *theK = 2; //variabile di supporto per capire a che punto siamo nel guess
                cout << "isShotBy 777" << endl;
                srand((unsigned int) time(NULL));
                *orientation = rand() % 2 + 1;
                
                cout << " orientation = " << *orientation << " Try_z = " << *Try_z << " k = " << *theK << endl;
                cout << " previous hit x = " << *theX << " y = " << *theY << endl;
            }
            

            if(*orientation == 1 && *theK == 2 && *Try_z < 2){ //orientazione verticale
                
                cout << "isShotBy 778" << endl;

                while(theGrid[*theX][*theY] == miss || theGrid[*theX][*theY] == hit || theGrid[*theX][*theY] == sunk || *theX < 0 || *theX > dim_grid - 1){    //fin tanto che non trova qualcosa da colpire randomizza un +-1 rispetto alla posizione del colpo precedente

                    srand((unsigned int) time(NULL));
                    
                    int g;
                    
                    if(*theX == 0)
                        *theX = old_shots[*r - 2] + 1;
                    else if(*theX == dim_grid - 1)
                        *theX = old_shots[*r - 2] - 1;
                    else{
                        srand((unsigned int) time(NULL));
                         g = rand () % 2;
                        *theX = old_shots[*r - 2] + plus_minus[g];
                        *theY = old_shots[*r - 1];
                    }
                    
                    cout << "isShotBy 788" << endl;
                    
                    cout << " r = " << *r << " plus_minus[g] = " << plus_minus[g] << endl;
                    
                    cout << " hit x = " << *theX << " y = " << *theY << endl;
                }

                *theK = *theK - 1;

            }else if(*orientation == 1 && *theK == 1 && *Try_z < 2){    //se il colpo con k = 2 abbiamo mancato
                
                cout << "isShotBy 793" << endl;
                
                if(old_shots[*r - 1] == 0 && theGrid[*theX][*theY] == miss){
                    *orientation = 2;
                    *theK = *theK - 1;
                    *Try_z = 2;
                    goto here;
                }else if(old_shots[*r - 1] == dim_grid - 1 && theGrid[*theX][*theY] == miss){
                    *orientation = 2;
                    *theK = *theK - 1;
                    *Try_z = 2;
                    goto here;
                }

                while(theGrid[*theX][*theY] == miss || theGrid[*theX][*theY] == hit || theGrid[*theX][*theY] == sunk || *theX < 0 || *theX > dim_grid - 1){

                    int g;
                    
                    if(*theX == 0)
                        *theX = old_shots[*r - 2] + 1;
                    else if(*theX == dim_grid - 1)
                        *theX = old_shots[*r - 2] - 1;
                    else{
                        srand((unsigned int) time(NULL));
                         g = rand () % 2;
                        *theX = old_shots[*r - 2] + plus_minus[g];
                        *theY = old_shots[*r - 1];
                    }
                    
                    cout << "isShotBy 807" << endl;
                    
                    cout << " r = " << *r << " plus_minus[g] = " << plus_minus[g] << endl;
                    
                    cout << " hit x = " << *theX << " y = " << *theY << endl;
                }

                *theK = *theK - 1;
            }
            
            here:

    
            if(*orientation == 2 && *theK == 2 && *Try_z < 2){ //orientazione orizzontale
                

                while(theGrid[*theX][*theY] == miss || theGrid[*theX][*theY] == hit || theGrid[*theX][*theY] == sunk || *theY < 0 || *theY > dim_grid - 1){

                    srand((unsigned int) time(NULL));
                    int g = rand () % 2;

                    if(*theY == 0){
                        *theY = old_shots[*r - 1] + 1;
                        cout << "isShotBy 871" << endl;
                    }
                    else if(*theY == dim_grid - 1){
                        *theY = old_shots[*r - 1] - 1;
                        cout << "isShotBy 875" << endl;
                    }
                    else{
                        *theX = old_shots[*r - 2];
                        *theY = old_shots[*r - 1] + plus_minus[g];
                    }
                    
                    cout << "isShotBy 882" << endl;
                    
                    cout << " r = " << *r << " plus_minus[g] = " << plus_minus[g] << endl;
                    
                    cout << " hit x = " << *theX << " y = " << *theY << endl;
                }

                *theK = *theK - 1;

            }else if(*orientation == 2 && *theK == 1 && *Try_z < 2){
                
                cout << "isShotBy 893" << endl;
                
                if(old_shots[*r] == 0 && theGrid[*theX][*theY] == miss){
                    *orientation = 1;
                    *theK = *theK - 1;
                    *Try_z = 2;
                    goto here;
                }else if(old_shots[*r] == 9 && theGrid[*theX][*theY] == miss){
                    *orientation = 1;
                    *theK = *theK - 1;
                    *Try_z = 2;
                    goto here;
                }

                while(theGrid[*theX][*theY] == miss || theGrid[*theX][*theY] == hit || theGrid[*theX][*theY] == sunk || *theY < 0 || *theY > dim_grid - 1){

                    srand((unsigned int) time(NULL));
                    int g = rand () % 2;
                    

                    if(*theY == 0)
                        *theY = old_shots[*r - 2] + 1;
                    else{
                        *theX = old_shots[*r - 2];
                        *theY = old_shots[*r - 1] + plus_minus[g];
                    }
                    
                    cout << " r = " << *r << " plus_minus[g] = " << plus_minus[g] << endl;
                    
                    cout << "isShotBy 843" << endl;
                    cout << " hit x = " << *theX << " y = " << *theY << endl;
                }

                *theK = *theK - 1;
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
                
            *theK = 0;
        }
        
        cout << "isShotBy 853" << endl;
        
        if(old_shots[1] == old_shots [3] && *Try_z == 2){ //se le prime due entrate pari del vettore sono uguali significa che la nave ha le y uguali e quindi è verticale
            *orientation = 1;
            if(old_shots[0] > old_shots [2]){ //cosi abbiamo nell'ultima entrata l'ordine maggiore, diventa utile nel while dopo
                temp = old_shots [2];
                old_shots [2] = old_shots[0];
                old_shots[0] = temp;
            }
            *theK = 0;
        }
        
        
        
        while(*already_hit && *Try_z >= 2 && *theK == 0){
            
            cout << "isShotBy 869" << endl;
            
            if(old_shots[*r - 2] != *theX || old_shots[*r - 1] != *theY){  //se ha mancato ma non ancora affondato allora cambia direzione del colpo
                *direction_hit = false;
                cout << "isShotBy 873" << endl;
                
            }
            
            if(*orientation == 2 && *direction_hit){  //orizzontale
                *theX = old_shots[*r - 2];
                *theY = old_shots[*r - 1] + 1;
                cout << "isShotBy 880" << endl;
                cout << " hit x = " << *theX << " y = " << *theY << endl;
                
                break;
                
            }else if(*orientation == 2 && !*direction_hit){
                *theX = old_shots[*r - 2];
                *theY = old_shots[*r - 1] - 1;
                cout << "isShotBy 888" << endl;
                cout << " hit x = " << *theX << " y = " << *theY << endl;
                break;
            }
            
            if(*orientation == 1 && *direction_hit){    //verticale
                *theX = old_shots[*r - 2] + 1;
                *theY = old_shots[*r - 1];
                cout << "isShotBy 896" << endl;
                cout << " hit x = " << *theX << " y = " << *theY << endl;
                break;
                
            }else if(*orientation == 1 && !*direction_hit){
                *theX = old_shots[*r - 2] - 1;
                *theY = old_shots[*r - 1];
                cout << "isShotBy 903" << endl;
                cout << " hit x = " << *theX << " y = " << *theY << endl;
                break;
            }
        }
        
        
        */
            
        end:;

        if(theGrid[*theX][*theY] == water){
            theGrid[*theX][*theY] = miss;
            return false;
        }

        else{
        
            *already_hit = true;
        
            old_shots [*r] = *theX;
            old_shots [*r + 1] = *theY;
        
            *r = *r + 2;
        
            *Try_z = *Try_z + 1;
        
        
            switch(theGrid[*theX][*theY]){
                case 'A':
                    shipVec[0]->setHit();
                    theGrid[*theX][*theY] = hit;
                    if(shipVec[0]->isSunk()){    //bisogna aggiungere una caratteristica della nave che è il numero di pezzi colpiti, poi si controlla se i pezzi colpiti == dim_ship, se vero allora è sunk
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        *orientation = 0;
                        
                        if (shipVec[0]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[0]->getSize(); i++){
                                theGrid[shipVec[0]->getX()][shipVec[0]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[0]->getSize(); i++){
                                theGrid[shipVec[0]->getX() + i][shipVec[0]->getY()] = sunk;
                            }
                        }
                        
                        delete[] old_shots;
                    }
                    break;
            
                case 'B':
                    shipVec[1]->setHit();
                    theGrid[*theX][*theY] = hit;
                    if(shipVec[1]->isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        *orientation = 0;
                        
                        if (shipVec[1]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[1]->getSize(); i++){
                                theGrid[shipVec[1]->getX()][shipVec[1]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[1]->getSize(); i++){
                                theGrid[shipVec[1]->getX() + i][shipVec[1]->getY()] = sunk;
                            }
                        }
                        
                        delete[] old_shots;
                    }
                    break;
            
                case 'C':
                    shipVec[2]->setHit();
                    theGrid[*theX][*theY] = hit;
                    if(shipVec[2]->isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        *orientation = 0;
                        theGrid[*theX][*theY] = sunk;
                        
                        if (shipVec[2]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[2]->getSize(); i++){
                                theGrid[shipVec[2]->getX()][shipVec[2]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[2]->getSize(); i++){
                                theGrid[shipVec[2]->getX() + i][shipVec[2]->getY()] = sunk;
                            }
                        }
                        
                        delete[] old_shots;
                    }
                    break;
            
                case 'D':
                    shipVec[3]->setHit();
                    theGrid[*theX][*theY] = hit;
                    if(shipVec[3]->isSunk()){
                        *already_hit = false;
                        *direction_hit = true;
                        *r = 0;
                        *Try_z = 0;
                        *orientation = 0;
                        theGrid[*theX][*theY] = sunk;
                        
                        if (shipVec[3]->ShipOrientation() == true){ //true = orizzontale
                            for(int i = 0; i < shipVec[3]->getSize(); i++){
                                theGrid[shipVec[3]->getX()][shipVec[3]->getY() + i] = sunk;
                            }
                        }else{
                            for(int i = 0; i < shipVec[3]->getSize(); i++){
                                theGrid[shipVec[3]->getX() + i][shipVec[3]->getY()] = sunk;
                            }
                        }
                        
                        delete[] old_shots;
                    }
                    break;
            }
        
            return true;
            
        }
        
    }
        
        //_________________________________________________________Il codice di vale_______________________________________________________
          //SI CONSIGLIA DI INSERIRLO NELLA RIGA 1179
        else if(sum_around == 1){


                    if(sum_hit == 0){

                        /*caso 2a.a

                            0|1|2|...
                          0|/|?|
                          1|*|.|

                         */

                        if((vec_side[0] == 1 && vec_side [2] == 1) && (vec_around [1] == miss || vec_around [1] == sunk)){ //hit è (0,0)
                            *orientation = 1; //orizzontale
                            x = 0;
                            y = 1;
                            goto end;

                        }

                        /*caso 2b.a

                            0|1|2|...
                          0|/|*|
                          1|?|.|

                         */

                        if((vec_side[0] == 1 && vec_side [2] == 1) && (vec_around [3] == miss || vec_around [3] == sunk)){

                            *orientation = 2; //verticale
                            x = 1;
                            y = 0;
                            goto end;

                        }

                        /*caso 2a.b

                             |0|1|
                            8|*|.|
                            9|/|?|

                         */

                        if((vec_side[1] == 1 && vec_side [2] == 1) && (vec_around [0] == miss || vec_around [0] == sunk)){

                            *orientation = 1; //orizzontale
                            x = dim_grid - 1;
                            y = 1;
                            goto end;

                        }

                        /*caso 2b.b

                             |0|1|
                            8|?|.|
                            9|/|*|

                         */

                        if((vec_side[1] == 1 && vec_side [2] == 1) && (vec_around [3] == miss || vec_around [3] == sunk)){

                            *orientation = 1; //verticale
                            x = dim_grid - 2;
                            y = 0;
                            goto end;

                        }

                        /*caso 2a.c

                             |8|9|
                            0|?|/|
                            1|.|*|

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1) && (vec_around [1] == miss || vec_around [1] == sunk)){

                            *orientation = 2; //orizzontale
                            x = 0;
                            y = dim_grid - 2;
                            goto end;

                        }

                        /*caso 2b.c

                             |8|9|
                            0|*|/|
                            1|.|?|

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1) && (vec_around [2] == miss || vec_around [2] == sunk)){

                            *orientation = 1; //verticale
                            x = 1;
                            y = dim_grid - 1;
                            goto end;

                        }

                        /*caso 2a.d

                             |8|9|
                             |.|*|8
                             |?|/|9

                         */

                        if((vec_side[1] == 1 && vec_side [3] == 1) && (vec_around [0] == miss || vec_around [0] == sunk)){

                            *orientation = 2; //orizzontale
                            x = dim_grid - 1;
                            y = dim_grid - 2;
                            goto end;

                        }

                        /*caso 2b.d

                             |8|9|
                             |.|?|8
                             |*|/|9

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1) && (vec_around [2] == miss || vec_around [2] == sunk)){

                            *orientation = 1; //verticale
                            x = dim_grid - 2;
                            y = dim_grid - 1;
                            goto end;

                        }
                    }

                    if(sum_hit == 1){

                        /*caso 3a.a

                            0|1|2|...
                          0|/|/|
                          1|*|.|

                         */

                        if((vec_side[0] == 1 && vec_side [2] == 1 && vec_hit [3] == 1) && (vec_around [1] == miss || vec_around [1] == sunk)){ //hit è (0,0)

                            int k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                                k++;
                            }

                            x = 0;
                            y = j + k;
                            goto end;

                        }

                        /*caso 3b.a

                            0|1|2|...
                          0|/|*|
                          1|/|.|

                         */

                        if((vec_side[0] == 1 && vec_side [2] == 1 && vec_hit [1] == 1) && (vec_around [3] == miss || vec_around [3] == sunk)){

                            int k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                                k++;
                            }

                            x = i + k;
                            y = 0;
                            goto end;

                        }

                        /*caso 3a.b

                             |0|1|
                            8|*|.|
                            9|/|/|

                         */

                        if((vec_side[1] == 1 && vec_side [2] == 1 && vec_hit [3] == 1) && (vec_around [0] == miss || vec_around [0] == sunk)){

                            int k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                                k++;
                            }

                            x = dim_grid - 1;
                            y = j + k;
                            goto end;

                        }

                        /*caso 3b.b

                             |0|1|
                            8|/|.|
                            9|/|*|

                         */

                        if((vec_side[1] == 1 && vec_side [2] == 1 && vec_hit [0] == 1) && (vec_around [3] == miss || vec_around [3] == sunk)){

                            int k = 0;

                            while(theGrid[i - k][j] == hit && i - k < dim_grid - 1){
                                k++;
                            }

                            x = i - k;
                            y = 0;
                            goto end;

                        }

                        /*caso 3a.c

                             |8|9|
                            0|/|/|
                            1|.|*|

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1 && vec_hit [2] == 1) && (vec_around [1] == miss || vec_around [1] == sunk)){

                            int k = 0;

                            while(theGrid[i][j - k] == hit && j - k < dim_grid - 1){
                                k++;
                            }

                            x = 0;
                            y = j - k;
                            goto end;

                        }

                        /*caso 3b.c

                             |8|9|
                            0|*|/|
                            1|.|/|

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1 && vec_hit [1] == 1) && (vec_around [2] == miss || vec_around [2] == sunk)){

                            int k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                                k++;
                            }

                            x = i + k;
                            y = dim_grid - 1;
                            goto end;

                        }

                        /*caso 3a.d

                             |8|9|
                             |.|*|8
                             |/|/|9

                         */

                        if((vec_side[1] == 1 && vec_side [3] == 1 && vec_hit [2] == 1) && (vec_around [0] == miss || vec_around [0] == sunk)){

                            int k = 0;

                            while(theGrid[i][j - k] == hit && j - k < dim_grid - 1){
                                k++;

                            x = dim_grid - 1;
                            y = j - k;
                            goto end;

                        }

                        /*caso 3b.d

                             |8|9|
                             |.|/|8
                             |*|/|9

                         */

                        if((vec_side[0] == 1 && vec_side [3] == 1 && vec_hit [0] == 1) && (vec_around [2] == miss || vec_around [2] == sunk)){

                            int k = 0;

                            while(theGrid[i - k][j] == hit && i - k < dim_grid - 1){
                                k++;
                            }

                            x = i - k;
                            y = dim_grid - 1;
                            goto end;

                        }
                    }
        
        
        
        
}
