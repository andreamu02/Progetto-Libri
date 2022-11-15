#ifndef BOOK_H
#define BOOK_H

//#include <string>
//#include <ostream>
#include "Date.h"
#include "Isbn.h"

class Book{

	public:
		//costruttore
		Book(std::string name, std::string surname, std::string title, std::string ISBN, int day = DefaultDay, Month month = DefaultMonth, int year = DefaultYear, bool checkout = DefaultCheckout);
	
		//metodi setter
		std::string title(void){ return title_;}
		std::string name(void){ return name_;}
		std::string surname(void){ return surname_;}
		std::string ISBN(void){return ISBN_.str_ISBN(); }
		Date date(void){return copyright_;}
		bool is_checked_out(void){return checkout_;}
		
		//metodi per registrare il prestito e la restituzione
		void lent();
		void restituted();
			
	private:
		std::string title_;
		std::string name_;
		std::string surname_;
		Isbn ISBN_;
		Date copyright_;
		bool checkout_;
		
		static constexpr int DefaultDay = 00;
		static constexpr Month DefaultMonth = Month::def;
		static constexpr int DefaultYear = 0000;
		static constexpr bool DefaultCheckout = false;
};

bool operator==(Book a, Book b);
bool operator!=(Book a, Book b);
std::ostream& operator<<(std::ostream& os, Book a);
		
#endif
