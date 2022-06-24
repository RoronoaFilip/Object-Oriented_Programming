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
	Rational(int = 0, int = 1);
	// функции за достъп
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	// мутатор
	void read();
	friend Rational operator+(Rational, Rational);
	friend Rational operator-(Rational, Rational);
	friend Rational operator*(Rational, Rational);
	friend Rational operator/(Rational, Rational);
};


#endif /* RATIONAL_H */
