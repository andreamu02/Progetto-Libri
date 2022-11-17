#include <iostream>
#include "Book.cpp"

std::string validity_ISBN(std::string a);
std::string trim(std::string a);

int main(void){                                 // MANCANZA DI CONTROLLO ERRORI //
  // --- INSERIMENTO NOME
    std::cout << " Inserire le informazioni del libro una ad una come segue, premendo invio dopo ogni inserimento.\n Nome: ";
    std::string name = "";
    do{
        std::cin >> name;
        name = trim(name);
        if(name == ""){
            std::cout << " Nome non valido, reinserire: ";
        }
    }while(name == "");
    
  // --- INSERIMENTO COGNOME
    std::cout << " Cognome: ";
    std::string surname = "";
    do{
        std::cin >> surname;
        surname = trim(surname);
        if(surname == ""){
            std::cout << " Cognome non valido, reinserire: ";
        }
    }while(surname == "");
    
  // --- INSERIMENTO TITOLO
    std::cout << " Titolo: ";
    std::string title = "";
    do{
        std::cin >> title;
        title = trim(title);
        if(title == ""){
            std::cout << " Cognome non valido, reinserire: ";
        }
    }while(title == "");
    
  // --- INSERIMENTO ISBN
    std::cout << " ISBN (Si può inserire separato da un limitatore come underscore o spazio oppure tutto attaccato: ";
    std::string isbn = "";
    do{
        std::cin >> isbn;
        isbn = trim(isbn);
        isbn = validity_ISBN(isbn);
        if(isbn == ""){
            std::cout << " ISBN non valido, reinserire: ";
        }
    }while(isbn == "");
    
  // --- INSERIMENTO DATA
    bool choice;
    std::cout << " Il libro ha una data di copyright attivo? (y/n): ";
    std::string t = "";
    do{
        std::cin >> t;
        if(t != "Y" && t != "y" && t!= "N" && t != "n"){
            t = "";
        }else  if(t == "Y" || t == "y"){
            choice == true;
        }else if(t!= "N" || t != "n"){
            choice = false;
        }
    }while(t == "");
    
    int day, month, year;
    if(choice){
        std::cout << " Data di opyright (formato dd mm aaaa): ";
        std::cin >> day;
        std::cin >> month;
        std::cin >> year;
    }
    
  // --- PRESTITO
    bool checkout;
    std::cout << " Il libro \212 in prestito? (y,n) ";
    t = "";
    do{
        std::cin >> t;
        if(t != "Y" && t != "y" && t!= "N" && t != "n"){
            t = "";
        }else  if(t == "Y" || t == "y"){
            checkout == true;
        }else if(t!= "N" || t != "n"){
            checkout = false;
        }
    }while(t == "");
    
  // --- COSTRUTTORE CLASSE
  // Book book();
    return 0;
}



// --- FUNZIONE CONTROLLO LUNGHEZZA ISBN --- //
std::string validity_ISBN(std::string a){
    if(a.length()!= 10 && a.length()!= 13){
        return "";
    }
    if(a.length() == 13){
        a.replace(3, 1, "");
        a.replace(6, 1, "");
        a.replace(9, 1, "");
    }
    return a;
}
    

// --- FUNZIONE PER RIMUOVERE SPAZI NON NECESSARI A INIZIO E FINE STRINGA --- //
std::string trim(std::string a){
    int i = 0;
    for(i = 0; i<a.length(); i++){
        if(a[i] != ' '){
            break;
        }
    }
    std::string t = a.substr(i, a.length());
    for(i = t.length()-1; i>=0; i--){
        if(t[i] != ' '){
            break;
        }
    }
    t = t.substr(0, i+1);
    return t;
}
    
