//
//  Account.cpp
//  Stardust Crusaders
//
//  Created by Matteo Gallo on 06/08/22.
//

#include "account.hpp"
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>


account::account(){
    logged = false;
}

account::account(string uname){
    other_player = uname;
    logged = false;
}

// Definition of encryption function
void account::encrypt(string f_name, string uname){
 
    // Input stream
    fstream fin, fout;
 
    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open(f_name, fstream::in);
    fout.open(uname.append("_encrypted.txt"), fstream::out);
 
    // Reading original file till
    // end of file
    while (fin >> noskipws >> c) {
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }
 
    // Closing both files
    fin.close();
    fout.close();
    
    char f_to_remove [f_name.length()];
    
    strcpy(f_to_remove, f_name.c_str());
    
    remove(f_to_remove);
    
}
 
// Definition of decryption function
void account::decrypt(string f_name, string uname){
    
    fstream fin;
    fstream fout;
    
    
    
    fin.open(f_name, fstream::in);
    
    fout.open(uname.append(".txt"), fstream::out);
 
    while (fin >> noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
    
    char f_to_remove [f_name.length()];
    
    strcpy(f_to_remove, f_name.c_str());
    
    
    remove(f_to_remove);
}


void account::signup(){
    
    string filename;
    
    system("clear");
    
    cout << "Scrivi il tuo username: ";
    cin >> username;
    cin.ignore();
    
    filename = username;
    
    filename.append("_encrypted.txt");
    
    ifstream file_to_check_existance;   //non ho capito benissimo cos'è però se definisco questa roba di tipo ifstream e poi faccio.open posso usarla come booleana per capire se il file con questo nome esiste già
    
    file_to_check_existance.open(filename);
    
    if(file_to_check_existance){
        file_to_check_existance.close();
        cout << "ERRORE!!! ESISTE GIÀ UN ACCOUNT CON QUESTO USERNAME. INSERIRE UN NOME DIVERSO.";
        cin.ignore();
        signup();
        return;
    }
    
    filename.clear();
    
    filename = username;
    
    filename.append(".txt");
    
    ofstream outfile (filename);
    
    cout << "\n\n";
    cout << "Scrivi la tua password: ";
    cin >> password;
    cin.ignore();
    
    outfile << password << endl;
    
    int choose;
    
    cout << "Domande di sicurezza per il recupero della password:" << endl;
    cout << "1. Il nome del tuo animale domestico?" << endl;
    cout << "2. Il nome della via/piazza/corso in cui vivi?" << endl;
    cout << "3. Il tuo sport preferito?" << endl;
    cout << "Per scegliere una domanda digitarne il numero:";
    cin >> choose;
    cin.ignore();
    
    while(choose != 1 && choose != 2 && choose != 3){
        cout << endl;
        cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m o \033[1;7;37m 3 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> choose;
        cin.ignore();
        cout << endl;
    }
    
    string answer;
    
    if(choose == 1){
        
        outfile << "Il nome del tuo animale domestico?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il nome del tuo animale domestico?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        outfile << answer << endl;
        
    }else if(choose == 2){
        
        outfile << "Il nome della via/piazza/corso in cui vivi?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il nome della via/piazza/corso in cui vivi?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        outfile << answer << endl;
        
    }else if(choose == 3){
        
        outfile << "Il tuo sport preferito?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il tuo sport preferito?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        outfile << answer << endl;
        
    }
    
    outfile.close();
    encrypt(filename ,username);
    
    system("clear");
    
    cout << "La registrazione è avvenuta con successo.";
    cin.ignore();
    
    cout << "Ora che ti sei registrato effettua il login.";
    cin.ignore();
    
    login();
}

void account::insert_password(string f_name){
    
    ifstream file_to_open;
    
    string pass_to_check;
    
    string pword;
    
    //string h = username;   //stringa di appoggio, h come help, così non modifico lo username
    
    decrypt(f_name, username);  //dopo che decriptiamo, il file da aprire sarà quello senza _encrypted.txt, quindi sovrascriviamo f_name
    f_name.clear(); //cancello contenuto stringa per sicurezza
    f_name = username;
    f_name = f_name.append(".txt");
    
    file_to_open.open(f_name);
    
    getline(file_to_open, pass_to_check);
    
    file_to_open.close();   //appena abbia acquisito le informazioni che ci interessano lo chiudiamo
    
    encrypt(f_name, username);  //dopo che decriptiamo, il file da aprire sarà quello con _encrypted.txt, quindi sovrascriviamo f_name
    f_name.clear();
    f_name = username;
    f_name = f_name.append("_encrypted.txt");
    
    cout << "\n\n";
    cout << "Inserisci la password: ";
    cin >> pword;
    cin.ignore();
    
    cout << "pword = " << pword << " pass_to_check = " << pass_to_check << endl;
    cin.ignore();
    
    cout << "pword.compare(pass_to_check) = " << pword.compare(pass_to_check) << endl;
    
    if(pword.compare(pass_to_check) == 0){
        cout << "insert_p 201" << endl;
        cin.ignore();
        logged = true;
        cout << "logged = " << logged << endl;  //0 = false, 1 = true
        cout << "insert_p 216" << endl;
        
    }else if(pword.compare(pass_to_check) != 0){
        
        int choose;
        
        cout << "insert_p 224" << endl;
        
        while(pword.compare(pass_to_check) != 0){
            cout << "insert_p 227" << endl;
            cout << "La password inserita e' sbagliata. Digitare \033[1;7;37m 1 \033[0m per reinserire la password, o \033[1;7;37m 2 \033[0m per recuperare la password: ";
            cin >> choose;
            cin.ignore();
            
            while(choose != 1 && choose != 2){
                cout << endl;
                cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
                cin >> choose;
                cin.ignore();
                cout << endl;
            }
            
            if(choose == 1){
                insert_password(f_name);
                return; //se non si mette il return rimane all'infinito dentro questa funzione 
            }else if(choose == 2){
                recover_password(f_name);
                return;
            }
        }
    }
    
    cout << "insert_p 243" << endl;
    //return;
    //cout << "insert_p 245" << endl;
}

void account::recover_password(string f_name){
    
    ifstream file_to_open;
    
    vector<string> read;
    
    string temp;
    
    string question;
    string answer;
    
    string answer_to_check;
    
    decrypt(f_name, username);
    
    f_name.clear();
    f_name = username;
    f_name = f_name.append(".txt");
    
    file_to_open.open(f_name);
    
    while(getline(file_to_open, temp))
        read.push_back(temp);
    
    question = read [1];    //in realtà è un passaggio inutile ma il codice è un pelo più chiaro
    answer = read [2];
    
    file_to_open.close();
    
    encrypt(f_name, username);
    f_name.clear();
    f_name = username;
    f_name = f_name.append("_encrypted.txt");
    
    system("clear");
    
    cout << "Hai scelto di recuperare la password." << endl;
    cout << "La tua domanda di sicurezza e': " << question << endl;
    cout << "La risposta e': ";
    getline(cin, answer_to_check);
    cin.ignore();
        
    int choose;
    
    while(answer.compare(answer_to_check) != 0){
        cout << "\t\t\t\t\t ERRORE, SI LA RISPOSTA INSERITA E' SBAGLIATA." << endl;
        cout << "\t\t\t\t\t Purtroppo se non ricordi la risposta il tuo account e' perso e dovrai crearne uno nuovo." << endl;
        cout << "\t\t\t\t\t Digita \033[1;7;37m 1 \033[0m per riprovare, o \033[1;7;37m 2 \033[0m per creare un nuovo account: " << endl;
        cin >> choose;
        
        while(choose != 1 && choose != 2){
            cout << endl;
            cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
        }
        
        if(choose == 2){
            signup();
            return;
        }
        
        answer_to_check.clear();
        
        cout << "\t\t\t\t\t Riprova la risposta: ";
        getline(cin, answer_to_check);
        cin.ignore();
    }
    
    if(answer.compare(answer_to_check) == 0){  //ci dovrebbe arrivare soltanto se la condizione è soddisfatta
        
        char choose;
        
        cout << "\n\n";
        cout << "La tua password e' " << read [0] << endl;
        cout << "\n\n";
        cout << "Vuoi cambiare la password, se si digita \033[1;7;37m y \033[0m, altrimenti \033[1;7;37m n \033[0m:";
        cin >> choose;
        
        while(choose != 'n' && choose != 'y'){
            cout << "\n";
            cout << "\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m y \033[0m o \033[1;7;37m n \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cout << endl;
        }
        
        system("clear");
        
        if(choose == 'y'){
            change_password(f_name);
        }else{
            cout << "Ora puoi proseguire con il login.";
            cin.ignore();
            insert_password(f_name);
        }
    }
}

void account::change_password(string f_name){   //l'idea è di salvare tutto quello che c'è nel file eliminarlo e crearne una copia con la password diverse
    
    ifstream file_to_open;
    
    vector<string> read;
    
    string new_password;
    
    string temp;

    system("clear");
    
    cout << "Hai scelto di cambiare la password." << endl;
    cout << "Inserisci la nuova password: ";
    getline(cin, new_password);
    
    
    decrypt(f_name, username);
    
    //cin.ignore();
    
    f_name.clear();
    f_name = username;
    f_name = f_name.append(".txt");
    
    file_to_open.open(f_name);
    int i = 0;
    while(getline(file_to_open, temp)){
        read.push_back(temp);   //leggiamo tutto quello che c'è nel file
        cout << " read [i] = " << read [i] << endl;
        i++;
    }
    cin.ignore();
    
    file_to_open.close();
    
    encrypt(f_name, username);
    
    if(new_password.compare(password) == 0){    //se la password nuova coincide con quella vecchia non va bene
        cout << "La password risulta uguale a quella precedente, inserire una password differente.";
        cin.ignore();
        
        f_name.clear();
        f_name = username;
        f_name = f_name.append("_encrypted.txt");
        
        change_password(f_name);
        return;
    }
    
    password = new_password;
    
    char f_to_remove [f_name.length()];
    
    strcpy(f_to_remove, f_name.c_str());
    
    remove(f_to_remove);    //cancelliamo il vecchio file
    
    ofstream newfile(f_name);   //f_name ora ha solo .txt, ofstream apre già il file
    
    newfile << password << endl;    //scriviamo
    newfile << read [1] << endl;
    newfile << read [2] << endl;
    
    newfile.close();    //chiudiamo
    
    encrypt(f_name, username);  //criptiamo
    
    cout << "Ora che hai cambiato la password riesegui il login.";
    cin.ignore();
    
    login();    //ed infine proviamoa fargli fare un login
}


void account::change_question(string f_name){
    ifstream file_to_open;
    
    vector<string> read;
    
    string temp;

    system("clear");
    
    cout << "Hai scelto di cambiare domanda e risposta di sicurezza." << endl;
    
    decrypt(f_name, username);
    
    f_name.clear();
    f_name = username;
    f_name = f_name.append(".txt");
    
    file_to_open.open(f_name);
    
    while(getline(file_to_open, temp))
        read.push_back(temp);
    
    file_to_open.close();
    
    encrypt(f_name, username);
    
    char f_to_remove [f_name.length()];
    
    strcpy(f_to_remove, f_name.c_str());
    
    remove(f_to_remove);
    
    ofstream newfile(f_name);
    
    int choose;
    
    cout << "Domande di sicurezza per il recupero della password:" << endl;
    cout << "1. Il nome del tuo animale domestico?" << endl;
    cout << "2. Il nome della via/piazza/corso in cui vivi?" << endl;
    cout << "3. Il tuo sport preferito?" << endl;
    cout << "Per scegliere una domanda digitarne il numero:";
    cin >> choose;
    cin.ignore();
    
    while(choose != 1 && choose != 2 && choose != 3){
        cout << endl;
        cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m o \033[1;7;37m 3 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> choose;
        cin.ignore();
        cout << endl;
    }
    
    string answer;
    
    newfile << password << endl;
    
    if(choose == 1){
        
        newfile << "Il nome del tuo animale domestico?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il nome del tuo animale domestico?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        newfile << answer << endl;
        
    }else if(choose == 2){
        
        newfile << "Il nome della via/piazza/corso in cui vivi?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il nome della via/piazza/corso in cui vivi?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        newfile << answer << endl;
        
    }else if(choose == 3){
        
        newfile << "Il tuo sport preferito?" << endl;
        system("clear");
        cout << "La domanda che hai scelto e' Il tuo sport preferito?" << endl;
        cout << "Scrivi la risposta alla domanda: ";
        getline(cin, answer);
        cin.ignore();
        newfile << answer << endl;
        
    }
    
    newfile.close();
    
    encrypt(f_name, username);
    
    cout << "Domanda e risposta cambiate con successo.";
    cin.ignore();
}

void account::change_answer(string f_name){
    ifstream file_to_open;
    
    vector<string> read;
    
    string new_answer;
    
    string temp;

    system("clear");
    
    cout << "Hai scelto di cambiare la risposta alla domanda di sicurezza." << endl;
    
    decrypt(f_name, username);
    
    f_name.clear();
    f_name = username;
    f_name = f_name.append(".txt");
    
    file_to_open.open(f_name);
    
    while(getline(file_to_open, temp))
        read.push_back(temp);
    
    file_to_open.close();
    
    encrypt(f_name, username);
    
    char f_to_remove [f_name.length()];
    
    strcpy(f_to_remove, f_name.c_str());
    
    remove(f_to_remove);
    
    
    cout << "La tua domanda di sicurezza e': " << read [1] << endl;
    cout << "La nuova risposta a questa domanda e': ";
    cin >> new_answer;
    
    ofstream newfile(f_name);
    
    newfile << read [0] << endl;    //scriviamo
    newfile << read [1] << endl;
    newfile << new_answer << endl;
    
    newfile.close();
    
    encrypt(f_name, username);
    
    cout << "Risposta cambiata con successo.";
    cin.ignore();
}
    

void account::login(){
    
    string name;
    string pword;
    string filename;
    
    ifstream file_to_open;  //roba utile, che non ho capito benissimo, serve per capire se un file esiste, l'idea credo sia "if stream" quindi in qualche modo se lo posso aprire allora esiste e restituisce true, altrimenti false
    
    system("clear");
    
    cout << "Inserisci il tuo username: ";
    cin >> name;
    cin.ignore();
    
    while(name == other_player){    //così vietiamo il login allo stesso account da entrambi i giocatori
        cout << "ERRORE!!! QUESTO ACCOUNT RISULTA ESSERE GIÀ LOGGATO. DIGITARE UNO USERNAME DIVERSO: ";
        cin >> name;
        cin.ignore();
    }
    
    filename = name;
    filename = filename.append("_encrypted.txt");
    
    file_to_open.open(filename);    //apriamo giusto per controllare se esiste
    
    if(file_to_open){
        
        file_to_open.close();
        
        username = name;
        
        cout << "login 432" << endl;
        
        insert_password(filename);  //arriva qua ancora da decriptare, quindi con estensione _encrypted.txt
        
        cout << "login 437" << endl;
        
        
    }else{
        
        int choose;
        
        cout << "login 443" << endl;
        
        cout << "Un account con questo username non esiste." << endl;
        cout << "Digitare \033[1;7;37m 1 \033[0m se si vuole reinserire lo username, \033[1;7;37m 2 \033[0m per creare un account oppure \033[1;7;37m 3 \033[0m per giocare come ospite:";
        cin >> choose;
        cin.ignore();
        
        while(choose != 1 && choose != 2 && choose != 3){
            cout << endl;
            cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m o \033[1;7;37m 3 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
            cin >> choose;
            cin.ignore();
            cout << endl;
        }
        
        if(choose == 1){
            login();
            return;
        }else if(choose == 2){
            signup();
            return;
        }else if(choose == 3)
            return;
        
    }
}

void account::manage_account(){
    system("clear");
    
    int choose;
    
    cout << "Per cambiare password digitare \033[1;7;37m 1 \033[0m, per cambiare domanda e risposta \033[1;7;37m 2 \033[0m, per cambiare risposta \033[1;7;37m 3 \033[0m, o per uscire \033[1;7;37m 4 \033[0m:";
    cin >> choose;
    cin.ignore();
    
    while(choose != 1 && choose != 2 && choose != 3 && choose != 4){
        cout << endl;
        cout << "\t\t\t\t\t\t\t ERRORE, SI E' INSERITO UN CARATTERE DIVERSO DA \033[1;7;37m 1 \033[0m,  \033[1;7;37m 2 \033[0m, \033[1;7;37m 3 \033[0m o \033[1;7;37m 4 \033[0m. REINSERIRE IL VALORE DESIDERATO: ";
        cin >> choose;
        cin.ignore();
        cout << endl;
    }
    
    string filename;
    
    filename = username;
    filename = filename.append("_encrypted.txt");
    
    switch(choose){
            
        case 1:
            change_password(filename);
            break;
            
        case 2:
            change_question(filename);
            break;
            
        case 3:
            change_answer(filename);
            break;
            
        case 4:
            break;
    }
    
}

string account::getUsername() const{
    return username;
}

bool account::getLogged() const{
    return logged;
}

void account::writeStats(bool victory, bool mode, int n_hit, int n_miss){ //se vince victory = 1, se perde victory = 0; se  ha giocato contro l'umano mode =  1 altrimenti 0

    string filename;

    system("clear");

    filename = username;

    filename.append("_Stats.txt");

    ifstream file_to_check_existance;   //per verificare l'esistenza del file

    file_to_check_existance.open(filename);

    if(!file_to_check_existance){
        //file_to_check_existance.close();
        cout << "File inesistente" << endl;
    }

    file_to_check_existance.close();

    fstream results;

    results.open(filename, ios::app);

    results << victory << "\t" << mode << "\t" << n_hit << "\t" << n_miss << endl;

    results.close();

}
