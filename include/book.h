#ifndef BOOK_H
#define BOOK_H

#include <ostream>
#include "date.h" 
#include "isbn.h"

//
class Book{
public:

	//Costruttori
	Book();

	Book(std::string name_in);

	Book(std::string name_in, std::string surname_in);

	Book(std::string name_in, std::string surname_in, std::string title_in);

	Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in);

	// Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in) : Book(name_in,  surname_in, title_in, ISBN(isbn_in)) {}
	Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in);
	Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, Date *release_in);
	Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, Date *release_in);
	Book(std::string name_in, std::string surname_in, std::string title_in, ISBN *isbn_in, std::string release_in);
	Book(std::string name_in, std::string surname_in, std::string title_in, std::string isbn_in, std::string release_in);


	//Operatore di assegnazione
	Book &operator=(Book a);

	//Funzioni getter 
	std::string name(void) const { return _name; }
	std::string surname(void) const { return _surname; }
	std::string title(void) const { return _title; }

	ISBN *isbn(void) const { return _isbn; }
	
	Date *release(void) const { return _release; }
	bool available(void) const { return _available; }
	Date *date_of_lend(void) { return _lended; }
	Date *date_of_return(void) { return _returned; }

	//funzioni setter
	void set_name(std::string name_in);
	void set_surname(std::string surname_in);
	void set_title(std::string title_in);
	void set_isbn(ISBN isbn_in);
	void set_release(Date release_in);
	void set_lended(Date lended_in);
	void set_returned(Date returned_in);
	
	//Funzione per la gestione delle eccezioni, usata solo in condizioni di errore
	class NotAvailable {};

private:
	ISBN *_isbn = nullptr;  	//Codice ISBN
	std::string _title; 		//Titolo del libro
	std::string _name;			//Nome dell'autore
	std::string _surname;		//Cognome dell'autore
	Date *_release = nullptr; 	// Data di copyright
	bool _available = true;		//Disponibilità del libro

	Date *_lended = nullptr;	//Data di prestito 
	Date *_returned = nullptr;	//Data di restituzione
};


//Helper functions 
//Output to stream
std::ostream &operator<<(std::ostream &os, Book a);

//Operatore di uguaglianza
bool operator==(Book a, Book b);

#endif // BOOK_H
