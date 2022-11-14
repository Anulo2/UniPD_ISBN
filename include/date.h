#ifndef DATE_H
#define DATE_H


#include <ostream>

class Date {
public:
	class Invalid {}; // per riportare errori
	Date (int y, int m, int d); // check e inizializza
	Date();
	
	int get_day(void) {return d;}
	int get_month(void) {return m;}
	int get_year(void) {return y;}
	
private:
	int y, m, d;
	bool is_valid(void); // ritorna true se la data è valida
	
};

std::ostream& operator<<(std::ostream& os, Date a);
bool operator==(Date a, Date b);

#endif // DATE_H
