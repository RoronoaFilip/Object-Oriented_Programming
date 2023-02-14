#include "classOfStudents.h"
#include <iostream>

//! public
classOfStudents::classOfStudents(std::ifstream &file) {
  countOfStudents = getCountOfStudentsFromFileStream(file);
  studentsArray = new Student[countOfStudents];
  studentsIndex = 0;
  getInfoForStudents(file);
}
classOfStudents::~classOfStudents() { delete[] studentsArray; }

//* Print the Students
void classOfStudents::print() const {
  std::cout << std::endl;
  for (int i = 0; i < countOfStudents; ++i) {
    studentsArray[i].print();
  }
}

//* Save Students to File
void classOfStudents::saveStudentsToFile(const char *filePath) const {
  std::ofstream fileForWrite(filePath, std::ios::trunc);

  if (!fileForWrite.is_open()) {
    std::cout << "Error opening File in write form!" << std::endl;
    return;
  }

  for (int i = 0; i < countOfStudents; ++i) {
    studentsArray[i].saveStudentToFileStream(fileForWrite);
  }

  fileForWrite.close();
}

//* Check if Fn exists
bool classOfStudents::checkIfFnExists(const char *fn) const {
  int intFn = parseStringToInt(fn);
  for (int i = 0; i < countOfStudents; ++i) {
    if (studentsArray[i].fn == intFn) {
      return true;
    }
  }
  return false;
}

//* Check if such an Attibute to edit exists
bool classOfStudents::doesAttributeToEditExist(const char *attribute) const {
  if (areStringsEqual(attribute, "name") ||
      areStringsEqual(attribute, "gender") ||
      areStringsEqual(attribute, "age") ||
      areStringsEqual(attribute, "grade") ||
      areStringsEqual(attribute, "email") || areStringsEqual(attribute, "fn")) {
    return true;
  }
  return false;
}

//* Validate Replacement Info
bool classOfStudents::isEditInfoValid(const char *newInfo,
                                      const char *attributeToReplace) const {
  if (areStringsEqual(attributeToReplace, "name")) {
    return true;
  } else if (areStringsEqual(attributeToReplace, "email")) {
    return validateEmail(newInfo);
  } else if (areStringsEqual(attributeToReplace, "gender")) {
    return validateGender(newInfo);
  } else if (areStringsEqual(attributeToReplace, "age")) {
    return validateAge(newInfo);
  } else if (areStringsEqual(attributeToReplace, "fn")) {
    return validateFn(newInfo);
  } else if (areStringsEqual(attributeToReplace, "grade")) {
    return validateGrade(newInfo);
  }

  return false;
}

//* Replace info
void classOfStudents::editInfo(const char *newInfo,
                               const char *attributeToReplace,
                               const char *neededFn) {
  int neededStudentIndex = getStudentIndexBasedOnFn(neededFn);

  if (areStringsEqual(attributeToReplace, "name")) {
    studentsArray[neededStudentIndex].setName(newInfo);
  } else if (areStringsEqual(attributeToReplace, "email")) {
    studentsArray[neededStudentIndex].setEmail(newInfo);
  } else if (areStringsEqual(attributeToReplace, "gender")) {
    studentsArray[neededStudentIndex].setGender(newInfo);
  } else if (areStringsEqual(attributeToReplace, "age")) {
    studentsArray[neededStudentIndex].setAge(newInfo);
  } else if (areStringsEqual(attributeToReplace, "fn")) {
    studentsArray[neededStudentIndex].setFn(newInfo);
  } else if (areStringsEqual(attributeToReplace, "grade")) {
    studentsArray[neededStudentIndex].setGrade(newInfo);
  }
}

//* Sort based on passed in Attribute
void classOfStudents::sort(const char *attribute) {
  if (areStringsEqual(attribute, "age")) {
    sortBasedOnAge();
  } else if (areStringsEqual(attribute, "grade")) {
    sortBasedOnGrade();
  } else if (areStringsEqual(attribute, "fn")) {
    sortBasedOnFn();
  } else if (areStringsEqual(attribute, "name")) {
    sortBasedOnName();
  } else if (areStringsEqual(attribute, "email")) {
    sortBasedOnEmail();
  } else if (areStringsEqual(attribute, "gender")) {
    sortBasedOnGender();
  } else {
    std::cout << "Error while Sorting!" << std::endl;
  }
}

//! private:

//* Sort based on Gender
void classOfStudents::sortBasedOnGender() {
  for (int i = 0; i < countOfStudents; i++) {
    for (int j = i + 1; j < countOfStudents; j++) {
      if (areStringsEqual(studentsArray[i].gender, "male") &&
          areStringsEqual(studentsArray[j].gender, "female")) {
        swapStudents(studentsArray[i], studentsArray[j]);
      }
    }
  }
}

//* Sort based on Email
void classOfStudents::sortBasedOnEmail() {
  for (int i = 0; i < countOfStudents; i++) {
    for (int j = i + 1; j < countOfStudents; j++) {
      if (!isFirstBeforeSecond(studentsArray[i].email,
                               studentsArray[j].email)) {
        swapStudents(studentsArray[i], studentsArray[j]);
      }
    }
  }
}

//* Sort based on Name
void classOfStudents::sortBasedOnName() {
  for (int i = 0; i < countOfStudents; i++) {
    for (int j = i + 1; j < countOfStudents; j++) {
      if (!isFirstBeforeSecond(studentsArray[i].name, studentsArray[j].name)) {
        swapStudents(studentsArray[i], studentsArray[j]);
      }
    }
  }
}

//* Sort based on Grade
void classOfStudents::sortBasedOnGrade() {
  for (int i = 0; i < countOfStudents; i++) {
    // find min
    int maxElementIndex = i;
    for (int j = i + 1; j < countOfStudents; j++) {
      if (studentsArray[j].grade > studentsArray[maxElementIndex].grade) {
        maxElementIndex = j;
      }
    }
    if (maxElementIndex != i) {
      swapStudents(studentsArray[i], studentsArray[maxElementIndex]);
    }
  }
}

//* Sort based on Fn
void classOfStudents::sortBasedOnFn() {
  for (int i = 0; i < countOfStudents; i++) {
    // find max
    int minElementIndex = i;
    for (int j = i + 1; j < countOfStudents; j++) {
      if (studentsArray[j].fn < studentsArray[minElementIndex].fn) {
        minElementIndex = j;
      }
    }
    if (minElementIndex != i) {
      swapStudents(studentsArray[i], studentsArray[minElementIndex]);
    }
  }
}

//* Sort based on Age
void classOfStudents::sortBasedOnAge() {
  for (int i = 0; i < countOfStudents; i++) {
    // findMin
    int minElementIndex = i;
    for (int j = i + 1; j < countOfStudents; j++) {
      if (studentsArray[j].age < studentsArray[minElementIndex].age) {
        minElementIndex = j;
      }
    }
    if (minElementIndex != i) {
      swapStudents(studentsArray[i], studentsArray[minElementIndex]);
    }
  }
}

//* Check if first string is before second
bool classOfStudents::isFirstBeforeSecond(const char *arr1,
                                          const char *arr2) const {
  int arr1Lenght = getLenght(arr1);
  int arr2Lenght = getLenght(arr2);
  for (int i = 0; i < arr1Lenght; ++i) {
    if (arr1[i] < arr2[i]) {
      return true;
    } else if (arr1[i] > arr2[i]) {
      return false;
    }
  }

  return false;
}

void classOfStudents::swapStudents(Student &student1, Student &student2) {
  Student temp = student1;
  student1 = student2;
  student2 = temp;
}

//* Validate the Email
bool classOfStudents::validateEmail(const char *email) const {
  for (int i = 0; email[i] != '\0'; ++i) {
    if (email[i] == '@') {
      return true;
    }
  }

  return false;
}

//* Validate the Gender
bool classOfStudents::validateGender(const char *gender) const {
  return areStringsEqual(gender, "male") || areStringsEqual(gender, "female");
}

//* Validate the Grade
bool classOfStudents::validateGrade(const char *grade) const {

  double doubleGrade = parseStringToDouble(grade);

  return doubleGrade >= 2 && doubleGrade <= 6;
}

//* Validate the Age
bool classOfStudents::validateAge(const char *age) const {

  double doubleAge = parseStringToInt(age);

  return doubleAge >= 15 && doubleAge <= 65;
}

//* Validate the fn
bool classOfStudents::validateFn(const char *fn) const {

  for (int i = 0; fn[i] != '\0'; ++i) {
    if (fn[i] < '0' || fn[i] > '9') {
      return false;
    }
  }

  return !checkIfFnExists(fn);
}

//* Check if the Strings are the same
bool classOfStudents::areStringsEqual(const char *arr1,
                                      const char *arr2) const {
  int arr1Lenght = getLenght(arr1);
  int arr2Lenght = getLenght(arr2);

  if (arr1Lenght != arr2Lenght) {
    return false;
  }

  for (int i = 0; arr1[i] != '\0'; ++i) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }

  return true;
}

//* Get the Lenght of Something
int classOfStudents::getLenght(const char *word) const {
  int count = 0;
  for (int i = 0; word[i] != '\0'; ++i) {
    ++count;
  }

  return count;
}

//* Get all info for the Students from the File and load it to the Array
void classOfStudents::getInfoForStudents(std::ifstream &file) {
  bool isStudentPassed = false;

  while (!file.eof()) {
    XmlParser xmlParser;

    file.getline(xmlParser.line, LineSize);
    int lineLenght = xmlParser.getLineLenght();

    while (xmlParser.currentIndex < lineLenght) {
      xmlParser.getTag();

      if (xmlParser.checkTag("name") && !isStudentPassed) {
        xmlParser.getInfo();
        studentsArray[studentsIndex].setName(xmlParser.info);
      } else if (xmlParser.checkTag("email") && !isStudentPassed) {
        xmlParser.getInfo();
        if (!validateEmail(xmlParser.info)) {
          --countOfStudents;
          isStudentPassed = true;
          continue;
        }
        studentsArray[studentsIndex].setEmail(xmlParser.info);
      } else if (xmlParser.checkTag("gender") && !isStudentPassed) {
        xmlParser.getInfo();
        if (!validateGender(xmlParser.info)) {
          --countOfStudents;
          isStudentPassed = true;
          continue;
        }
        studentsArray[studentsIndex].setGender(xmlParser.info);
      } else if (xmlParser.checkTag("fn") && !isStudentPassed) {
        xmlParser.getInfo();
        if (!validateFn(xmlParser.info)) {
          --countOfStudents;
          isStudentPassed = true;
          continue;
        }
        studentsArray[studentsIndex].setFn(xmlParser.info);
      } else if (xmlParser.checkTag("age") && !isStudentPassed) {
        xmlParser.getInfo();
        if (!validateAge(xmlParser.info)) {
          --countOfStudents;
          isStudentPassed = true;
          continue;
        }
        studentsArray[studentsIndex].setAge(xmlParser.info);
      } else if (xmlParser.checkTag("grade") && !isStudentPassed) {
        xmlParser.getInfo();
        if (!validateGrade(xmlParser.info)) {
          --countOfStudents;
          isStudentPassed = true;
          continue;
        }
        studentsArray[studentsIndex].setGrade(xmlParser.info);
      } else if (xmlParser.checkTag("\\student") && !isStudentPassed) {
        studentsIndex++;
      } else if (xmlParser.checkTag("/student") && !isStudentPassed) {
        studentsIndex++;
      } else if (xmlParser.checkTag("student") && isStudentPassed) {
        isStudentPassed = false;
      }
    }
    file.peek();
  }

  file.clear();
  file.seekg(0);
}

//* Parse String to Int
int classOfStudents::parseStringToInt(const char *word) const {
  int num = 0;

  for (int i = 0; word[i] != '\0'; ++i) {
    num = num * 10 + (word[i] - '0');
  }

  return num;
}

//* Parse String to Double
double classOfStudents::parseStringToDouble(const char *word) const {
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

    num2 = num2 + ((double)(word[i] - '0') / multiplier);
    multiplier *= 10;
  }

  return num + num2;
}

//* Get the Count of the Students from the File Stream
int classOfStudents::getCountOfStudentsFromFileStream(
    std::ifstream &file) const {
  int count = 0;

  while (!file.eof()) {
    XmlParser xmlParser;

    file.getline(xmlParser.line, LineSize);
    int lineLenght = xmlParser.getLineLenght();

    while (xmlParser.currentIndex < lineLenght) {
      xmlParser.getTag();

      if (xmlParser.checkTag("student")) {
        ++count;
      }
    }
  }
  file.clear();
  file.seekg(0);
  return count;
}

//* Get the Student Index based on Fn
int classOfStudents::getStudentIndexBasedOnFn(const char *fn) const {
  int intFn = parseStringToInt(fn);

  for (int i = 0; i < countOfStudents; ++i) {
    if (studentsArray[i].fn == intFn) {
      return i;
    }
  }

  return -1;
}