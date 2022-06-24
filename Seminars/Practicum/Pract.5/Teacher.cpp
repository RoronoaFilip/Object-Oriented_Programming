#include <iostream>

int getStringLenght(const char *word) {
  int count = 0;
  for (int i = 0; word[i] != '\0'; ++i) {
    ++count;
  }

  return count;
}

void copyStrings(char *destination, const char *source) {
  delete[] destination;

  destination = new char[1024];

  int i = 0;
  for (; source[i] != '\0'; ++i) {
    destination[i] = source[i];
  }

  destination[i] = '\0';
}

class Teacher {
  char *name;
  int age;
  int lenghtOfService;

public:
  Teacher() {
    this->name = new char[1024];
    age = 0;
    lenghtOfService = 0;
  }

  Teacher(const char *name, const int age, const int lenghtOfService) {
    this->name = new char[1024];
    setName(name);
    setAge(age);
    setLenghtOfServide(lenghtOfService);
  }

  ~Teacher() {
    if (this->name == nullptr) {
      delete this->name;
    } else {
      delete[] this->name;
    }
  }

  void print() const {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Lenght of Service: " << this->lenghtOfService << std::endl;
  }

  void setName(const char *name) { copyStrings(this->name, name); }
  void setAge(const int age) { this->age = age; }
  void setLenghtOfServide(const int lenghtOfService) {
    this->lenghtOfService = lenghtOfService;
  }

  char *getName() const {
    char *toReturn = new char[1024];
    copyStrings(toReturn, this->name);
    return toReturn;
  }
  int getAge() const { return this->age; }
  int getLenghtOfSerice() { return this->lenghtOfService; }
};

int main() {
  Teacher teacher;
  teacher.setName("QLKDNQUIFDHEIFHEWIUFHEWUIFUIEWF");
  teacher.setAge(54);
  teacher.setLenghtOfServide(30);
  teacher.print();

  Teacher teacher2("FILIP     f", 89, 40);
  teacher2.print();

  teacher.setName("ME");
  teacher.print();

  return 0;
}