#include "WordCollection.h"

int main() {
  //! NOTE: Adding Collections works as a Union between Sets

  //! DEMO:

  std::cout << "Demo:" << '\n'
            << '\n';

  WordCollection words1;
  (words1 *= {"Filip"}) *= {"Filchev"};
  (words1 *= {"Filip"}) *= {"Filchev"};
  words1 >> "Filip" >> "Filchev"; //* Must get added just once
  std::cout << "Words1: " << words1 << '\n';

  WordCollection words2;
  ((words2 *= {"Anton"}) *= {"Toni"}) *= {"Ivan"};
  std::cout << "Words2: " << words2 << '\n';

  WordCollection words3;
  ((words3 *= {"Georgi"}) *= {"Hristo"}) *= {"Toni"};
  std::cout << "Words3: " << words3 << '\n';

  std::cout << '\n';

  WordCollection final = words2 + words3;
  std::cout << "Words2 + Words3: " << final << '\n';
  final += final; //* Must do nothing

  WordCollection final2 = words2 - words3;
  std::cout << "Words2 - Words3: " << final2 << '\n';
  final2 += final2; //* Must do nothing

  std::cout << '\n';

  final /= {"Georgi"}; //* Eliminates "Georgi"
  final2 /= {"Ivan"};  //* Eliminates "Ivan"

  std::cout << "Final 1 = (Words2 + Words3) /= {\"Georgi\"}: "
            << final << '\n';
  std::cout << "Final 2 = (Words2 - Words3) /= {\"Ivan\"}: "
            << final2 << '\n';

  std::cout << '\n';

  final2 >> "John";
  "John" >> final2;
  std::cout << "Final 2 = Final 2 >> \"John\": " << final2 << '\n';

  std::cout << '\n';

  //! Console:
  std::cout << "Enter a number of Names you want to input: ";

  int number = 0;
  std::cin >> number;

  for (int i = 0; i < number; ++i) {
    std::cin >> final; //* Uses Operator*=
  }

  final2 += words1;

  //* Final Output:
  std::cout << '\n'
            << "Final = Final 1 + Final 2 + Words1 + Input: "
            << final + final2 + words1 << '\n';

  std::cout << '\n';

  std::cout << "Final Search for {\"Filip\"} and {\"Alabala\"}: "
            << (final + final2 + words1)["Filip"] << " "
            << (final + final2 + words1)["Alabala"] << '\n'; //* Operator[] test

  return 0;
}