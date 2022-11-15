#ifndef BOOK_H
#define BOOK_H

#include <ostream>
#include "date.h"
#include "isbn.h"


class Book
{
public:
	Book(); 
    Book(std::string name_in, std::string surname_in, std::string title_in, ISBN isbn_in);
	Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in);
    Book(std::string name_in, std::string surname_in, std::string title_in, ISBN isbn_in, Date release_in);
	
    
	Book& operator=(Book a);
	
	std::string name(void) const {return _name;}
	std::string surname(void) const {return _surname;}
	std::string title(void) const {return _title;}
	ISBN isbn(void) const{return _isbn;}
	Date release(void) const{return _release;}
	bool status(void) const{return _status;}
	Date date_of_lend(void) {return _lended;}
	Date date_of_return(void) {return _returned;}
	
	
	void set_name(std::string name_in);
	void set_surname(std::string surname_in);
	void set_title(std::string title_in);
	void set_isbn(ISBN isbn_in);
	void set_release(Date release_in);
	void set_lended(Date lended_in);
	void set_returned(Date returned_in);
private:

	ISBN _isbn;
	std::string _title;
	std::string _name;
	std::string _surname;
	Date _release; // Data di copyright
	bool _status;
	
	Date _lended;
	Date _returned;
	
};

std::ostream& operator<<(std::ostream& os, Book a);
bool operator==(Book a, Book b);


#endif // BOOk_H

