//
//  grid.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 09/04/22.
//


#include "grid.hpp"


void grid::recordGrid(int d_grid, int num_ships, bool player_mode, string op_name){
    
    unknown = '?';
    hit = '/';
    sunk = 'X';
    water = '~';
    miss = '*';

    dim_grid = d_grid;
    n_ships = num_ships;

    p_mode = player_mode;
    
    opponent = op_name;

    vector<char> row;

    for(int i = 0; i < dim_grid; i++){
        row.push_back(water);
    }

    for(int j = 0; j < dim_grid; j++){
        theGrid.push_back(row);
    }
    
    shipVec.push_back(&ssd);
    shipVec.push_back(&sd);
    shipVec.push_back(&gc);
    shipVec.push_back(&tf);

    orientation = new int(0);
    return;
}





void grid::printInfo(){
    cout << "\t\t\t\t  Legenda simboli:" << endl;
    cout << "\t\t\t\t / = colpito, ~ = acqua, * = mancato, X = affondato, ? = ignoto\n";
    cout << "\t\t\t\t A = Super Star Destroyer,  B = Star Destroyer,  C = Gozanti Cruiser,  D = TIE Fighter" << endl;
    cout << "\n\n\n";
    
    cout << "\t\t\t\t Le navi che hai affondato sono:\n";
    for(int i = 0; i < shipVec.size(); i++){
        if(shipVec[i]->isSunk()){
            cout << "\t\t\t\t " << shipVec[i]->getName() << " ";
            shipVec[i]->printShip();
            cout << " di dimensione " << shipVec[i]->getSize() << "\n";
        }
    }
        
        cout << "\n\n";
        
    cout << "\t\t\t\t Le navi che devi ancora affondare sono:\n";
    for(int i = 0; i < shipVec.size(); i++){
        if(!shipVec[i]->isSunk()){
            cout << "\t\t\t\t " << shipVec[i]->getName() << " ";
            shipVec[i]->printShip();
            cout << " di dimensione " << shipVec[i]->getSize() << "\n";
        }
    }
    return;
}

void grid::printPlayerGrid(){

    cout << "\t\t\t\t\t\t\t\t\t     ";
    
    for(int i = 0; i < dim_grid; i ++){
        cout << i;
        if(i < dim_grid - (dim_grid - 10)){
            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << "\t\t\t\t\t\t\t\t\t ";
            }
        }
        cout << "|";
    }
    
    cout << endl;
    
    for(int i = 0; i < dim_grid; i ++){
        cout << "\t\t\t\t\t\t\t\t\t   ";
        for(int j = 0; j < dim_grid; j++){
            if(j == 0){
                cout << i;
                if(i < dim_grid - (dim_grid - 10)){
                    for(int k = 0; k < log10(dim_grid) - 1; k++){
                        cout << "\t\t\t\t\t\t\t\t\t ";
                    }
                }
                cout << "|";
            }
            cout << theGrid[i][j];
            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << "\t\t\t\t\t\t\t\t\t ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
    return;
}


void grid::printOpponentGrid(){
    
    cout << "\t\t\t\t\t\t\t\t\t     ";

    for(int i = 0; i < dim_grid; i ++){
        cout << i;
        if(i < dim_grid - (dim_grid - 10)){
            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << "\t\t\t\t\t\t\t\t\t ";
            }
        }
        cout << "|";
    }
    
    cout << endl;
    
    for (int i = 0; i < dim_grid; i ++){
        cout << "\t\t\t\t\t\t\t\t\t   ";
        for(int j = 0; j < dim_grid; j++){
            if(j == 0){
                cout << i;
                if(i < dim_grid - (dim_grid - 10)){
                    for(int k = 0; k < log10(dim_grid) - 1; k++){
                        cout << "\t\t\t\t\t\t\t\t\t ";
                    }
                }
                cout << "|";
            }
            if(theGrid[i][j] == sunk || theGrid[i][j] == miss || theGrid[i][j] == hit)
                cout << theGrid[i][j];
            else
                cout << "\033[35m" << unknown << "\033[0m";

            for(int k = 0; k < log10(dim_grid) - 1; k++){
                cout << "\t\t\t\t\t\t\t\t\t ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void grid::CountDown (int count) const{
    
    switch(count){
            
    case 4:
            
            cout << "\n\n\n\n\n\n\n\n\n";
            
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m        444444444\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m       4::::::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m      4:::::::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m     4::::44::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    4::::4 4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m   4::::4  4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  4::::4   4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 4::::444444::::444\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 4::::::::::::::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 4444444444:::::444\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m          4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m          4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m          4::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m        44::::::44\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m        4::::::::4\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m        4444444444\033[0m" << endl;
            
            break;
            
        case 3:
            
            cout << "\n\n\n\n\n\n\n\n\n";
            
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  333333333333333\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3:::::::::::::::33\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3::::::33333::::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3333333     3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m     33333333:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m     3:::::::::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m     33333333:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3333333     3:::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3::::::33333::::::3\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 3:::::::::::::::33\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  333333333333333\033[0m" << endl;
            
            break;
            
        case 2:
            
            cout << "\n\n\n\n\n\n\n\n\n";
            
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  222222222222222\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2:::::::::::::::22\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2::::::222222:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2222222     2:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             2:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m             2:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m          2222::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m     22222::::::22\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m   22::::::::222\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  2:::::22222\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2:::::2       222222\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2::::::2222222:::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 2::::::::::::::::::2\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 22222222222222222222\033[0m" << endl;
            
            break;
            
        case 1:
            
            cout << "\n\n\n\n\n\n\n\n\n";
            
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  1111111\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m  1::::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 1:::::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 111:::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::l\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::l\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::l\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::l\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m    1::::l\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 111::::::111\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 1::::::::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 1::::::::::1\033[0m" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t \033[1;35m 111111111111\033[0m" << endl;
            
            break;
    }
    return;
}



void grid::setGrid(bool player_mode){ //la griglia è gia piena di acqua, come dice il costruttore, numero di navi e dimensione griglia sono  note dal costruttore.


    int x, y;   //posizione cartesiana dell'estremità sinistra/alta della nave
    bool condition;  //condizione che verrà utile in seguito, da lasciare fuori dagli if
    bool orientation;   //orientazione della nave


    if(player_mode){   //se il giocatore che sta settando è umano

        for(int i = 0; i < shipVec.size(); i++){
            
            x = 0;
            y = 0;
            condition = true;
            
            cout << "\n\n\n\n\n\n";

            cout << "\t\t\t\t Posizionare la nave \033[1;7;37m " << shipVec[i]->getName() << " \033[0m dove si desidera." << endl;  //prende l'i-esima nave e ricava il nome
            cout << "\n\n";
            cout << "\t\t\t\t " << shipVec[i]->getName() << "  ";
            shipVec[i]->printShip(); //stampa l'i-esima nave, volendo si potrebbe fare l'overloading dell'operatore << così possiamo ficcarla nel cout (se rimane tempo)
            cout << " ha una dimensione di " << shipVec[i]->getSize() << endl;    //prendiamo l'i-esima dimensione
            cout << "\n\n";

            cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
            printPlayerGrid();

            cout << "\n\n";

            cout << "\t\t\t\t Scegliere se la nave deve essere posizionata con un'orientazione verticale, digitando v, od orizzontale digitando o: ";

            char temp;  //variabile temporanea per leggere char in input

            cin >> temp;
            cin.ignore();

            cout << endl;

            while(temp != 'v' && temp != 'o'){
                cout << "\t\t\t\t  ERRORE, SI È INSERITO UN CARATTERE DIVERSO DA 'v' od 'o'. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> temp;
                cin.ignore();
            }

            int n = 0;
            bool cond = false;
            vector<int> vec_n;  //numero di spazi disponibili in una determinata riga/colonna
            
            int max_v;


            //TUTTO IL PROCESSO DI CONTROLLO È OTTIMIZZABILE

            if(temp == 'o'){
                orientation = true; //true = orizzontale
                system("clear");
                
                cout << "\n\n\n\n\n\n";
                
                cout << "\t\t\t\t  Hai selezionato orizzontale" << endl;
                cout << "\n";
                cout << "\t\t\t\t " << shipVec[i]->getName() << "   ";
                shipVec[i]->printShip();
                cout << "    ha una dimensione di " << shipVec[i]->getSize() << endl;
                cout << "\n\n";

                cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
                printPlayerGrid();

                cout << "\n\n";


                cout << "\t\t\t\t  Scegliere la riga in cui si vuole inserire l'estremità sinistra della nave: ";
                cin >> x;
                cin.ignore();
                
                


                while(!cond){
                
                    while(x > dim_grid - 1 || x < 0){   //affinché la riga sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero massimo di spazi consecutivi sia almeno lo stesso numero degli spazi occupabili dalla nave
                        cout << "\t\t\t\t  ERRORE!!! Inserire un numero valido: ";
                        cin >> x;
                        cin.ignore();
                    }

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //potremmo trovare un modo migliore per fare questo controllo, non mi piace che rifcciamo questo ciclo
                        if(theGrid[x][y + j] == water)
                            n++;
                           //contiamo quanti spazi consecutivi separati da navi ci sono
                            
                        if(theGrid[x][y + j] != water || y + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
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

                    if(max_v >= shipVec[i]->getSize())
                        cond = true;
                    else
                        x = 10;
                    
                }

                cout << "\t\t\t\t  Scegliere la colonna in cui si vuole inserire l'estremità sinistra della nave: ";
                cin >> y;
                cin.ignore();


                
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
                    cout << "\t\t\t\t  ERRORE!!! Inserire un numero valido: ";
                    cin >> y;
                    cin.ignore();

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

                cout << "\t\t\t\t  Hai posizionato la nave con successo:" << endl;

                cout << "\n\n";

                cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
                printPlayerGrid();

                system("clear");


            }else if(temp == 'v'){
                //caso in cui la nave ha orientazione verticale

                orientation = false;
                system("clear");
                
                cout << "\n\n\n\n\n\n";

                cout << "\t\t\t\t  Hai selezionato verticale" << endl;
                cout << "\n";
                cout << "\t\t\t\t " << shipVec[i]->getName() << "   ";
                shipVec[i]->printShip();
                cout << "    ha una dimensione di " << shipVec[i]->getSize() << endl;
                cout << "\n\n";

                cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
                printPlayerGrid();

                cout << "\n\n";


                cout << "\t\t\t\t  Scegliere la colonna in cui si vuole inserire l'estremità alta della nave: ";
                cin >> y;
                cin.ignore();

                
                
                while(!cond){

                    while(y > dim_grid - 1 || y < 0){   //affinché la colonna sia valida, devo controllare che il numero inserito non sia fuori dalla grid e che inoltre il numero di spazi consecutivi sia almeno lo stesso numero degli spazi occupati dalla nave
                        cout << "\t\t\t\t  ERRORE!!! Inserire un numero valido: ";
                        cin >> y;
                        cin.ignore();
                    }

                    vec_n.clear();  //cancelliamo tutto quello che sta dentro il vettore

                    for(int j = 0; j < dim_grid; j++){  //ricordo che di default x = 0 e y = 0
                        if(theGrid[x + j][y] == water)   //contiamo quanti spazi consecutivi separati da navi ci sono
                            n++;

                        if(theGrid[x + j][y] != water || x + j == 9){
                            vec_n.push_back(n); //ogni volta che incontriamo un pezzo di nave mettiamo i conteggi dentro il vettore o se abbiamo finito la board
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
                

                    if(max_v >= shipVec[i]->getSize())
                        cond = true;
                    else
                        y = 10;
                }

                cout << "\t\t\t\t  Scegliere la riga in cui si vuole inserire l'estremità alta della nave: ";
                cin >> x;
                cin.ignore();

                
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
                    cout << "\t\t\t\t  ERRORE!!! Inserire un numero valido: ";
                    cin >> x;
                    cin.ignore();

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
                

                cout << "\t\t\t\t  Hai posizionato la nave con successo" << endl;

                cout << "\n\n";

                cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
                printPlayerGrid();

                system("clear");
            }
        }

        cout << "\t\t\t\t La tua flotta è in posizione comandante!" << endl;

        cout << "\n\n\n";

        cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
        printPlayerGrid();

        system("clear");

    }else{  //se il giocatore che sta settando la board è CPU
        
        int k;

        for(int i = 0; i < shipVec.size(); i++){
            
            system("clear");
            
            cout << "\n\n\n";
            
            CountDown(shipVec.size() - i);
            
            x = 0;
            y = 0;
            condition = true;
            
            srand((unsigned int) time(NULL));

            if(rand() % 2 == 0)
                orientation = true; //orizzontale
            else
                orientation = false;
            

            if(orientation){    //orientazione orizzontale
                
                sleep(1);
                
                srand((unsigned int) time(NULL));
                
                x = rand() % 10;
                y = rand() % (11 - shipVec[i]->getSize());
                
                k = 0;
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){
                    if(theGrid[x][y + j] != water)
                        k++;
                }
                
                if(k != 0)
                    condition = false;

                while(theGrid[x][y] != water || !condition){
                    
                    sleep(1);
                    
                    srand((unsigned int) time(NULL));
                    
                    x = rand() % 10;
                    y = rand() % (11 - shipVec[i]->getSize());
                    
                    k = 0;

                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        if(theGrid[x][y + j] != water)
                            k++;
                    }
                    
                    if(k != 0)
                        condition = false;
                    else
                        condition = true;
                    
                }
                
                shipVec[i]->setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){  //finiti i controlli stampiamo
                    theGrid[x][y + j] = shipVec[i]->getCode();
                }
                
            }else{  //orientazione verticale
                
                sleep(1);
                
                srand((unsigned int) time(NULL));
                
                x = rand() % (11 - shipVec[i]->getSize());
                y = rand() % 10;
                
                k = 0;
                
                for(int j = 0; j < shipVec[i]->getSize(); j++){
                    if(theGrid[x + j][y] != water)
                        k++;
                }
                
                if(k != 0)
                    condition = false;

                while(theGrid[x][y] != water || !condition){
                    
                    sleep(1);
                    
                    srand((unsigned int) time(NULL));
                    
                    x = rand() % (11 - shipVec[i]->getSize());
                    y = rand() % 10;
                    
                    k = 0;
                    
                    for(int j = 0; j < shipVec[i]->getSize(); j++){
                        if(theGrid[x + j][y] != water)
                            k++;
                    }
                    
                    if(k != 0)
                        condition = false;
                    else
                        condition = true;
                }
                
                shipVec[i]->setShip(x, y, orientation);
                
                for(int j = 0; j < shipVec[i]->getSize(); j++) //finiti i controlli stampiamo
                    theGrid[x + j][y] = shipVec[i]->getCode();
                
            }
        system("clear");
        }
    }
    return;
}


bool grid::getPmode() const{
    return p_mode;
}

bool grid::hittable() const{    //se il giocatore non può piu hittare nulla return false
    
    int j = 0;
    
    for(int i = 0; i < shipVec.size(); i++){
        if(shipVec[i]->isSunk())
            j++;
    }
    
    if(j == shipVec.size())
        return false;
    else
        return true;
}




// è la funzione che viene richiamata in Game

bool grid::isShotBy(grid board){
    
    system("clear");
    
    int x = 0, y = 0, k;
    if(board.getPmode()){
    
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t Premere \033[1;7;37m ENTER \033[0m per iniziare l'attacco";
        cin.ignore();
        system("clear");

        printInfo();
        cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
        board.printPlayerGrid();
        cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t LA FLOTTA DEL NEMICO:" << endl;
        printOpponentGrid();
        cout << "\n\n\n";

        cout << "\t\t\t\t Dove vuoi sparare? Inserisci le coordinate digitando prima il numero della riga e poi della colonna: " << endl;
        cout << "\t\t\t\t Riga: ";
        cin >> x;
        cin.ignore();
        cout << "\t\t\t\t Colonna: ";
        cin >> y;
        cin.ignore();

        while (x < 0 || x > dim_grid - 1 || y < 0 || y > dim_grid - 1 || theGrid [x][y] == sunk || theGrid [x][y] == hit || theGrid [x][y] == miss){
            cout << "\t\t\t\t ERRORE, INSERIRE DELLE COORDINATE VALIDE: " << endl;
            cout << "\t\t\t\t Riga: ";
            cin >> x;
            cin.ignore();
            cout << "\t\t\t\t Colonna: ";
            cin >> y;
            cin.ignore();
        }


    //Controlli sui tre scenari


        if (theGrid[x][y] == water){
            
            system("clear");
            
            printInfo();
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
            board.printPlayerGrid();
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t LA FLOTTA DEL NEMICO:" << endl;
            printOpponentGrid();
            cout << "\n\n\n";

            theGrid[x][y] = miss;
            cout << "\t\t\t\t MANCATO!";
            cin.ignore();

            return false;

        }else{
            
            system("clear");
            
            printInfo();
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t LA TUA FLOTTA:" << endl;   //cambiare con il nome delle forze/razza/etnia
            board.printPlayerGrid();
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t LA FLOTTA DEL NEMICO:" << endl;
            printOpponentGrid();
            cout << "\n\n\n";

            switch(theGrid[x][y]){
            case 'A':
                shipVec[0]->setHit();
                theGrid [x][y] = hit;
                    cout << "\t\t\t\t COLPITO! " << endl;



                if(shipVec[0]->isSunk()){
                    cout << "\t\t\t\t Ottime notizie comandante! Il " << shipVec[0]->getName() << " nemico è stato distrutto." << endl;
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
                    cout << "\t\t\t\t COLPITO! " << endl;



                    if(shipVec[1]->isSunk()){
                        cout << "\t\t\t\t Si! Lo " << shipVec[1]->getName() << " è andato in frantumi sotto i nostri colpi." << endl;
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
                    cout << "\t\t\t\t COLPITO! " << endl;

                    if(shipVec[2]->isSunk()){
                        cout << "\t\t\t\t Tutto procede per il meglio, abbiamo affondato il loro " << shipVec[2]->getName() << "." << endl;
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
                    cout << "\t\t\t\t COLPITO! " << endl;

                    if(shipVec[3]->isSunk()){
                        cout << "\t\t\t\t Il " << shipVec[3]->getName() << " è stato abbattuto comandante, bel colpo!" << endl;
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
                    
        }
        
        if(hittable())
            cout << "\t\t\t\t Hai un altro colpo a disposizione";
        else
            cout << "\t\t\t\t Hai interamente distrutto la flotta avversaria!";
        
        cin.ignore();
        
        

        return true;
            
        
    }else{  //se il giocatore è CPU
        
        

        // Vorrei che tutte le scritte si cancellassero. Va bene usare system("clear")?
        
        int plus_minus [] = {-1, 1};
        int g;
        int vec_around [4] = {0}; //controlla i sunk e i miss intorno all'hit
        int vec_hit [4] = {0};    //controlla gli hit intorno all'hit
        int vec_side [4] = {0}; //controlla dove sono i lati della board intorno all'hit

        
            
        int i = 0;  //x di hit
        int j = 0;  //y di hit
        
        for(i = 0; i < dim_grid; i++){   //andiamo a cercare il primo hit in un una ricerca riga per riga
            for(j = 0; j < dim_grid; j++){
                if(theGrid[i][j] == hit)
                    goto here;
                else if(i == dim_grid - 1 && j == dim_grid - 1)
                    goto here;
            }
        }
        
        here:
        
        
        if(i == dim_grid - 1 && j == dim_grid - 1 && theGrid[i][j] != hit){

            srand((unsigned int) time(NULL));

            x = rand() % 10;
            y = rand() % 10;
            
            while(theGrid[x][y] == miss || theGrid[x][y] == hit || theGrid[x][y] == sunk){
                srand((unsigned int) time(NULL));
                
                x = rand() % 10;
                y = rand() % 10;
            }
            goto end;
        }
        
        
        
        
        //riempiamo side
        
        /*
            [0]
            [2]   [3]
            [1]
            
            */
        
        if(i == 0)
            vec_side [0] = 1;
        
        if(j == 0)
            vec_side [2] = 1;
        
        if(i == dim_grid - 1)
            vec_side [1] = 1;
        
        if(j == dim_grid - 1)
            vec_side [3] = 1;
        
        
        
        if(vec_side [0] == 1 && vec_side [2] == 1){   //bordo in (0, 0)
            if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                vec_around [1] = 1;
            
            if(theGrid[i + 1][j] == hit)
                vec_hit [1] = 1;
            
            if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                vec_around [3] = 1;
            
            if(theGrid[i][j + 1] == hit)
                vec_hit [3] = 1;
                
        }else if(vec_side [0] == 1 && vec_side [3] == 1){  //bordo in (0, 9)
            if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                vec_around [1] = 1;
            
            if(theGrid[i + 1][j] == hit)
                vec_hit [1] = 1;
            
            if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                vec_around [2] = 1;
            
            if(theGrid[i][j - 1] == hit)
                vec_hit [2] = 1;
            
        }else if(vec_side [1] == 1 && vec_side [2] == 1){  //bordo in (9, 0)
            
            if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
                vec_around [0] = 1;
            
            if(theGrid[i - 1][j] == hit)
                vec_hit [0] = 1;
            
            if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                vec_around [3] = 1;
            
            if(theGrid[i][j + 1] == hit)
                vec_hit [3] = 1;
            
        }else if(vec_side [1] == 1 && vec_side [3] == 1){   //bordo in (9, 9)
            
            if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
                vec_around [0] = 1;
            
            if(theGrid[i - 1][j] == hit)
                vec_hit [0] = 1;
            
            if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                vec_around [2] = 1;
            
            if(theGrid[i][j - 1] == hit)
                vec_hit [2] = 1;
            
        }else if(vec_side [0] == 1 && j != 0 && j != dim_grid - 1){    //lato alto
            
            
            if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                vec_around [1] = 1;
            
            if(theGrid[i + 1][j] == hit)
                vec_hit [1] = 1;
            
            if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                vec_around [3] = 1;
            
            if(theGrid[i][j + 1] == hit)
                vec_hit [3] = 1;
            
            if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                vec_around [2] = 1;
            
            if(theGrid[i][j - 1] == hit)
                vec_hit [2] = 1;
            
        }else if(vec_side [1] == 1 && j != 0 && j != dim_grid - 1){    //lato basso
            
            
            if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
                vec_around [0] = 1;
            
            if(theGrid[i - 1][j] == hit)
                vec_hit [0] = 1;
            
            if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                vec_around [3] = 1;
            
            if(theGrid[i][j + 1] == hit)
                vec_hit [3] = 1;
            
            if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                vec_around [2] = 1;
            
            if(theGrid[i][j - 1] == hit)
                vec_hit [2] = 1;
            
        }else if(vec_side [2] == 1 && i != 0 && i != dim_grid - 1){    //lato sinistro
            
            
            if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                vec_around [1] = 1;
            
            if(theGrid[i + 1][j] == hit)
                vec_hit [1] = 1;
        
            if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
                vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
            }else if(vec_side [3] == 1 && i != 0 && i != dim_grid - 1){    //lato destro
                
                
                if(theGrid[i + 1][j] == sunk || theGrid[i + 1][j] == miss)
                    vec_around [1] = 1;
                
                if(theGrid[i + 1][j] == hit)
                    vec_hit [1] = 1;
            
                if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
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
                
            
                if(theGrid[i - 1][j] == sunk || theGrid[i - 1][j] == miss)
                    vec_around [0] = 1;
                
                if(theGrid[i - 1][j] == hit)
                    vec_hit [0] = 1;
                
                if(theGrid[i][j + 1] == sunk || theGrid[i][j + 1] == miss)
                    vec_around [3] = 1;
                
                if(theGrid[i][j + 1] == hit)
                    vec_hit [3] = 1;
                
                if(theGrid[i][j - 1] == sunk || theGrid[i][j - 1] == miss)
                    vec_around [2] = 1;
                
                if(theGrid[i][j - 1] == hit)
                    vec_hit [2] = 1;
                
            }
            
            
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
                    
                    /*caso 1A
                     
                       |0|1|
                      0|/|?|
                      1|?|.|
                     
                     */
                    
                    if(vec_side [0] == 1 && vec_side [2] == 1){
                        
                        srand((unsigned int) time(NULL));
                        
                        *orientation = rand() % 2 + 1;
                        
                        if(*orientation == 1){   //orizzontale
                            x = 0;
                            y = 1;
                        }else{    //verticale
                            x = 1;
                            y = 0;
                        }
                    }
                        
                        
                        
                    /*caso 1B
                     
                        |8|9|
                        |?|/|0
                        |.|?|1
                     
                    */
                        
                    if(vec_side [0] == 1 && vec_side [3] == 1){
                            
                        srand((unsigned int) time(NULL));
                            
                        *orientation = rand() % 2 + 1;
                            
                        if(*orientation == 1){   //orizzontale
                            y = dim_grid - 2;
                            x = 0;
                        }else{    //verticale
                            x = 1;
                            y = dim_grid - 1;
                        }
                    }
                    
                    /*caso 1C
                      
                     8|?|.|
                     9|/|?|
                      |0|1|2|...
                     
                     */
                    
                    if(vec_side [1] == 1 && vec_side [2] == 1){
                            
                        srand((unsigned int) time(NULL));
                            
                        *orientation = rand() % 2 + 1;
                            
                        if(*orientation == 1){   //orizzontale
                            y = 1;
                            x = dim_grid - 1;
                        }else{    //verticale
                            x = dim_grid - 2;
                            y = 0;
                        }
                    }
                    
                    /*caso 1D
                      
                     |.|?|8
                     |?|/|9
                     |8|9|
                     
                     */
                    
                    if(vec_side [1] == 1 && vec_side [3] == 1){
                            
                        srand((unsigned int) time(NULL));
                            
                        *orientation = rand() % 2 + 1;
                            
                        if(*orientation == 1){   //orizzontale
                            y = dim_grid - 2;
                            x = dim_grid - 1;
                        }else{    //verticale
                            y = dim_grid - 1;
                            x = dim_grid - 2;
                        }
                    }
                        
                        
                    
                }else if(sum_hit == 1){
                    
                    
                    /*caso 2A
                     
                        0|1|2|...
                      0|/|/|
                      1|?|.|
                     
                     */
                    
                    if(vec_side [0] == 1 && vec_side [2] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j + k;
                                x = 0;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 2){  //orientazione verticale
                            x = 1;
                            y = 0;
                        }
                    }
                        
                    /*caso 2B
                     
                        0|1|2|...
                      0|/|?|
                      1|/|.|
                     
                     */
                        
                    if(vec_side [0] == 1 && vec_side [2] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                        
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //se trova qualcosa da colpire colpisce
                                x = i + k;
                                y = 0;
                                goto end;
                            }
                            
                            *orientation = 1;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 1){  //orientazione orizzontale
                            y = 1;
                            x = 0;
                        }
                    }
                    
                    /*caso 2C
                     
                        |8|9|
                        |/|/|0
                        |.|?|1
                     
                    */
                    
                    if(vec_side [0] == 1 && vec_side [3] == 1 && vec_hit [2] == 1){
                            
                        k = 0;
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j - k] == hit && j - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j - k] != miss && theGrid[i][j - k] != sunk && theGrid[i][j - k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j - k;
                                x = 0;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 2){  //orientazione verticale
                            x = 1;
                            y = dim_grid - 1;
                        }
                        
                    }
                    
                    /*caso 2D
                     
                        |8|9|
                        |?|/|0
                        |.|/|1
                     
                    */
                    
                    if(vec_side [0] == 1 && vec_side [3] == 1 && vec_hit [1] == 1){
                            
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                        
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //se trova qualcosa da colpire colpisce
                                x = k;
                                y = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 1;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 1){  //orientazione orizzontale
                            y = dim_grid - 2;
                            x = 0;
                        }
                        
                    }
                    
                    
                    /*caso 2E
                      
                     8|?|.|
                     9|/|/|
                      |0|1|2|...
                     
                     */
                    
                    if(vec_side [1] == 1 && vec_side [2] == 1 && vec_hit [3] == 1){
                            
                        k = 0;
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j + k] == hit && j + k > dim_grid - 1){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j + k;
                                x = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 2){  //orientazione verticale
                            x = dim_grid - 2;
                            y = 0;
                        }
                        
                    }
                    
                    /*caso 2F
                      
                     8|/|.|
                     9|/|?|
                      |0|1|2|...
                     
                     */
                    
                    if(vec_side [1] == 1 && vec_side [2] == 1 && vec_hit [0] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                        
                            while(theGrid[i - k][j] == hit && i - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i - k][j] != miss && theGrid[i - k][j] != sunk && theGrid[i - k][j] != hit){ //se trova qualcosa da colpire colpisce
                                x = i - k;
                                y = 0;
                                goto end;
                            }
                            
                            *orientation = 1;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 1){  //orientazione orizzontale
                            x = dim_grid - 1;
                            y = 1;
                        }
                    }
                    
                    
                    /*caso 2G
                      
                      |.|?|8
                      |/|/|9
                      |8|9|
                     
                     */
                    
                    
                    if(vec_side [3] == 1 && vec_side [1] == 1 && vec_hit [2] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j - k] == hit && j - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j - k] != miss && theGrid[i][j - k] != sunk && theGrid[i][j - k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j - k;
                                x = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 2){  //orientazione verticale
                            x = dim_grid - 2;
                            y = dim_grid - 1;
                        }
                        
                    }
                    
                    /*caso 2H
                      
                      |.|/|8
                      |?|/|9
                      |8|9|
                     
                     */
                    
                    if(vec_side [3] == 1 && vec_side [1] == 1 && vec_hit [0] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                        
                            while(theGrid[i - k][j] == hit && i - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i - k][j] != miss && theGrid[i - k][j] != sunk && theGrid[i - k][j] != hit){ //se trova qualcosa da colpire colpisce
                                x = i - k;
                                y = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 1;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 1){  //orientazione orizzontale
                            x = dim_grid - 1;
                            y = dim_grid - 2;
                        }
                    }
                
                }else if(sum_hit == 2){
                        
                    /*caso 3A
                     
                       |0|1|2|...
                      0|/|/|
                      1|/|.|
                     
                     */
                    
                    if(vec_side [0] == 1 && vec_side [2] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            
                        
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j + k;
                                x = 0;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)   //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            
                        
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //se trova qualcosa da colpire colpisce
                                y = 0;
                                x = i + k;
                                goto end;
                            }
                        }
                    }
                    
                    
                    /*caso 3B
                     
                       |8|9|
                       |/|/|0
                       |.|/|1
                     
                     */
                    
                    
                    if(vec_side [0] == 1 && vec_side [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j - k] == hit && j - k > 0)    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            
                        
                            if(theGrid[i][j - k] != miss && theGrid[i][j - k] != sunk && theGrid[i][j - k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j - k;
                                x = 0;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)   //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            
                        
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //se trova qualcosa da colpire colpisce
                                y = dim_grid  - 1;
                                x = i + k;
                                goto end;
                            }
                        }
                    }
                    
                    
                    /*caso 3C
                     
                      8|/|.|
                      9|/|/|
                       |0|1|
                     
                     */
                    
                    if(vec_side [2] == 1 && vec_side [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j + k;
                                x = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){  //orientazione verticale
                            
                            while(theGrid[i - k][j] == hit && i - k > 0)    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            
                        
                            if(theGrid[i - k][j] != miss && theGrid[i - k][j] != sunk && theGrid[i - k][j] != hit){ //se trova qualcosa da colpire colpisce
                                y = 0;
                                x = i - k;
                                goto end;
                            }
                        }
                    }
                    
                    
                    /*caso 3D
                     
                       |.|/|8
                       |/|/|9
                       |8|9|
                     
                     */
                    
                    if(vec_side [1] == 1 && vec_side [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){  //orientazione orizzontale
                        
                            while(theGrid[i][j - k] == hit && j - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i][j - k] != miss && theGrid[i][j - k] != sunk && theGrid[i][j - k] != hit){ //se trova qualcosa da colpire colpisce
                                y = j - k;
                                x = dim_grid - 1;
                                goto end;
                            }
                            
                            *orientation = 2;   //se non ha toccayo il goto allora vuol dire che è andato finito in fondo e ha trovato o miss/sunk oppure il fondo della board, allora cambia orientazione e prosegue
                            
                        }
                        
                        if(*orientation == 2){  //orientazione verticale
                            
                            while(theGrid[i - k][j] == hit && i - k > 0){    //va avanti  finchè trova qualcosa di diverso da hit o finisce la board
                                k++;
                            }
                        
                            if(theGrid[i - k][j] != miss && theGrid[i - k][j] != sunk && theGrid[i - k][j] != hit){ //se trova qualcosa da colpire colpisce
                                y = dim_grid - 1;
                                x = i - k;
                                goto end;
                            }
                        }
                    }
                }   //chiuse parentesi sum_hit == 2
            
        }else if(sum_around == 1){
            
            
            if(sum_hit == 0){

                /*caso 4A

                   |0|1|2|...
                  0|/|?|
                  1|*|.|

                 */

                if(vec_side [0] == 1 && vec_side [2] == 1 && vec_around [1] == 1){ //hit è (0,0)
                    *orientation = 1; //orizzontale
                    x = 0;
                    y = 1;
                    goto end;

                }

                /*caso 4B

                   |0|1|2|...
                  0|/|*|
                  1|?|.|

                 */

                if(vec_side [0] == 1 && vec_side [2] == 1 && vec_around [3] == 1){

                    *orientation = 2; //verticale
                    x = 1;
                    y = 0;
                    goto end;

                }

                /*caso 4C

                     
                    8|*|.|
                    9|/|?|
                     |0|1|

                 */

                if(vec_side [1] == 1 && vec_side [2] == 1 && vec_around [0] == 1){

                    *orientation = 1; //orizzontale
                    x = dim_grid - 1;
                    y = 1;
                    goto end;

                }

                /*caso 4D

                    8|?|.|
                    9|/|*|
                     |0|1|

                 */

                if(vec_side [1] == 1 && vec_side [2] == 1 && vec_around [3] == 1){

                    *orientation = 2; //verticale
                    x = dim_grid - 2;
                    y = 0;
                    goto end;

                }

                /*caso 4E

                     |8|9|
                     |?|/|0
                     |.|*|1

                 */

                if(vec_side [0] == 1 && vec_side [3] == 1 && vec_around [1] == 1){

                    *orientation = 1; //orizzontale
                    x = 0;
                    y = dim_grid - 2;
                    goto end;

                }

                /*caso 4F

                     |8|9|
                     |*|/|0
                     |.|?|1

                 */

                if(vec_side [0] == 1 && vec_side [3] == 1 && vec_around [2] == 1){

                    *orientation = 2; //verticale
                    x = 1;
                    y = dim_grid - 1;
                    goto end;

                }

                /*caso 4G

                     |.|*|8
                     |?|/|9
                     |8|9|

                 */

                if(vec_side [1] == 1 && vec_side [3] == 1 && vec_around [0] == 1){

                    *orientation = 1; //orizzontale
                    x = dim_grid - 1;
                    y = dim_grid - 2;
                    goto end;

                }

                /*caso 4H

                     |.|?|8
                     |*|/|9
                     |8|9|

                 */

                if(vec_side [1] == 1 && vec_side [3] == 1 && vec_around [2] == 1){

                    *orientation = 2; //verticale
                    x = dim_grid - 2;
                    y = dim_grid - 1;
                    goto end;

                }

        }else if(sum_hit == 1){

                /*caso 5A

                   |0|1|2|...
                  0|/|/|
                  1|*|.|

                 */

                if(vec_side [0] == 1 && vec_side [2] == 1 && vec_hit [3] == 1 && vec_around [1] == 1){ //hit è (0,0)

                    k = 0;

                    while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                        k++;
                    }

                    x = 0;
                    y = j + k;
                    goto end;

                }

                /*caso 5B

                   |0|1|2|...
                  0|/|*|
                  1|/|.|

                 */

                if(vec_side [0] == 1 && vec_side [2] == 1 && vec_hit [1] == 1 && vec_around [3] == 1){

                    k = 0;

                    while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                        k++;
                    }

                    x = i + k;
                    y = 0;
                    goto end;

                }

                /*caso 5C

                    8|*|.|
                    9|/|/|
                     |0|1|

                 */

                if(vec_side [1] == 1 && vec_side [2] == 1 && vec_hit [3] == 1 && vec_around [0] == 1){

                    k = 0;

                    while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                        k++;
                    }

                    x = dim_grid - 1;
                    y = j + k;
                    goto end;

                }

                /*caso 5D

                    8|/|.|
                    9|/|*|
                     |0|1|

                 */

                if(vec_side [1] == 1 && vec_side [2] == 1 && vec_hit [0] == 1 && vec_around [3] == 1){

                    k = 0;

                    while(theGrid[i - k][j] == hit && i - k > 0){
                        k++;
                    }

                    x = i - k;
                    y = 0;
                    goto end;

                }

                /*caso 5E

                     |8|9|
                     |/|/|0
                     |.|*|1

                 */

                if(vec_side [0] == 1 && vec_side [3] == 1 && vec_hit [2] == 1 && vec_around [1] == 1){

                    k = 0;

                    while(theGrid[i][j - k] == hit && j - k > 0){
                        k++;
                    }

                    x = 0;
                    y = j - k;
                    goto end;

                }

                /*caso 5F

                     |8|9|
                     |*|/|0
                     |.|/|1

                 */

                if(vec_side [0] == 1 && vec_side [3] == 1 && vec_hit [1] == 1 && vec_around [2] == 1){

                    k = 0;

                    while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                        k++;
                    }

                    x = i + k;
                    y = dim_grid - 1;
                    goto end;

                }

                /*caso 5G

                     |.|*|8
                     |/|/|9
                     |8|9|

                 */

                if(vec_side [1] == 1 && vec_side [3] == 1 && vec_hit [2] == 1 && vec_around [0] == 1){

                    k = 0;

                    while(theGrid[i][j - k] == hit && j - k > 0){
                        k++;

                    x = dim_grid - 1;
                    y = j - k;
                    goto end;

                    }
                }

                /*caso 5H

                     |.|/|8
                     |*|/|9
                     |8|9|

                 */

                if(vec_side [1] == 1 && vec_side [3] == 1 && vec_hit [0] == 1 && vec_around [2] == 1){

                    k = 0;

                    while(theGrid[i - k][j] == hit && i - k > 0){
                        k++;
                    }

                    x = i - k;
                    y = dim_grid - 1;
                    goto end;

                }
            }
        }
        
        }else if(sum_side == 1){ //Inizio casistica bordi della griglia - NO SPIGOLI

                if(sum_around == 0){
                    if(sum_hit == 0){

                /*caso N

                      0|1|2|...
                  N-1|?|.|
                  N  |/|?|
                  N+1|?|.|

                 */
                    if(vec_side [2] == 1){ // bordo sinistro

                        srand((unsigned int) time(NULL));

                        *orientation = rand() % 2 + 1;

                        if(*orientation == 1){ //orizzontale
                            x = i;
                            y = 1;

                        }else{ //orientazione verticale

                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = i + plus_minus[g]; //randomizzo un +/- 1
                            y = 0;

                        }

                    }

                    /*caso N

                    8| . |?| . |
                    9| ? |/| ? |
                      N-1|N|N+1

                 */
                    if(vec_side [1] == 1){ //bordo basso

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;
                        if(*orientation == 1){ //orizzontale

                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = dim_grid - 1;
                            y = j + plus_minus[g]; //randomizzo un +/- 1 per settare il verso
                            
                        }else{

                            x = i - 1;
                            y = j;

                        }

                    }

                    /*caso N

                     8|9|
                    |.|?|N-1
                    |?|/|N
                    |.|?|N+1

                    */
                    if(vec_side [3] == 1){ //bordo destro

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;
                        if(*orientation == 2){ //verticale

                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = i + plus_minus[g]; //randomizzo un +/- 1 per settare il verso
                            y = dim_grid -1;

                        }else{ //orizzontale

                            x = i;
                            y = dim_grid - 2;

                        }

                    }

                    /*caso N

                      N-1|N|N+1
                    0| ? |/| ? |
                    1| . |?| . |


                    */
                    if(vec_side [0] == 1){ //bordo alto

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;
                        if(*orientation == 1){ //orizzontale

                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = 0 ;
                            y = j + plus_minus[g]; //randomizzo un +/- 1 per settare il verso

                        }else{ //verticale

                            x = 1;
                            y = j;

                        }

                    }
                }else if(sum_hit == 1){ //chiusura di around = 0 e hit = 0 e apertura di around = 0 e hit = 1

                    /*caso NA

                      0|1|2|...
                  N-1|?|.|
                  N  |/|/|
                  N+1|?|.|

                 */
                    if(vec_side [2] == 1 && vec_hit [3] == 1){ // bordo sinistro
                        if (*orientation == 1){

                            k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                                k++;
                            }

                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                                x = i; // setta le coordinate del nuovo sparo
                                y = j + k;

                                goto end;
                            }else{
                                *orientation = 2; // se sono presenti miss o sunk significa che le navi sono in verticale, quindi torna indietro e metti verticale
                                srand((unsigned int) time(NULL));
                                g = rand () % 2;

                                x = i + plus_minus[g]; //randomizzo un +/- 1 per settare il verso
                                y = 0;
                            }
                        }else{

                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = i + plus_minus[g]; //randomizzo un +/- 1 per settare il verso
                            y = 0;
                        }
                    }

                    /*caso NB

                      0|1|2|...
                  N-1|?|.|
                  N  |/|?|
                  N+1|/|.|

                 */
                    if(vec_side [2] == 1 && vec_hit [1] == 1){
                        // L'orientazione è già verticale

                            k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                                k++;
                            }

                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                                x = i + k; // setta le coordinate del nuovo sparo
                                y = 0;

                                goto end;
                            }else{

                                x = i - 1; //spara sopra
                                y = 0;
                            }
                    }

                    /*caso N

                    8| . |?| . |
                    9| ? |/| / |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_hit [3] == 1){ //bordo in basso. L'orientazione è già settata ed è orizzontale

                    k = 0;

                    while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                        k++;
                    }

                    if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                        x = dim_grid - 1; // setta le coordinate del nuovo sparo
                        y = j + k;

                        goto end;
                    }else{

                        x = dim_grid - 1;
                        y = j - 1; //spara a sinistra
                    }
                 }

                  /*caso N

                     8|9|
                    |.|?|N-1
                    |?|/|N
                    |.|/|N+1

                    */
                    if(vec_side [3] == 1 && vec_hit [1] == 1){ //bordo destro. L'orientazione è verticale

                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                            k++;
                        }

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                            x = i + k; // setta le coordinate del nuovo sparo
                            y = j;

                            goto end;
                        }else{

                            x = i - 1; //spara sopra
                            y = dim_grid;
                        }
                    }

                    /*caso NA

                      N-1|N|N+1
                    0| ? |/| / |
                    1| . |?| . |


                    */

                    if(vec_side [0] == 1 && vec_hit [3] == 1){ // bordo alto. L'orientazione è orizzontale

                        k = 0;

                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                            k++;
                        }

                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                            x = 0; // setta le coordinate del nuovo sparo
                            y = j + k;

                            goto end;
                        }else{
                            x = 0;
                            y = j - 1;
                        }

                    }

                    /*caso NB

                      N-1|N|N+1
                    0| ? |/| ? |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_hit [1] == 1){ // bordo alto. L'orientazione è verticale
                        if(*orientation == 2){
                            k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                                k++;
                            }

                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){ //controlla che nel posto in cui si vuole sparare non ci siano miss e sunk
                                x = i + k; // setta le coordinate del nuovo sparo
                                y = j;

                                goto end;
                            }else{
                                *orientation = 1; //cambia orientazione  e torna indietro a sparare in orizzontale

                                srand((unsigned int) time(NULL));
                                g = rand () % 2;

                                x = 0 ;
                                y = j + plus_minus[g];
                            }
                        }else{
                            srand((unsigned int) time(NULL));
                            g = rand () % 2;

                            x = 0 ;
                            y = j + plus_minus[g];
                        }

                    }

                }else if(sum_hit == 2){//chiusura di around = 0 e hit = 1 e apertura di around = 0 e hit = 2

                    /*caso N

                      0|1|2|...
                  N-1|?|.|
                  N  |/|/|
                  N+1|/|.|

                 */
                    
                   
                    
                    if(vec_side [2] == 1 && vec_hit [3] == 1 && vec_hit [1] == 1){ //bordo sinistro
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){ //orizzontale
                            while(theGrid[i][j + k] == hit && j + k < dim_grid){
                                k++;
                            }
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = i;
                                y = j + k;

                                goto end;
                            }
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){ //verticale
                            while(theGrid[i + k][j] == hit && i + k < dim_grid){
                                k++;
                            }
                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = 0;

                            goto end;

                        }
                    }
                    x = i - 1;
                    y = 0;
                }

                /*caso N

                      N-1|N|N+1
                    0| ? |/| / |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_hit [1] == 1 && vec_hit [3] == 1){ //bordo alto
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacato
                        
                        if(*orientation == 1){ //orizzontale
                            while(theGrid[i][j + k] == hit && j + k < dim_grid){
                                k++;
                            }
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = 0;
                                y = j + k;

                                goto end;
                            }
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){ //verticale
                            while(theGrid[i + k][j] == hit && i + k < dim_grid){
                                k++;
                            }
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;

                                goto end;

                            }
                        }
                        
                        x = i;
                        y = j - 1;
                    }
                }
            }// chiusura if di around = 0

            if(sum_around == 1){
                if(sum_hit == 0){

                    /*caso NA

                      0|1|2|...
                  N-1|*|.|
                  N  |/|?|
                  N+1|?|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1){ // bordo sinistro

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;

                    if(*orientation == 1){ //orizzontale
                        x = i;
                        y = 1;

                    }else{ //orientazione verticale

                        x = i + 1; //non posso salire!
                        y = 0;

                    }
                 }

                 /*caso NB

                      0|1|2|...
                  N-1|?|.|
                  N  |/|*|
                  N+1|?|.|

                 */

                 if(vec_side [2] == 1 && vec_around [3] == 1){ // bordo sinistro

                    *orientation = 2; //verticale

                    srand((unsigned int) time(NULL));
                    g = rand () % 2;

                    x = i + plus_minus[g];
                    y = 0;
                 }

                 /*caso NC

                      0|1|2|...
                  N-1|?|.|
                  N  |/|?|
                  N+1|*|.|

                 */

                 if(vec_side [2] == 1 && vec_around [1] == 1){ // bordo sinistro

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;

                    if(*orientation == 1){ //orizzontale
                        x = i;
                        y = 1;

                    }else{ //orientazione verticale

                        x = i - 1; //non posso scendere!
                        y = 0;

                    }
                 }

                 /*caso NA

                    8| . |?| . |
                    9| * |/| ? |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [2] == 1){ //bordo basso
                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;

                    if(*orientation == 1){ //orizzontale
                        x = dim_grid - 1;
                        y = j + 1; //non posso andare a sinistra!

                    }else{ //orientazione verticale

                        x = i - 1; //non posso scendere!
                        y = j;

                    }
                 }

                 /*caso NB

                    8| . |*| . |
                    9| ? |/| ? |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [0] == 1){ //bordo basso

                    *orientation = 1; // orizzontale
                    srand((unsigned int) time(NULL));
                    g = rand() % 2;

                    x = dim_grid - 1; //non posso salire!
                    y = j + plus_minus[g];

                 }

                 /*caso NC

                    8| . |?| . |
                    9| ? |/| * |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [3] == 1){ //bordo basso

                    srand((unsigned int) time(NULL));

                    *orientation = rand() % 2 + 1;

                    if(*orientation == 1){ //orizzontale
                        x = dim_grid - 1;
                        y = j - 1; //non posso andare a destra!

                    }else{ //orientazione verticale

                        x = i - 1; //non posso scendere!
                        y = j;

                    }

                 }

                 /*caso NA

                     8|9|
                    |.|*|N-1
                    |?|/|N
                    |.|?|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [0] == 1){ //bordo destro.
                        srand((unsigned int) time(NULL));

                        *orientation = rand() % 2 + 1;

                        if(*orientation == 1){ //orizzontale
                            x = i;
                            y = dim_grid - 2; //non posso andare a destra!

                        }else{ //orientazione verticale

                            x = i + 1; //non posso salire!
                            y = dim_grid - 1;

                        }
                    }

                    /*caso NB

                     8|9|
                    |.|?|N-1
                    |*|/|N
                    |.|?|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [2] == 1){ //bordo destro.

                        *orientation = 2; //verticale
                        srand((unsigned int) time(NULL));
                        g = rand() % 2;

                        x = i + plus_minus[g];
                        y = dim_grid - 1;
                    }

                    /*caso NC

                     8|9|
                    |.|?|N-1
                    |?|/|N
                    |.|*|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [1] == 1){ //bordo destro.

                        srand((unsigned int) time(NULL));

                        *orientation = rand() % 2 + 1;

                        if(*orientation == 1){ //orizzontale
                            x = i;
                            y = dim_grid - 2; //non posso andare a destra!

                        }else{ //orientazione verticale

                            x = i - 1; //non posso scendere!
                            y = dim_grid - 1;

                        }
                    }

                    /*caso NA

                      N-1|N|N+1
                    0| * |/| ? |
                    1| . |?| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1){ //bordo alto

                        srand((unsigned int) time(NULL));

                        *orientation = rand() % 2 + 1;

                        if(*orientation == 1){ //orizzontale
                            x = 0;
                            y = j + 1; //non posso andare a sinistra!

                        }else{ //orientazione verticale

                            x = 1; //non posso salire!
                            y = j;

                        }
                    }

                    /*caso NB

                      N-1|N|N+1
                    0| ? |/| ? |
                    1| . |*| . |


                    */

                    if(vec_side [0] == 1 && vec_around [1] == 1){ //bordo alto

                        *orientation = 1; //orizzontale

                        srand((unsigned int) time(NULL));
                        g = rand() % 2;

                        x = 0; //non posso salire!
                        y = j + plus_minus[g];
                    }

                     /*caso NC

                      N-1|N|N+1
                    0| ? |/| * |
                    1| . |?| . |


                    */

                    if(vec_side [0] == 1 && vec_around [3] == 1){ //bordo alto

                        srand((unsigned int) time(NULL));

                        *orientation = rand() % 2 + 1;

                        if(*orientation == 1){ //orizzontale
                            x = 0;
                            y = j - 1; //non posso andare a destra!

                        }else{ //orientazione verticale

                            x = 1; //non posso salire!
                            y = j;

                        }
                    }

                }else if(sum_hit == 1){//chiusura around = 1 e hit = 0 e apertura di a = 1 e h = 1

                    /*caso NA

                      0|1|2|...
                  N-1|*|.|
                  N  |/|?|
                  N+1|/|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_hit [1] == 1){ // bordo sinistro

                    if(*orientation == 2){ //verticale
                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = 0;

                            goto end;
                        }
                    }
                //Se non ha trovato niente deve tornare inditero e cominciare a sparare orizzotalmente
                 *orientation = 1; //orizzontale
                 x = i;
                 y = 1;

                 }

                 /*caso NB

                      0|1|2|...
                  N-1|?|.|
                  N  |/|*|
                  N+1|/|.|

                 */

                 if(vec_side [2] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){ // bordo sinistro. L'orientazione è gia verticale

                    k = 0;

                    while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                        k++;

                    }

                    if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                        x = i + k;
                        y = 0;

                        goto end;
                    }else {

                        x = i - 1;
                        y = 0;

                    }
                 }

                 /*caso NC

                      0|1|2|...
                  N-1|*|.|
                  N  |/|/|
                  N+1|?|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_hit [3] == 1){ // bordo sinistro

                    if(*orientation == 1){ //orizzontale
                        k = 0;

                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;

                            goto end;
                        }
                    }
                    //Se non ha trovato niente deve tornare inditero e cominciare a sparare verticalmente
                    *orientation = 2; //verticale
                    x = i + 1; //non può salire!
                    y = 0;

                 }

                  /*caso ND

                      0|1|2|...
                  N-1|?|.|
                  N  |/|/|
                  N+1|*|.|

                 */

                 if(vec_side [2] == 1 && vec_around [1] == 1 && vec_hit [3] == 1){ // bordo sinistro. L'orientazione è gia orizzontale

                    if(*orientation == 1){
                        k = 0;

                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;

                            goto end;
                        }
                    }
                    //Se non ha trovato nulla deve sparare verso l'alto verticalmente
                    *orientation = 2;
                    x = i - 1;
                    y = 0;
                 }

                 /*caso NA

                    8| . |?| . |
                    9| * |/| / |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [2] == 1 && vec_hit [3] == 1){

                    if(*orientation == 1){
                        k = 0;

                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = dim_grid - 1;
                            y = j + k;

                            goto end;
                        }
                    }
                    //Se non ha trovato nulla deve sparare verso l'alto verticalmente
                    *orientation = 2;
                    x = dim_grid - 2;
                    y = j;
                 }

                 /*caso NB

                    8| . |*| . |
                    9| ? |/| / |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [0] == 1 && vec_hit [3] == 1){ //L'orientazione dovrebbe essere orizzontale

                   k = 0;

                    while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                        k++;

                    }

                    if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                        x = dim_grid - 1;
                        y = j + k;

                        goto end;
                    }else{  //non capisco il senso

                        x = dim_grid - 1;
                        y = j - 1;

                    }
                 }

                /*caso NA

                     8|9|
                    |.|*|N-1
                    |?|/|N
                    |.|/|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [0] == 1 && vec_hit [1] == 1){ //bordo destro.

                        if(*orientation == 2){ //verticale
                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = dim_grid - 1;

                            goto end;
                        }
                    }
                        //Se non ha trovato niente deve tornare inditero e cominciare a sparare orizzotalmente
                        *orientation = 1; //orizzontale
                        x = i;
                        y = dim_grid - 2;
                 }

                 /*caso NB

                     8|9|
                    |.|?|N-1
                    |*|/|N
                    |.|/|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [2] == 1 && vec_hit [1] == 1){ //bordo destro. L'orientazione è verticale

                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = dim_grid - 1;

                            goto end;
                        }else {

                            x = i - k;
                            y = dim_grid - 1;

                        }
                 }

                 /*caso NA

                      N-1|N|N+1
                    0| * |/| ? |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_hit [1] == 1){ //bordo alto

                        if(*orientation == 2){ //verticale
                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                            k++;

                        }

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = j;

                            goto end;
                        }
                    }
                //Se non ha trovato niente deve tornare inditero e cominciare a sparare orizzotalmente
                        *orientation = 1; //orizzontale
                        x = 0;
                        y = j + 1; // non può sparare a sinistra
                    }

                    /*caso NB

                      N-1|N|N+1
                    0| * |/| / |
                    1| . |?| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_hit [3] == 1){ //bordo alto

                        if(*orientation == 1){ //orizzontale
                            k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                                k++;

                            }

                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = 0;
                                y = j + k;

                                goto end;
                            }
                        }
                        //Se non ha trovato niente deve tornare inditero e cominciare a sparare verticalmente
                        *orientation = 2; //verticale
                        x = 1; //non può salire!
                        y = j;
                    }

                    /*caso NC

                      N-1|N|N+1
                    0| ? |/| / |
                    1| . |*| . |


                    */

                    if(vec_side [0] == 1 && vec_around [1] == 1 && vec_hit [3] == 1){ //bordo alto

                        if(*orientation == 1){ //orizzontale
                            k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1){
                                k++;

                            }

                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = 0;
                                y = j + k;

                                goto end;
                            }else{
                                x = 0;
                                y = j - 1;

                                goto end;
                            }
                        }
                    }

                    /*caso ND

                      N-1|N|N+1
                    0| ? |/| * |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){ //bordo alto

                        if(*orientation == 2){ //verticale
                            k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1){
                                k++;

                            }

                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;

                                goto end;
                            }
                        }
                //Se non ha trovato niente deve tornare inditero e cominciare a sparare orizzotalmente
                        *orientation = 1; //orizzontale
                        x = 0;
                        y = j - 1; // non può sparare a destra
                    }

                }else if(sum_hit == 2){//chiusura a = 1 e h = 1 e apertura di a = 1 e h = 2

                    /*caso NA

                      0|1|2|...
                  N-1|*|.|
                  N  |/|/|
                  N+1|/|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_hit [1] == 1 && vec_hit [3] == 1){ // bordo sinistro
                     
                     
                     if(*orientation == 0)
                         *orientation = 2;   //se gliela faccio randomizzare e va a 1 è una cacata

                    if(*orientation == 2){ //verticale
                        k = 0;

                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                            k++;

                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = 0;

                            goto end;
                        }
                    }
                     
                    if(*orientation == 1){
                        k = 0;

                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                            k++;

                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;

                            goto end;
                        }
                    }
                 }

                 /*caso N

                      N-1|N|N+1
                    0| * |/| / |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_hit [1] == 1 && vec_hit [3] == 1){ //bordo alto
                        
                        if(*orientation == 0)
                            *orientation = 2;   //se gliela faccio randomizzare e va a 1 è una cacata

                        if(*orientation == 2){ //verticale
                            k = 0;

                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;


                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;

                                goto end;
                            }
                        }
                        
                        if(*orientation == 1){ //orizzontale
                            k = 0;

                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;

                        

                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = 0;
                                y = j + k; //non può mica sparare a sinistra EEEEEEEHHHHHHHH SCEMEGUERRA!!!!

                                goto end;
                            }
                        }
                    }

                }//chiusura a = 1 e h = 2
            }//chiusura di if around = 1
            if(sum_around == 2){
                if(sum_hit == 0){

                /*caso NA

                      0|1|2|...
                  N-1|*|.|
                  N  |/|?|
                  N+1|*|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_around [1] == 1){ // bordo sinistro

                    *orientation = 1; //orizzontale
                    x = i;
                    y = 1;

                 }

                 /*caso NB

                      0|1|2|...
                  N-1|*|.|
                  N  |/|*|
                  N+1|?|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_around [3] == 1){ // bordo sinistro

                    *orientation = 2; //verticale
                    x = i + 1;
                    y = 0;

                 }

                 /*caso NC

                      0|1|2|...
                  N-1|?|.|
                  N  |/|*|
                  N+1|*|.|

                 */

                 if(vec_side [2] == 1 && vec_around [1] == 1 && vec_around [3] == 1){ // bordo sinistro

                    *orientation = 2; //verticale
                    x = i - 1;
                    y = 0;

                 }

                 /*caso NA

                    8| . |*| . |
                    9| * |/| ? |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [2] == 1 && vec_around [0] == 1){

                    *orientation = 1; //orizzontale
                    x = dim_grid - 1;
                    y = j + 1; //non può andare a sinistra
                 }

                 /*caso NB

                    8| . |?| . |
                    9| * |/| * |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [2] == 1 && vec_around [3] == 1){

                    *orientation = 2; //verticale
                    x = dim_grid - 2;
                    y = j;
                 }

                 /*caso NC

                    8| . |*| . |
                    9| ? |/| * |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [0] == 1 && vec_around [3] == 1){

                    *orientation = 1; //orizzontale
                    x = dim_grid - 1;
                    y = j - 1; //non può andare a destra
                 }

                 /*caso NA

                     8|9|
                    |.|*|N-1
                    |*|/|N
                    |.|?|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [0] == 1 && vec_around [2] == 1){

                        *orientation = 2; //verticale
                        x = i + 1;
                        y = dim_grid - 1;
                    }

                    /*caso NB

                     8|9|
                    |.|?|N-1
                    |*|/|N
                    |.|*|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [1] == 1 && vec_around [2] == 1){

                        *orientation = 2; //verticale
                        x = i - 1;
                        y = dim_grid - 1;
                    }

                    /*caso NC

                     8|9|
                    |.|*|N-1
                    |?|/|N
                    |.|*|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [1] == 1 && vec_around [0] == 1){

                        *orientation = 1; //orizzontale
                        x = i;
                        y = dim_grid - 2;
                    }

                    /*caso NA

                      N-1|N|N+1
                    0| * |/| ? |
                    1| . |*| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_around [1] == 1){

                        *orientation = 1; //orizzontale
                        x = 0;
                        y = j + 1;

                    }

                    /*caso NB

                      N-1|N|N+1
                    0| ? |/| * |
                    1| . |*| . |


                    */

                    if(vec_side [0] == 1 && vec_around [1] == 1 && vec_around [3] == 1){

                        *orientation = 1; //orizzontale
                        x = 0;
                        y = j - 1;

                    }

                    /*caso NC

                      N-1|N|N+1
                    0| * |/| * |
                    1| . |?| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_around [3] == 1){

                        *orientation = 2; //verticale
                        x = 1;
                        y = j;

                    }

                }else if(sum_hit == 1){//chiusura di a = 2 e h = 0 e apertura di a = 2 e h = 1

                    /*caso NA

                      0|1|2|...
                  N-1|*|.|
                  N  |/|/|
                  N+1|*|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_around [1] == 1 && vec_hit [3] == 1){ // bordo sinistro

                    *orientation = 1; //orizzontale

                    k = 0;
                    while(theGrid[i][j + k] == hit && j + k < dim_grid  - 1){
                        k++;
                    }

                    x = i;
                    y = j + k;

                 }

                 /*caso NB

                      0|1|2|...
                  N-1|*|.|
                  N  |/|*|
                  N+1|/|.|

                 */

                 if(vec_side [2] == 1 && vec_around [0] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){ // bordo sinistro

                    *orientation = 2; //verticale

                    k = 0;
                    while(theGrid[i + k][j] == hit && i + k < dim_grid  - 1){
                        k++;
                    }

                    x = i + k;
                    y = 0;

                 }

                 /*caso N

                    8| . |*| . |
                    9| * |/| / |
                      N-1|N|N+1

                 */

                 if(vec_side [1] == 1 && vec_around [2] == 1 && vec_around [0] == 1 && vec_hit [3] == 1){

                    *orientation = 1; //orizzontale

                    k = 0;
                    while(theGrid[i][j + k] == hit && j + k < dim_grid  - 1){
                        k++;
                    }

                    x = dim_grid - 1;
                    y = j + k;
                 }

                 /*caso N

                     8|9|
                    |.|*|N-1
                    |*|/|N
                    |.|/|N+1

                    */
                    if(vec_side [3] == 1 && vec_around [0] == 1 && vec_around [2] == 1 && vec_hit [1] == 1){

                        *orientation = 2; //verticale

                        k = 0;
                        while(theGrid[i + k][j] == hit && i + k < dim_grid  - 1){
                            k++;
                        }

                        x = i + k;
                        y = dim_grid - 1;
                    }

                    /*caso NA

                      N-1|N|N+1
                    0| * |/| / |
                    1| . |*| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_around [1] == 1 && vec_hit [3] == 1){

                        *orientation = 1; //orizzontale

                        k = 0;
                        while(theGrid[i][j + k] == hit && j + k < dim_grid  - 1){
                            k++;
                        }

                        x = 0;
                        y = j + k;

                    }

                    /*caso NA

                      N-1|N|N+1
                    0| * |/| * |
                    1| . |/| . |


                    */

                    if(vec_side [0] == 1 && vec_around [2] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){

                        *orientation = 2; //verticale

                        k = 0;
                        while(theGrid[i + k][j] == hit && i + k < dim_grid  - 1){
                            k++;
                        }

                        x = i + k;
                        y = j;

                    }

                }//chiusura di a = 2 e h = 1

            }//chiusura di if around = 2
            
        }else if(sum_side == 0){
            
            
            if(sum_around == 0){
                
                if(sum_hit == 0){
                    
                    /*caso N

                         | |?| |
                         |?|/|?|
                         | |?| |

                     */
                
                    srand((unsigned int) time(NULL));
                    *orientation = rand() % 2 + 1;
                
                    if(*orientation == 1){  //orientazione orizzontale
                    
                        x = i;
                    
                        srand((unsigned int) time(NULL));
                        g = rand() % 2;
                    
                        y = j + plus_minus[g];
                    
                    }else if(*orientation == 2){    //orientazione orizzontale
                    
                        y = j;
                    
                        srand((unsigned int) time(NULL));
                        g = rand() % 2;
                    
                        x = i + plus_minus[g];
                    
                    }
                    
                }else if(sum_hit == 1){

                    /*caso NA

                         | |?| |
                         |?|/|/|
                         | |?| |

                     */
                    
                    if(vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){  //orizzontale
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                x = i;
                                y = j + k;
                                
                                goto end;
                                
                            }
                            
                        }
                        
                        x = i;
                        y = j - 1;
                    }
                    
                    /*caso NB

                         | |?| |
                         |?|/|?|
                         | |/| |

                     */
                    
                    if(vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //verticale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                            
                            
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                
                                x = i + k;
                                y = j;
                                
                                goto end;
                                
                            }
                        }
                        
                        y = j;
                        x = i - 1;
                    }
                }else if(sum_hit == 2){
                    //ci sono entrato solo sum_around == 0 && sum_hit == 2
                    /*caso N

                         | |?| |
                         |?|/|/|
                         | |/| |

                     */
                    
                    k = 0;
                    
                    if(*orientation == 0)
                        *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacata
                    
                    if(*orientation == 1){  //orizzontale
                        
                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            
                            x = i;
                            y = j + k;
                            
                            goto end;
                            
                        }
                        
                        *orientation = 2;
                    }
                    
                    k = 0;
                        
                    if(*orientation == 2){    //verticale
                        
                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            
                            x = i + k;
                            y = j;
                            
                            goto end;
                            
                        }
                    }
                    
                    x = i;
                    y = j - 1;
                    
                }
                
            }else if(sum_around == 1){  //sum_around == 1
                
                if(sum_hit == 0){   //sum_around == 1
                    
                    /*caso NA

                         | |?| |
                         |?|/|*|
                         | |?| |

                     */
                    
                    if(vec_around [3] == 1){
                        
                        if(*orientation == 0){
                            
                            srand((unsigned int) time(NULL));
                            *orientation = rand() % 2 + 1;
                            
                        }
                        
                        if(*orientation == 1){
                            
                            x = i;
                            y = j - 1;
                            
                        }else if(*orientation == 2){
                            
                            y = j;
                            
                            srand((unsigned int) time(NULL));
                            g = rand() % 2;
                        
                            x = i + plus_minus[g];
                            
                        }
                    }
                    
                    /*caso NB

                         | |?| |
                         |?|/|?|
                         | |*| |

                     */
                    
                    
                    if(vec_around [1] == 1){
                        
                        if(*orientation == 0){
                            
                            srand((unsigned int) time(NULL));
                            *orientation = rand() % 2 + 1;
                            
                        }
                        
                        if(*orientation == 1){
                            
                            x = i;
                            
                            srand((unsigned int) time(NULL));
                            g = rand() % 2;
                        
                            y = j + plus_minus[g];
                            
                        }else if(*orientation == 2){
                            
                            y = j;
                            x = i - 1;
                            
                        }
                    }
                    
                    /*caso NC

                         | |?| |
                         |*|/|?|
                         | |?| |

                     */
                    
                    if(vec_around [2] == 1){
                        
                        if(*orientation == 0){
                            
                            srand((unsigned int) time(NULL));
                            *orientation = rand() % 2 + 1;
                            
                        }
                        
                        if(*orientation == 1){
                            
                            x = i;
                            y = j + 1;
                            
                        }else if(*orientation == 2){
                            
                            y = j;
                            
                            srand((unsigned int) time(NULL));
                            g = rand() % 2;
                        
                            x = i + plus_minus[g];
                            
                        }
                    }
                    
                    /*caso ND

                         | |*| |
                         |?|/|?|
                         | |?| |

                     */
                    
                    if(vec_around [0] == 1){
                        
                        
                            
                        srand((unsigned int) time(NULL));
                        *orientation = rand() % 2 + 1;
                        
                        
                        if(*orientation == 1){
                            
                            x = i;
                            
                            srand((unsigned int) time(NULL));
                            g = rand() % 2;
                        
                            y = j + plus_minus[g];
                            
                        }else if(*orientation == 2){
                            
                            y = j;
                            x = i + 1;
                            
                        }
                    }
                    
                }else if(sum_hit == 1){ //sum_around == 1
                    
                    /*caso NA

                         | |?| |
                         |*|/|/|
                         | |?| |

                     */
                    
                    if(vec_around [2] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                x = i;
                                y = j + k;
                                
                                goto end;
                            }
                            
                            *orientation = 2;
                        }
                        
                        if(*orientation == 2){
                            
                            y = j;
                            
                            srand((unsigned int) time(NULL));
                            g = rand() % 2;
                        
                            x = i + plus_minus[g];
                        }
                    }
                    
                    /*caso NB

                         | |*| |
                         |?|/|/|
                         | |?| |

                     */
                    
                    if(vec_around [0] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                x = i;
                                y = j + k;
                                
                                goto end;
                            }
                            
                            x = i;
                            y = j - 1;
                            
                        }
                    }
                    
                    /*caso NC

                         | |?| |
                         |*|/|?|
                         | |/| |

                     */
                    
                    if(vec_around [2] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                
                                y = j;
                                x = i + k;
                                
                                goto end;
                            }
                            
                            y = j;
                            x = i - 1;
                            
                        }
                    }
                    
                    /*caso ND

                         | |*| |
                         |?|/|?|
                         | |/| |

                     */
                    
                    if(vec_around [0] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                
                                y = j;
                                x = i + k;
                                
                                goto end;
                            }
                            
                            *orientation = 1;
                            
                            if(*orientation == 1){
                                
                                x = i;
                                
                                srand((unsigned int) time(NULL));
                                g = rand() % 2;
                            
                                y = j + plus_minus[g];
                                
                            }
                            
                        }
                    }
                    
                    
                    /*caso NE

                         | |?| |
                         |?|/|*|
                         | |/| |

                     */
                    
                    
                    if(vec_around [3] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                
                                y = j;
                                x = i + k;
                                
                                goto end;
                            }
                            
                            y = j;
                            x = i - 1;
                            
                            
                        }
                    }
                    
                    
                    /*caso NF

                         | |?| |
                         |?|/|/|
                         | |*| |

                     */
                    
                    
                    if(vec_around [1] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                y = j + k;
                                x = i;
                                
                                goto end;
                            }
                            
                            y = j - 1;
                            x = i;
                        }
                    }
                    
                    
                    
                }else if(sum_hit == 2){ //sum_around == 1
                    
                    /*caso NA

                         | |?| |
                         |*|/|/|
                         | |/| |

                     */
                    
                    if(vec_around [2] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacata
                        
                        if(*orientation == 1){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                y = j + k;
                                x = i;
                                
                                goto end;
                            }
                            
                            *orientation = 2;
                        }
                        
                        k = 0;
                        
                        if(*orientation == 2){
                            
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                
                                y = j;
                                x = i + k;
                                
                                goto end;
                            }
                        }
                        y = j;
                        x = i - 1;
                    }
                    
                    /*caso NB

                         | |*| |
                         |?|/|/|
                         | |/| |

                     */
                    
                    if(vec_around [0] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 0)
                            *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacata
                        
                        if(*orientation == 1){  //in teoria in questo caso mi sembra che possa avere soltanto orientazione orizzontale
                            
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                                
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                
                                y = j + k;
                                x = i;
                                
                                goto end;
                            }
                            
                            *orientation = 2;
                            
                            k = 0;
                            
                            if(*orientation == 2){
                                
                                while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                    k++;
                                    
                                if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                    
                                    y = j;
                                    x = i + k;
                                    
                                    goto end;
                                }
                            }
                            
                            y = j - 1;
                            x = i;
                        }
                    }
                    
                    
                    
                }  //chiusura sum_hit == 2
                
            }else if(sum_around == 2){  //sum_around == 2
                
                if(sum_hit == 0){   //sum_around == 2
                    
                    /*caso NA

                         | |*| |
                         |?|/|*|
                         | |?| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [3] == 1){
                        
                        srand((unsigned int) time(NULL));
                        *orientation = rand() % 2 + 1;
                        
                        if(*orientation == 1){
                            x = i;
                            y = j - 1;
                        }else if(*orientation == 2){
                            y = j;
                            x = i + 1;
                        }
                    }
                    
                    /*caso NB

                         | |?| |
                         |?|/|*|
                         | |*| |

                     */
                    
                    if(vec_around [1] == 1 && vec_around [3] == 1){
                        
                        srand((unsigned int) time(NULL));
                        *orientation = rand() % 2 + 1;
                        
                        if(*orientation == 1){
                            x = i;
                            y = j - 1;
                        }else if(*orientation == 2){
                            y = j;
                            x = i - 1;
                        }
                    }
                    
                    /*caso NC

                         | |?| |
                         |*|/|?|
                         | |*| |

                     */
                    
                    if(vec_around [1] == 1 && vec_around [2] == 1){
                        
                        srand((unsigned int) time(NULL));
                        *orientation = rand() % 2 + 1;
                        
                        if(*orientation == 1){
                            x = i;
                            y = j + 1;
                        }else if(*orientation == 2){
                            y = j;
                            x = i - 1;
                        }
                    }
                    
                    /*caso ND

                         | |*| |
                         |*|/|?|
                         | |?| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [2] == 1){
                        
                        srand((unsigned int) time(NULL));
                        *orientation = rand() % 2 + 1;
                        
                        if(*orientation == 1){
                            x = i;
                            y = j + 1;
                        }else if(*orientation == 2){
                            y = j;
                            x = i + 1;
                        }
                    }
                    
                    /*caso NE

                         | |*| |
                         |?|/|?|
                         | |*| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [1] == 1){
                        
                        *orientation = 1;
                        
                        x = i;
                        
                        srand((unsigned int) time(NULL));
                        g = rand() % 2;
                    
                        y = j + plus_minus[g];
                    }
                    
                    /*caso NF

                         | |?| |
                         |*|/|*|
                         | |?| |

                     */
                    
                    if(vec_around [2] == 1 && vec_around [3] == 1){
                        
                        *orientation = 2;
                        
                        y = j;
                        
                        srand((unsigned int) time(NULL));
                        g = rand() % 2;
                    
                        x = i + plus_minus[g];
                    }
                    
                    
                }else if(sum_hit == 1){ //sum_around == 2
                    
                    /*caso NA

                         | |*| |
                         |*|/|/|
                         | |?| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [2] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = i;
                                y = j + k;
                                
                                goto end;
                            }
                        }
                        
                        *orientation = 2;
                        
                        x = i + 1;
                        y = j;
                    }
                    
                    /*caso NB

                         | |*| |
                         |?|/|/|
                         | |*| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [1] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = i;
                                y = j + k;
                                
                                goto end;
                            }
                        }
                        
                        x = i;
                        y = j - 1;
                    }
                    
                    /*caso NC

                         | |*| |
                         |*|/|?|
                         | |/| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [2] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;
                                
                                goto end;
                            }
                        }
                        
                        *orientation = 1;
                        
                        x = i;
                        y = j + 1;
                    }
                    
                    /*caso ND

                         | |*| |
                         |?|/|*|
                         | |/| |

                     */
                    
                    if(vec_around [0] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;
                                
                                goto end;
                            }
                        }
                        
                        *orientation = 1;
                        
                        x = i;
                        y = j - 1;
                    }
                    
                    
                    /*caso NE

                         | |?| |
                         |*|/|/|
                         | |*| |

                     */
                    
                    if(vec_around [1] == 1 && vec_around [2] == 1 && vec_hit [3] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 1){
                            while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                                x = i;
                                y = j + k;
                                
                                goto end;
                            }
                        }
                        
                        *orientation = 2;
                        
                        x = i - 1;
                        y = j;
                    }
                    
                    /*caso NF

                         | |?| |
                         |*|/|*|
                         | |/| |

                     */
                    
                    if(vec_around [2] == 1 && vec_around [3] == 1 && vec_hit [1] == 1){
                        
                        k = 0;
                        
                        if(*orientation == 2){
                            while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                                k++;
                            
                            if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                                x = i + k;
                                y = j;
                                
                                goto end;
                            }
                        }
                        
                        x = i - 1;
                        y = j;
                    }
                    
                    
                }else if(sum_hit == 2){   //chiusura sum_hit == 1, sum_around == 2
                    
                    /*caso N

                         | |*| |
                         |*|/|/|
                         | |/| |

                     */
                    
                    k = 0;
                    
                    if(*orientation == 0)
                        *orientation = 1;   //se gliela faccio randomizzare e va a 2 è una cacata
                    
                    
                    if(*orientation == 1){
                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;
                            
                            goto end;
                        }
                        
                        *orientation = 2;
                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = j;
                            
                            goto end;
                        }
                    }
                    
                    if(*orientation == 2){
                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = j;
                            
                            goto end;
                        }
                        
                        *orientation = 1;
                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;
                            
                            goto end;
                        }
                    }
                }   //chiusura sum_hit == 2
                    
                    
            }else if(sum_around == 3){  //sum_around == 3
                
                if(sum_hit == 0){
                    
                    /*caso NA

                         | |*| |
                         |*|/|?|
                         | |*| |

                     */
                    
                    if(vec_around [3] == 0){
                        
                        *orientation = 1;
                        
                        x = i;
                        y = j + 1;
                    }
                    
                    /*caso NB

                         | |*| |
                         |*|/|*|
                         | |?| |

                     */
                    
                    if(vec_around [1] == 0){
                        
                        *orientation = 2;
                        
                        x = i + 1;
                        y = j;
                    }
                    
                    /*caso NC

                         | |*| |
                         |?|/|*|
                         | |*| |

                     */
                    
                    if(vec_around [2] == 0){
                        
                        *orientation = 1;
                        
                        x = i;
                        y = j - 1;
                    }
                    
                    /*caso ND

                         | |?| |
                         |*|/|*|
                         | |*| |

                     */
                    
                    if(vec_around [0] == 0){
                        
                        *orientation = 2;
                        
                        x = i - 1;
                        y = j;
                    }
                    
                }else if(sum_hit == 1){ //sum_around == 3
                    
                    /*caso NA

                         | |*| |
                         |*|/|/|
                         | |*| |

                     */
                    k = 0;
                    
                    if(vec_hit [3] == 1){
                        
                        while(theGrid[i][j + k] == hit && j + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i][j + k] != miss && theGrid[i][j + k] != sunk && theGrid[i][j + k] != hit){
                            x = i;
                            y = j + k;
                        }
                    }
                    
                    /*caso NB

                         | |*| |
                         |*|/|*|
                         | |/| |

                     */
                    
                    if(vec_hit [1] == 1){
                        
                        while(theGrid[i + k][j] == hit && i + k < dim_grid - 1)
                            k++;
                        
                        if(theGrid[i + k][j] != miss && theGrid[i + k][j] != sunk && theGrid[i + k][j] != hit){
                            x = i + k;
                            y = j;
                        }
                    }
                }   //chiusura sum_hit == 1
            }   //chiusura sum_around == 3
        }   //chiusura parentesi sum_side == 0
    }   //chiusura already_hit
        
    end:

        if(theGrid[x][y] == water){
            theGrid[x][y] = miss;
            
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          
            cout << "\t\t\t\t\t\t\t\t\t \033[1;31m" << opponent << "\033[0m ti ha mancato.";
                
            cin.ignore();
            
            system("clear");
            
            return false;
            
        }else{
            
        
            switch(theGrid[x][y]){
                case 'A':
                    
                    shipVec[0]->setHit();
                    theGrid[x][y] = hit;
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t\t\t\t\t Il tuo " << shipVec[0]->getName() << " è stato colpito." << endl;
                    
                    if(shipVec[0]->isSunk()){    //bisogna aggiungere una caratteristica della nave che è il numero di pezzi colpiti, poi si controlla se i pezzi colpiti == dim_ship, se vero allora è sunk
                        *orientation = 0;
                        theGrid[x][y] = sunk;
                        cout << "\n";
                        cout << "\t\t\t\t\t\t Comandante! Pessime notizie, il nostro " << shipVec[0]->getName() << " è stato distrutto dal nemico.";
                        
                        if(shipVec[0]->ShipOrientation() == true){ //true = orizzontale
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
                    theGrid[x][y] = hit;
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t\t\t\t\t Il tuo " << shipVec[1]->getName() << " è stato colpito." << endl;
                    
                    if(shipVec[1]->isSunk()){
                        *orientation = 0;
                        theGrid[x][y] = sunk;
                        cout << "\n";
                        cout << "\t\t\t\t\t\t\t Oh no! Lo " << shipVec[1]->getName() << " è andato in frantumi sotto i colpi avversari.";
                        
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
                    theGrid[x][y] = hit;
                    
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t\t\t\t\t Il tuo " << shipVec[2]->getName() << " è stato colpito." << endl;
                    
                    if(shipVec[2]->isSunk()){
                        *orientation = 0;
                        theGrid[x][y] = sunk;
                        cout << "\n";
                        cout << "\t\t\t\t\t\t Il nemico è piu' abile di quanto pensassimo, hanno affondato il nostro " << shipVec[2]->getName() << ".";
                        
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
                    theGrid[x][y] = hit;
                    
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t\t\t\t\t Il tuo " << shipVec[3]->getName() << " è stato colpito." << endl;
                    
                    if(shipVec[3]->isSunk()){
                        *orientation = 0;
                        theGrid[x][y] = sunk;
                        cout << "\n";
                        cout << "\t\t\t\t\t\t\t\t     Il " << shipVec[3]->getName() << " è stato abbattuto comandante.";
                        
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
            
            cin.ignore();
            system("clear");
            
            
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            
            if(hittable())
                cout << "\t\t\t\t\t\t\t Il tuo avversario ha ancora un turno a disposizione.";
            else
                cout << "\t\t\t\t\t\t Tutta la flotta è stata distrutta, le scialuppe di salvataggio battono in ritirata.";
            
            printPlayerGrid();
            
            cin.ignore();
            system("clear");
            
            return true;
        }
}


void grid::countTheShots(int& num_hit, int& num_miss){

    int i = 0;  //coordinata x
    int j = 0;  //coordinata y

    //facciamo un controllo sulla board riga per riga

    for(i = 0; i < dim_grid; i++){
        for(j = 0; j < dim_grid; j++){
            if(theGrid[i][j] == hit || theGrid[i][j] == sunk)
                num_hit ++; //incrementa il numero di hit e sunk*/
            if(theGrid[i][j] == miss)
                num_miss ++; //incrementa il numero di miss
        }
    }
    return;
}
