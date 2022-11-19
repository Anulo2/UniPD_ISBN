#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <vector>

class Date {
   public:
    // Costruttori con controllo e inizializzazione della data
    Date(int y);
    Date(int y, int m);
    Date(int y, int m, int d);
    Date(std::string date);

    // Operatore di assegnazione
    Date& operator=(Date a);

    // Funzioni getter
    int get_day(void) { return d; }
    int get_month(void) { return m; }
    int get_year(void) { return y; }

    // Funzione per la gestione delle eccezioni, usata solo in condizioni di errore
    class Invalid {};

   private:
    int y, m = 0, d = 0;  // anno, mese, giorno

    // Verifica se la data inserita è valida
    bool is_valid(void);

    // Controlla se l'anno è bisestile
    bool is_leap(void);

    int to_int(std::string in);
};

// Helper functions
// Output to stream
std::ostream& operator<<(std::ostream& os, Date& a);
std::ostream& operator<<(std::ostream& os, Date* a);

// Operatore di uguaglianza
bool operator==(Date a, Date b);

#endif  // DATE_H
