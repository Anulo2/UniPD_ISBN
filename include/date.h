#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <vector>

class Date {
public:

	//Costruttori con controllo e inizializzazione della data
	Date (int y, int m, int d);
	Date (int y, int m);
	Date (int y);
	Date (std::string date);
	
	//Funzioni getter
	int get_day(void) {return d;}
	int get_month(void) {return m;}
	int get_year(void) {return y;}

	//Funzione per la gestione delle eccezioni, usata solo in condizioni di errore
	class Invalid {};
	
private:
	int y, m, d = NULL; 	//anno, mese, giorno

	//Verifica se la data inserita è valida
	bool is_valid(void);

	//Controlla se l'anno è bisestile
	bool is_leap(void);
};

//Helper functions 
//Output to stream
std::ostream& operator<<(std::ostream& os, Date &a);
std::ostream& operator<<(std::ostream& os, Date *a);

//Operatore di uguaglianza
bool operator==(Date a, Date b);

#endif // DATE_H
