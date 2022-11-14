#ifndef BOOK_H
#define BOOK_H

#include <ostream>

class Book
{
public:
    Book(std::string name_in, std::string surname_in, std::string title_in, ISBN identifier_in);
    Book(std::string name_in, std::string surname_in, std::string title_in, ISBN identifier_in, Date release_in);
    
	Book& operator=(Book a);
	
	std::string name(void) const {return name;}
	std::string surname(void) const {return surname;}
	std::string title(void) const {return title:;}
	ISBN identifier(void) const{return identifier;}
	Date date(void) const{return release;}
	bool status(void) const{return status;}
	Date date_of_lend(void) {return lended;}
	Date date_of_return(void) {return returned;}
	
	
	void set_name(std::string name_in);
	void set_surname(std::string surname_in);
	void set_title(std::string title_in);
	void set_isbn(ISBN identifier_in);
	void set_release(Date release_in);
	void set_lended(Date lended_in);
	void set_returned(Date returned_in);

	void set_status(bool status_in);

    Book& operator=(Book a);
	
	std::ostream& operator<<(std::ostream& os, Book a);
	
	bool& operator==(Book a, Book b);
	
private:

	ISBN identifier;
	std::string title;
	std::string name;
	std::string surname;
	Date release; // Data di copyright
	bool status;
	
	Date lended;
	Date returned;
	
};

#endif // BOOk_H
