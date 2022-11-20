#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <string>

enum class Month {
	def = 0, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
	public:
		// costruttori
		Date(int day, Month month, int year, bool exist);
		Date(bool exist);
		// classe per la gestione degli errori
		class Invalid {};
		// metodi getter
		int year(void) const {return year_;}
		Month month(void) const {return month_;}
		int day(void) const {return day_;}
		bool exist(void) const {return exist_;}
		// metodi ausiliari
		bool is_date(void);
		bool leapyear(void);
		std::string str_copyright(void) const;
		std::string month_to_int(void) const;
		
	private:
		int year_;
		Month month_;
		int day_;
		bool exist_;			
};

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
