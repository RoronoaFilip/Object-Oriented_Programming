#include "interval.h"
#include "helper_functions.h"

Interval::Interval() {
  a = 0;
  b = 0;
}

Interval::Interval(int a, int b) {
  if (a <= b) {
    this->a = a;
    this->b = b;
  } else {
    this->a = 0;
    this->b = 0;
  }
}
void Interval::print() const {
  std::cout << '[' << this->a << ',' << this->b << ']' << std::endl;
}

int Interval::getA() const { return this->a; }
int Interval::getB() const { return this->b; }

int Interval::getIntervalLenght() const { return b - a; }

bool Interval::isNumberInInterval(const int num) const {
  return a <= num && num <= b;
}

int Interval::getCountOfPrimeNumbers() const { return getCountOf(&isPrime); }

int Interval::getCountOfPalindroms() const {
  return getCountOf(&isNumPalindrome);
}

int Interval::getCountOfNumsWithDiffCiphers() const {
  return getCountOf(&isNumWithDiffCiphers);
}

bool Interval::isBeginAndEndDregeeOfTwo() const {
  return isNumDegreeOfTwo(a) && isNumDegreeOfTwo(b);
}

Interval Interval::getSection(const Interval &myInterval) const {
  int newA;
  int newB;

  if (this->b <= myInterval.a || this->a >= myInterval.b) {
    return Interval(0, 0);
  }

  if (this->a <= myInterval.a) {
    newA = myInterval.a;
  } else {
    newA = this->a;
  }

  if (this->b >= myInterval.b) {
    newB = myInterval.b;
  } else {
    newB = this->b;
  }

  return Interval(newA, newB);
}

Interval Interval::getUnion(const Interval &myInterval) const {
  int newA;
  int newB;

  Interval section = this->getSection(myInterval);
  if (section.getA() == 0 && section.getB() == 0) {
    return section;
  }

  if (this->a >= myInterval.a) {
    newA = myInterval.a;
  } else {
    newA = this->a;
  }

  if (this->b <= myInterval.b) {
    newB = myInterval.b;
  } else {
    newB = this->b;
  }

  return Interval(newA, newB);
}
bool Interval::isIntervalInCurrent(const Interval &myInterval) const {
  return this->a <= myInterval.a && this->b >= myInterval.b;
}
int Interval::getCountOf(bool (*function)(int)) const {
  int countOfNumsWithDiffCiphers = 0;

  for (int i = a; i <= b; ++i) {
    if (function(i)) {
      ++countOfNumsWithDiffCiphers;
    }
  }

  return countOfNumsWithDiffCiphers;
}
