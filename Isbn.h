#ifndef ISBN_H
#define ISBN_H

#include <string>

class Isbn{
	
	public:
		Isbn(std::string first, std::string second, std::string third, std::string last);
		std::string str_ISBN(void);
		
	private:
		std::string first_;
		std::string second_;
		std::string third_;
		std::string last_;
		bool is_valid(void);
};

#endif
