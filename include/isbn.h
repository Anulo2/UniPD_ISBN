#ifndef ISBN_H
#define ISBN_H

#include <ostream>
#include <vector>

/*

        Interfaccia per la classa ISBN {International Standard Book Number}

        Composizione del codice ISBN:
                n-n-n-x, con n intero e x una singola cifra o una lettera (i quattro campi sono separati da un carattere ‘-’).

*/

class ISBN {
   public:
    // Costruttori con controllo della validità della stringa/dei campi inseriti
    ISBN(int field1_in, int field2_in, int field3_in, char field4_in);
    ISBN(std::string isbn);

    // Operatore di assegnazione
    ISBN& operator=(ISBN a);

    // Funzioni getter
    int get_field1(void) const { return field1; }
    int get_field2(void) const { return field2; }
    int get_field3(void) const { return field3; }
    char get_field4(void) const { return field4; }

    // Funzione per la gestione delle eccezioni, usata solo in condizioni di errore
    class InvalidIdentifier {};

   private:
    int field1;
    int field2;
    int field3;
    char field4;

    // Funzione per il controllo della valitá di field4
    // necessaria in quanto char, devono essere inserite solo lettere o numeri
    bool is_invalid(void) const { return (field4 < 'a' || field4 > 'z') && (field4 < 'A' || field4 > 'Z') && (field4 < '0' || field4 > '9'); }

    int to_int(std::string in);
};

// helper functions
// Operatore di uguaglianza
bool operator==(ISBN a, ISBN b);

// Output to stream
std::ostream& operator<<(std::ostream& os, ISBN& a);
std::ostream& operator<<(std::ostream& os, ISBN* a);

#endif  // ISBN_H
