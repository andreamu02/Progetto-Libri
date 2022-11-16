#ifndef ISBN_H
#define ISBN_H

#include <string>
#include <ostream>

class Isbn{	
	public:
		Isbn(std::string first, std::string second, std::string third, std::string last);
		std::string str_ISBN(void);
		std::string first(void) const { return first_;}
		std::string second(void) const { return second_;}
		std::string third(void) const { return third_;}
		std::string last(void) const { return last_;}	
	private:
		std::string first_;
		std::string second_;
		std::string third_;
		std::string last_;
		bool is_valid(void);
};

std::ostream& operator<<(std::ostream& os, const Isbn& t);

#endif
