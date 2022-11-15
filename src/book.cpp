#include "book.h"

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
    ISBN buffer_isbn(isbn_in);
    _isbn = &buffer_isbn;
}


Book::Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, Date *release_in):
_name{name_in}, _surname{surname_in}, _title{title_in}, _isbn{isbn_in}, _release{release_in}{
    
}
Book::Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, Date *release_in){
    _name = name_in;
    _surname = surname_in;
    _title = title_in;
    ISBN buffer_isbn(isbn_in);
    _isbn = &buffer_isbn;
    _release = release_in;
}

Book& Book::operator=(Book a){
    _name = a._name;
    _surname = a._surname;
    _title = a._title;
    _isbn = a._isbn;
    _release = a._release;
    
    return *this;
}

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
    _status = true;
}

void Book::set_returned(Date returned_in){
    _returned = &returned_in;
    _status = false;
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
    return os << a.title() << " \n" << a.surname() << ((a.surname() == "") ? "": " ") << a.name() << " \n" << a.isbn() << " \n" << a.release();

}

bool operator==(Book a, Book b){
    return (a.name() == b.name() && a.surname() == b.surname() && a.title() == b.title() && a.isbn() == b.isbn() && a.release() == b.release()); 
}