#include "student.h"
#include <fstream>
#include <iostream>

//* Print the Student to Console
void Student::print() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Fn: " << fn << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Gender: " << gender << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Grade: " << grade << std::endl;
  std::cout << std::endl;
}

//* Set the Info of the Student
void Student::setName(const char *info) { setInfo(name, info); }

void Student::setEmail(const char *info) {
  if (validateEmail(info)) {
    setInfo(email, info);
  } else {
    setInfo(email, "Invalid Email!");
  }
}

void Student::setGender(const char *info) { setInfo(gender, info); }

void Student::setAge(const char *info) {
  setInfo(ageRaw, info);
  age = parseStringToInt(ageRaw);
}

void Student::setFn(const char *info) {
  setInfo(fnRaw, info);
  fn = parseStringToInt(fnRaw);
}

void Student::setGrade(const char *info) {
  setInfo(gradeRaw, info);
  grade = parseStringToDouble(gradeRaw);
}

void Student::saveStudentToFileStream(std::ofstream &file) const {
  file << "<student>" << std::endl;
  file << '\t' << "<name>" << name << "<\\name>" << std::endl;
  file << '\t' << "<fn>" << fn << "<\\fn>" << std::endl;
  file << '\t' << "<age>" << age << "<\\age>" << std::endl;
  file << '\t' << "<gender>" << gender << "<\\gender>" << std::endl;
  file << '\t' << "<email>" << email << "<\\email>" << std::endl;
  file << '\t' << "<grade>" << grade << "<\\grade>" << std::endl;
  file << "<\\student>" << std::endl;
  file << std::endl;
}

//! private:

//* Parse String to Double
double Student::parseStringToDouble(const char *word) const {
  double num = 0;

  int i = 0;

  for (; word[i] != '.'; ++i) {
    if (word[i] == '\0') {
      return num;
    }
    if (word[i] == ',') {
      break;
    }
    num = num * 10 + (word[i] - '0');
  }

  ++i;

  double multiplier = 10;
  double num2 = 0;
  for (; word[i] != '\0'; ++i) {

    num2 = num2 + ((double)word[i] - '0') / multiplier;
    multiplier *= 10;
  }

  return num + num2;
}

//* Parse String to Int
int Student::parseStringToInt(const char *word) const { return atoi(word); }

//* Validate the Email
bool Student::validateEmail(const char *email) const {
  for (int i = 0; email[i] != '\0'; ++i) {
    if (email[i] == '@') {
      return true;
    }
  }

  return false;
}

//* Function that copies Source to Destination
void Student::setInfo(char *destination, const char *source) {
  int destinationIndex = 0;
  int sourceIndex = 0;
  while (source[sourceIndex] != '\0') {
    destination[destinationIndex++] = source[sourceIndex++];
  }

  destination[destinationIndex] = '\0';
}
