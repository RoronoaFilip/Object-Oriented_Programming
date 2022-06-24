#include <iostream>

class Rational {
  double ch;
  double zn;
  double num;

  bool validateZn() const { return !(zn == 0); }
  bool validateZn(const double num) const { return !(num == 0); }

  void setNum() { num = ch / zn; }

  double myAbs(double num) const { return (num >= 0) ? num : -num; }

  void setCh(const double newCh) {
    ch = newCh;
    setNum();
  }
  void setZn(const double newZn) {
    if (validateZn(newZn)) {
      zn = newZn;
      setNum();
    } else {
      setCh(0);
      setZn(1);
    }
  }

public:
  Rational() {
    ch = 0;
    zn = 1;
  }

  Rational(double ch, double zn) {
    this->ch = ch;
    if (validateZn(zn)) {
      this->zn = zn;
    } else {
      this->zn = 1;
    }
    setNum();
  }

  void swapChAndZn() {
    double temp = ch;
    ch = zn;
    zn = temp;
  }

  void print() {
    if (zn == 1) {
      std::cout << ch << std::endl;
    } else if (zn < 0 && (zn == 1 || zn == -1)) {
      std::cout << -ch << std::endl;
    } else if (zn < 0 && zn != 1) {
      std::cout << -ch << "/" << -zn << std::endl;
    } else {
      std::cout << ch << "/" << zn << std::endl;
    }
  }

  double getCh() const { return ch; }

  double getZn() const { return zn; }

  double getNum() const { return num; }

  void sumNums(const Rational &otherRational) {

    if (otherRational.zn == zn) {
      setCh(ch + otherRational.ch);
    } else {
      setCh((ch * otherRational.zn) + (zn * otherRational.ch));
      setZn(zn * otherRational.zn);
    }

    canonize();
  }

  void diffNums(const Rational &otherRational) {
    if (otherRational.zn == zn) {
      setCh(myAbs(ch - otherRational.ch));
    } else {
      setCh(myAbs((ch * otherRational.zn) - (zn * otherRational.ch)));
      setZn(zn * otherRational.zn);
    }

    canonize();
  }

  void multiplyNums(const Rational &otherRational) {
    setCh(ch * otherRational.ch);
    setZn(zn * otherRational.zn);

    canonize();
  }

  void divNums(Rational &otherRational) {
    otherRational.swapChAndZn();

    this->setCh(ch * otherRational.getCh());
    this->setZn(zn * otherRational.getZn());

    otherRational.swapChAndZn();
  }

  int numcmp(const Rational &otherRational) const {
    if (num == otherRational.getNum()) {
      return 0;
    } else if (num > otherRational.getNum()) {
      return 1;
    } else {
      return -1;
    }
  }

  void canonize() {
    int temp;
    if (ch > zn) {
      temp = ch;
    } else {
      temp = zn;
    }
    for (int i = 2; i <= temp; ++i) {
      if ((int)ch % i == 0 && (int)zn % i == 0) {
        while ((int)ch % i == 0 && (int)zn % i == 0) {
          ch /= i;
          zn /= i;
        }
      }
    }
  }
};

int main() {
  Rational rat1(42, 17);
  Rational rat2(7, 8);

  rat1.canonize();

  rat1.print();

  return 0;
}