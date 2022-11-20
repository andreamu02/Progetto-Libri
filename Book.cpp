#include "Book.h"
#include <stdexcept>

// --- IMPLEMENTAZIONE ISBN --- //

Isbn::Isbn(std::string first, std::string second, std::string third, std::string last)
	: first_ {first}, second_ {second}, third_ {third}, last_{last}
	{
		if(!is_valid()) {
			throw Isbn::invalid_isbn();

		}
	}
	
bool Isbn::is_valid(void) {
	if(first_.length()!=3){
		return false;
	}
	int t;
	try{
		t = stoi(first_);
	}catch(std::invalid_argument() )
	{ return false;}
	
	if(second_.length()!=3){
		return false;
	}
	try{
		t = stoi(second_);
	}catch(std::invalid_argument() )
	{ return false;}
	
	if(third_.length()!=3){
		return false;
	}
	try{
		t = stoi(third_);
	}catch(std::invalid_argument() )
	{return false;}
	
	if(last_.length()!=1){
		return false;
	}else{
		try{
			t = stoi(last_);
		}catch(std::invalid_argument() ){
			if (!(last_[0] >= 'A' && last_[0] <= 'Z' || last_[0] >= 'a' && last_[0] <= 'z')){
				return false;
			}
		}
	}	
	return true;
}

std::string Isbn::str_ISBN(void) const {
	std::string t {first_ + "-" + second_ + "-" + third_ + "-" + last_};
	return t;
}




// --- IMPLEMENTAZIONE DATE --- //

Date::Date(int day, Month month, int year, bool exist)
	: day_{day}, month_{month}, year_{year}, exist_{exist}
{
	if (!is_date())
		throw Date::invalid_date();

}

Date::Date(bool exist)
	: day_{0}, month_ {Month::def}, year_ {0}, exist_{exist}

{
	if(exist_ == true){
		throw Date::invalid_date();
	}
}


bool Date::is_date(void) {
	if (!exist_)
		return true;
	if (year_ <= 0 || day_ <= 0)
		return false;
	if (month_ < Month::jan || Month::dec < month_)
		return false;
	
	int days_in_month = 31;
	
	switch (month_) {
		case Month::feb:
			days_in_month = (leapyear()) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov: 
			days_in_month = 30;
			break;
		default:
			break;
	}	
	
	if (days_in_month < day_)
		return false;

	return true;
}

bool Date::leapyear(void) {
	if(year()%400 == 0){
		return true;
	}
	if(year()%4 == 0){
		if(!(year()%100 == 0)){
			return true;
		}
	}
	return false;
}

std::string Date::month_to_int(void) const {

	if (month()<Month::jan || month()>Month::dec){
		throw Date::invalid_date();
	}
	return std::to_string(int(month()));
}

std::string Date::str_copyright(void) const {
	return std::to_string(day_) + " " + month_to_int() + " " + std::to_string(year_);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
	if (!d.exist()){
		return os;
	}
	return os << d.day() << " " << d.month_to_int() << " " << d.year();
}


// --- IMPLEMENTAZIONE BOOK --- //
	   
Book::Book(std::string name, std::string surname, std::string title, std::string ISBN, Date copyright, bool checkout)
	: name_ {name}, surname_ {surname}, title_ {title}, ISBN_ {ISBN.substr(0,3), ISBN.substr(3,3), ISBN.substr(6,3), ISBN.substr(9,1)}, copyright_ {copyright}, checkout_ {checkout}
{
	if(!can_be_name()){
		throw Book::invalid_arguments();
	}
	if(!can_be_surname()){
		throw Book::invalid_arguments();

	}
}

bool Book::can_be_name(void) {
	std::string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ'- ";
	for(int i = 0; i<name().length(); i++){
		if(temp.find(toupper(name()[i])) == std::string::npos){
			return false;
		}
	}
	return true;
}

bool Book::can_be_surname(void) {
	std::string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ'- ";
	for(int i = 0; i<surname().length(); i++){
		if(temp.find(toupper(surname()[i])) == std::string::npos){
			return false;
		}
	}
	return true;
}

void Book::lent() {
	checkout_ = true;
}

void Book::restituted() {
	checkout_ = false;
	return;
}

bool operator==(Book a, Book b) {
	return a.ISBN() == b.ISBN();
}

bool operator!=(Book a, Book b) {
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, Book a) {
	std::string t = a.title() + "\n" + a.name() + " " + a.surname();
	t = t + "\n" + a.ISBN();
	
	if(a.copyright().exist()){
		t = t + "\n" + a.copyright().str_copyright();
	}
	
	t = t + "\n";
  	if(!a.is_checked_out()){
    	t = t + "NON ";
 	 }
 	t = t + "IN PRESTITO";
 	
	return os << t;
}

void Book::set_name(std::string name) {
	name_ = name;
	return;
}

void Book::set_surname(std::string surname) {
	surname_ = surname;
	return;
}

void Book::set_title(std::string title) {
	title_ = title;
	return;
}

void Book::set_ISBN(std::string ISBN) {
	ISBN_ = {ISBN.substr(0,3), ISBN.substr(3,3), ISBN.substr(6,3), ISBN.substr(9,1)};
	return;
}

void Book::set_copyright(Date copyright) {
	copyright_ = copyright;
	return;
}
