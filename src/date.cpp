#include "date.h"

// Array che definisce la lunghezza di ogni mese
static int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//costruttori
Date::Date(int yy) : y{yy} {
    if (!is_valid()) throw Invalid();
}

Date::Date(int yy, int mm) : y{yy}, m{mm} {
    if (!is_valid()) throw Invalid();
}

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
    if (!is_valid()) throw Invalid();
}

//costruttore di Date con stringa
Date::Date(std::string date) {
    std::vector<std::string> fields;
    int start = 0;
    int end = date.find("/");
    while (end != -1) {
        fields.push_back(date.substr(start, end - start));
        start = end + 1;
        end = date.find("/", start);
    }

    fields.push_back(date.substr(start, end - start));
    
    //ogni campo inserito nella data viene convertito
    //in un valore intero e salvato nelle apposite variabili

    y = to_int(fields[0]);

    if (fields.size() > 1) {
        m = to_int(fields[1]);
        if (fields.size() > 2) {
            d = to_int(fields[2]);
        }
    }

    if (!is_valid()) throw Invalid();
}

//conversione della data (stringa) in un numero intero
int Date::to_int(std::string in) {
    int result = 0;
    for (char& c : in) {
        if (c >= '0' && c <= '9') {
            result = result * 10 - (c - '0');
        } else {
            throw Invalid();
        }
    }
    return -result;
}

// Controllo della validità della data su mese e giorno
bool Date::is_valid() {
    if (y >= 2023) return false;
    if (m != 0 && m < 1 || m > 12) return false;
    bool leap = is_leap();
    if (d != 0 && (d > ((m == 2) ? (leap ? 29 : 28) : length[m]) || d < 1)) return false;
    return true;
}

// Controllo dell'anno bisestile
bool Date::is_leap() {
    if (y % 400 == 0)
        return true;

    if (y % 100 == 0)
        return false;

    if (y % 4 == 0)
        return true;
    return false;
}

// Output nello stream formattato
std::ostream& operator<<(std::ostream& os, Date& a) {
    os << a.get_year();
    if (a.get_month() != 0) {
        os << "/" << a.get_month();
        if (a.get_day() != 0) {
            os << "/" << a.get_day();
        }
    }
    return os;
}

// Output nello stream
std::ostream& operator<<(std::ostream& os, Date* a) {
    os << *a;
    return os;
}

// Operatore di uguaglianza
bool operator==(Date a, Date b) {
    return (a.get_year() == b.get_year()) && (a.get_month() == b.get_month()) && (a.get_day() == b.get_day());
}

// operatore di assegnazione
Date& Date::operator=(Date a) {
    y = a.y;
    m = a.m;
    d = a.d;

    return *this;
}