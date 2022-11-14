#ifndef RATIONAL_H
#define RATIONAL_H

#include <ostream>

// Invarianti:
// - denominator_ è sempre diverso da 0
// - la frazione è sempre in forma normale
// NOTA: il secondo invariante mi costringe a normalizzare la frazione
//       per ogni set di numeratore e denominatore (oltre che nel costruttore)
class Rational
{
public:
    // Un solo costruttore che gestisce tre casi:
    // - nessun argomento (frazione inizializzata a 0)
    // - un solo argomento (numero intero perché il denominatore è 1)
    // - due argomenti
    // NOTA: questo è possibile sfruttando gli argomenti di default, che
    //       fanno riferimento a due costanti definite in fondo alla classe.
    Rational(int num = kDefaultNumerator, int den = kDefaultDenominator);
    
    // Assignment - gli altri operatori sono implementati come helper function
    // NOTA: l'argomento è passato per copia e non per const reference
    // perché copio solo due int (ed è probabilmente più veloce che sfruttare una reference)
    Rational& operator=(Rational a);

    // accessors / get functions: stesso nome della variabile
    // mutators / set functions: set_<var name>
    // Approfondimento:
    // https://google.github.io/styleguide/cppguide.html#Function_Names
    // NOTA: definite in-class, sono inline (ragionevole per queste funzioni con una sola istruzione)
    int numerator(void) const { return numerator_; }
    int denominator(void) const { return denominator_; }
    
    // Implementano l'invariante secondo cui la frazione è sempre in forma normale
    // (quindi dividono numeratore e denominatore per Gcd
    void set_numerator(int num);
    void set_denominator(int den);
    
    // NOTA: devo fare il cast di numerator_, altrimenti eseguirebbe prima la divisione
    // intera e poi la conversione a double. Convertire il denominatore non serve perché,
    // essendo il primo operando double, il compilatore è costretto a convertire anche il secondo
    // e ad eseguire la divisione tra double.
    // NOTA: implementato in-class, quindi funzione inline - è un cast + una divisione, è ragionevole.
    double ToDouble(void) const { return static_cast<double> (numerator_) / denominator_; }
    
    // Fornisco anche l'interfaccia tramite cast
    // NOTA: all'epoca del laboratorio non sapevate ancora che si potesse fare.
    //       Per questo ho previsto sia la funzione ToDouble che l'overloading del cast,
    //       ma normalmente avrei previsto solo il cast (senza implementare anche ToDouble).
    operator double() const { return ToDouble(); }
    
    // Per la gestione delle eccezioni. Definita qui in fondo perché ho preferito mettere
    // in evidenza i costruttori e l'interfaccia che si usa in condizioni normali (mentre questa classe
    // si usa in condizioni di errore).
    class DivideByZeroException {};
    
private:
    // Funzione membro privata, usata solo dalle altre funzioni membro
    void normalize(void);
    
    // Notare l'uso di _ alla fine, seguendo la convenzione di Google
    int numerator_;
    int denominator_;
    
    // Default initializers
    // Preferisco definire qui le costanti e usarle nella dichiarazione
    // del costruttore come valori di default
    // Sono static per averne una sola istanza, comune a tutti gli oggetti di questa classe
    static constexpr int kDefaultNumerator = 0;
    static constexpr int kDefaultDenominator = 1;
};

// Nota:
// https://google.github.io/styleguide/cppguide.html#Classes
// Prefer to define non-modifying binary operators as non-member functions.
// If a binary operator is defined as a class member,
// implicit conversions will apply to the right-hand argument,
// but not the left-hand one.
// It will confuse your users if a < b compiles but b < a doesn't.

// Addition
Rational operator+(Rational a, Rational b);
// Subtraction
Rational operator-(Rational a, Rational b);
// Multiplication
Rational operator*(Rational a, Rational b);
// Division
Rational operator/(Rational a, Rational b);
// Equality
bool operator==(Rational a, Rational b);
// Output to stream - questo non era richiesto dall'esercizio, ma mi è comodo per il debug
std::ostream& operator<<(std::ostream& os, Rational a);

// Le funzioni seguenti sono slegate dalla classe e disponibili all'utente.
// Questo non costituisce nessun problema. Eventualmente potrebbero essere spostate in un modulo
// separato (una mini libreria), usata anche da Rational.

// Greatest common divisor
int Gcd(int a, int b);
// Least common multiple
int Lcm(int a, int b);


#endif // RATIONAL_H
