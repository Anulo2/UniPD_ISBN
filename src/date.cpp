#include "date.h"

//Array che definisce la lunghezza di ogni mese
static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


Date::Date(int yy, int mm, int dd) : y {yy}, m{mm}, d{dd}{
	if (!is_valid()) throw Invalid();
}

Date::Date(std::string date){
	std::vector<std::string> fields;
	int start = 0;
    int end = date.find("/");
    while (end != -1) {
        fields.push_back(date.substr(start, end - start));
        start = end + 1;
        end = date.find("/", start);
    }

    fields.push_back(date.substr(start, end - start));
    
    y = std::stoi(fields[0]);
    m = std::stoi(fields[1]);
    d = std::stoi(fields[2]);
    if (!is_valid()) throw Invalid();
}

//Controllo della validità della data su mese e giorno
bool Date::is_valid(){
	if (m < 1 || m > 12) return false;
	bool leap = is_leap();
	if (d > ((m == 2) ? (leap ? 29 : 28) : length[m])|| d < 1) return false; //TODO: fare con conto per anni bisestili.
	return true;
}

//Controllo dell'anno bisestile
bool Date::is_leap(){
	if (y % 400 == 0)
        return true;
 
    if (y % 100 == 0)
        return false;
 
    if (y % 4 == 0)
        return true;
    return false;
}


//Output nello stream formattato
std::ostream& operator<<(std::ostream& os, Date &a){
	return os << a.get_year() << "/" << a.get_month() << "/" << a.get_day();
}

//Output nello stream
std::ostream& operator<<(std::ostream& os, Date *a){
    os << *a;
	return os;
}

//Operatore di uguaglianza
bool operator==(Date a, Date b){
	return (a.get_year() == b.get_year()) && (a.get_month() == b.get_month())  && (a.get_day() == b.get_day());
}

