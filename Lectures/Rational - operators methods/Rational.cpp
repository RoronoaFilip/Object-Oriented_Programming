/*
*  Rational.cpp
*/
#include "Rational.h"

#include <iostream>

using namespace std;

// ����������� � 2 ����������
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


// �������� �� ��������
int Rational::getNumerator() const {
	return numer;
}

// �������� �� ����������
int Rational::getDenominator() const {
	return denom;
}

// ������� �� ���������
void Rational::print() const {
	cout << getNumerator() << '/' << getDenominator();
}

// ������� (������� �� �������) ���� ���������
void Rational::read() {
	// ������: 2/5
	cin >> numer;
	cin.ignore();
	cin >> denom;
}


// ���-����� ��� �������
int Rational::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


// ������������� �� ��������� +
Rational Rational::operator+(Rational q) const {
	return Rational(getNumerator() * q.getDenominator()
		+ getDenominator() * q.getNumerator(),
		getDenominator() * q.getDenominator());
}

// ������������� �� ��������� -
Rational Rational::operator-(Rational q) const {
	return Rational(getNumerator() * q.getDenominator()
		- getDenominator() * q.getNumerator(),
		getDenominator() * q.getDenominator());
}

// ������������� �� ��������� *
Rational Rational::operator*(Rational q) const {
	return Rational(getNumerator() * q.getNumerator(),
		getDenominator() * q.getDenominator());
}

// ������������� �� ��������� /
Rational Rational::operator/(Rational q) const {
	return Rational(getNumerator() * q.getDenominator(),
		getDenominator() * q.getNumerator());
}

