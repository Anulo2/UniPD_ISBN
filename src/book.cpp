#include "book.h"

/***Costruttori***/

Book::Book() : _name{""}, _surname{""}, _title{""} {}

Book::Book(std::string name_in) : _name{name_in}, _surname{""}, _title{""}{}

Book::Book(std::string name_in, std::string surname_in) : _name{name_in}, _surname{surname_in}, _title{""}{}

Book::Book(std::string name_in, std::string surname_in, std::string title_in) : _name{name_in}, _surname{surname_in}, _title{title_in}{}


Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in):
_name{name_in}, _surname{surname_in}, _title{title_in}, _isbn{isbn_in} {

}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in){
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    _isbn = new ISBN(isbn_in);
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, Date *release_in):
_name{name_in}, _surname{surname_in}, _title{title_in}, _isbn{isbn_in}, _release{release_in}{

}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, Date *release_in){
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    _isbn = new ISBN(isbn_in);
    _release = release_in;
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, std::string release_in){
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    _isbn = isbn_in;
    _release = new Date(release_in);   
}

Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, std::string release_in){
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    _isbn = new ISBN(isbn_in);
    _release = new Date(release_in);
}

//Operatore di uguaglianza
Book& Book::operator=(Book a){
    _name = a._name;
    _surname = a._surname;
    _title = a._title;
    _isbn = a._isbn;
    _release = a._release;
    
    return *this;
}

/***Funzioni Setter***/
void Book::set_name(std::string name_in){
    _name = name_in;
}

void Book::set_surname(std::string surname_in){
    _surname = surname_in;
}

void Book::set_title(std::string title_in){
    _title = title_in;
}

void Book::set_isbn(ISBN isbn_in){
    _isbn = &isbn_in;
}

void Book::set_release(Date release_in){
    _release = &release_in;
}

void Book::set_lended(Date lended_in){
    _lended = &lended_in;
    _available = true;
}

void Book::set_returned(Date returned_in){
    _returned = &returned_in;
    _available = false;
}


/*std::ostream& operator<<(std::ostream& os, Book a){
    if (a.status()){
        return os << a.name() << " " << a.surname() << ", " << a.title() << ", " << a.release() << ", " << a.isbn() <<".\n"
        << "The book is currently not available. It has been lended on this date: " << a.date_of_lend();
    }else{
        return os << a.name() << " " << a.surname() << ", " << a.title() << ", " << a.release() << ", " << a.isbn() <<".\n"
        << "The book is currently available. It has been returned on this date: " << a.date_of_return();
    }
}*/


std::ostream& operator<<(std::ostream& os, Book a){
    os << ((a.title() == "") ? "Titolo non presente" : a.title());
    os << "\n" << ((a.surname() == "") ? "Cognome non presente" : a.surname()) << ", " << ((a.name() == "") ? "Nome non presente" : a.name());
    if (a.isbn() != nullptr){
        os << "\n" << *a.isbn();
    }
    else{
        os << "";
    }
    if (a.release() != nullptr){
        os << "\n" << *a.release();
    }
    else{
        os << "";
    }
    return os;
}

bool operator==(Book a, Book b){
    return (a.name() == b.name() && a.surname() == b.surname() && a.title() == b.title() && a.isbn() == b.isbn() && a.release() == b.release()); 
}