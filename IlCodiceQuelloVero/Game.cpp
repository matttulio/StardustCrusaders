//
//  Game.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 13/07/22.
//http://www.kammerl.de/ascii/AsciiSignature.php
//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal


#include "Game.hpp"
#include "grid.hpp"

game::game(){
    
}

game::game(bool m, bool s, int n, int d, string name1, string name2, bool player1, bool player2){

    mode = m;

    status = s;

    n_ships = n;

    dim_grid = d;

    //whostart = w;

    player1_name = name1;

    player2_name = name2;
    

    player1_mode = true; //variabili in cui salviamo se i giocatori sono umani o cpu

    player2_mode = true;

}


void game::PrintMenu(){ //font da asciisignature è il graffiti, hho anche selezionato "kerning"
    
    system("clear");
    
    char choose;

    cout <<"  \033[1;35m_________  __                      .___               __    _________                                   .___\033[0m\n";
    cout <<" \033[1;35m/   _____/_/  |_ _____  _______   __| _/__ __  _______/  |_  \\_   ___ \\_______  __ __  ___________     __| _/ ____ _______  ______\033[0m\n";
    cout <<" \033[1;35m\\_____  \\ \\   __\\\\__  \\ \\_  __ \\ / __ ||  |  \\/  ___/\\   __\\ /    \\  \\/\\_  __ \\|  |  \\/  ___/\\__  \\   / __ |_/ __ \\\\_  __ \\/  ___/\033[0m\n";
    cout <<" \033[1;35m/        \\ |  |   / __ \\_|  | \\// /_/ ||  |  /\\___ \\  |  |   \\     \\____|  | \\/|  |  /\\___ \\  / __ \\_/ /_/ |\\  ___/ |  | \\/\\___ \\ \033[0m\n";
    cout <<"\033[1;35m/_______  / |__|  (____  /|__|   \\____ ||____//____  > |__|    \\______  /|__|   |____//____  >(____  /\\____ | \\___  >|__|  /____  >\033[0m\n";
    cout <<"        \033[1;35m\\/             \\/             \\/           \\/                 \\/                   \\/      \\/      \\/     \\/            \\/\033[0m\n";

    cout << "\n";
    cout << "                                                                                       \033[1;35mcreated by Barletta Valentina & Gallo Matteo\033[0m" << endl;

    cout << "La sangunaria contesa che da tempo infuria tra gli Atreides e gli Harkonnen dura ormai da lungo tempo. I due popoli";
    cout << "hanno come comune obbiettivo il recupero del rarissimo frammento della stella Bebop, esplosa milioni di anni fa.";
    cout << "Acquisire tale oggetto permetterebbe agli Atreides, specie affetta da nanismo, di aumentare la loro altezza di ";
    cout << "circa 10 milioni di faaD atreideri (ovvero 1,5 cm in unità terrestri). Consentirebbe, invece, agli Harkonen di ";
    cout << "risolvere il gravoso problema che sta portando la loro specie allo sterminio: l'irritante traballare del tavolo ";
    cout << "dell'imperatore che ne causa l'ira furiosa e che si manifesta con pubbliche esecuzioni.";
    cout << "Entrambi gli schieramenti sono giunte allo stremo. Per vincere gli Atreides hanno incaricato di capitanare le loro ";
    cout << "milizie spaziali al comandante della flotta della Valle del Vento, mentre gli Harkonnen si sono affidati al ";
    cout << "capitano dei Boogie Woogie Feng Shui. Le sorti di queste due popolazioni si decideranno oggi nella battaglia ";
    cout << "definitiva di Stardust Crusaders. Chi vincerà? " << endl;

    cout << "Digitare y per giocare oppure n per uscire: ";
    cin >> choose;

        while(choose != 'n' && choose != 'y'){
            cout << "ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA y o n. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
    }

    if(choose == 'n')
        exit(0);    //comando che fa chiudere il programma
    else
        system("clear");    //comando che cancella tutte le scritte sul terminale

}


void game::SetGameMode(){

    int temp;   //variabile temporanea in cui carichiamo le scelte fatte dallo user

    cout << "Selezionare la modalità di gioco:\n";
    cout << "Per giocare contro il computer digitare 1\n";
    cout << "Per giocare contro un'altra persona digitare 2\n";
    cin >> temp;
    cout << endl;


    while(temp != 1 && temp != 2){
        cout << "ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA 1 o 2. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> temp;
        cout << endl;
}

    if(temp == 2){  //convertiamo temp in qualcosa di intellegibile
        mode = true;    //mode = true e' contro un altro giocatore
    }else{
        mode = false;
    }

    status = true;  //così a priori non so se la utilizzeremo ma idealmente è una variabile che contiene lo stato della partita, se =true allora stiamo giocando, se =false allora qualcuno ha vinto e si potrà stampare la schermata finale

    n_ships = 4;    //in un eventuale espansione questi due numeri possono essere messi a scelta, aggiungendo modalita piu lunghe o corte, e anche magari metto tutto customizzabile dal giocatore. Quello che poensavo e che nel caso di un aumento delle dimensioni della board si può randomizzare la scelta delle navi in più considerando che comunque il gioco rimarrebbe bilanciato anche se i player hanno una flotta diversa. Infatti se hai una nave piu grossa sei piu facile da colpire ma devi colpire piu volte per vincere, se hai una nave piu piccola devi colpire meno volte ma è piu difficile da trovare

    dim_grid = 10;

    cout << "Hai selezionato la modalità ";

    if(mode){   //quando si fanno cicli con variabili booleane si può scruvere direttamente cosí per sottintendere mode == true
        cout << "giocatore vs giocatore";
        player1_mode = true;
        player2_mode = true;
    }else{
        cout << "giocatore vs computer";
        player1_mode = true;    //non importa per ora chi sia il bot, diventerà fondamentale nel momento in cui si sceglie chi parte
        player2_mode = false;
    }

    sleep(2);
    cout << endl;

    system("clear");

    if(mode){

        cout << "Digitare il nome di uno dei giocatori: ";
        cin >> player1_name;

        cout << endl;

        cout << "Digitare il nome dell'altro giocatore: ";
        cin >> player2_name;

        cout << endl;


    }else{

        srand((unsigned int) time(NULL));
        cout << "Digitare il nome del giocatore: ";
        cin >> player1_name;

        player2_name = random_name[(rand() % 10)];

        cout << endl;
    }

    cout << "I nomi dei giocatori sono " << player1_name << " & " << player2_name << endl;

    sleep(4);

    system("clear");
}


bool game::GetMode() const{

    return mode;

}

bool game::GetStatus() const{

    return status;
}

int game::GetNumShips() const{

    return n_ships;

}

int game::GetDimGrid() const{

    return dim_grid;

}

void game::WhoStarts(){

    string temp;
    bool t;
    srand((unsigned int) time(NULL));

    int whostart = rand() % 2;

    if(whostart == 1){  //randomiziamo da 1 a 10, se è pari inizia 1 se è dispari inizia 2
        
        cout << "Il primo a giocare e' " << player1_name;

        cout << endl;

    }else{

        temp = player1_name;
        player1_name = player2_name;
        player2_name = temp;    //faccio uno swap di nomi così sono sicuro che se dopo stampo player1name sto stampando il nome del primo giocatore
        
        t = player1_mode;
        player1_mode = player2_mode;
        player2_mode = t;

        cout << "Il primo a giocare e' " << player1_name;
        

        cout << endl;
    }
    

}

/*int game::GetWhoStarts() const{ //forse inutile

    return whostart;

}*/

bool game::GetP1Mode() const{

    return player1_mode;
}

bool game::GetP2Mode() const{

    return player2_mode;
}

void game::Play(){

    grid p1(dim_grid, n_ships, player1_mode);
    grid p2(dim_grid, n_ships, player2_mode);
    

    if(player1_mode){
        cout << "Passare il computer al giocatore che deve iniziare..." << endl;
        cout << "Se sei pronto e il tuo avversario non sta guardando premere invio" << endl;
        cin.ignore();

        p1.setGrid(player1_mode);
    }else{
        cout << "Il tuo avversario si sta preparando per la battaglia, attendere..." << endl;
        cout << "Game 238";
        p1.setGrid(player1_mode);

        sleep(3);
    }

    cout << "Game 244";
    
    if(player2_mode){
        cout << "Passare il computer al secondo giocatore..." << endl;
        cout << "Se sei pronto e il tuo avversario non sta guardando premere invio" << endl;
        cin.ignore();

        p2.setGrid(player2_mode);

    }else{
        cout << "Il tuo avversario si sta preparando per la battaglia, attendere..." << endl;

        p2.setGrid(player2_mode);

        sleep(3);
    }

    cout << "Bene comandanti i preparativi sono stati ultimati: si dia inizio alla battaglia!" << endl;
    cout << "\n\n";


    int s1 = 1;
    int s2 = 1;
    
    while(status){
        
        while(status){
            if(p2.isShotBy(p1)){
                s1++;
                cout << "s1 = " << s1;
            }else
                break;
        }
        
        
        if(s1 == ship_spaces){
            who_won = true;
            sleep(2);
            break;
        }
        
        while(status){
            if(p1.isShotBy(p2)){
                s2++;
                cout << "s2 = " << s2;
            }
            else
                break;
        }
        
        if(s2 == ship_spaces){
            who_won = false;
            break;
        }
    }


}


void game::PrintWinnerScreen(){
//SMSLANT KERNEL

    system("clear");
    
    string p_winner;

    if(who_won)
        p_winner = player1_name;
    else
        p_winner = player2_name;

    if(player1_mode && player2_mode){

        cout <<"  \033[1;35m_   __ ____ ______ ______ ____   ___   ____ ___\033[0m\n";
        cout <<" \033[1;35m| | / //  _//_  __//_  __// __ \\ / _ \\ /  _// _ |\033[0m\n";
        cout <<" \033[1;35m| |/ /_/ /   / /    / /  / /_/ // , _/_/ / / __ |\033[0m\n";
        cout <<" \033[1;35m|___//___/  /_/    /_/   \\____//_/|_|/___//_/ |_|\033[0m\n";

        cout << "\n\n\n\n";


        cout << "Complimenti comandante " << p_winner << " hai vinto questa battaglia di Stardust Crusaders!" << endl;

        cout << "\n\n\n";
        sleep(1);
        cout << "Sei stato in gamba, ma ricorda...";
        sleep(1);
        cout << "Vincere una battaglia non significa vincere la guerra. " << endl;
        sleep(1);
        cout << "Sulla tua strada incontrerai ancora molti avversari" << endl;
        cout << "Ma ogni piccolo passo che farai ti condurrà alla vittoria finale";
        cout << "\n\n\n";
        sleep(1);
        cout << "See you space Cowboy";

        cout << "Grazie per aver giocato! Per avviare una nuova partita riavvia il programma";

    }else{

        cout <<"  \033[1;35m  ____ _____ ____   _  __ ____ ____ ______ ______ ___\033[0m\n";
        cout <<" \033[1;35m  / __// ___// __ \\ / |/ // __//  _//_  __//_  __// _ |\033[0m\n";
        cout <<" \033[1;35m _\\ \\ / /__ / /_/ //    // _/ _/ /   / /    / /  / __ |\033[0m\n";
        cout <<" \033[1;35m/___/ \\___/ \\____//_/|_//_/  /___/  /_/    /_/  /_/ |_|\033[0m\n";

        cout << "\n\n\n\n";
        cout << "Sei stato sconfitto dal comandante " << p_winner << endl;
        cout << "Ma non demordere!";
        sleep(1);
        cout << "I grandi uomini accettano le sconfitte, imparano da esse e sono in grado di trarne più vantaggi possibile.";
        cout << "\n\n\n\n";
        sleep(1);
        cout << "La vera guerra Stardust Crusaders e' appena iniziata!";
        cout << "Per rigiocare riavvia il programma";
        cout << "See you space Cowboy...";
    }

    return;


}
