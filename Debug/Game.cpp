//
//  Game.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 13/07/22.
//http://www.kammerl.de/ascii/AsciiSignature.php
//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal


#include "Game.hpp"
#include "account.hpp"


game::game(){
    
    random_name.push_back("Edward Wong Hau Pepelu Tivrusky IV");
    random_name.push_back("Magi system");
    random_name.push_back("Il Genio delle Tartarughe");
    random_name.push_back("Tetsuo");
    random_name.push_back("Star Platinum");
    random_name.push_back("Senza-Volto");
    random_name.push_back("Fsociety");
    random_name.push_back("Sauron");
    random_name.push_back("Hector blu");
    random_name.push_back("Mystery Machine");
}

game::game(bool m, bool s, int n, int d, string name1, string name2, bool player1, bool player2){

    mode = m;

    status = s;

    n_ships = n;

    dim_grid = d;

    //whostart = w;

    player1_name = name1;

    player2_name = name2;
    

    player1_mode = player1; //variabili in cui salviamo se i giocatori sono umani o cpu

    player2_mode = player2;

}


void game::PrintMenu(){ //font da asciisignature è il graffiti, hho anche selezionato "kerning"
    
    system("clear");
    
    char choose, rules;
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cout <<"\033[1;35m \t\t\t     _________  __                      .___               __    _________                                   .___\033[0m\n";
    cout <<"\033[1;35m \t\t\t    /   _____/_/  |_ _____  _______   __| _/__ __  _______/  |_  \\_   ___ \\_______  __ __  ___________     __| _/ ____ _______  ______\033[0m\n";
    cout <<"\033[1;35m \t\t\t    \\_____  \\ \\   __\\\\__  \\ \\_  __ \\ / __ ||  |  \\/  ___/\\   __\\ /    \\  \\/\\_  __ \\|  |  \\/  ___/\\__  \\   / __ |_/ __ \\\\_  __ \\/  ___/\033[0m\n";
    cout <<"\033[1;35m \t\t\t    /        \\ |  |   / __ \\_|  | \\// /_/ ||  |  /\\___ \\  |  |   \\     \\____|  | \\/|  |  /\\___ \\  / __ \\_/ /_/ |\\  ___/ |  | \\/\\___ \\ \033[0m\n";
    cout <<"\033[1;35m \t\t\t   /_______  / |__|  (____  /|__|   \\____ ||____//____  > |__|    \\______  /|__|   |____//____  >(____  /\\____ | \\___  >|__|  /____  >\033[0m\n";
    cout <<"\033[1;35m \t\t\t           \\/             \\/             \\/           \\/                 \\/                   \\/      \\/      \\/     \\/            \\/\033[0m\n";

    cout << "\n";
    cout << "                                                                                       \033[1;35mcreated by Barletta Valentina & Gallo Matteo\033[0m" << endl;
    
    cout << "\n\n";

    cout << "                               La sangunaria contesa che da tempo infuria tra gli Atreides e gli Harkonen popoli hanno come comune                " << endl;
    cout << "                               obbiettivo il recupero del rarissimo frammento della stella Bebop, esplosa milioni di anni fa.                        " << endl;
    cout << "                               Acquisire tale oggetto permetterebbe agli Atreides, specie affetta da nanismo, di aumentare la loro                 " << endl;
    cout << "                               altezza di circa 10 milioni di faaD atreideri (ovvero 1,5 cm in unita' terrestri). Consentirebbe,                    " << endl;
    cout << "                               invece, agli Harkonen di risolvere il gravoso problema che sta portando la loro specie allo             " << endl;
    cout << "                               sterminio: l'irritante traballare del tavolo dell'imperatore che ne causa l'ira furiosa e che si ma-                " << endl;
    cout << "                               nifesta con pubbliche esecuzioni.                 " << endl;
    cout << "                               Entrambi gli schieramenti sono giunte allo stremo. Per vincere gli Atreides hanno incaricato di capi-               " << endl;
    cout << "                               tanare le loro milizie spaziali al comandante della flotta della Valle del Vento, mentre gli Harkonen               " << endl;
    cout << "                               si sono affidati al capitano dei Boogie Woogie Feng Shui. Le sorti di queste due popolazioni si deci-               " << endl;
    cout << "                               deranno oggi nella battaglia definitiva di Stardust Crusaiders. Chi vincera'?                " << endl;
    
    cout << "\n\n";

    cout << "\t\t\t\t Digitare \033[1;7;37m y \033[0m per giocare oppure \033[1;7;37m n \033[0m per uscire: ";
    cin >> choose;

    

    if(choose == 'n')
        exit(0);    //comando che fa chiudere il programma
    else
        system("clear");    //comando che cancella tutte le scritte sul terminale
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    cout << "\t\t\t\t\t Vuoi visionare il regolamento della partita? Digita \033[1;7;37m y \033[0m per guardarlo oppure \033[1;7;37m n \033[0m per ignorare:";
    cin >> rules;

    while(rules != 'n' && rules != 'y'){
        cout << "\n";
        cout << "\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> rules;
        cout << endl;
    }
    
    system("clear");

    if(rules == 'y')
    PrintInstructions();

    system("clear");
    
}

void game::PrintInstructions(){

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cout <<"\033[1;35m \t\t\t\t\t\t\t      ___                    __                       __      \033[0m\n";
    cout <<"\033[1;35m \t\t\t\t\t\t\t     / _ \\ ___  ___ _ ___   / /___ _ __ _  ___  ___  / /_ ___ \033[0m\n";
    cout <<"\033[1;35m \t\t\t\t\t\t\t    / , _// -_)/ _ `// _ \\ / // _ `//  ' \\/ -_)/ _ \\/ __// _ \\ \033[0m\n";
    cout <<"\033[1;35m \t\t\t\t\t\t\t   /_/|_| \\__/ \\_, / \\___//_/ \\_,_//_/_/_/\\__//_//_/\\__/ \\___/\033[0m\n";
    cout <<"\033[1;35m \t\t\t\t\t\t\t              /___/                                           \033[0m\n";

    cout << "\n\n";


    cout << "\t                               Ogni giocatore posiziona segretamente tutte le sue navi sulla griglia. Le navi possono essere" << endl;
    cout << "\t                               piazzate verticalmente o orizzontalmente, non in digonale, in ogni spazio libero del campo da" << endl;
    cout << "\t                               gioco. Le navi possono toccarsi ma non possono occupare le stesse caselle. La loro posizione " << endl;
    cout << "\t                               non è modificabile." << endl;
    cout << "\t                               Durante il proprio turno il giocatore può sparare in un punto qualsisi della griglia dell'av-" << endl;
    cout << "\t                               versario. Se riesce a beccare un pezzo di nave nemica, avrà a disposizione un'altro colpo da " << endl;
    cout << "\t                               sparare. Quando tutte le caselle di una nave vengono colpite, allora la nave verrà considera-" << endl;
    cout << "\t                               ta affondata. Se, invece, il giocatore in questione dovesse mancare il bersaglio, allora pas-" << endl;
    cout << "\t                               serà il turno all'avversario. Si continua a giocare finché un giocatore non affonda tutte le " << endl;
    cout << "\t                               navi opposte e vince il gioco!" << endl;
    cout << "\t                               La modalità 'veloce' permette ad ogni giocatore di avere a disposizione 4 colpi ogni turno" << endl;

    cout << "\n\n";
    
    cout << "\t\t\t\t\t\t\t\t Premere ENTER per proseguire";
    cin.ignore();
    cin.ignore();
}


void game::SetGameMode(){

    int temp;   //variabile temporanea in cui carichiamo le scelte fatte dallo user
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cout << "\t\t\t\t\t\t\t Scegli con chi giocare:\n";
    cout << "\t\t\t\t\t\t\t Per giocare contro il computer digitare \033[1;7;37m 1 \033[0m\n";
    cout << "\t\t\t\t\t\t\t Per giocare contro un'altra persona digitare \033[1;7;37m 2 \033[0m\n";
    cout << "\t\t\t\t\t\t\t ";
    cin >> temp;


    while(temp != 1 && temp != 2){
        cout << endl;
        cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m o \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> temp;
        cout << endl;
    }
    
    cout << endl;
    cout << "\t\t\t\t\t\t\t Hai selezionato la modalità ";

    if(temp == 2){   //quando si fanno cicli con variabili booleane si può scruvere direttamente cosí per sottintendere mode == true
        cout << "\033[1;7;37m giocatore vs giocatore \033[0m" << endl;
        player1_mode = true;
        player2_mode = true;
    }else{
        cout << "\033[1;7;37m giocatore vs computer \033[0m" << endl;
        player1_mode = true;    //non importa per ora chi sia il bot, diventerà fondamentale nel momento in cui si sceglie chi parte
        player2_mode = false;
    }
    
    

    status = true;  //così a priori non so se la utilizzeremo ma idealmente è una variabile che contiene lo stato della partita, se =true allora stiamo giocando, se =false allora qualcuno ha vinto e si potrà stampare la schermata finale

    n_ships = 4;    //in un eventuale espansione questi due numeri possono essere messi a scelta, aggiungendo modalita piu lunghe o corte, e anche magari metto tutto customizzabile dal giocatore. Quello che poensavo e che nel caso di un aumento delle dimensioni della board si può randomizzare la scelta delle navi in più considerando che comunque il gioco rimarrebbe bilanciato anche se i player hanno una flotta diversa. Infatti se hai una nave piu grossa sei piu facile da colpire ma devi colpire piu volte per vincere, se hai una nave piu piccola devi colpire meno volte ma è piu difficile da trovare

    dim_grid = 10;
    
    cout << "\n\n";
    
    char choose;
    int a;
    
    
    if(temp == 2){
        
        account A1; //criamo gli account
        
        cout << "Hai già un account? Digita \033[1;7;37m y \033[0m se si, altrimenti \033[1;7;37m n \033[0m:";
        cin >> choose;
        
        while(choose != 'n' && choose != 'y'){
            cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
        }
        
        if(choose == 'y'){
            
            system("clear");
            
            cout << "Se vuoi giocare come ospite digitare \033[1;7;37m 1 \033[0m, se vuoi accedere \033[1;7;37m 2 \033[0m:";
            cin >> a;
            
            while(a != 1 && a != 2){
                cout << endl;
                cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m o \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> temp;
                cout << endl;
            }
            
            if(a == 1){
                cout << "\t\t\t\t\t\t\t Digitare il tuo username: ";
                cin >> player1_name;
                goto here1;
            }else{
                A1.login();
                player1_name = A1.getUsername();
            }
            
        }else if(choose == 'n'){
            cout << "\n\n";
            cout << "Vuoi creare un account? Digitare \033[1;7;37m y \033[0m per crearne uno, altrimenti \033[1;7;37m n \033[0m per giocare come ospite:";
            cin >> choose;
            
            if(choose == 'y'){  //se si registriamo l'account
                A1.signup();    //dentro signup c'è gia il login
                player1_name = A1.getUsername();
            }else if(choose == 'n'){
                cout << "\t\t\t\t\t\t\t Digitare il tuo username: ";
                cin >> player1_name;
            }
        }
        
        here1:
        
        if(A1.getLogged()){
            
            bool condition = true;
            
            while(condition){   //potrebbe voler cambiare più di una cosa, o la stessa cosa due volte
                system("clear");
                cout << "Vuoi cambiare username, password o domanda di sicurezza? Per farlo digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    A1.manage_account();
                else
                    condition = false;
            }
            
            condition = true;
            
            system("clear");
            
            while(condition){
                cout << "Vuoi vedere le statistiche delle tue partite precedenti? Se si digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    cout << "Ancora da fare" << endl;
                //A1.getStats();
                else
                    condition = false;
            }
        }
        
        account A2(player1_name);
        
        system("clear");
        cout << "Hai già un account? Digita \033[1;7;37m y \033[0m se si, altrimenti \033[1;7;37m n \033[0m:";  //ripetiamo la procedura per il secondo giocatore umano
        cin >> choose;
        
        while(choose != 'n' && choose != 'y'){
            cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
        }
        
        if(choose == 'y'){
            
            system("clear");
            
            cout << "Se vuoi giocare come ospite digitare \033[1;7;37m 1 \033[0m, se vuoi accedere \033[1;7;37m 2 \033[0m:";
            cin >> a;
            
            while(a != 1 && a != 2){
                cout << endl;
                cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m o \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> temp;
                cout << endl;
            }
            
            if(a == 1){
                cout << "\t\t\t\t\t\t\t Digitare il tuo username: ";
                cin >> player2_name;
                goto here2;
            }else{
                A2.login();
                player2_name = A2.getUsername();
            }
            
        }else if(choose == 'n'){
            cout << "\n\n";
            cout << "Vuoi creare un account? Digitare \033[1;7;37m y \033[0m per crearne uno, altrimenti \033[1;7;37m n \033[0m per giocare come ospite:";
            cin >> choose;
            
            if(choose == 'y'){
                A2.signup();
                player2_name = A2.getUsername();
            }else if(choose == 'n'){
                cout << "\t\t\t\t\t\t\t Digitare il nome dell'altro giocatore: ";
                cin >> player2_name;
            }
        }
        
        here2:
        
        cout << "A2 logged = " << A2.getLogged() << endl;
    
        if(A2.getLogged()){
            
            cout << "Sono entrato" << endl;
            
            bool condition = true;
            
            while(condition){   //potrebbe voler cambiare più di una cosa, o la stessa cosa due volte
                system("clear");
                cout << "Vuoi cambiare username, password o domanda di sicurezza? Per farlo digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    A2.manage_account();
                else
                    condition = false;
            }
            
            condition = true;
                
            system("clear");
            
            while(condition){
                cout << "Vuoi vedere le statistiche delle tue partite precedenti? Se si digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    cout << "Ancora da fare" << endl;
                //A2.getStats();
                else
                    condition = false;
            }
        }
        
    }else if(temp == 1){
        
        account A1;
        
        cout << "Hai già un account? Digita \033[1;7;37m y \033[0m se si, altrimenti \033[1;7;37m n \033[0m:";
        cin >> choose;
        
        while(choose != 'n' && choose != 'y'){
            cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
        }
        
        if(choose == 'y'){
            
            system("clear");
            
            cout << "Se vuoi giocare come ospite digitare \033[1;7;37m 1 \033[0m, se vuoi accedere \033[1;7;37m 2 \033[0m:";
            cin >> a;
            
            while(a != 1 && a != 2){
                cout << endl;
                cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m o \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> temp;
                cout << endl;
            }
            
            if(a == 1){
                cout << "\t\t\t\t\t\t\t Digitare il tuo username: ";
                cin >> player1_name;
                goto here3;
            }else{
                A1.login();
                player1_name = A1.getUsername();
            }
            
        }else if(choose == 'n'){
            cout << "\n\n";
            cout << "Vuoi creare un account? Digitare \033[1;7;37m y \033[0m per crearne uno, altrimenti \033[1;7;37m n \033[0m per giocare come ospite:";
            cin >> choose;
            
            if(choose == 'y'){  //se si registriamo l'account
                A1.signup();    //dentro signup c'è gia il login
                player1_name = A1.getUsername();
            }else if(choose == 'n'){
                cout << "\t\t\t\t\t\t\t Digitare il tuo username: ";
                cin >> player1_name;
            }
        }
        
        here3:
        
        if(A1.getLogged()){
            
            bool condition = true;
            
            while(condition){   //potrebbe voler cambiare più di una cosa, o la stessa cosa due volte
                system("clear");
                cout << "Vuoi cambiare username, password o domanda di sicurezza? Per farlo digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    A1.manage_account();
                else
                    condition = false;
            }
            
            condition = true;
            
            system("clear");
            
            while(condition){
                cout << "Vuoi vedere le statistiche delle tue partite precedenti? Se si digita \033[1;7;37m y \033[0m altrimenti \033[1;7;37m n \033[0m: ";
                cin >> choose;
                while(choose != 'n' && choose != 'y'){
                    cout << "\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                    cin >> choose;
                    cout << endl;
                }
                if(choose == 'y')
                    cout << "Ancora da fare" << endl;
                //A1.getStats();
                else
                    condition = false;
            }
        }

        srand((unsigned int) time(NULL));

        player2_name = random_name[(rand() % 10)];

        cout << endl;
    }

    cout << "\n\n";
    
    cout << "\t\t\t\t\t\t\t Il comandante della flotta della Valle del Vento e' \033[1;36m" << player1_name << "\033[0m" << endl;
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t Il comandante dei Boogie Woogie Feng Shui e' \033[1;31m" << player2_name << "\033[0m" << endl;
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t Premere ENTER per proseguire...";

    cin.ignore();
    cin.ignore();

    system("clear");
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    cout << "\t\t\t\t\t\t\t Scegli la modalita' di gioco:" << endl;
    cout << "\t\t\t\t\t\t\t Per la modalita' normale digitare \033[1;7;37m 1 \033[0m\n";
    cout << "\t\t\t\t\t\t\t Per la modalita' veloce digitare \033[1;7;37m 2 \033[0m\n";
    cout << "\t\t\t\t\t\t\t ";
    cin >> temp;
    
    while(temp != 1 && temp != 2){
        cout << endl;
        cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m o \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> temp;
        cout << endl;
    }
    
    cout << "\n\n\n";
    
    if(temp == 1){
        mode = true;    //velocita normale
        
        cout << "\t\t\t\t\t\t\t Hai selezionato la modalità normale.";
    }else{
        mode = false;   //fast
        
        cout << "\t\t\t\t\t\t\t Hai selezionato la modalità veloce.";
    }
    
    cin.ignore();
    cin.ignore();
    
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

    whostart = rand() % 2;

    if(whostart == 1){  //randomiziamo da 1 a 10, se è pari inizia 1 se è dispari inizia 2
        
        cout << "\n\n\n\n\n\n";
        
        cout << "\t\t\t\t\t\t\t\t Il primo a giocare e' \033[1;36m" << player1_name << "\033[0m";

        cout << endl;
        
        cout << "\n\n";

    }else{

        temp = player1_name;
        player1_name = player2_name;
        player2_name = temp;    //faccio uno swap di nomi così sono sicuro che se dopo stampo player1name sto stampando il nome del primo giocatore
        
        t = player1_mode;
        player1_mode = player2_mode;
        player2_mode = t;
        cout << "\n\n";
        
        cout << "\t\t\t\t\t\t\t\t Il primo a giocare e' \033[1;31m" << player1_name << "\033[0m";
        
        cout << "\n\n";
        

        cout << endl;
    }
    

}

int game::GetWhoStarts() const{ //forse inutile

    return whostart;

}

bool game::GetP1Mode() const{

    return player1_mode;
}

bool game::GetP2Mode() const{

    return player2_mode;
}

void game::Play(){

    grid p1(dim_grid, n_ships, player1_mode);
    grid p2(dim_grid, n_ships, player2_mode);
    

    if(player1_mode && whostart == 1){  //se whostart == 1 allora inizia il primo giocatore
        cout << "\t\t\t\t\t\t\t Passare il computer a \033[1;36m" << player1_name<< "\033[0m che deve iniziare." << endl;
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t Se sei pronto premi ENTER per posizionare la tua flotta sul campo..." << endl;
        cin.ignore();

        p1.setGrid(player1_mode);
    }else if(player1_mode && whostart == 0){    //se whostart == 0 allora inizia il secondo giocatore ma passiamo prima per l'if che trasferisce tutto in player1_name e mode
        cout << "\t\t\t\t\t\t\t Passare il computer a \033[1;31m" << player1_name<< "\033[0m che deve iniziare." << endl;
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t Se sei pronto premi ENTER per posizionare la tua flotta sul campo..." << endl;
        cin.ignore();

        p1.setGrid(player1_mode);
    }else if(!player1_mode && whostart == 0){
        cout << "\t\t\t\t\t\t\t \033[1;36m" << player1_name<< "\033[0m si sta preparando per la battaglia, attendere..." << endl;
        p1.setGrid(player1_mode);

        sleep(3);
    }else if(!player1_mode && whostart == 1){
        cout << "\t\t\t\t\t\t\t \033[1;31m" << player1_name<< "\033[0m si sta preparando per la battaglia, attendere..." << endl;
        p1.setGrid(player1_mode);

        sleep(3);
    }
    
    if(player2_mode && whostart == 1){
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t Passare il computer a \033[1;36m" << player2_name<< "\033[0m" << endl;
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t Se sei pronto premi ENTER per posizionare la tua flotta sul campo..." << endl;
        cin.ignore();

        p2.setGrid(player2_mode);
    }else if(!player2_mode && whostart == 1){
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t \033[1;36m" << player2_name<< "\033[0m si sta preparando per la battaglia, attendere..." << endl;

        p2.setGrid(player2_mode);

        sleep(3);
    }else if(player2_mode && whostart == 0){
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t Passare il computer a \033[1;31m" << player2_name<< "\033[0m" << endl;
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t Se sei pronto premi ENTER per posizionare la tua flotta sul campo..." << endl;
        cin.ignore();

        p2.setGrid(player2_mode);
    }else if(!player2_mode && whostart == 0){
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t \033[1;31m" << player2_name<< "\033[0m si sta preparando per la battaglia, attendere..." << endl;

        p2.setGrid(player2_mode);

        sleep(3);
    }

    cout << "Bene comandanti i preparativi sono stati ultimati: si dia inizio alla battaglia!" << endl;
    cout << "\n\n";
    cin.ignore();
    
    bool k;

    if(mode){
        
        while(status){
            
            k = p2.isShotBy(p1);
            
            while(k){
                
                if(!p2.hittable()){
                    who_won = true;
                    goto end;
                }
                
                k = p2.isShotBy(p1);
                
                if(!k)
                    break;
            }
            
            if(player1_mode && player2_mode){
                
                cout << "\t\t\t\t Non hai più colpi a disposizione. Passa il computer al tuo avversario." << endl;
                cout << "QUANDO SEI PRONTO E IL TUO AVVERSARIO NON STA GUARDANDO PREMERE INVIO." << endl;

            }else if(!player1_mode && player2_mode){
                cout << "\t\t\t\t Il tuo avversario non ha più colpi a disposizione. Tocca a te! Aguzza il tuo istinto e SPARA" << endl;
            }else if(player1_mode && !player2_mode){
                cout << "\t\t\t\t Non hai più colpi a disposizione. Tocca al tuo nemico." << endl;
            }
            
                
            k = p1.isShotBy(p2);
            
            while(k){
                
                if(!p1.hittable()){
                    who_won = false;
                    goto end;
                }
                
                k = p1.isShotBy(p2);
    
                if(!k)
                    break;
            }
        }
            
        if(player1_mode && player2_mode){
            cout << "\t\t\t\t Non hai più colpi a disposizione. Passa il computer al tuo avversario." << endl;
            cout << "QUANDO SEI PRONTO E IL TUO AVVERSARIO NON STA GUARDANDO PREMERE INVIO." << endl;

        }else if(player1_mode && !player2_mode){
            cout << "\t\t\t\t Il tuo avversario non ha più colpi a disposizione. Tocca a te! Aguzza il tuo istinto e SPARA" << endl;
        }else if(!player1_mode && player2_mode){
            cout << "\t\t\t\t Non hai più colpi a disposizione. Tocca al tuo nemico." << endl;
        }
        
    }else{
        
        int turn_p1 = 0, turn_p2 = 0;
        int turn_gap_p1 = 4, turn_gap_p2 = 4;
        
        while(status){
            
            while(status){
                
                k = p2.isShotBy(p1);
                
                if(k){
                    
                    turn_p1++;
                    turn_gap_p1++;
                    
                    cout << "TRUE turn_p1 = " << turn_p1 << " turn_gap_p1 = " << turn_gap_p1 << endl;
                    
                    if(!p2.hittable()){
                        who_won = true;
                        goto end;
                    }
                }else if(!k){
                    
                    turn_p1++;
                
                    cout << "FALSE turn_p1 = " << turn_p1 << " turn_gap_p1 = " << turn_gap_p1 << endl;
                    
                }
                    
                if(turn_p1 == turn_gap_p1)
                    break;
            }
            
            turn_p1 = 0;
            turn_gap_p1 = 4;
            
            
            if(player1_mode && player2_mode){
                cout << "\t\t\t\t Non hai più colpi a disposizione. Passa il computer al tuo avversario." << endl;
                cout << "QUANDO SEI PRONTO E IL TUO AVVERSARIO NON STA GUARDANDO PREMERE INVIO." << endl;

            }else if(!player1_mode && player2_mode){
                cout << "\t\t\t\t Il tuo avversario non ha più colpi a disposizione. Tocca a te! Aguzza il tuo istinto e SPARA" << endl;
            }else if(player1_mode && !player2_mode){
                cout << "\t\t\t\t Non hai più colpi a disposizione. Tocca al tuo nemico." << endl;
            }
            
            while(status){
                
                k = p1.isShotBy(p2);
                
                if(k){
                    
                    turn_p2++;
                    turn_gap_p2++;
                    
                    cout << "TRUE turn_p2 = " << turn_p2 << " turn_gap_p2 = " << turn_gap_p2 << endl;
                    
                    if(!p1.hittable()){
                        who_won = false;
                        goto end;
                    }
                    
                }else if(!k){
                    
                    turn_p2++;
                    cout << "FALSE turn_p2 = " << turn_p2 << " turn_gap_p2 = " << turn_gap_p2 << endl;
                    
                }
                
                if(turn_p2 == turn_gap_p2)
                    break;
            }
            
            turn_p2 = 0;
            turn_gap_p2 = 4;
            
            if(player1_mode && player2_mode){
                cout << "\t\t\t\t Non hai più colpi a disposizione. Passa il computer al tuo avversario." << endl;
                cout << "QUANDO SEI PRONTO E IL TUO AVVERSARIO NON STA GUARDANDO PREMERE INVIO." << endl;

            }else if(player1_mode && !player2_mode){
                cout << "\t\t\t\t Il tuo avversario non ha più colpi a disposizione. Tocca a te! Aguzza il tuo istinto e SPARA" << endl;
            }else if(!player1_mode && player2_mode){
                cout << "\t\t\t\t Non hai più colpi a disposizione. Tocca al tuo nemico." << endl;
            }
        }
        
    }
    
    end:
    
    return;
    
}


void game::PrintWinnerScreen(){
    //SMSLANT KERNEL
        
        string p_winner;

        if(who_won && player1_mode){    //se vince il primo ed è umano
            
            p_winner = player1_name;
            
            cout <<"\t\t\t\t\t\t  \033[1;35m_   __ ____ ______ ______ ____   ___   ____ ___\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m| | / //  _//_  __//_  __// __ \\ / _ \\ /  _// _ |\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m| |/ /_/ /   / /    / /  / /_/ // , _/_/ / / __ |\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m|___//___/  /_/    /_/   \\____//_/|_|/___//_/ |_|\033[0m\n";

            cout << "\n\n\n\n";


            cout << "\t\t\t\t\t\t Complimenti comandante \033[1;33m" << p_winner << "\033[0m hai vinto questa battaglia di Stardust Crusaders!" << endl;

            cout << "\n\n\n";
            sleep(1);
            cout << "\t\t\t\t\t\t Sei stato in gamba, ma ricorda..." << endl;
            sleep(1);
            cout << "\t\t\t\t\t\t Vincere una battaglia non significa vincere la guerra. " << endl;
            sleep(1);
            cout << "\t\t\t\t\t\t Sulla tua strada incontrerai ancora molti avversari." << endl;
            cout << "\t\t\t\t\t\t Ma ogni piccolo passo che farai ti condurrà alla vittoria finale.";
            cout << "\n\n\n";
            sleep(1);
            cout << "\t\t\t\t\t\t See you space Cowboy..." << endl;

            cout << "\t\t\t\t\t\t Grazie per aver giocato! Per avviare una nuova partita riavvia il programma." << endl;

        }else if(who_won && !player1_mode){ //se vince il primo ma è CPU
            
            p_winner = player1_name;

            cout <<"\t\t\t\t\t\t  \033[1;35m  ____ _____ ____   _  __ ____ ____ ______ ______ ___\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m  / __// ___// __ \\ / |/ // __//  _//_  __//_  __// _ |\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m _\\ \\ / /__ / /_/ //    // _/ _/ /   / /    / /  / __ |\033[0m\n";
            cout <<"\t\t\t\t\t\t \033[1;35m/___/ \\___/ \\____//_/|_//_/  /___/  /_/    /_/  /_/ |_|\033[0m\n";

            cout << "\n\n\n\n";
            cout << "\t\t\t\t\t\t Sei stato sconfitto dal comandante \033[1;33m" << p_winner << "\033[0m" << endl;
            cout << "Ma non demordere!";
            sleep(1);
            cout << "I grandi uomini accettano le sconfitte, imparano da esse e sono in grado di trarne più vantaggi possibile.";
            cout << "\n\n";
            sleep(1);
            cout << "La vera guerra e' appena iniziata! ";
            cout << "Per rigiocare riavvia il programma" << endl;
            cout << "\n\n";
            cout << "See you space Cowboy...";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
            
        }else if(!who_won && player2_mode){ //se vince il secondo ed è umano
            
            p_winner = player2_name;
            
            cout <<"  \033[1;35m_   __ ____ ______ ______ ____   ___   ____ ___\033[0m\n";
            cout <<" \033[1;35m| | / //  _//_  __//_  __// __ \\ / _ \\ /  _// _ |\033[0m\n";
            cout <<" \033[1;35m| |/ /_/ /   / /    / /  / /_/ // , _/_/ / / __ |\033[0m\n";
            cout <<" \033[1;35m|___//___/  /_/    /_/   \\____//_/|_|/___//_/ |_|\033[0m\n";

            cout << "\n\n\n\n";


            cout << "Complimenti comandante \033[1;33m" << p_winner << "\033[0m hai vinto questa battaglia di Stardust Crusaders!" << endl;

            cout << "\n\n\n";
            sleep(1);
            cout << "Sei stato in gamba, ma ricorda..." << endl;
            sleep(1);
            cout << "Vincere una battaglia non significa vincere la guerra. " << endl;
            sleep(1);
            cout << "Sulla tua strada incontrerai ancora molti avversari." << endl;
            cout << "Ma ogni piccolo passo che farai ti condurrà alla vittoria finale.";
            cout << "\n\n\n";
            sleep(1);
            cout << "See you space Cowboy..." << endl;

            cout << "Grazie per aver giocato! Per avviare una nuova partita riavvia il programma." << endl;
            
        }else if(!who_won && !player2_mode){    //se vince il secondo ma è CPU
            
            p_winner = player2_name;

            cout <<"  \033[1;35m  ____ _____ ____   _  __ ____ ____ ______ ______ ___\033[0m\n";
            cout <<" \033[1;35m  / __// ___// __ \\ / |/ // __//  _//_  __//_  __// _ |\033[0m\n";
            cout <<" \033[1;35m _\\ \\ / /__ / /_/ //    // _/ _/ /   / /    / /  / __ |\033[0m\n";
            cout <<" \033[1;35m/___/ \\___/ \\____//_/|_//_/  /___/  /_/    /_/  /_/ |_|\033[0m\n";

            cout << "\n\n\n\n";
            cout << "Sei stato sconfitto dal comandante \033[1;33m" << p_winner << "\033[0m" << endl;
            cout << "Ma non demordere!";
            sleep(1);
            cout << "I grandi uomini accettano le sconfitte, imparano da esse e sono in grado di trarne più vantaggi possibile.";
            cout << "\n\n";
            sleep(1);
            cout << "La vera guerra e' appena iniziata! ";
            cout << "Per rigiocare riavvia il programma" << endl;
            cout << "\n\n";
            cout << "See you space Cowboy...";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        }
        return;
}
