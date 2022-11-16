#include <iostream>
#include <vector>
#include <iomanip>
#include "book.h"
#include "date.h"
#include "isbn.h"

using namespace std;

int main(int argc, char **argv)
{
    char normal[]={0x1b,'[','0',';','3','9','m',0};
    char green[]={0x1b,'[','0',';','3', '2','m',0};
    char Upurple[]={0x1b,'[','4',';','3','5','m',0};

    Date date1(2022, 11, 15);
    Date date2("2022/11/15");
    /*
    cout << date1 << "\n";
    cout << date2 << "\n";
    */
    ISBN isbn1("222-333-444-c");
    ISBN isbn2(222, 333, 444, 'c');
    /*
    cout << isbn1 << "\n";
    cout << isbn2 << "\n";
    */
    Book book0;
    Book book1("Matteo");
    Book book2("Matteo", "Manenti");
    Book book3("Matteo", "Manenti", "Racconti da lo torbido medioevo");
    Book book4("Matteo", "Manenti", "Racconti da lo torbido medioevo", &isbn1);
    Book book5("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c");
    Book book6("Matteo", "Manenti", "Racconti da lo torbido medioevo", &isbn1, &date1);
    Book book7("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c", &date1);
    Book book8("Matteo", "Manenti", "Racconti da lo torbido medioevo", &isbn1, "2022/11/15");
    Book book9("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c", "2022/11/15");
    Book book10("George", "Orwell", "1984");
    /*
    cout << book0 << "\n";
    cout << book1 << "\n";
    cout << book2 << "\n";
    cout << book3 << "\n";
    cout << book4 << "\n";
    cout << book5 << "\n";
    cout << book6 << "\n";
    cout << book7 << "\n";
    cout << book8 << "\n";
    cout << book9 << "\n";
    */

   Book racconti_da_lo_torbido_medioevo("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c", "2022/11/15");
   Book millenovecentoottantaquattro("George", "Orwell", "1984");
   Book guida_galattica_per_gli_autostoppisti("Douglas", "Adams", "Guida galattica per gli autostoppisti", "88-41353-0", "1980/10/10"); //Non ho trovato ne mese ne giorno
   Book the_art_of_computer_programming("Donald", "Knuth", "The Art of Computer Programming", "0-75104-3", "1968/02/29"); //ho trovato solo il mese

    vector<Book> library = {racconti_da_lo_torbido_medioevo, guida_galattica_per_gli_autostoppisti};
    vector<Book> rented_books = {millenovecentoottantaquattro,the_art_of_computer_programming};

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

    while (looping)
    {
        cout << "\nCosa vuoi fare?\n";
        cout << "1) Aggiungere un libro alla biblioteca\n";
        cout << "2) Prendere in prestito un libro\n";
        cout << "3) Depositare un libro preso in presito\n";
        cout << "4) Elencare i libri disponibili nella biblioteca\n";
        cout << "5) Elencare i libri che hai preso in prestito\n";
        cout << "6) Uscire dal programma\n";

        int answer;
        cin >> answer;
        

        switch (answer)
        {
            case 1:
            {
                cout << "Inserisci il titolo del libro (premi invio se non presente): ";
                string title;
                getline(cin>>ws, title);
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

                if (isbn != "")
                {
                    book_buffer.set_isbn(*new ISBN(isbn));
                }
                {
                    book_buffer.set_release(*new Date(release));
                }

                library.push_back(book_buffer);

                break;
            }
            case 2:
            {   
                if (library.size() == 0){
                    cout << "Non ci sono libri! \n";
                    break;
                }
                for (int i = 0; i < library.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout <<"   /      /,\n";
                    cout << "  /";
                    int number = i+1;
                    int digits = 0; while (number != 0) { number /= 10; digits++; }
                    int first_space =(6-digits)/2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i+1 << green;
                    cout << string(6-first_space-digits, ' '); 
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"<<normal;
         
                    //cout << i+1 << "\n";
                    cout << library.at(i) << '\n';
                }
                cout << "\nInserisci il numero corrispondente al libro che vuoi prendere (inserisci 0 per annullare): ";
                int selection;
                cin>> selection;
                if (selection != 0){
                    rented_books.push_back(library.at(selection-1));
                    library.erase(library.begin()+selection+1);
                }
                break;
            }
            case 3:
            {
                if (rented_books.size() == 0){
                    cout << "Non hai libri! \n";
                    break;
                }
                for (int i = 0; i < rented_books.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout <<"   /      /,\n";
                    cout << "  /";
                    int number = i+1;
                    int digits = 0; while (number != 0) { number /= 10; digits++; }
                    int first_space =(6-digits)/2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i+1 << green;
                    cout << string(6-first_space-digits, ' '); 
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"<<normal;
         
                    //cout << i+1 << "\n";
                    cout << rented_books.at(i) << '\n';
                }
                cout << "\nInserisci il numero corrispondente al libro che vuoi prendere (inserisci 0 per annullare): ";
                int selection;
                cin>> selection;
                if (selection != 0){
                    library.push_back(rented_books.at(selection-1));
                    rented_books.erase(rented_books.begin()+selection+1);
                }
                break;
            }
            case 4:
            {
                if (library.size() == 0){
                    cout << "Non ci sono libri! \n";
                    break;
                }
                for (int i = 0; i < library.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout <<"   /      /,\n";
                    cout << "  /";
                    int number = i+1;
                    int digits = 0; while (number != 0) { number /= 10; digits++; }
                    int first_space =(6-digits)/2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i+1 << green;
                    cout << string(6-first_space-digits, ' '); 
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"<<normal;
         
                    //cout << i+1 << "\n";
                    cout << library.at(i) << '\n';
                }
                break;
            }
            case 5:
            {
                if (rented_books.size() == 0){
                    cout << "Non hai libri! \n";
                    break;
                }
                for (int i = 0; i < rented_books.size(); i++) {
                    cout << "    " << green << "_______\n";
                    cout <<"   /      /,\n";
                    cout << "  /";
                    int number = i+1;
                    int digits = 0; while (number != 0) { number /= 10; digits++; }
                    int first_space =(6-digits)/2;
                    cout << string(first_space, ' ');
                    cout << Upurple << i+1 << green;
                    cout << string(6-first_space-digits, ' '); 
                    cout << "//\n";
                    cout << " /______//\n";
                    cout << "(______(/\n\n"<<normal;
         
                    //cout << i+1 << "\n";
                    cout << rented_books.at(i) << '\n';
                }
                break;
            }
            case 6:
            {
                looping = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    cout << "Arrivederci!\n";
    return 0;
}
