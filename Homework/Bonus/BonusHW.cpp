#include "interval.h"

int main() {
  //! Change these if needed
  Interval interval1(-64, 128);
  Interval interval2(-45, 254);

  std::cout << "Interval is [-64, 128]" << std::endl;
  std::cout << "Interval for Comparison is [-45, 254]" << std::endl;
  std::cout << std::endl;

  std::cout << "A: " << interval1.getA() << std::endl;
  std::cout << "B: " << interval1.getB() << std::endl;
  std::cout << "Count Of Prime Numbers: " << interval1.getCountOfPrimeNumbers()
            << std::endl;
  std::cout << "Count Of Palindroms: " << interval1.getCountOfPalindroms()
            << std::endl;
  std::cout << "Count Of Numbers with Different Ciphers: "
            << interval1.getCountOfNumsWithDiffCiphers() << std::endl;
  std::cout << "Lenght of Interval: " << interval1.getIntervalLenght()
            << std::endl;

  Interval interval3 = interval1.getSection(interval2);
  std::cout << "Section with [-45, 254]: ";
  interval3.print();

  interval3 = interval1.getUnion(interval2);
  std::cout << "Union with [-45, 254]: ";
  interval3.print();

  std::cout << "Are the Begin and the End a Dregree of 2: "
            << interval1.isBeginAndEndDregeeOfTwo() << std::endl;

  std::cout << "Is [-45, 254] in the Interval: "
            << interval1.isIntervalInCurrent(interval2) << std::endl;
  std::cout << "Is 69 in the Interval: " << interval1.isNumberInInterval(69)
            << std::endl;

  return 0;
}