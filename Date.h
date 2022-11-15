#ifndef DATE_H
#define DATE_H

#include <ostream>
enum class Month {
	def, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
	
	public:
		Date(int y, Month m, int d, bool ex);
		
		class Invalid {};
		
		int year(void) const {return year_;}
		Month month(void) const {return month_;}
		int day(void) const {return day_;}
		bool exist(void) const {return exist_;}
		
	private:
	int year_;
	Month month_;
	int day_;
	bool exist_;		
};

bool is_date(int y, Month month, int d, bool ex);
bool leapyear(int y);

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
