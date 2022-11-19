#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#include "book.h"
#include "date.h"
#include "isbn.h"

using namespace std;

int main(int argc, char **argv) {
    char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};
    char green[] = {0x1b, '[', '0', ';', '3', '2', 'm', 0};
    char Upurple[] = {0x1b, '[', '4', ';', '3', '5', 'm', 0};

    bool valid = true;

    /*
    ##################################################
    #                      TEST DATE                 #
    ##################################################
    */

    try {
        Date date0{2022};
        Date date1("2022");
        Date date2(2022, 11);
        Date date3("2022/11");
        Date date4(2022, 11, 19);
        Date date5("2022/11/19");

        try {
            Date date6(2023);
            valid = false;
        } catch (Date::Invalid e) {
        }

        try {
            Date date7("2023");
            valid = false;
        } catch (Date::Invalid e) {
        }

        try {
            Date date8(2022, 13);
            valid = false;
        } catch (Date::Invalid e) {
        }

        try {
            Date date9("2022/13");
            valid = false;
        } catch (Date::Invalid e) {
        }

        try {
            Date date10(2022, 02, 29);
            valid = false;
        } catch (Date::Invalid e) {
        }

        try {
            Date date11("2022/02/29");
            valid = false;
        } catch (Date::Invalid e) {
        }

        if (!valid) {
            throw Date::Invalid();
        }

        cout << "[✅] Test Costruttori Date Completato\n";
    } catch (Date::Invalid e) {
        cout << "[❌] Test Costruttori Date Fallito\n";
    }

    valid = true;

    Date date12(2022, 11, 19);

    if (date12.get_day() != 19) {
        valid = false;
    }
    if (date12.get_month() != 11) {
        valid = false;
    }
    if (date12.get_year() != 2022) {
        valid = false;
    }

    Date date13(2022);
    date13 = date12;

    if (!(date12 == date13)) {
        valid = false;
    }

    if (valid) {
        cout << "[✅] Test Metodi Date Completato\n";
    } else {
        cout << "[❌] Test Metodi Date Fallito\n";
    }

    /*
    ##################################################
    #                    TEST ISBN                   #
    ##################################################
    */

    valid = true;

    try {
        ISBN isbn0{123, 456, 789, 'a'};
        ISBN isbn1("123-456-789-a");

        try {
            ISBN isbn2(123, 456, 789, '?');
            valid = false;
        } catch (ISBN::InvalidIdentifier e) {
        }

        try {
            ISBN isbn3("a-456-789-a");
            valid = false;
        } catch (ISBN::InvalidIdentifier e) {
        }

        try {
            ISBN isbn4("123-a-789-a");
            valid = false;
        } catch (ISBN::InvalidIdentifier e) {
        }

        try {
            ISBN isbn5("123-456-a-a");
            valid = false;
        } catch (ISBN::InvalidIdentifier e) {
        }

        try {
            ISBN isbn6("123-456-789-?");
            valid = false;
        } catch (ISBN::InvalidIdentifier e) {
        }

        if (!valid) {
            throw ISBN::InvalidIdentifier();
        }

        cout << "[✅] Test Costruttori ISBN Completato\n";
    } catch (ISBN::InvalidIdentifier e) {
        cout << "[❌] Test Costruttori ISBN Fallito\n";
    }

    valid = true;

    ISBN isbn7(123, 456, 789, 'a');

    if (isbn7.get_field1() != 123) {
        valid = false;
    }
    if (isbn7.get_field2() != 456) {
        valid = false;
    }
    if (isbn7.get_field3() != 789) {
        valid = false;
    }
    if (isbn7.get_field4() != 'a') {
        valid = false;
    }

    ISBN isbn8(987, 654, 321, 'z');
    isbn8 = isbn7;

    if (!(isbn7 == isbn8)) {
        valid = false;
    }

    if (valid) {
        cout << "[✅] Test Metodi ISBN Completato\n";
    } else {
        cout << "[❌] Test Metodi ISBN Fallito\n";
    }

    /*
    ##################################################
    #                    TEST BOOK                   #
    ##################################################
    */

    valid = true;

    try {
        Book book0;
        Book book1("Matteo");
        Book book2("Matteo", "Manenti");
        Book book3("Matteo", "Manenti", "Racconti da lo torbido medioevo");
        Book book4("Matteo", "Manenti", "Racconti da lo torbido medioevo", new ISBN(123, 456, 789, 'a'));
        Book book5("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-a");
        Book book6("Matteo", "Manenti", "Racconti da lo torbido medioevo", new ISBN(123, 456, 789, 'a'), new Date(2022, 11, 19));
        Book book7("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-a", new Date(2022, 11, 19));
        Book book8("Matteo", "Manenti", "Racconti da lo torbido medioevo", new ISBN(123, 456, 789, 'a'), "2022/11/19");
        Book book9("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-a", "2022/11/19");

        try {
            Book book10("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-?");
            valid = false;
        } catch (Book::InvalidBook e) {
        }

        try {
            Book book11("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-?", new Date(2022, 11, 19));
            valid = false;
        } catch (Book::InvalidBook e) {
        }

        try {
            Book book12("Matteo", "Manenti", "Racconti da lo torbido medioevo", new ISBN(123, 456, 789, 'a'), "2022/02/29");
            valid = false;
        } catch (Book::InvalidBook e) {
        }

        try {
            Book book13("Matteo", "Manenti", "Racconti da lo torbido medioevo", "123-456-789-?", "2022/02/29");
            valid = false;
        } catch (Book::InvalidBook e) {
        }

        if (!valid) {
            throw Book::InvalidBook();
        }

        cout << "[✅] Test Costruttori Book Completato\n";
    } catch (Book::InvalidBook e) {
        cout << "[❌] Test Costruttori Book Fallito\n";
    }

    valid = true;

    Book book14("Matteo", "Manenti", "Racconti da lo torbido medioevo", new ISBN(123, 456, 789, 'a'), new Date(2022, 11, 19));

    if (book14.name() != "Matteo") {
        valid = false;
    }
    if (book14.surname() != "Manenti") {
        valid = false;
    }
    if (book14.title() != "Racconti da lo torbido medioevo") {
        valid = false;
    }
    if (!(*book14.isbn() == ISBN(123, 456, 789, 'a'))) {
        valid = false;
    }
    if (!(*book14.release() == Date(2022, 11, 19))) {
        valid = false;
    }
    if (book14.available() == false) {
        valid = false;
    }

    Book book15("Donald", "Knuth", "The Art of Computer Programming");

    book15.set_name("Donale");
    book15.set_surname("Knuth");
    book15.set_title("The Art of Computer Programming");

    try {
        ISBN isbn = *book15.isbn();
        valid = false;
    } catch (Book::FieldNotPresent e) {
    }
    try {
        Date date = *book15.release();
        valid = false;
    } catch (Book::FieldNotPresent e) {
    }
    book15.set_isbn(new ISBN(123, 456, 789, 'a'));
    book15.set_release(new Date(2022, 11, 19));
    book15.set_isbn("123-456-789-a");
    book15.set_release("2022/11/19");
    book15.set_available(false);

    try {
        book15.set_isbn("123-456-789-?");
        valid = false;
    } catch (Book::InvalidBook e) {
    }
    try {
        book15.set_release("2022/02/29");
        valid = false;
    } catch (Book::InvalidBook) {
    }

    book15 = book14;

    if (!(book14 == book15)) {
        valid = false;
    }

    if (valid) {
        cout << "[✅] Test Metodi Book Completato\n";
    } else {
        cout << "[❌] Test Metodi Book Fallito\n";
    }

    /*
    ##################################################
    #                   INTERAZIONE                  #
    ##################################################
    */

    Book racconti_da_lo_torbido_medioevo("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c", "2022/11/15");
    Book millenovecentoottantaquattro("George", "Orwell", "1984");
    Book guida_galattica_per_gli_autostoppisti("Douglas", "Adams", "Guida galattica per gli autostoppisti", "88-41353-0", "1980/10/10");  // Non ho trovato ne mese ne giorno
    Book the_art_of_computer_programming("Donald", "Knuth", "The Art of Computer Programming", "0-75104-3", "1968/02/29");                // ho trovato solo il mese

    guida_galattica_per_gli_autostoppisti.set_available(false);
    the_art_of_computer_programming.set_available(false);

    vector<Book> library = {racconti_da_lo_torbido_medioevo, guida_galattica_per_gli_autostoppisti, millenovecentoottantaquattro, the_art_of_computer_programming};
    vector<Book *> rented_books = {&guida_galattica_per_gli_autostoppisti, &the_art_of_computer_programming};

    cout << R"(
   ____________________________________________________
  |____________________________________________________|
  | __     __   ____   ___ ||  ____    ____     _  __  |
  ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |
  ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |
  ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |
  ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|
  ||_______________________||__________________________|
  | _____________________  ||      __   __  _  __    _ |
  ||=|=|=|=|=|=|=|=|=|=|=| __..\/ |  |_|  ||#||==|  / /|
  || | | | | | | | | | | |/\ \  \\|++|=|  || ||==| / / |
  ||_|_|_|_|_|_|_|_|_|_|_/_/\_.___\__|_|__||_||__|/_/__|
  |____________________ /\~()/()~//\ __________________|
  | __   __    _  _     \_  (_ .  _/ _    ___     _____|
  ||~~|_|..|__| || |_ _   \ //\\ /  |=|__|~|~|___| | | |
  ||--|+|^^|==|1||2| | |__/\ __ /\__| |==|x|x|+|+|=|=|=|
  ||__|_|__|__|_||_|_| /  \ \  / /  \_|__|_|_|_|_|_|_|_|
  |_________________ _/    \/\/\/    \_ _______________|
  | _____   _   __  |/      \../      \|  __   __   ___|
  ||_____|_| |_|##|_||   |   \/ __|   ||_|==|_|++|_|-|||
  ||______||=|#|--| |\   \   o    /   /| |  |~|  | | |||
  ||______||_|_|__|_|_\   \  o   /   /_|_|__|_|__|_|_|||
  |_________ __________\___\____/___/___________ ______|
  |__    _  /    ________     ______           /| _ _ _|
  |\ \  |=|/   //    /| //   /  /  / |        / ||%|%|%|
  | \/\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|
__|  \/\|/   /(____|/ //                    /  /||~|~|~|__
  |___\_/   /________//   ________         /  / ||_|_|_|
  |___ /   (|________/   |\_______\       /  /| |______|
      /                  \|________)     /  / | |
)" << '\n';
    cout << R"(
 ____  ____  _  _  _  _  ____  _  _  __  __  ____  _____ 
(  _ \( ___)( \( )( \/ )( ___)( \( )(  )(  )(_  _)(  _  )
 ) _ < )__)  )  (  \  /  )__)  )  (  )(__)(   )(   )(_)( 
(____/(____)(_)\_)  \/  (____)(_)\_)(______) (__) (_____)
)" << '\n';

    bool looping = true;

    while (looping) {
        cout << "\nCosa vuoi fare?\n";
        cout << "1) Aggiungere un libro alla biblioteca\n";
        cout << "2) Prendere in prestito un libro\n";
        cout << "3) Depositare un libro preso in presito\n";
        cout << "4) Elencare i libri disponibili nella biblioteca\n";
        cout << "5) Elencare i libri che hai preso in prestito\n";
        cout << "6) Elencare i libri della biblioteca inclusi quelli presi in prestito\n";
        cout << "7) Uscire dal programma\n";

        int answer;
        cin >> answer;

        switch (answer) {
            case 1: {
                cout << "Inserisci il titolo del libro (premi invio se non presente): ";
                string title;
                cin.ignore();
                getline(cin, title);
                cout << "Inserisci il nome dell'autore (premi invio se non presente): ";
                string name;
                getline(cin, name);
                cout << "Inserisci il cognome dell'autore (premi invio se non presente): ";
                string surname;
                getline(cin, surname);
                cout << "Inserisci il codice ISBN del libro (premi invio se non presente): ";
                string isbn;
                getline(cin, isbn);
                cout << "Inserisci la data di copyright del libro (premi invio se non presente): ";
                string release;
                getline(cin, release);

                Book book_buffer;

                book_buffer.set_name(name);
                book_buffer.set_surname(surname);
                book_buffer.set_title(title);

                if (isbn != "") {
                    try {
                        book_buffer.set_isbn(isbn);
                    } catch (Book::InvalidBook e) {
                        cout << "ISBN inserito non valido!\n";
                        break;
                    }
                }
                if (release != "") {
                    try {
                        book_buffer.set_release(release);
                    } catch (Book::InvalidBook e) {
                        cout << "Data di copyright non valida!\n";
                        break;
                    }
                }

                library.push_back(book_buffer);

                break;
            }
            case 2: {
                if (library.size() == 0) {
                    cout << "Non ci sono libri! \n";
                    break;
                }

                for (int i = 0; i < library.size(); i++) {
                    if (library.at(i).available()) {
                        cout << "    " << green << "_______\n";
                        cout << "   /      /,\n";
                        cout << "  /";
                        int number = i + 1;
                        int digits = 0;
                        while (number != 0) {
                            number /= 10;
                            digits++;
                        }
                        int first_space = (6 - digits) / 2;
                        cout << string(first_space, ' ');
                        cout << Upurple << i + 1 << green;
                        cout << string(6 - first_space - digits, ' ');
                        cout << "//\n";
                        cout << " /______//\n";
                        cout << "(______(/\n\n"
                             << normal;

                        // cout << i+1 << "\n";
                        cout << library.at(i) << '\n';
                    }
                }

                cout << "Inserisci il numero corrispondente al libro che vuoi prendere (inserisci 0 per annullare): ";
                int selection = 0;
                bool invalid = true;
                while (invalid) {
                    while (!(cin >> selection)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Inserisci il numero corrispondente al libro che vuoi prendere (inserisci 0 per annullare): ";
                    }
                    if ((selection == 0) || (selection <= library.size() && library.at(selection - 1).available())) {
                        invalid = false;
                    } else {
                        cout << "Inserisci il numero corrispondente al libro che vuoi prendere (inserisci 0 per annullare): ";
                    }
                }
                if (selection != 0) {
                    rented_books.push_back(&library.at(selection - 1));
                    library.at(selection - 1).set_available(false);
                }
                break;
            }
            case 3: {
                if (rented_books.size() == 0) {
                    cout << "Non hai libri! \n";
                    break;
                }

                for (int i = 0; i < rented_books.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout << "   /      /,\n";
                    cout << "  /";
                    int number = i + 1;
                    int digits = 0;
                    while (number != 0) {
                        number /= 10;
                        digits++;
                    }
                    int first_space = (6 - digits) / 2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i + 1 << green;
                    cout << string(6 - first_space - digits, ' ');
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"
                         << normal;

                    cout << *rented_books.at(i) << '\n';
                }

                cout << "Inserisci il numero corrispondente al libro che vuoi depositare (inserisci 0 per annullare): ";
                int selection = 0;
                bool invalid = true;
                while (invalid) {
                    while (!(cin >> selection)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Inserisci il numero corrispondente al libro che vuoi depositare (inserisci 0 per annullare): ";
                    }
                    if (selection <= rented_books.size()) {
                        invalid = false;
                    } else {
                        cout << "Inserisci il numero corrispondente al libro che vuoi depositare (inserisci 0 per annullare): ";
                    }
                }
                if (selection != 0) {
                    Book buffer = *rented_books.at(selection - 1);
                    for (int i = 0; i < library.size(); i++) {
                        if (library[i] == buffer) {
                            library[i].set_available(true);
                        }
                    }
                    rented_books.erase(rented_books.begin() + selection + 1);
                }

                break;
            }
            case 4: {
                if (library.size() == 0) {
                    cout << "Non ci sono libri! \n";
                    break;
                }

                for (int i = 0; i < library.size(); i++) {
                    if (library.at(i).available()) {
                        cout << "    " << green << "_______\n";
                        cout << "   /      /,\n";
                        cout << "  /";
                        int number = i + 1;
                        int digits = 0;
                        while (number != 0) {
                            number /= 10;
                            digits++;
                        }
                        int first_space = (6 - digits) / 2;
                        cout << string(first_space, ' ');
                        cout << Upurple << i + 1 << green;
                        cout << string(6 - first_space - digits, ' ');
                        cout << "//\n";
                        cout << " /______//\n";
                        cout << "(______(/\n\n"
                             << normal;

                        cout << library.at(i) << '\n';
                    }
                }

                break;
            }
            case 5: {
                if (rented_books.size() == 0) {
                    cout << "Non hai libri! \n";
                    break;
                }

                for (int i = 0; i < rented_books.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout << "   /      /,\n";
                    cout << "  /";
                    int number = i + 1;
                    int digits = 0;
                    while (number != 0) {
                        number /= 10;
                        digits++;
                    }
                    int first_space = (6 - digits) / 2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i + 1 << green;
                    cout << string(6 - first_space - digits, ' ');
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"
                         << normal;

                    cout << *rented_books.at(i) << '\n';
                }
                break;
            }
            case 6: {
                if (library.size() == 0) {
                    cout << "Non ci sono libri! \n";
                    break;
                }

                for (int i = 0; i < library.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout << "   /      /,\n";
                    cout << "  /";
                    int number = i + 1;
                    int digits = 0;
                    while (number != 0) {
                        number /= 10;
                        digits++;
                    }
                    int first_space = (6 - digits) / 2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i + 1 << green;
                    cout << string(6 - first_space - digits, ' ');
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"
                         << normal;

                    cout << library.at(i) << '\n';
                }

                break;
            }

            case 7: {
                looping = false;
                break;
            }

            default: {
                break;
            }
        }
    }

    cout << "Arrivederci!\n";
    return 0;
}
