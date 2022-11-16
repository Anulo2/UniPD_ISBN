#ifndef DATE_H
#define DATE_H


#include <ostream>
#include <vector>


class Date {
public:
	
	Date (int y, int m, int d); // check e inizializza
	Date (std::string date);
	
	int get_day(void) {return d;}
	int get_month(void) {return m;}
	int get_year(void) {return y;}

	class Invalid {}; // per riportare errori
	
private:
	int y, m, d;
	bool is_valid(void); // ritorna true se la data è valida
	bool is_leap(void);
	
	
};

std::ostream& operator<<(std::ostream& os, Date &a);
std::ostream& operator<<(std::ostream& os, Date *a);
bool operator==(Date a, Date b);


#endif // DATE_H
