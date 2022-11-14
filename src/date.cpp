#include "date.h";

Date::Date(int yy, int mm, int dd) : y (yy), m(mm), d(dd){
	if (!is_valid()) throw Invalid();
}

bool Date::is_valid(){
	if (m < 1 || m > 12) return false;
	if (d > length[m] || d < 1) return false;
}

std::ostream& operator<<(std::ostream& os, Date a){
	return os << a.get_year() << "/" << a.get_month() << "/" << a.get_day();
}