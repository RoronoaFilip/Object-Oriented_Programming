#include <iostream>

class Interval {
  int a;
  int b;

public:
  Interval();
  Interval(int a, int b);

  void print() const;
  int getA() const;
  int getB() const;
  int getIntervalLenght() const;
  bool isNumberInInterval(const int num) const;

  int getCountOfPrimeNumbers() const;
  int getCountOfPalindroms() const;
  int getCountOfNumsWithDiffCiphers() const;

  bool isBeginAndEndDregeeOfTwo() const;
  Interval getSection(const Interval &myInterval) const;
  Interval getUnion(const Interval &myInterval) const;
  bool isIntervalInCurrent(const Interval &myInterval) const;

private:
  int getCountOf(bool (*function)(int)) const;
};