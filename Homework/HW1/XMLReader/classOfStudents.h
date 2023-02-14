#pragma once
#include "XmlParser.h"
#include "student.h"
#include <fstream>

class classOfStudents {
public:
  Student *studentsArray;
  int countOfStudents;

  classOfStudents(std::ifstream &file);
  ~classOfStudents();

  //* Print the Students
  void print() const;

  //* Save Students to File
  void saveStudentsToFile(const char *filePath) const;

  //* Check if Fn exists
  bool checkIfFnExists(const char *fn) const;

  //* Check if such an Attibute to edit exists
  bool doesAttributeToEditExist(const char *attribute) const;

  //* Validate Replacement Info
  bool isEditInfoValid(const char *newInfo,
                       const char *attributeToReplace) const;

  //* Replace info
  void editInfo(const char *newInfo, const char *attributeToReplace,
                const char *neededFn);

  //* Sort based on passed in Attribute
  void sort(const char *attribute);

private:
  int studentsIndex;

private:
  //! Sort**********************************************************

  //* Sort based on Gender
  void sortBasedOnGender();

  //* Sort based on Email
  void sortBasedOnEmail();

  //* Sort based on Name
  void sortBasedOnName();

  //* Sort based on Grade
  void sortBasedOnGrade();

  //* Sort based on Fn
  void sortBasedOnFn();

  //* Sort based on Age
  void sortBasedOnAge();

  //! VALIDATION****************************************************
  //* Validate the Email
  bool validateEmail(const char *email) const;

  //* Validate the Gender
  bool validateGender(const char *gender) const;

  //* Validate the Grade
  bool validateGrade(const char *grade) const;

  //* Validate the Age
  bool validateAge(const char *age) const;

  //* Validate the fn
  bool validateFn(const char *fn) const;

  //! Other Functions************************************************
  //* Check if the Strings are the same
  bool areStringsEqual(const char *arr1, const char *arr2) const;

  //* Get the Lenght of Something
  int getLenght(const char *word) const;

  //* Get all info for the Students from the File and load it to the Array
  void getInfoForStudents(std::ifstream &file);

  //* Parse String to Int
  int parseStringToInt(const char *word) const;

  //* Parse String to Double
  double parseStringToDouble(const char *word) const;

  //* Get the Count of the Students from the File Stream
  int getCountOfStudentsFromFileStream(std::ifstream &file) const;

  //* Get the Student Index based on Fn
  int getStudentIndexBasedOnFn(const char *fn) const;

  //* Swap Students
  void swapStudents(Student &student1, Student &student2);

  //* Check if first string is before second
  bool isFirstBeforeSecond(const char *arr1, const char *arr2) const;
};
