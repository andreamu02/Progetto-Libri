#ifndef ISBN_H
#define ISBN_H

#include <string>
#include <iostream>

class Isbn {	
	public:
		// costruttore
		Isbn(std::string first, std::string second, std::string third, std::string last);
		
		// metodi getter
		std::string str_ISBN(void) const;
		std::string first(void) const { return first_;}
		std::string second(void) const { return second_;}
		std::string third(void) const { return third_;}
		std::string last(void) const { return last_;}	
		
		// classe per la gestione degli errori
		class invalid_isbn{};
	private:
		std::string first_;
		std::string second_;
		std::string third_;
		std::string last_;
		bool is_valid(void);
};

std::ostream& operator<<(std::ostream& os, const Isbn& t);

#endif
