#include <fstream>
#include <iostream>

struct Problem {
  char *name;
  char *conditions;
  int points;

  Problem() {
    this->name = nullptr;
    this->conditions = nullptr;
    this->points = 0;
  }

  ~Problem() {
    delete[] name;
    delete[] conditions;
  }

public:
  // Print the  Problem to Console
  void print() {
    std::cout << "Problem's Name: " << this->name << std::endl;
    std::cout << "Problem's Conditions: " << this->conditions << std::endl;
    std::cout << "Problem's Points: " << this->points << std::endl;
  }

  // Change Name
  void changeName(const char *newName) {
    delete[] this->name;
    this->name = new char[1024];
    copyStrings(this->name, newName);
  }

  // Change Conditions
  void changeConditions(const char *newConditions) {
    delete[] this->conditions;
    this->conditions = new char[1024];
    copyStrings(this->conditions, newConditions);
  }
  void changePoints(const int newPoints) { this->points = newPoints; }

private:
  // Copying Strings
  void copyStrings(char *destination, const char *source) {
    int i = 0;
    for (; source[i] != '\0'; ++i) {
      destination[i] = source[i];
    }
    destination[i] = '\0';
  }
};

const int SIZE = 5; // Number of Problems in the Exam

struct Exam {
  Problem problem[SIZE];
  int minPoints;

  Exam() { this->minPoints = 0; }

public:
  // Print the Exam to Console
  void print() {
    for (int i = 0; i < SIZE; ++i) {
      this->problem[i].print();
      std::cout << std::endl;
    }

    std::cout << "Minimum Points needed for Passing: " << this->minPoints;
  }

  // Saving the Exam to a Binary File
  void saveToFile(const char *filePath) {
    std::ofstream file(filePath, std::ios::binary | std::ios::trunc);

    if (!file.is_open()) {
      std::cout << "Error opening File int writeToFile!" << std::endl;
      return;
    }

    // for (int i = 0; i < SIZE; ++i) {
    //   int nameLenght = getStringLenght(this->problem[i].name);
    //   int conditionsLenght = getStringLenght(this->problem[i].conditions);

    //   file.write((const char *)&nameLenght, sizeof(nameLenght));
    //   file.write((const char *)this->problem[i].name, nameLenght);

    //   file.write((const char *)&conditionsLenght, sizeof(conditionsLenght));
    //   file.write((const char *)this->problem[i].conditions,
    //   conditionsLenght);

    //   file.write((const char *)&this->problem[i].points,
    //              sizeof(this->problem[i].points));
    // }

    file.write((const char *)this->problem, SIZE * sizeof(Problem));

    file.write((const char *)&this->minPoints, sizeof(this->minPoints));

    file.close();
  }

  // Reading Exam from a Binary File
  void readFromFile(const char *filePath) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
      std::cout << "Error opening File int readFromFile!" << std::endl;
      return;
    }

    // for (int i = 0; i < SIZE; ++i) {
    //   char name[1024];
    //   char conditions[1024];
    //   int nameLenght;
    //   int conditionsLenght;
    //   int points;

    //   file.read((char *)&nameLenght, sizeof(nameLenght));
    //   file.read((char *)&name, nameLenght);
    //   this->problem[i].changeName(name);

    //   file.read((char *)&conditionsLenght, sizeof(conditionsLenght));
    //   file.read((char *)&conditions, conditionsLenght);
    //   this->problem[i].changeName(conditions);

    //   file.read((char *)&points, sizeof(points));
    //   this->problem[i].points = points;
    //   file.clear();
    // }

    file.read((char *)this->problem, SIZE * sizeof(Problem));

    int minPoints;
    file.read((char *)&this->minPoints, sizeof(minPoints));
    this->minPoints = minPoints;
  }

  // Change the minimum Points needed for Passing the Exam
  void changeMin(const int newMinPoints) { this->minPoints = newMinPoints; }

  // Get the maximum Points you can get from the Exam
  int getMax() {
    int maxPoints = 0;
    for (int i = 0; i < SIZE; ++i) {
      maxPoints += this->problem[i].points;
    }

    return maxPoints;
  }

private:
  // Getting the Lenght Of String
  int getStringLenght(const char *word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
      ++count;
    }
    return count + 1;
  }
};

// Initialize the Problem with the passed in Components
void initProblem(Problem &problem, const char *name, const char *conditions,
                 const int points) {

  // int i;
  // for (i = 0; name[i] != '\0'; ++i) {
  //   problem.name[i] = name[i];
  // }
  // problem.name[i] = '\0';
  // for (i = 0; conditions[i] != '\0'; ++i) {
  //   problem.conditions[i] = conditions[i];
  // }
  // problem.conditions[i] = '\0';

  problem.changeName(name);
  problem.changeConditions(conditions);

  problem.points = points;
}

// Initialize Problem from the Console
void initProblemFromConsole(Problem &problem) {
  char name[1024];
  char conditions[1024];
  int points;

  std::cout << "Enter Problem's Name: ";
  std::cin.getline(name, 1024);

  std::cout << "Enter Problem's Conditions: ";
  std::cin.getline(conditions, 1024);

  std::cout << "Enter Problem's Points: ";
  std::cin >> points;
  std::cout << std::endl;
  std::cin.ignore();

  initProblem(problem, name, conditions, points);
}

// Input Exam
void initExam(Exam &exam) {

  for (int i = 0; i < SIZE; ++i) {
    initProblemFromConsole(exam.problem[i]);
    exam.minPoints += exam.problem[i].points / 2;
  }
}

int main() {
  Exam exam1;
  initExam(exam1);

  exam1.saveToFile("exam.zoro");

  Exam exam2;
  exam2.readFromFile("exam.zoro");
  exam2.print();

  return 0;
}
