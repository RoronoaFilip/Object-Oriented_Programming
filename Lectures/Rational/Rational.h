#pragma once
/*
* Rational.h
*/


#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int numer, denom;
	int gcd(int, int);

public:
	// конструктори
	Rational();
	Rational(int, int);
	// функции за достъп
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	// мутатор
	void read();
};

Rational add(Rational, Rational);
Rational subtract(Rational, Rational);
Rational multiply(Rational, Rational);
Rational divide(Rational, Rational);

#endif /* RATIONAL_H */
