#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Isbn.h"

class Book{
	public:
		//costruttore
		Book(std::string name, std::string surname, std::string title, std::string ISBN, bool checkout = DefaultCheckout);
		Book(std::string name, std::string surname, std::string title, std::string ISBN, int day, Month month, int year, bool checkout = DefaultCheckout);
	
		//metodi getter
		std::string title(void) const { return title_;}
		std::string name(void) const { return name_;}
		std::string surname(void) const { return surname_;}
		std::string ISBN(void) {return ISBN_.str_ISBN();}
		Date copyright(void) const {return copyright_;}
		bool is_checked_out(void) const {return checkout_;}
		
		//metodi per registrare il prestito e la restituzione
		void lent();
		void restituted();

		bool can_be_name();
		bool can_be_surname(void);
			
	private:
		std::string title_;
		std::string name_;
		std::string surname_;
		Isbn ISBN_;
		Date copyright_;
		bool checkout_;
	
		static const bool DefaultCheckout = false;
};

bool operator==(Book a, Book b);
bool operator!=(Book a, Book b);
std::ostream& operator<<(std::ostream& os, Book a);
		
#endif
