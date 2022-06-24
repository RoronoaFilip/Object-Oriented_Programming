/*
*  Rational.cpp
*/
#include "Rational.h"

#include <iostream>

using namespace std;

// Конструктор по подразбиране
Rational::Rational() {
	numer = 0;
	denom = 1;
}


// Конструктор с 2 параметъра
Rational::Rational(int n, int d) {
	if (n == 0 || d == 0) {
		numer = 0;
		denom = 1;
	}
	else {
		int g = gcd(abs(n), abs(d));
		if (n > 0 && d > 0 || n < 0 && d < 0) {
			numer = abs(n) / g;
			denom = abs(d) / g;
		}
		else {
			numer = -abs(n) / g;
			denom = abs(d) / g;
		}
	}
}


// селектор за числител
int Rational::getNumerator() const {
	return numer;
}

// селектор за знаменател
int Rational::getDenominator() const {
	return denom;
}

// функция за извеждане
void Rational::print() const {
	cout << getNumerator() << '/' << getDenominator();
}

// мутатор (функция за промяна) чрез въвеждане
void Rational::read() {
	// Пример: 2/5
	cin >> numer;
	cin.ignore();
	cin >> denom;
}


// Най-голям общ делител
int Rational::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


// Събиране на 2 рационални числа
Rational add(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
		+ p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Изваждане на 2 рационални числа
Rational subtract(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
		- p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Умножение на 2 рационални числа
Rational multiply(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Деление на 2 рационални числа
Rational divide(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator(),
		p.getDenominator() * q.getNumerator());
}

