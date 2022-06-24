#include "interface.h"

//! public:
ConsoleInterface::ConsoleInterface() {
  input = new char[InterfaceInputSize];
  command = nullptr;
  currentInputIndex = 0;
}
ConsoleInterface::~ConsoleInterface() {
  delete[] input;
  delete[] command;
}

//* Gets Command from the Input
void ConsoleInterface::getCommand() {
  delete[] command;
  command = new char[InterfaceCommandSize];
  for (; input[currentInputIndex] != ' '; ++currentInputIndex) {
    if (input[currentInputIndex] == '\0') {
      break;
    }
    command[currentInputIndex] = input[currentInputIndex];
  }

  command[currentInputIndex] = '\0';
  ++currentInputIndex;
}

//* Validate Input
bool ConsoleInterface::validateInput() const { return input[0] == '>'; }

//* Check what Command is input
bool ConsoleInterface::checkCommand(const char *inputCommand) const {
  return areStringsEqual(command, inputCommand);
}

//* Check if a File Path has been input
bool ConsoleInterface::isThereFilePath() const {
  return areStringsEqual(command, input);
}

//* Get the File Path from the Input
char *ConsoleInterface::getInfoToSpaceOnlyDigits() {
  char *info = new char[InterfaceCommandSize];
  int infoIndex = 0;

  for (; input[currentInputIndex] != ' '; ++currentInputIndex) {
    if (input[currentInputIndex] < '0' || input[currentInputIndex] > '9' ||
        input[currentInputIndex] == '\0') {
      info[0] = '\0';
      return info;
    }
    info[infoIndex++] = input[currentInputIndex];
  }

  ++currentInputIndex;

  info[infoIndex] = '\0';
  return info;
}

//* Get Attribute to edit
char *ConsoleInterface::getInfoToSpace() {
  char *info = new char[InterfaceCommandSize];
  int infoIndex = 0;

  for (; input[currentInputIndex] != ' '; ++currentInputIndex) {
    if (input[currentInputIndex] == '\0') {
      info[0] = '\0';
      return info;
    }
    info[infoIndex++] = input[currentInputIndex];
  }

  ++currentInputIndex;

  info[infoIndex] = '\0';
  return info;
}

//* Get Info from Input up to '\0'
char *ConsoleInterface::getInfoToTerminateZero() {
  char *info = new char[InterfaceCommandSize];
  int infoIndex = 0;

  for (; input[currentInputIndex] != '\0'; ++currentInputIndex) {
    info[infoIndex++] = input[currentInputIndex];
  }

  info[infoIndex] = '\0';
  return info;
}

//! private:

//* Check if the Strings are the same
bool ConsoleInterface::areStringsEqual(const char *arr1,
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
int ConsoleInterface::getLenght(const char *word) const {
  int count = 0;
  for (int i = 0; word[i] != '\0'; ++i) {
    ++count;
  }

  return count;
}