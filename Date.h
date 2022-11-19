#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <string>

enum class Month {
	def = 0, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
	public:
		Date(int day, Month month, int year, bool exist);
		Date(bool exist);
		class Invalid {};
		int year(void) const {return year_;}
		Month month(void) const {return month_;}
		int day(void) const {return day_;}
		bool exist(void) const {return exist_;}
		
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
