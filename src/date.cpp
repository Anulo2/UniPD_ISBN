#include "date.h"

static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int yy, int mm, int dd) : y {yy}, m{mm}, d{dd}{
	if (!is_valid()) throw Invalid();
}

Date::Date() : y{0}, m{0}, d{0}{
	
}

bool Date::is_valid(){
	if (m < 1 || m > 12) return false;
	if (d > length[m] || d < 1) return false; //TODO: fare con conto per anni bisestili.
	return true;
}

std::ostream& operator<<(std::ostream& os, Date a){
	return os << a.get_year() << "/" << a.get_month() << "/" << a.get_day();
}

bool operator==(Date a, Date b){
	return (a.get_year() == b.get_year()) && (a.get_month() == b.get_month())  && (a.get_day() == b.get_day());
}