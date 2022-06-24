#pragma once
#include <fstream>

const int studentInfoSize = 25;

struct Student {
  char name[studentInfoSize];
  char gender[studentInfoSize];
  char email[studentInfoSize];
  double grade;
  int fn;
  int age;

public:
  //* Print Info
  void print() const;

  //* Set Info
  void setName(const char *info);
  void setEmail(const char *info);
  void setAge(const char *info);
  void setGrade(const char *info);
  void setFn(const char *info);
  void setGender(const char *info);

  //* Save Info to File Stream
  void saveStudentToFileStream(std::ofstream &file) const;

private:
  //* Parse String to Double
  double parseStringToDouble(const char *word) const;

  //* Parse String to Int
  int parseStringToInt(const char *word) const;

  //* Validate the Email
  bool validateEmail(const char *email) const;

  //* Function that copies Source to Destination
  void setInfo(char *destination, const char *source);

private:
  char fnRaw[100];
  char ageRaw[100];
  char gradeRaw[100];
};