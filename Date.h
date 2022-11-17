#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <string>

enum class Month {
	def, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
	public:
		Date(int y, Month m, int d, bool exist);
		Date(bool exist);
		class Invalid {};
		int year(void) const {return year_;}
		Month month(void) const {return month_;}
		int day(void) const {return day_;}
		bool exist(void) const {return exist_;}
		bool is_date(void);
		static bool leapyear(int y);
		
	
	private:
		int year_;
		Month month_;
		int day_;
		bool exist_;		
};



std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
