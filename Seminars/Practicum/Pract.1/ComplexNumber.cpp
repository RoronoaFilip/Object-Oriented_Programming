#include <iostream>
struct ComplexNumber {
    double real;
    double im;
};
void readNum(ComplexNumber &num) { std::cin >> num.real >> num.im; }
ComplexNumber mySum(const ComplexNumber &num1, const ComplexNumber &num2) {
    ComplexNumber sum;
    sum.real = num1.real + num2.real;
    sum.im = num1.im + num2.im;
    return sum;
}
int main() {
    ComplexNumber num1;
    readNum(num1);
    ComplexNumber num2;
    readNum(num2);
    ComplexNumber sum = mySum(num1, num2);
    std::cout << sum.real << " " << sum.im;
    return 0;
}