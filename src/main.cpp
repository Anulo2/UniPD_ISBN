#include <iostream>
#include "rational.h"
#include "book.h"
#include "date.h"
#include "isbn.h"

using namespace std;

double const_function(const Rational& r);

int main(int argc, char **argv)
{
    
    Date date1(2022, 11,15);

    cout << date1 << "\n";

    ISBN isbn1("222-333-444-c");
    ISBN isbn2(222, 333, 444, 'c');

    cout << isbn1 << "\n";
    cout << isbn2 << "\n";
    
    Book book1("Matteo");
    Book book2("Matteo", "Manenti");
    Book book3("Matteo", "Manenti", "Racconti da lo torbido medioevo");
    Book book4("Matteo", "Manenti", "Racconti da lo torbido medioevo", &isbn1);
    Book book5("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c");
    Book book6("Matteo", "Manenti", "Racconti da lo torbido medioevo", &isbn1, &date1);
    Book book7("Matteo", "Manenti", "Racconti da lo torbido medioevo", "222-333-444-c", &date1);
    
    cout << book1 << "\n";
    cout << book2 << "\n";
    cout << book3 << "\n";
    cout << book4 << "\n";
    cout << book5 << "\n";
    cout << book6 << "\n";
    cout << book7 << "\n";
    
    Rational default_rational;
    cout << "Default rational is: " << default_rational << endl;
    
    Rational num_only(5);
    cout << "I get an integer if I provide only the numerator: " << num_only << endl;
    
    // Test conversione a double
    Rational a(4, 8);
    cout << a << endl;
    cout << static_cast<double>(a) << endl;
    cout << a.ToDouble() << endl;
    
    // Test costruttore con 2 argomenti
    Rational b(8, 16);
    cout << b << endl;
    
    // Test equality
    cout << "Testing equality...\n";
    if (a == b)
        cout << "a == b\n";
    else
        cout << "a != b\n";
    
    cout << "Testing operator+\n";
    cout << a + b << endl;
    
    cout << "Testing operator-\n";
    Rational c = a - b;
    cout << c << endl;
    
    cout << "Testing operator=\n";
    Rational d = a;
    cout << d << endl;
    
    Rational e(8, 11);
    cout << e << endl;
    
    Rational f(22, 16);
    cout << "Testing operator*\n";
    Rational g = e * f;
    cout << g << endl;

    Rational h = Rational(4, 15);
    Rational i(2, 3);
    
    cout << "Testing operator/\n";
    cout << h / i << endl;
    
    cout << "Testing set function and automatic normalization\n";
    Rational l(8, 5);
    l.set_numerator(5);
    cout << l << endl;
    
    l.set_numerator(4);
    l.set_denominator(7);
    cout << l << endl;
    
    // Testing dangerous stuff... ]:->
    try
    {
        l.set_denominator(0);
    }
    catch (Rational::DivideByZeroException)
    {
        cout << "It was VERY dangerous to set the denominator to zero...\n";
    }
    
    Rational zero(0, 3);
    try
    {
        // Test gestione divisione per zero
        Rational problematic = h / zero;
        cout << problematic << endl;
    }
    catch (Rational::DivideByZeroException)
    {
        cout << "Ouch! You tried to divide by zero!\n";
    }
    
    Rational m(-5, -8);
    cout << "Negative num and den: " << m << endl;
    
    const_function(m);
    
    Rational n(-5, 8);
    cout << "Negative num: " << n << endl;
    
    Rational o(5, -8);
    cout << "Negative den: " << o << endl;
    
    cout << n * o << endl;
    
    // Gcd e Lcm sono liberamente accessibili :)
    cout << "Testing Gcd and Lcm: " << Gcd(4, -8) << " " << Lcm(7, -11) << endl;
    
	return 0;
}

double const_function(const Rational& r)
{
    cout << r << " " << r << " " << endl;
    cout << r.numerator() << " " << r.denominator() << endl;
    
    double d = r.ToDouble();
    
    // Questa non compila (r è const)
//    r.set_denominator(4);
    
    return d;
}