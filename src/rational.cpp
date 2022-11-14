#include "rational.h"

Rational::Rational(int num, int den)
    : numerator_{num}, denominator_{den}
{
    if (den == 0)
        throw DivideByZeroException();
    // Invariante di forma normale
    normalize();
}

// Questa funzione potrebbe essere anche definita in-class, ma set_denominator() è troppo lunga per essere
// in-class a sua volta (vedi implementazione qui sotto). Quindi ho raggruppato entrambe le funzioni qui.
void Rational::set_numerator(int num)
{
    numerator_ = num;
    normalize();
    
    return;
}

void Rational::set_denominator(int den)
{
    if (den == 0)
        throw DivideByZeroException();
    denominator_ = den;
    normalize();
    
    return;
}

// NOTA: questa funzione sposta il negativo al numeratore (se num e den sono discordi).
// Quindi non è necessario gestire il caso di numeratore positivo
// e denominatore negativo in operator<<.
// Se num e den sono negativi li rende positivi.
void Rational::normalize(void)
{
    int gcd = Gcd(numerator_, denominator_);
    if (gcd != 1)
    {
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
    
    return;
}

// Assignment
Rational& Rational::operator=(Rational a)
{
    // NOTA: essendo una funzione membro, accedo direttamente ai membri privati
    // NOTA: copio senza verifiche perché a rispetta gli invarianti
    numerator_ = a.numerator_;
    denominator_ = a.denominator_;
    
    return *this;
}

// Addition
Rational operator+(Rational a, Rational b)
{
    // Notate come una buona scelta dei nomi delle variabili membro e quindi degli accessor
    // renda il codice molto leggibile
    int common_den = Lcm(a.denominator(), b.denominator());
    int num_a_common = a.numerator() * (common_den / a.denominator());
    int num_b_common = b.numerator() * (common_den / b.denominator());
    
    // Sfrutto l'invariante: la frazione sarà normalizzata nel costruttore
    // Stesso ragionamento negli operator seguenti
    return Rational(num_a_common + num_b_common, common_den);
}

// Subtraction
Rational operator-(Rational a, Rational b)
{
    // Il codice è quasi identico a operator+, però non ho implementato una funzione
    // per queste tre righe di codice perché:
    int common_den = Lcm(a.denominator(), b.denominator());
    int num_a_common = a.numerator() * (common_den / a.denominator());
    int num_b_common = b.numerator() * (common_den / b.denominator());
    
    return Rational(num_a_common - num_b_common, common_den);
}

// Multiplication
Rational operator*(Rational a, Rational b)
{
    // Una versione maggiormente robusta agli overflow avrebbe potuto valutare
    // eventuali fattori comuni tra:
    // a.numerator() e b.denominator()
    // a.denominator() e b.numerator()
    return Rational (a.numerator() * b.numerator(), a.denominator() * b.denominator());
}

// Division
Rational operator/(Rational a, Rational b)
{
    // Avrei potuto creare una funzione che calcola il reciproco, ma nel contesto
    // dell'esercizio tale funzione sarebbe servita solo qui, quindi non l'ho fatto
    // NOTA: l'eventuale divisione per zero è gestita nel costruttore chiamato
    // nel return statement di operator*.
    return a * Rational(b.denominator(), b.numerator());
}

// Equality
bool operator==(Rational a, Rational b)
{
    // NOTA: l'invariante di forma normale mi permette di considerare solo il caso in cui
    // numeratore e denominatore sono uguali
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

// Output to stream - questo non era richiesto dall'esercizio, ma mi è comodo per il debug
std::ostream& operator<<(std::ostream& os, Rational a)
{
    return os << a.numerator() << "/" << a.denominator();
}


// Greatest common divisor
// Algoritmo euclideo + modulo operator
// Approfondimenti:
// - https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
// - https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
// NOTA: il numero di passi dell'algoritmo è basso per qualunque intero rappresentabile,
// perciò non ci sono problemi di stack overflow
int Gcd(int a, int b)
{
    if (b == 0)
        return a;
        
    return Gcd(b, a % b);
}

// Least common multiple
// Vedi riferimenti per Gcd
int Lcm(int a, int b)
{
    // NOTE: dividing before multiplying avoids overflow
    return a / Gcd(a, b) * b;
}
