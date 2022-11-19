#include <iostream>
#include "Book.cpp"
#include <vector>

std::string validity_ISBN(std::string a);
std::string trim(std::string a);
std::string get_name(void);
std::string get_surname(void);
std::string get_title(void);
std::string get_ISBN(void);
Date get_date(void);
bool checked_out(void);
Month int_to_Month(int x);
void print(std::vector<Book>& x);
void print_checked(std::vector<Book>& x);
void print_copyright(std::vector<Book>& x);
void print_complete(std::vector<Book>& x);

int main(void){                                 // MANCANZA DI CONTROLLO ERRORI //
    std::cout << " Programma di simulazione biblioteca/prestito libri.\n Per favore, indicare quanti libri si desiderano archiviare: ";
    int n;
    bool help = true;
    while(help){
        try{
        	std::string in;
            std::cin >> in;
            n = std::stoi(in);
            help = false;
        }catch(std::invalid_argument){
            std::cout << " Dati immessi non corretti, reinserire: ";
            help = true;
        }
        if(n<1){
            help = true;
        }
    }
    std::vector<Book> books;
    int i = 0;
    while(i<n){
        try{
            books.push_back(Book {get_name(), get_surname(), get_title(), get_ISBN(), get_date(), checked_out()});
            i++;
        }catch(Book::Invalid e){
        	std::cout << "Libro invalid";
        }
        catch (Date::Invalid e) {
        	std::cout << "Data non valida";
        }
    }
    
    bool end = true;
    while(end){
        try{
            int scelta;
            std::cout << "\n Scegli l'operazione da fare:\n 1 - AGGIUNGI UN LIBRO\n 2 - RIMUOVI UN LIBRO\n 3 - GESTISCI PRESTITO\n 4 - AGGIUNGI/RIMUOVI COPYRIGHT\n 5 - MODIFICA INFORMAZIONI LIBRO\n 6 - ESCI\n -> ";
            std::cin >> scelta;
            switch(scelta){
                case 1:
                    books.push_back(Book {get_name(), get_surname(), get_title(), get_ISBN(), get_date(), checked_out()});
                    break;
                case 2:
                    if(books.size() == 0){
                        std::cout << " Impossibile rimuovere un libro. Elenco gia' vuoto.\n";
                    }else{
                        std::cout << " Seleziona il libro che vuoi rimuovere dall'elenco\n";
                        print(books);
                        std::cout << "\n -> ";
                        int i = 0;
                        while(i<1){
                            try{
                            	std::string in;
            					std::cin >> in;
           	 					i = std::stoi(in);
                             }catch(std::invalid_argument){
                                i = 0;
                                std::cout << " Dato immesso non valido. Reinserire: ";
                            }
                            if(i<1 || i>books.size()){
                                std::cout << " Numero non accettato. Reinserire: ";
                                i = 0;
                            }
                        }
                        i = i-1;
                        books.erase(books.begin()+i);
                    }
                    break;
                case 3: 
                    if(books.size() == 0){
                        std::cout << " Elenco vuoto.\n";
                    }else{
                        std::cout << " Seleziona il libro dall'elenco\n";
                        print_checked(books);
                        std::cout << "\n -> ";
                        int i = 0;
                        while(i<1){
                            try{
                                std::string in;
            					std::cin >> in;
           	 					i = std::stoi(in);
                             }catch(std::invalid_argument){
                                i = 0;
                                std::cout << " Dato immesso non valido. Reinserire: ";
                            }
                            if(i<1 || i>books.size()){
                                std::cout << " Numero non accettato. Reinserire: ";
                                i = 0;
                            }
                        }
                        i--;
                        if(books[i].is_checked_out()){
                            books[i].restituted();
                        }else{
                            books[i].lent();
                    	}
                    }	
                    break;
                case 4:
                	if(books.size() == 0){
                        std::cout << " Elenco vuoto, impossibile modificare una data.\n";
                    }else{
                    	std::cout << " Seleziona il libro dall'elenco\n";
                        print_copyright(books);
                        std::cout << "\n -> ";
                        int i = 0;
                        while(i<1){
                            try{
                                std::string in;
            					std::cin >> in;
           	 					i = std::stoi(in);
                             }catch(std::invalid_argument){
                                i = 0;
                                std::cout << " Dato immesso non valido. Reinserire: ";
                            }
                            if(i<1 || i>books.size()){
                                std::cout << " Numero non accettato. Reinserire: ";
                                i = 0;
                            }
                        }
                        i--;
                        Date new_date {false};
                        if (!books[i].copyright().exist()) {
                        	std::cout << " Inserisci una data: ";
                        	new_date = get_date();
                        	books[i].set_copyright(new_date);
                        }
                        else {
                        	books[i].set_copyright(new_date);
                        	std::cout << " Data rimossa";
                        }
                    }
                    break;
                case 5:
                	if(books.size() == 0){
                        std::cout << " Elenco vuoto, impossibile modificare un libro.\n";
                    }else{
                    	std::cout << " Seleziona il libro dall'elenco\n";
                        print_complete(books);
                        std::cout << "\n -> ";
                        int i = 0;
                        while(i<1){
                            try{
                                std::string in;
            					std::cin >> in;
           	 					i = std::stoi(in);
                             }catch(std::invalid_argument){
                                i = 0;
                                std::cout << " Dato immesso non valido. Reinserire: ";
                            }
                            if(i<1 || i>books.size()){
                                std::cout << " Numero non accettato. Reinserire: ";
                                i = 0;
                            }
                        }
                        i--;
                        std::cout << " Cosa vuoi modificare?\n";
                        std::cout << " 1 - MODIFICA NOME\n 2 - MODIFICA COGNOME\n 3 - MODIFICA TITOLO\n 4 - MODIFICA ISBN\n ->";
                        // serie di case e break per gestire 
                    }  
                    break;
                case 6:
                    end = false;
                    std::cout << " Grazie.\n Terminazione programma.\n";
                    break;
                default:
                    std::cout << " Dato immesso non valido.\n";
                    break;
    			}
        	}catch(std::invalid_argument){ std::cout << " Dato immesso non valido.\n";}
        }
    return 0;
}


// --- GET NAME --- //
std::string get_name(void){
  std::cout << " Nome: ";
  std::string name = "";
  do{
      std::cin >> name;
      name = trim(name);
      if(name == ""){
          std::cout << " Nome non valido, reinserire: ";
      }
  }while(name == "");
  return name;
}


// --- GET SURNAME --- //
std::string get_surname(void){
  std::cout << " Cognome: ";
  std::string surname = "";
  do{
      std::cin >> surname;
      surname = trim(surname);
      if(surname == ""){
          std::cout << " Cognome non valido, reinserire: ";
      }
  }while(surname == "");
  return surname;
}


// --- GET TITLE --- //
std::string get_title(void){
  std::cout << " Titolo: ";
  std::string title = "";
  do{
      std::cin >> title;
      title = trim(title);
      if(title == ""){
          std::cout << " Cognome non valido, reinserire: ";
      }
  }while(title == "");
  return title;
}


// --- GET ISBN --- //
std::string get_ISBN(void){
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
    return isbn;
}


// --- GET DATE --- // controllare che siano numeri e non lettere
Date get_date(void){
    bool choice;
    std::cout << " Il libro ha una data di copyright attivo? (y/n): ";
    std::string t = "";
    do{
        std::cin >> t;
        t = trim(t);
        if(t != "Y" && t != "y" && t!= "N" && t != "n"){
            t = "";
        }else  if(t == "Y" || t == "y"){
            choice = true;
        }else if(t== "N" || t == "n"){
            choice = false;
        }
    }while(t == "");
    
    int day, month, year;
    bool date_invalid = true;
    if (choice)
    {
		std::cout << " Data di copyright (formato dd mm aaaa): ";
		while (date_invalid)
		{
			try
			{
				std::cin >> day;
				std::cin >> month;
				std::cin >> year;
				Date x {day, int_to_Month(month), year, choice};
				date_invalid = false;
				return x;
			
			} catch (Book::Invalid e) {
				std::cout << " Data non valida, reinserire: ";
			}
		}
	}
	Date x {choice};
	return x;
}

 
// --- IS CHECKED OUT --- //
bool checked_out(void){
    bool checkout;
    std::cout << " Il libro \212 in prestito? (y,n) ";
    std::string t = "";
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
    return checkout;
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
    
    
// --- FROM INT TO MONTH --- //
Month int_to_Month(int x){
    if(x<1 || x>12){
        throw Book::Invalid();
    }
    Month months[12] {Month::jan, Month::feb, Month::mar, Month::apr, Month::may, Month::jun, Month::jul, Month::aug, Month::sep, Month::oct, Month::nov, Month::dec};
    return months[x];
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
  
// --- FUNZIONI PER STAMPARE LIBRI --- //
void print(std::vector<Book>& x){
    for(int i  = 0; i<x.size(); i++){
        std::cout << " " << (i+1) << " - " << x[i].title() << std::endl;
    }
    return;
}
    
void print_checked(std::vector<Book>& x){
    for(int i  = 0; i<x.size(); i++){
        if(x[i].is_checked_out()){
            std::cout << " " << (i+1) << " - " << x[i].title() << " - in prestito\n";
        }else{
            std::cout << " " << (i+1) << " - " << x[i].title() << " - non in prestito\n";
    	}
    }
    return;
}

void print_copyright(std::vector<Book>& x){
    for(int i  = 0; i<x.size(); i++){
        if(x[i].copyright().exist()){
            std::cout << " " << (i+1) << " - " << x[i].title() << " - " << x[i].copyright() << std::endl;
        }else{
            std::cout << " " << (i+1) << " - " << x[i].title() << std::endl;
    	}
    }
    return;
}
    
void print_complete(std::vector<Book>& x) {
	for(int i  = 0; i<x.size(); i++){
        std::cout << " " << (i+1) << " - " << x[i].title() << " - " << x[i].name() << " - " << x[i].surname() << " - " << x[i].ISBN() << std::endl;
    }
	return;
}
