#include "Book.h"
#include <stdexcept>


// --- IMPLEMENTAZIONE ISBN --- //

Isbn::Isbn(std::string first, std::string second, std::string third, std::string last)
	: first_ {first}, second_ {second}, third_ {third}, last_{last}
	{
		if(!is_valid()){
			throw std::invalid_argument();
		}
	}
	
bool Isbn::is_valid(void){
	if(first_.length()!=3){
		return false;
	}
	int t;
	try{
		t = stoi(first_);
	}catch(std::invalid_argument() ){ return false;}
	
	if(second_.length()!=3){
		return false;
	}
	try{
		t = stoi(second_);
	}catch(std::invalid_argument() ){ return false;}
	
	if(third_.length()!=3){
		return false;
	}
	try{
		t = stoi(third_);
	}catch(std::invalid_argument() ){return false;}
	
	if(last_.length()!=1){
		return false;
	}
	return true;
}


// --- IMPLEMENTAZIONE DATE --- //

Date::Date(int yy, Month mm, int dd, bool ex)
	: year_{yy}, month_{mm}, day_{dd}, exist_{ex}
{
	if (!is_date(yy, mm, dd, ex))
		throw Invalid{};
}

bool Date::is_date(int y, Month m, int d, bool ex)
{
	if (!ex)
		return true;
	if (y <= 0 || d <= 0)
		return false;
	if (m < Month::jan || Month::dec < m)
		return false;
	
	int days_in_month = 31;
	
	switch (m) {
		case MOnth::feb:
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov: 
			days_in_month = 30;
			break;
	}	
	
	if (days_in_month < d)
		return false;

	return true;
}

//DA IMPLEMENTARE
bool leapyear(int y) {
	return false;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	if (!d.exist())
		return os << "";
	return os << d.day() << '/' << d.month() << '/' << d.year();
}

//IMPLEMENTAZIONE BOOK -----------------------------
//costruttori ...

Book::Book(std::string name, std::string surname, std::string title, std::string ISBN, bool checkout = DefaultCheckout)
	: name_ {name}, surname_ {surname}, title_ {title}, ISBN_ {new Isbn(ISBN.substr(0,3), ISBN.substr(3,3), ISBN.substr(6,3), ISBN.substr(9,1))}, copyright {nullptr}, checkout_ {checkout}
{
	if(!can_be_name(name()){
		cout << "Invalid";
	}
	if(!can_be_name(surname()){
		cout << "Invalid";
	}
}
	   
Book::Book(std::string name, std::string surname, std::string title, std::string ISBN, int day, Month month, int year, bool checkout = DefaultCheckout)
	: name_ {name}, surname_ {surname}, title_ {title}, ISBN_ {new Isbn {ISBN.substr(0,3), ISBN.substr(3,3), ISBN.substr(6,3), ISBN.substr(9,1)}}, copyright {new Date {day, month, year}}, checkout_ {checkout}
{
	if(!can_be_name(name()){
		cout << "Invalid";
	}
	if(!can_be_name(surname()){
		cout << "Invalid";
	}
}

static bool Book::can_be_name(std::string a){
	for(int i = 0; i<a.length(); i++){
		if("ABCDEFGHIJKLMNOPQRSTUVWXYZ'- ".find(toupper(a[i])) == std::string::npos){
			return false;
		}
	return true;
	}
}

void Book::lent(){
	checkout_ = true;
}
void Book::restituted() {
	checkout_ = false;
}

bool Book::exist_date(void){
	return month_
}
bool operator==(Book a, Book b) {
	return a.ISBN() == b.ISBN();
}
bool operator!=(Book a, Book b) {
	return !(a == b);
}
std::ostream& operator<<(std::ostream& os, Book a) {
	std::string t = a.title() + "\n" + a.name() + " " + a.surname();
	if(a.valid()){
		t = t + "\n" + a.day() + " " + a.month() + " " + a.year();
	}
  if(!a.checkout()){
    t = t + "\nNON ";
  }
  t = t + "IN PRESTITO";
	return os << t;
}
