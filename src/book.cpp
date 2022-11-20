#include "book.h"

/***Costruttori***/

Book::Book() : _name{""}, _surname{""}, _title{""} {}

Book::Book(std::string name_in) : _name{name_in}, _surname{""}, _title{""} {}

Book::Book(std::string name_in, std::string surname_in) : _name{name_in}, _surname{surname_in}, _title{""} {}

Book::Book(std::string name_in, std::string surname_in, std::string title_in) : _name{name_in}, _surname{surname_in}, _title{title_in} {}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in) : _name{name_in}, _surname{surname_in}, _title{title_in}, _isbn{isbn_in} {
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in) {
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    try {
        _isbn = new ISBN(isbn_in);
    } catch (ISBN::InvalidIdentifier e) {
        throw InvalidBook();
    }
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, Date *release_in) : _name{name_in}, _surname{surname_in}, _title{title_in}, _isbn{isbn_in}, _release{release_in} {
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, Date *release_in) {
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    try {
        _isbn = new ISBN(isbn_in);
    } catch (ISBN::InvalidIdentifier e) {
        throw InvalidBook();
    }
    _release = release_in;
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, std::string release_in) {
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    _isbn = isbn_in;
    try {
        _release = new Date(release_in);
    } catch (Date::Invalid e) {
        throw InvalidBook();
    }
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, std::string release_in) {
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    try {
        _isbn = new ISBN(isbn_in);
    } catch (ISBN::InvalidIdentifier e) {
        throw InvalidBook();
    }
    try {
        _release = new Date(release_in);
    } catch (Date::Invalid e) {
        throw InvalidBook();
    }
}

// Operatore di uguaglianza
Book &Book::operator=(Book a) {
    _name = a._name;
    _surname = a._surname;
    _title = a._title;
    _isbn = a._isbn;
    _release = a._release;

    return *this;
}

/***Funzioni Setter***/
void Book::set_name(std::string name_in) {
    _name = name_in;
}

void Book::set_surname(std::string surname_in) {
    _surname = surname_in;
}

void Book::set_title(std::string title_in) {
    _title = title_in;
}

void Book::set_isbn(ISBN *isbn_in) {
    _isbn = isbn_in;
}

void Book::set_release(Date *release_in) {
    _release = release_in;
}

void Book::set_isbn(std::string isbn_in) {
    try {
        _isbn = new ISBN(isbn_in);
    } catch (ISBN::InvalidIdentifier e) {
        throw InvalidBook();
    }
}

void Book::set_release(std::string release_in) {
    try {
        _release = new Date(release_in);
    } catch (Date::Invalid e) {
        throw InvalidBook();
    }
}

void Book::set_available(bool available_in) {
    _available = available_in;
}

//output nello stream con formattazione
std::ostream &operator<<(std::ostream &os, Book a) {
    os << ((a.title() == "") ? "Titolo non presente" : a.title());
    os << "\n"
       << ((a.surname() == "") ? "Cognome non presente" : a.surname()) << ", " << ((a.name() == "") ? "Nome non presente" : a.name()) << "\n";
    try {
        os << *a.isbn();
        os << "\n";
    } catch (Book::FieldNotPresent e) {
        os << "";
    }
    try {
        os << *a.release();
        os << "\n";
    } catch (Book::FieldNotPresent e) {
        os << "";
    }
    return os;
}

//operatore di uguaglianza
bool operator==(Book a, Book b) {
    return (a.name() == b.name() && a.surname() == b.surname() && a.title() == b.title() && a.isbn() == b.isbn() && a.release() == b.release());
}