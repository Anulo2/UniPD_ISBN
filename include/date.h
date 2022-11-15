#ifndef DATE_H
#define DATE_H


#include <ostream>

#include <iostream>

class Date {
public:
	
	Date (int y, int m, int d); // check e inizializza
	
	int get_day(void) {return d;}
	int get_month(void) {return m;}
	int get_year(void) {return y;}

	class Invalid {}; // per riportare errori
	
private:
	int y, m, d;
	bool is_valid(void); // ritorna true se la data è valida
	
};

std::ostream& operator<<(std::ostream& os, Date &a);
std::ostream& operator<<(std::ostream& os, Date *a);
bool operator==(Date a, Date b);

bool is_leap(int year);

#endif // DATE_H
